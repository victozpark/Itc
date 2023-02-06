# Inter thread communication
Topic-based inter-thread communication

## WARNING
Currently under development. <br>
There may be bugs. And it will have more functions later.

## Basic features
- Topic-based data communication. (send, request, reply message)
    > - Send message : It sends a message to all Listeners listening on the topic.
    > - Reqeust message : It sends a message to one of Listeners listening on the topic and wait for a response-message to arrive.
    > - Reply message : When a user-service thread receives a reuqest-message, it can reply back to the sender with a response-message.
- 1:n or 1:1 data transmission.

## UML class diagram
#### Itc module
<img src="https://user-images.githubusercontent.com/46546765/216922493-78c7a9a6-89bd-4850-a16b-8f47d00214b2.png" width="40%">

#### Sample user module
<img src="https://user-images.githubusercontent.com/46546765/216966461-ed6b0477-dc07-4050-a39f-97580eab377c.png" width="40%">

----

## Install (Itc module)
```shell
$ mkdir build                # Make a build directory
$ cd build                   # Change to the build directory
$ cmake ..                   # Create a Makefile
$ make                       # Make a libray file
$ make install               # Install header and library files
$ ls -al ../release/include  # You can check a header file
$ ls -al ../release/lib      # You can check a library file
```

## Test (Sample user module)
```shell
### "Install" is required before testing.
$ cd test                    # Change to the test directory
$ mkdir build                # Make a build directory
$ cd build                   # Change to the build directory
$ cmake ..                   # Create a Makefile
$ make                       # Make a binary file
$ ./main                     # Run test
```

----
Please let me know if there are any bugs or features you would like to use. <br>
Thank you. :)
