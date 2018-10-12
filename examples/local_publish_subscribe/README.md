
This example shows how to publish and subscribe between two processes on the same machine.

`$ ./build/camera_sensor -n camera_sensor.sock`

The above camera_sensor process will listen on the UNIX socket "camera_sensor.sock".

`$ ./build/image_processor -s camera_sensor.sock`

The above image_processor will connect to "camera_sensor.sock" and subscribe to "sensors.raw_data.camera".
