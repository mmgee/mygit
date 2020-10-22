#include "../myhead.h"

int main(int argc, char const *argv[])
{
	int tcp_socket = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in tcp_client = {
     	.sin_family = AF_INET,
    	.sin_port=htons(6666),
        .sin_addr.s_addr =inet_addr("192.168.71.189")  
         };


	int ret = connect(tcp_socket, (struct sockaddr *)&tcp_client,sizeof(tcp_client));
	if (ret <0)
	{
		perror("connect failed");
	}
	printf("Connect success!!!!!!\n");
	char buf[1024]={0};
	while(1)
	{
		read(tcp_socket,buf,1024);
		printf("%s\n",buf);
		sleep(1);
	}
	return 0;
}