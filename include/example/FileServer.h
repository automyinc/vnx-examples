/*
 * FileServer.h
 *
 *  Created on: Mar 16, 2020
 *      Author: mad
 */

#ifndef VNX_EXAMPLES_INCLUDE_EXAMPLE_FILESERVER_H_
#define VNX_EXAMPLES_INCLUDE_EXAMPLE_FILESERVER_H_

#include <example/FileServerBase.hxx>
#include <example/InputOutputError.hxx>


namespace example {

class FileServer : public FileServerBase {
public:
	FileServer(const std::string& _vnx_name)
		:	FileServerBase(_vnx_name)
	{
	}
	
protected:
	struct worker_t {
		std::thread thread;
	};
	
	struct request_t {
		vnx::request_id_t id;
		std::string file_name;
		std::function<void(const std::shared_ptr<const File>&)> callback;
	};
	
	void init() override {
		vnx::open_pipe(vnx_name, this, UNLIMITED);
	}
	
	void main() override
	{
		for(int i = 0; i < num_threads; ++i) {
			auto worker = std::make_shared<worker_t>();
			worker->thread = std::thread(&FileServer::work_loop, this);
			workers.push_back(worker);
		}
		Super::main();
		{
			std::lock_guard<std::mutex> lock(mutex);
			do_run = false;
			condition.notify_all();
			for(auto worker : workers) {
				worker->thread.join();
			}
		}
	}
	
	void get_file_async(const std::string& file_name,
						const std::function<void(const std::shared_ptr<const File>&)>& callback,
						const vnx::request_id_t& request_id) const override
	{
		std::lock_guard<std::mutex> lock(mutex);
		auto request = std::make_shared<request_t>();
		request->id = request_id;
		request->file_name = file_name;
		request->callback = callback;
		work_queue.push(request);
		condition.notify_one();
	}
	
private:
	void work_loop()
	{
		while(do_run) {
			std::shared_ptr<request_t> request;
			{
				std::unique_lock<std::mutex> lock(mutex);
				while(do_run && work_queue.empty()) {
					condition.wait(lock);
				}
				if(do_run) {
					request = work_queue.front();
					work_queue.pop();
				}
			}
			if(!request) {
				break;
			}
			
			::FILE* p_file = ::fopen(request->file_name.c_str(), "rb");
			if(!p_file) {
				auto ex = InputOutputError::create();
				ex->what = "fopen() failed for: " + request->file_name;
				vnx_async_return(request->id, ex);
				continue;
			}
			
			::fseek(p_file, 0, SEEK_END);
			const int64_t file_size = ::ftell(p_file);
			::fseek(p_file, 0, SEEK_SET);
			
			auto file = File::create();
			file->contents.resize(file_size);
			
			const size_t num_read = ::fread(&file->contents[0], 1, size_t(file_size), p_file);
			if(num_read != file_size) {
				auto ex = InputOutputError::create();
				ex->what = "fread() failed for: " + request->file_name;
				vnx_async_return(request->id, ex);
				continue;
			}
			request->callback(file);
			
			::fclose(p_file);
		}
	}
	
private:
	bool do_run = true;
	
	mutable std::mutex mutex;
	mutable std::condition_variable condition;
	
	mutable std::queue<std::shared_ptr<request_t>> work_queue;
	
	std::vector<std::shared_ptr<worker_t>> workers;
	
};


} // example

#endif /* VNX_EXAMPLES_INCLUDE_EXAMPLE_FILESERVER_H_ */
