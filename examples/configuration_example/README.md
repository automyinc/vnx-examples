
This example shows the different ways to set configuration options:

- Via command line parameters
- Via plain configuration files
- Via JSON configuration files

Example without any configuration:
```
$ ./configuration_example
some_option = 'default'
SomeModule.some_option = 'default'
AnotherModule.some_option = 'default'
```

Example with "config" folder:
```
$ ./configuration_example -c config/
INFO: some_option = '1234'
INFO: SomeModule.some_option = '1234'
INFO: AnotherModule.some_option = '1234'
```

Example with "config" folder and command line options:
```
$ ./configuration_example -c config/ --some_option 5 6 7 8 --SomeModule.some_option 4321 --AnotherModule.some_option
INFO: some_option = '[5,6,7,8]'
INFO: SomeModule.some_option = '4321'
INFO: AnotherModule.some_option = '1'
```
