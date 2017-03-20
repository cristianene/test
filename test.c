#include<winsock2.h>
#include<winsock.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
/* comment */
SOCKET s; //Socket handle

int main(int argc, char **argv)
{
	SOCKADDR_IN target; //Socket address information
	char sendBuff[] = "asdfasfdasdfasddfasfdasfasadfasfasfasfasfdasfasdfdfsadfasfasfasfasfdasfasdfdfsadfasfasfasfasfdasfasdfdfsadfasfasfasfasfdasfasdfdfsadfasfasfasfasfdasfasdfdfsadfasfasfasfasfdasfasdfdfsadfasfasfasfasfdasfasdfdfsadfasfasfasfasfdasfasdfdfsadfasfasfasfasfdasfasdfdfsadfasfasfasfasfdasfasdfdfsadfasfasfasfasfdasfasdfdfsadfasfasfasfasfdasfasdfdfsadfasfasfasfasfdasfasdfdfsadfasfasfasfasfdasfasdfdfsadfasfasfasfasfdasfasdfdfsadfasfasfasfasfdasfasdfdfsadfasfasfasfasfdasfasdfdfsadfasfasfasfasfdasfasdfdfsdafsfsdfsafsadfa";
	int i;
	//Start up Winsock…
	WSADATA wsadata;

	int error = WSAStartup(0x0202, &wsadata);

	target.sin_family = AF_INET; // address family Internet
	target.sin_port = htons (atoi(argv[2])); //Port to connect on
	target.sin_addr.s_addr = inet_addr (argv[1]); //Target IP

	do
	{
		s = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP); //Create socket
		if (s == INVALID_SOCKET)
		{
			printf("error creating socket\n");
		}  

 		/* Try to connect to server */

		if (SOCKET_ERROR == connect(s, (SOCKADDR *)&target, sizeof(target)))
		{
			printf("error connecting to server\n");
			if (s)
        		closesocket(s);
		}

		/* Send dummy data to server */
	//	send(s, sendBuff, sizeof(sendBuff), 0);
	//	sleep(1);
	//	if (s)
    //    	closesocket(s);
	} while(1);
	
	return 0;
}
