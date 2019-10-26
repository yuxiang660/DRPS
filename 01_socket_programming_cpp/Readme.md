This project is object-oriented socket programming for server-client programs.

# Available Scripts

* Build both server and client
```
/> make
```

* Build server
```
/> make server
```

* Build client
```
/> make client
```

* Build debug programs for gdb
```
/> make debug
```


# Classes

* Server
    - constructor : open a socket for server
    - destructor : close the server socket
    - listen : listen for connections on a port
    - accept : accept a connection on the socket

* Connection
    - constructor : create a connection with an accepted socket from server
    - destructor : close the connection socket
    - send : send a message to client
    - receive : receive a message from client

* Client
    - constructor : open a socket for client
    - destructor : close the client socket
    - connect : connect the client socket with the server
    - send : send a message from client to server
    - receive : receive a message from server to client
    