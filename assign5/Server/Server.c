#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>

#define BUFLEN 512
#define PORT 5421

void die(char *s) 	//exit function
{
    perror(s);
    exit(1);
}

int main(void) 
{
    struct sockaddr_in si_me, si_other;

    int sockfd, i, slen = sizeof(si_other), recv_len;
    char buf[BUFLEN];

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) 
		//creating socket and getting socket file descriptor
    {
        die("Socket Error");
    }

    memset((char *) &si_me, 0, sizeof(si_me));	//set the address of port

    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(PORT);
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sockfd, (struct sockaddr *) &si_me, sizeof(si_me)) == -1) //binding the port with the port number
    {
        die("bind");
    }

    while (1) 
    {
        printf("Server Waiting for data...");
        fflush(stdout);
	
	//recieve the file name from client
        if ((recv_len = recvfrom(sockfd, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen)) == -1) 
        {
            die("recvfrom()");
        }
        buf[recv_len] = '\0';//append the file name at the end with null

        printf("\nFile name obtained from client: %s\n", buf);
        FILE *fp = fopen(buf, "r");	//open the file to read the contents in order to send to the client
        if (fp == NULL) //if not open correctly display error and exit
        {
            printf("Cannot open file for reading: %s\n", buf);
            buf[0] = EOF;
            die("sendto()");
        } 
        sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *) &si_other, slen);	
		//send the file name to client which is in buf

        while ((recv_len = fread(buf, 1, sizeof(buf), fp)) > 0) 
		//read the contents of file one by one till the end
        {
            if (sendto(sockfd, buf, recv_len, 0, (struct sockaddr *) &si_other, slen) == -1) 
		//send the contents read to client
            {
                die("sendto()");
            }
        }

        fclose(fp);
        printf("File transferred.\n");

        break;
    }

    close(sockfd);
    return 0;
}
