#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
int main(){
int sd,cadl;
struct sockaddr_in sad,cad;
char str[50];
sd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
sad.sin_family=AF_INET;
sad.sin_port=htons(9995);
sad.sin_addr.s_addr=inet_addr("127.0.0.1");
connect(sd, (struct sockaddr *)&sad, sizeof(sad));
do
{
recv(sd, str, sizeof(str),0);
printf("\n codeword recv from sender is %s \n",str);
printf("Enter the string :");
fflush(stdin);
scanf("%s",str);
send(sd, str, sizeof(str),0);
}while(strcmp(str,"bye")!=0);
close(sd);
}