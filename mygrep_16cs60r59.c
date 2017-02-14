#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h> 
#include<stdlib.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <fcntl.h> 
int main(int argc,char *argv[])
{
FILE *fp;
char line[512],pattern[512];
char temp[10];
int a=0;//sizeof(line);
int b=0;//sizeof(pattern);
int l_len;
int p_len;
int i=0,j=0,n=0,k=0;
 if(strcmp(argv[1],"-v")==0)
 {
 strcpy(pattern,argv[2]);
 p_len=strlen(pattern);
 for(j=3;j<argc;j++)
 {
 fp=fopen(argv[j],"r");
while(!feof(fp))
{
fgets(line,sizeof(line), fp);
l_len=strlen(line);
//printf("%s %d\n",line,l_len);
a=0;
b=0;

while(a<l_len&&b<p_len)
{
    if(pattern[b+1]=='*')
    { 
     while(pattern[b]==line[a])
        a++;
     b=b+2;
    }
    else if(pattern[b+1]=='+')
    { 
        if(pattern[b]!=line[a]){
        a++;
        b=0;
      continue;
      }
     while(pattern[b]==line[a])
        a++;
     b=b+2;
    }
    else if(pattern[b+1]=='?')
    { 
        if(pattern[b]==line[a])
        a++;
        b+=2;
    }
    else if(pattern[b]==line[a])
    {
        b++;
        a++;
    }
    else
    {
         a++;
        b=0;
    }
}
if(b!=p_len)
printf("%s",line);
}
}
}


//grep -m
else
if(strcmp(argv[1],"-m")==0)
 {
 strcpy(pattern,argv[3]);
 p_len=strlen(pattern);
 for(j=4;j<argc;j++)
 {
 fp=fopen(argv[j],"r");
 fp=fopen(argv[j],"r");
 strcpy(temp,argv[2]);
 //printf("%s",argv[2]);
    while(temp[i]!='\0')
    {
    n=n*10;
    n=n+(int)(temp[i]-'0');
    i++;
    }
    k=n;
while(!feof(fp)&&k>0)
{
fgets(line,sizeof(line), fp);
l_len=strlen(line);
//printf("%s %d\n",line,l_len);
a=0;
b=0;

while(a<l_len&&b<p_len)
{
    if(pattern[b+1]=='*')
    { 
     while(pattern[b]==line[a])
        a++;
     b=b+2;
    }
    else if(pattern[b+1]=='+')
    { 
        if(pattern[b]!=line[a]){
        a++;
        b=0;
      continue;
      }
     while(pattern[b]==line[a])
        a++;
     b=b+2;
    }
    else if(pattern[b+1]=='?')
    { 
        if(pattern[b]==line[a])
        a++;
        b+=2;
    }
    else if(pattern[b]==line[a])
    {
        b++;
        a++;
    }
    else
    {
         a++;
        b=0;
    }
}
if(b==p_len){
printf("%s",line);
k--;
}
}
}
}

//simple
else{
strcpy(pattern,argv[1]);
 p_len=strlen(pattern);
 for(j=2;j<argc;j++)
 {
 fp=fopen(argv[j],"r");
while(!feof(fp))
{
fgets(line,sizeof(line), fp);
l_len=strlen(line);
//printf("%s %d\n",line,l_len);
a=0;
b=0;

while(a<l_len&&b<p_len)
{
    if(pattern[b+1]=='*')
    { 
     while(pattern[b]==line[a])
        a++;
     b=b+2;
    }
    else if(pattern[b+1]=='+')
    { 
        if(pattern[b]!=line[a]){
        a++;
        b=0;
      continue;
      }
     while(pattern[b]==line[a])
        a++;
     b=b+2;
    }
    else if(pattern[b+1]=='?')
    { 
        if(pattern[b]==line[a])
        a++;
        b+=2;
    }
    else if(pattern[b]==line[a])
    {
        b++;
        a++;
    }
    else
    {
         a++;
        b=0;
    }
}
if(b==p_len)
printf("%s",line);
}
}
}

return 0;
}
