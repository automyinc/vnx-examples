
This benchmark will send synchronous requests as fast as possible from a single thread.

The maximum throughput is usally limited by how fast the operating system can schedule threads (in case of UNIX sockets),
or by the latency of the network (in case of TCP).
With multiple clients a much higher throughput is possible.

## Between two processes over a UNIX domain socket

`$ ./build/database_server`

`$ ./build/examples/benchmark_request_response/benchmark_request_response`

Result on a i7-7700HQ: ~26000 requests/s

## Between two machines over TCP

`Box_A$ ./build/database_server -n :9999`

`Box_B$ ./build/examples/benchmark_request_response/benchmark_request_response -n Box_A:9999`

