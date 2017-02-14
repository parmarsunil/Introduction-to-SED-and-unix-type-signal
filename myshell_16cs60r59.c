#include <sys/stat.h>
#include <sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <termios.h>
#include <signal.h>
#include <sys/wait.h>
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

void handler(int sig)
{
  pid_t pid;

  pid = wait(NULL);

  //printf("Pid %d exited.\n", pid);
}




//run
int main()
{
     char ch;
    int i=0,j=0,k=0;
     char command[100];
    char history[200][100];
	char *cmd,*temp;
	pid_t pid;
	size_t len;
	char *argv[100],temp1[200][200],*argv1[100];
	char arr[1024],*arr1;
	arr1=(char*)malloc(1024*sizeof(char));
	ssize_t status;
	char del[4];
	//char del1[4]=" |\t\n";
	cmd=(char *)malloc(sizeof(char)*1000);
	getcwd(arr,1024);
	arr1=getenv("PATH");
	strcat(arr1,":");
	strcat(arr1,arr);
	setenv("PATH",arr1,1);

    //char history[200][200];
    //int point=0,last;
	while(1)
	{
	//int z;
		//status=getline(&cmd,&len,stdin);
		j=0;
         i=k-1;
        while((ch=getch())!='\n')
        {
          if(ch=='\033')
         {
             getch();
             switch(getch())
            {
              case 'A':
             {
      //printf("up");
              if(i<0)
                 break;
         printf("\33[2K\r");
         strcpy(cmd,history[i]);
          j=strlen(history[i]);
           printf("%s",history[i]);
           i--;
           break;
            }
              case 'B':
              {
              //printf("down");
                if(i>k-1)
                    break;
                   i++;
              printf("\33[2K\r");
              strcpy(cmd,history[i]);
              j=strlen(history[i]);
             printf("%s",history[i]);
              break;
              }
              case 'C':
              {
              //printf("left");
              break;
              }
              case 'D':
              {
              //printf("right");
              break;
              }
              default:
              {
              printf("chutiya");
              break;
              }
          }
       }
        else if(ch==127)
         {
        printf("\b \b");
           j--;
           }
           else{
           cmd[j++]=ch;
           printf("%c",ch);
           }
         }
        cmd[j++]='\0';
        printf("\n");
        strcpy(history[k++],cmd);
		
		int l=strlen(cmd);
		int flag=0,i=0;
		while(l>0)
		{
		if(cmd[i]=='|')
		  { 
		   flag=1;
		   
		   }
		    i++;
		    l--;
		   
		}
		
		int j=0,k=0;
		if(flag==1)
		{
		strcpy(del,"|\n");
		temp=strtok(cmd,del);
		argv[0]="mypipe";
		int i=1,j;
		while(temp!=NULL)
		{
			argv[i]=temp;
			temp=strtok(NULL,del);
			i++;
		}
		argv[i]=NULL;
		//printf("%d\n",i);
		//for(j=1;j<i;j++)
		//printf("..%s\t",argv[j]);
		if((pid=fork())==0){				
                execvp("./mypipe",argv);
                exit(0);
               }
           waitpid(pid,&status,WIFEXITED(&status));     
		}
		else
			
		{
		strcpy(del," \n\t");
		temp=strtok(cmd,del);
		int i=0,j;
		while(temp!=NULL)
		{
			argv[i]=temp;
			temp=strtok(NULL,del);
			i++;
		}
		argv[i]=NULL;
		
		//if(strcmp(argv[1],"&")==0)
		
		if(strcmp(argv[0],"mycd")==0)
		{
		chdir(argv[1]);
		char cwd[1024];
               getcwd(cwd, sizeof(cwd));
               printf("%s\n", cwd);
               //continue;
                }
        //    if(strcmp(argv[i-1],"&")==0)
                
		if(strcmp(argv[0],"myexit")==0)
			exit(1);
			signal(SIGCHLD, handler);
		if((pid=fork())==0)
		{
		if(strcmp(argv[i-1],"&")==0) {
		   argv[i-1]=NULL;
		 setpgid(0,0);
		 }
		 
			if(strcmp(argv[0],"mymkdir")==0)
				execvp("./mymkdir",argv);
			else
				if(strcmp(argv[0],"myrm")==0)
					execvp("./myrm",argv);
				else
					if(strcmp(argv[0],"mymv")==0)
						execvp("./mymv",argv);
			  else
			if(strcmp(argv[0],"mytail")==0)
				execvp("./mytail",argv);
		   else
			if(strcmp(argv[0],"myls")==0)
				execvp("./myls",argv);
			else	
			if(strcmp(argv[0],"mypwd")==0)
				execvp("./mypwd",argv);
				else
			if(strcmp(argv[0],"myps")==0)
				execvp("./myps",argv);
				else
		        if(strcmp(argv[0],"mygrep")==0)
		               execvp("./mygrep",argv);
		     else
		     if(strcmp(argv[0],"mysed")==0)
		          execvp("./mysed",argv);
			else execvp(argv[0],argv);
			printf("command not found");
			free(cmd);
			exit(0);
		}
		else
		 {   if(strcmp(argv[i-1],"&")==0) {
		   
		    }
		    else
			waitpid(pid,&status,WIFEXITED(&status));
		}
		}
	}
	return 0;
}

