#include <stdio.h>
#include <string.h> //strlen
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr
#include <unistd.h> //close

int main (int argc, char *argv[])
{
    int socket_desc;
    struct sockaddr_in server;
    char *message, server_reply[2000];

    //CREATE SOCKET
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
        perror("socket");
    }

    server.sin_addr.s_addr = inet_addr("216.58.192.142");
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
        perror("send");
        /*puts("Send failed");*/

        return (1);
    }

    puts("Data Sent\n");

    //RECEIVE REPLY FROM THE SERVER
    
    /*size_t bytes_received;
    if ((bytes_received = recv(socket_desc, server_reply, sizeof(server_reply) - 1, 0)) < 0)*/
    
    if( recv(socket_desc, server_reply, 2000, 0) < 0)
    {
        perror("recv");
        /*puts("Receive failed");*/
        
        return (1);
    }
    /*TEST THIS:
    server_reply[bytes_received] = '\0';*/

    puts("Reply received\n");
    puts(server_reply);

    /*Can use read() as well*/
    /*read(socket_desc, server_reply , 2000);*/

    //CLOSE THE SOCKET
    close(socket_desc);

    return (0);
}