
This example shows how to perform zero-copy publish/subscribe.

Zero copy only works between modules in the same process and when the samples are published
via `std::shared_ptr`.

As can be seen from the source code of zero_copy_publish_subscribe.cpp all that's needed is two modules
running in the same process:

`$ ./build/examples/zero_copy_publish_subscribe/zero_copy_publish_subscribe`

Generally it is a good idea to group multiple modules into a single process,
as long as the use-case allows for doing so.
