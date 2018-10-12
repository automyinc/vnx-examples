
This example shows how to publish and subscribe between two machines.

## Using vnxrouter on each machine

This is a typical setup for scenarios where multiple processes are running on each machine.
Using vnxrouter will avoid sending the same data multiple times over the network, in case of multiple subscribing processes.

First we start a vnxrouter on each machine:

`Box_A$ screen -d -S vnxrouter -m vnxrouter -c examples/remote_publish_subscribe/Box_A/config/`

`Box_B$ screen -d -S vnxrouter -m vnxrouter -c examples/remote_publish_subscribe/Box_B/config/`

Then we start a lidar_sensor on Box_A listening on lidar_sensor.sock:

`Box_A$ ./build/lidar_sensor -n lidar_sensor.sock -c examples/remote_publish_subscribe/Box_A/config/`

vnxrouter on Box_A is configured to connect to lidar_sensor.sock and subscribe to "sensors.raw_data".

Then we start a lidar_processor on Box_B and tell it to connect to the local vnxrouter,
which is (by default) configured to listen on ".vnxrouter.sock" as well as on the default TCP port 4444 on all interfaces:

`Box_B$ ./build/lidar_processor -s .vnxrouter.sock`

vnxrouter on Box_B is configured to connect to Box_A's vnxrouter on the default port 4444 and subscribe to "sensors.raw_data.lidar".

Now we could start another lidar_processor on Box_B and it will get the same data from vnxrouter, avoiding
a duplicate network load which would be the case if we connected directly to lidar_sensor over TCP.

Another example is vnxdump, which by default will connect to the local vnxrouter on TCP port 4444:

`Box_B$ vnxdump -i`

The above command will show all samples that go through the local vnxrouter. (without -i it will also dump the contents)

vnxrouter will try to connect and re-connect to all it's configured nodes once a second, as well as try to bind
 to it's server socket every 3 seconds.

## Time synchronization

As an example, vnxrouter on Box_B is also configured to sync it's time with Box_A's vnxrouter, which essentially
turns Box_A into a time server.

Now we could further sync any process on Box_B to the local vnxrouter by setting Proxy.time_sync to true:

`Box_B$ ./build/lidar_processor -s .vnxrouter.sock --Proxy.time_sync 1`

This will make `vnx::get_time_*()` inside lidar_processor return the same time as on Box_A.

It's important to note that the system clock is never adjusted in any case, this allows running multiple processes
which are each sync'ed to different clocks.

