#include <stdio.h>
#include <string.h> //strlen
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr

int main (int argc, char *argv[])
{
    int socket_desc;
    struct sockaddr_in_server;
    char *message;

    //CREATE SOCKET
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
        perror("socket");
    }

    server.sin_addr.s_addr = inet_addr("74.125.235.20");
    server.sin_family = AF_INET;
    server.sin_port = htons( 80 );

    //CONNECT TO A REMOTE SERVER
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("connect");
        /*puts("connect error");*/
        return (1);
    }

    puts("Connected");

    //SEND SOME DATA
    message = "GET / HTTP/1.1\r\n\r\n";
    if( send(socket_desc, message, strlen(message), 0) < 0)
    {
        puts("Send failed");

        return (1);
    }

    puts("Data Sent\n");

    return (0);
}