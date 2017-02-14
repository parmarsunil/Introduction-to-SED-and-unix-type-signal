#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<string.h>
int main (int argc, char ** argv) {
    int i;
   
    char *cmd[1024];
      char del[4]=" ";
      
   for( i=1; i<argc; i++)
    {
       char *temp=(char *)malloc(sizeof(char)*1024);
       temp=strtok(argv[i],del);
		
		int j=0;
		while(temp!=NULL)
		{   
		    *(cmd+j)=(char *)malloc(sizeof(char)*strlen(temp));
			strcpy(cmd[j],temp);
			temp=strtok(NULL,del);
	
			j++;
		}
		cmd[j]=NULL;
       
 if(i==argc-1)
 {
 execvp(cmd[0], cmd);
    perror("exec");
    abort();
 
 }      
        int pd[2];            //refer from internet
        pipe(pd);

        if (!fork()) {
            dup2(pd[1], 1); 
            execvp(cmd[0], cmd);
            perror("exec");
            abort();
        }

        
        dup2(pd[0], 0);
        close(pd[1]);
    }

    
}

