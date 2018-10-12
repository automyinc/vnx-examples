
This benchmark will try to send 8MP 8-bit mono image frames at ~1000 Hz, for a maximum of ~8 GB/s of bandwidth.

## Between two processes over a UNIX domain socket

`$ ./build/camera_sensor -c examples/benchmark_raw_data_throughput/config/`

`$ vnxdump -d 4 -i -s camera_sensor.sock -t sensors.raw_data.camera | grep Proxy`

## Between two machines over TCP

`Box_A$ ./build/camera_sensor -c examples/benchmark_raw_data_throughput/config/ -n :9999`

`Box_B$ vnxdump -d 4 -i -s Box_A:9999 -t sensors.raw_data.camera | grep Proxy`

## How to compute bandwidth

Debug output of vnxdump's Proxy shows number of samples received per second (s/s = samples/sec),
which is equal to number of frames per second in this case:

`[Proxy] DEBUG: send: 0 s/s, 0 req/s, recv: 690 s/s, 0 req/s`

Bandwidth in MB/s = 8 MB * frames_per_second = 5600 MB/s (in this case, on a i7-7700HQ)
