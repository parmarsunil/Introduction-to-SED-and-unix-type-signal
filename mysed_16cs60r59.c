#include <stdio.h>
#include <string.h>
#include <regex.h>
#include<stdlib.h>
#include"sed4_16cs60r59.h"   //header file for mysed \[line1...line2]d
#include"sed1_16cs60r59.h"   //header file for mysed [line]d
#include"sed2_16cs60r59.h"   //header file for mysed [line1,line2]d
#include"sed3_16cs60r59.h"   //header file for mysed [line1...line2]d
char name[20];
void ren(char *file)
{ 

strcpy(name,file);

}
char** tokenize(char *argv[])
{
    char *temp,*temp1;
    int p_len=strlen(argv[1]);
    int j;
    temp=(char*)malloc(sizeof(char)*p_len);
    strcpy(temp,argv[1]);
    //strcpy(file,argv[2]);
    char del[3]="/\n";
       
       int i=1;
      // strcpy(del,"/\n");
	  temp1=strtok(temp,del);
	  while(temp1!=NULL)
	   {
	     argv[i]=temp1;
	     temp1=strtok(NULL,del);
		 i++;
	   }
	    argv[i]=NULL;
     return argv;
}

void main(int argc,char *arr[])
{
    FILE *fp,*w_fp;
    char *line,*replace;
    char file[20],temp[10];
    char **argv;
    regex_t re;
    size_t n_match;
    size_t len;
    char temp2[50];
     regmatch_t index[1];
     int status,i=0,p_len,n=0,reval,control=0,j=0,flag=0;
     //char *replace;
     strcpy(file,arr[2]);
     replace=(char*)malloc(sizeof(char)*100);
     while(arr[1][i]!='\0')
     {
         if(arr[1][i]=='[')
         {
         control=1;
         //break;
         
         }
         i++;
     }
       if(control==1)
       { 
                  i=0;
                   strcpy(temp2,arr[1]); //copy options into temp
             if(temp2[0]=='\\')
                {
                flag=1;
                } 
             else{
            while(temp2[i]!='\0')
            {
                if(temp2[i]=='.')
                 {
                 flag=2;
                 break;
                 }
            else if(temp2[i]==',')
                 {
                  flag=3;
                  break;
                  }
                  i++;
            }
            }
            if(flag==1)
            {
            //printf("hi");
            sed4(arr); //call  function for mysed \[line1...line2]d
            }
            else if(flag==2)
            {
            sed3(arr);  //call function for mysed [line1...line2]d
            }
            else if(flag==3)
            {
            sed2(arr);   //call function for mysed [line1,line2]d
            }
            else{
            sed1(arr);   //call function for mysed [line]d
            }
       }
    else
    { 
    argv=tokenize(arr);
     strcpy(replace,argv[3]);
    // p_len=strlen(argv[3]);
    line=(char*)malloc(sizeof(char)*1024);
    fp=fopen(file,"r");
    w_fp=fopen("temp","w");
    if(strcmp(argv[4],"g")==0)
    {    
        if(regcomp(&re,argv[2],REG_EXTENDED)!=0)
        {
        printf("cant be compiled");
        } 
         while((reval=getline(&line,&len, fp))!=-1)
         {
            while(*line!='\0')
            {
             status=regexec(&re,line,1,index,0);
             if(status==0)
             {
                 i=0;
                 while((size_t)i!=index[0].rm_so)
                 {
                 fputc(line[i],w_fp);
                 i++;
                 }
                 fputs(replace,w_fp);
                 line+=index[0].rm_eo;
                 
                 
              }
             else
             {
              fputs(line,w_fp);
              break;
              }
            }
          }
          regfree(&re);
          fclose(w_fp);
     }
     else
     {
         i=0;
         strcpy(temp,argv[4]);
        while(temp[i]!='\0')
        {
        n=n*10;
        n=n+(int)(temp[i]-'0');
        i++;
        }
      if(regcomp(&re,argv[2],REG_EXTENDED)!=0)
        {
        printf("cant be compiled");
        } 
         while((reval=getline(&line,&len, fp))!=-1)
         {
            while(*line!='\0')
            {
             status=regexec(&re,line,1,index,0);
             if(status==0)
             { 
               /*if(n!=1)
               {
                fputs(line,w_fp);
                n--;
                break;
               }*/
               //else{
                i=0;
                 while((size_t)i!=index[0].rm_so)
                 {
                 fputc(line[i],w_fp);
                 i++;
                 } 
                    if(n==1){
                     fputs(replace,w_fp);
                     line+=index[0].rm_eo;
                     n--;
                     }
                     else{
                      while((size_t)i!=index[0].rm_eo)
                         {
                         fputc(line[i],w_fp);
                         i++;
                         } 
                         line+=index[0].rm_eo;
                         n--;
                      }
              }
             else
             {
              fputs(line,w_fp);
              break;
              }
            }
          }
          regfree(&re);
          fclose(w_fp);
     }
      ren(file);
      remove(file);
      rename("temp",name);
      //printf("%s",name);
    }
}
