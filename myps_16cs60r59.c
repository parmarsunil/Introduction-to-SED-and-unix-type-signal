#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pwd.h>
#include<grp.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
int  main(int argc,char *argv[])
{
int status,count,i,k;
DIR*p;
FILE *fp;
char *str_mer,*dir_name;
struct dirent *d;
struct stat s_stat;
struct stat buff;
struct group *grp;
struct passwd *pwd;
struct tm *info;
char mem[1000],num[50];
char temp2[1000];
ssize_t temp;
str_mer =(char *)malloc(sizeof(char)*100); 
dir_name=(char *)malloc(sizeof(char)*100); 
char buffer[256];
p=NULL;
p=opendir("/proc");
printf("   PID CMD\n");
while((d=readdir(p))!=NULL)
{
if(d->d_name[0]=='.')
  continue;
count=8;
for(i=0;i<strlen(d->d_name);i++)
{
if((d->d_name[i]>='0')&&(d->d_name[i]<='9'))
continue;
else break;
}
if(i==strlen(d->d_name))
{}
else
continue;
status=stat(d->d_name,&buff);
strcpy(str_mer,"/proc/");
strcat(str_mer,d->d_name);
//printf("%s%s",d->d_name,str_mer);
//strcat(str_mer,);
strcat(str_mer,"/comm");
printf("%5s ",d->d_name);
fp=fopen(str_mer,"r");

fscanf(fp,"%s",buffer);
printf("%s\t",buffer);
str_mer[strlen(str_mer)-5]='\0';
strcat(str_mer,"/fd/0");
for(i=0;i<1000;i++)
{mem[i]='z';

}

temp=readlink(str_mer,mem,1000);
i=0;

while(i<100&&mem[i]!='z')
{
if(mem[0]=='t'||mem[0]=='p')
printf("%c",mem[i]);
i++;
}
str_mer[strlen(str_mer)-5]='\0';
strcat(str_mer,"/sched");
fp=fopen(str_mer,"r");


printf("\n");
}
return 0;
}
