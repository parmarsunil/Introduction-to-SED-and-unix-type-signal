#include<stdio.h>
#include<signal.h>
#include<sys/wait.h>
#include<stdlib.h>

void handler1(int);
void handler(int signum)
{
signal(signum,SIG_IGN);
FILE *fp;
char str[20]="interrupted";
fp=fopen("temp","w");
//printf("jfgbjkhfdd");
fprintf(fp,"%s",str);
rewind(fp);
signal(SIGINT,handler1);
}
void handler1(int signum)
{

//sleep(2);
printf("\nnow i am taking rest now");
fflush(stdout);
//sleep(2);
signal(SIGINT,SIG_DFL);
}
int main()
{
signal(SIGINT,handler);

while(1)
{
//printf("working\n");
//sleep(100);
}
return 0;
}
