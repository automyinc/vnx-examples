
This benchmark will send asynchronous requests as fast as possible from a single thread.

## Between two processes over a UNIX domain socket

`$ ./build/database_server`

`$ ./build/examples/benchmark_async_request_response/benchmark_async_request_response`

Result on a i7-9750H: ~400000 requests/s

## Between two machines over TCP

`Box_A$ ./build/database_server -n :9999`

`Box_B$ ./build/examples/benchmark_async_request_response/benchmark_async_request_response -n Box_A:9999`

