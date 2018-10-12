
This benchmark will try to send 64K lidar points at ~1000 Hz, for a maximum of 64M points/s, or ~2.5 GB/s.

## Between two processes over a UNIX domain socket

`$ ./build/lidar_sensor -c examples/benchmark_struct_data_throughput/config/`

`$ ./build/lidar_processor`

## Between two machines over TCP

`Box_A$ ./build/lidar_sensor -c examples/benchmark_struct_data_throughput/config/ -n :9999`

`Box_B$ ./build/lidar_processor -s Box_A:9999`

## How to compute bandwidth

`[LidarProcessor] INFO: Processing 30998528 points/s`

LidarProcessor shows how many points are being processed, we assume that processing is not the bottleneck
but rather serialization (in case of UNIX socket) or network transmission.

Bandwidth in MB/s = 40 * points_per_second / 1024 / 1024 = 1182 MB/s (in this case, on a i7-7700HQ)
