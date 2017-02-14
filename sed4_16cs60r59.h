
    //start prog mysed [line1...line2]d
    void sed4(char *argv[])   
    {
    char *line,filename[20];
    int l_num1=0,l_count=0,l_num2=0;
    char temp[50],num[50];
    FILE *fp;
    int i=0,j=0;
   size_t len;
    ssize_t status;
    line=(char*)malloc(sizeof(char)*1024);   //allocate memory to store line
    FILE *w_fp=fopen("tempp","w");   //open a temporary file
    strcpy(temp,argv[1]);            //store the file in temp for future
    //printf("%s %s ",argv[1],argv[2]);
        while(temp[i]!='.')      //calculate the first no.
        {
         if(temp[i]!=91&&temp[i]!=93&&temp[i]!=92)
         {
          num[j]=temp[i];
          l_num1*=10;
          l_num1+=(int)(num[j]-'0');
          j++;        
         }
         i++;    
        }
        i+=3;      //skip all the dot
        j=0;
        while(temp[i]!='\0')
        {
         if(temp[i]!=91&&temp[i]!=93&&temp[i]!='d')  //skip all [,],d,.,,
         {
          num[j]=temp[i];
          l_num2*=10;
          l_num2+=(int)(num[j]-'0');
          j++;        
         }
         i++;
        }
         
   fp=fopen(argv[2],"r");       //open the input file
        while(status=getline(&line,&len,fp)!=-1)
        {
            
            l_count++;
            if(l_count>=l_num1&&l_count<=l_num2)
            {
             fputs(line,w_fp);   //write into temp file
            }
        }      //endof file
    rewind(fp);
    remove(argv[2]);    //delete input file
    rename("tempp",argv[2]); //rename temp file
    
    }
 //end prog mysed [line1...line2]d
