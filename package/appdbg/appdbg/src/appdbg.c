/*
 ============================================================================
 Name        : appdbg.c
 Author      : yogi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define dbg_socket "/tmp/appdbg.socket"
#define max_buf_len 256


int main(int argc, const char argv[]) {
	int socket_fd;
	struct sockaddr_un sock_addr;
	int ret;
	char send_buf[max_buf_len]={0};
	char recv_buf[max_buf_len]={0};
	unsigned short i=0;
	unsigned short num=0;
	unsigned char timeout = 5;//5s
	unsigned short recv_num=0;
//	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	printf("main paramater asgc %d, argv %s",argc,argv);

	socket_fd = socket(PF_LOCAL, SOCK_STREAM, 0);
	if(socket_fd < 0){
		printf("socket creat failed\r\n");
		perror("socked failed reason:");
		return 1;

	}
	sock_addr.sun_family = AF_UNIX;
	strcpy(sock_addr.sun_path,dbg_socket);

	ret = connect(socket_fd, (struct sockaddr *)&sock_addr,sizeof(sock_addr));
	if(ret < 0){
		printf("connect to server failed\r\n");
		perror("connect failed reason:");
		close(socket_fd);
		return 1;
	}

	for(i=0; i< argc; i++){
		if(num + strlen(argv[i]) + 1 >  max_buf_len){
			printf("error: send buffer is too long");
			close(socket_fd);
			return 1;
		}
		strcpy(send_buf+num, argv[1]);
		num += strlen(argv[i]) + 1;
	}

	write(socket_fd, send_buf, max_buf_len);

	do{
		recv_num = read(socket_fd, recv_buf, max_buf_len);
		if(recv_num ==0)
			sleep(1);

	}while(timeout>0 && recv_num==0);

	if(recv_buf[0] == -1){
		printf("command error");
	}
	else{
		printf("%s",recv_buf+1);
	}

	return EXIT_SUCCESS;
}
