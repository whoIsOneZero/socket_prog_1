# Socket Programming
Getting started.clear
 
## server.c
-> FILES INCLUDED <-

- sys/types.h: contains definitions of a number of data types used in system calls.

- sys/socket.h: includes a number of definitions of structures needed for sockets.

- netinet.h: contains constants and structures needed for internet domain addresses

### Tutorials
https://www.binarytides.com/socket-programming-c-linux-tutorial/

## Get IP address of hostname
- When connecting to a remote host , it is necessary to have its IP address. Function gethostbyname is used for this purpose. It takes the domain name as the parameter and returns a structure of type hostent. This structure has the ip information. It is present in netdb.h