#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
void sign_handler(int sig)
{
if(sig==2)
{
signal(sig,sign_handler);
printf("you pressed ctrl+c\n");
fflush(stdout);
}
if(sig==3)
exit(0);
}
int main()
{
signal(SIGINT,sign_handler);
signal(SIGQUIT,sign_handler);
while(1){
}
}

