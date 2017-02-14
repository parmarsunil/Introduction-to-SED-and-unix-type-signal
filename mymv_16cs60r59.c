#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


int main(int argc,char *argv[])
{
char cmd[10];
int status;
//printf("%s %s %s %s",argv[0],argv[1],argv[2],argv[3]);
if(argc>4)
printf("too many argumants");
else
status=rename(argv[1],argv[2]);
if(status!=0)
printf("error");
return 0;
}

