#include <sys/stat.h>
 #include <sys/types.h>
 #include<stdio.h>
int main(int argc,char *argv[])
{
int i,status;
//printf("%d %s %s %s %s %s %s",argc,argv[0],argv[1],argv[2],argv[3],argv[4],argv[5],argv[6]);
for(i=1;i<argc;i++)
{
if((status=mkdir(argv[i],S_IRWXU|S_IRWXG|S_IRWXO))!=0)
printf("mymkdir: cannot create directory '%s':File exists",argv[i]);
}
return 0;
}
