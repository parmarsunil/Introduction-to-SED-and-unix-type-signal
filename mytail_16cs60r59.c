#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{    
    int n=0,i=1;
    char temp[10];
    //char const* const fileName = argv[2];  
    FILE* file = fopen(argv[2], "r"); 
    char line[512];
    int count=0;
    int skip;
    strcpy(temp,argv[1]);
    while(temp[i]!='\0')
    {
    n=n*10;
    n=n+(int)(temp[i]-'0');
    i++;
    }
    //printf("%d",n);
    while (fgets(line, sizeof(line), file)) {
        
        //printf("%s", line);
        count++; 
    }
    
    //printf("\n%d",count);
    skip=count-n;
    if(skip<0)
    exit(0);
    rewind(file);
    while (fgets(line, sizeof(line), file))
    {
    if(skip>0)
    skip--;
    else
    printf("%s", line);
    }
    fclose(file);

    return 0;
 }
