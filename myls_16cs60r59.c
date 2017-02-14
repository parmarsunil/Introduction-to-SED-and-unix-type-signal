#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pwd.h>
#include<grp.h>
#include<dirent.h>
#include<sys/stat.h>
int  main(int argc,char *argv[])
{
int status;
DIR*p;
struct dirent *d;
struct stat s_stat;
struct stat buff;
struct group *grp;
struct passwd *pwd;
struct tm *info; 
char buffer[80];
 char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("%s",cwd);
    if(argc==1)
  { 
p=opendir(cwd);
}
//printf("%d",argc);
else{
p=opendir(argv[1]);
}
while((d=readdir(p))!=NULL)
{
  status=stat(d->d_name,&buff);
  if(d->d_name[0]=='.')
  continue;
  info=localtime(&(buff.st_mtime));
 pwd=getpwuid(buff.st_uid);
  printf( (S_ISDIR(buff.st_mode)) ? "d" : "-");
    printf( (buff.st_mode & S_IRUSR) ? "r" : "-");
    printf( (buff.st_mode & S_IWUSR) ? "w" : "-");
    printf( (buff.st_mode & S_IXUSR) ? "x" : "-");
    printf( (buff.st_mode & S_IRGRP) ? "r" : "-");
    printf( (buff.st_mode & S_IWGRP) ? "w" : "-");
    printf( (buff.st_mode & S_IXGRP) ? "x" : "-");
    printf( (buff.st_mode & S_IROTH) ? "r" : "-");
    printf( (buff.st_mode & S_IWOTH) ? "w" : "-");
    printf( (buff.st_mode & S_IXOTH) ? "x" : "-");
 printf(" %d\t",buff.st_nlink);
 printf("%s\t",pwd->pw_name);
 grp = getgrgid(buff.st_gid);
 printf("%s\t", grp->gr_name);
 printf("%d\t",(int)buff.st_size);
 strftime(buffer,80,"%b %d %X", info);
   printf("%s\t", buffer );
  
  printf("%s\n",d->d_name);
  
  
  }
  return 0;
}
