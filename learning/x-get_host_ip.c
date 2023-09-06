#include<stdio.h> //printf
#include<string.h> //strcpy
#include<sys/socket.h>
#include<netdb.h>
#include<arpa/inet.h>

/*netdb - declarations and definitions related to network database 
operations. struct hostent, gethostbyname()*/

/**
* main - entry point; resolves the IP address of  given hostname
*
* Return: 0 (success)
*/
int main(int argc, char *argv[])
{
	char *hostname = "www.google.com";
	char ip[100];
	struct hostent *he;
	struct in_addr **addr_list; //Store a list of addresses associated with hostname
	int i;
		
	if ( (he = gethostbyname( hostname ) ) == NULL) 
	{
		//gethostbyname failed
		herror("gethostbyname");
		return 1;
	}
	
	//Cast the h_addr_list to in_addr, since h_addr_list also has the ip address in long format only
    /*Assign address list obtained from gethostbyname() to 'addr_list' pointer*/
	addr_list = (struct in_addr **) he->h_addr_list;
	
	for(i = 0; addr_list[i] != NULL; i++) 
	{
		//Return the first one;
        //convert IP address from binary
		strcpy(ip , inet_ntoa(*addr_list[i]) );
	}
	
	printf("%s resolved to : %s" , hostname , ip);

	return (0);
}