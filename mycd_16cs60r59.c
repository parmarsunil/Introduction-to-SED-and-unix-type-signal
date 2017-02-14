#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char *argv[])
{

int status;
status=chdir(argv[1]);
return 0;
}
