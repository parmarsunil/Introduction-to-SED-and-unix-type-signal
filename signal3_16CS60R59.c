#include  <stdio.h>
#include  <signal.h>
#include<stdlib.h>

//long  prev_fact, i;    
//REFER FROM http://stackoverflow.com/questions/6168636/how-to-trigger-sigusr1-and-sigusr2


void my_handler(int signum)
{
    if (signum == SIGUSR1)
    {   
       
        printf("Received USER SIGNAL\n");
        fflush(stdout);
    }
    exit(0);
}

int main()
{
pid_t pid;
pid=getpid();
printf("%d",pid);
fflush(stdout);
signal(SIGUSR1, my_handler);
while(1)
{
//sleep(10);
}
}
