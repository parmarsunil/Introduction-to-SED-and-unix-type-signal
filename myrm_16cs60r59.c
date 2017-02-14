#include<stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include<malloc.h>
#include<string.h>
#include <sys/types.h>
#include<errno.h>

int removedir(char path[500])
{

int count=1;
DIR *p = NULL;
struct dirent *pent = NULL;
struct stat eStat;
p = opendir(path);
char x[500];
if ( p == NULL)
{
return -1;
}
while ( (pent=readdir(p)) != NULL )
{
if((strcmp((pent->d_name),".")==0)||(strcmp((pent->d_name),"..")==0))
{	
continue;
}
else
{
strcpy(x,path);
path=strcat(path,"/");
path=strcat(path,pent->d_name);

if(stat(path, &eStat))
{
////printf("ERROR: %s... Meaning it can be a file(Most certainly)\n", strerror(errno));
//unlink(path);
//path=x;
}
else{


if(S_ISDIR(eStat.st_mode))
{ 
removedir(path);
strcpy(path,x);
}
else
 {
unlink(path);
strcpy(path,x);
}	
}
} 
} 
if (!rmdir(path)) return -1; // delete the directory */
}

//run
int main(int argc,char *argv[])
{
int ret;
int status;
int i;
//printf("%d %s %s",argc,argv[1],argv[2]);
if(argc>2)
{
if(strcmp(argv[1],"-r")==0)
{
//printf("%s",argv[i]);
char *path_dir=malloc(500);
strcpy(path_dir,argv[2]);
ret=removedir(path_dir);
}
else
if(strcmp(argv[1],"-d")==0)

//printf("%d",argc);

for(i=2;i<argc;i++)
{
//printf("%s",argv[i]);
status=rmdir(argv[i]);
if(status!=0)
printf("error  %s",argv[i]);
}
}
else
{ 
//printf("%d",i);
for(i=1;i<argc;i++)
{
//printf("%s %d",argv[i],i);
status=remove(argv[i]);

if(status!=0)
printf("error  %s",argv[i]);
}
}

return 0;
}
