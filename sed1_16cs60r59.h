

 void sed1(char *argv[])
    {
    char *line,filename[20];
    int l_num=0,l_count=1;
    char temp[50],num[50];
    FILE *fp;
    int i=0,j=0;
    size_t len;
    ssize_t status;
    line=(char*)malloc(sizeof(char)*1024);
    FILE *w_fp=fopen("tempp","w");
    strcpy(temp,argv[1]);
    //printf("%s %s ",argv[1],argv[2]);
        while(temp[i]!='\0')
        {
         if(temp[i]!=91&&temp[i]!=93&&temp[i]!='d')
         {
          num[j]=temp[i];
          l_num*=10;
          l_num+=(int)(num[j]-'0');
          j++;        
         }
         i++;
        }
         
   fp=fopen(argv[2],"r");
        while(status=getline(&line,&len, fp)!=-1)
           {
          if(l_count==l_num)
            {}
            else{
            fputs(line,w_fp);
            }
             l_count++;
        }
    //rewind(fp);
    remove(argv[2]);
    rename("tempp",argv[2]);
    
    }

