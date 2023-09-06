#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr

int main(int argc, char *argv[])
{
    int socket_desc;
    struct sockaddr_in server;

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

    puts("Conntected");
    return (0);
}