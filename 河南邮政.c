char filename[100+1]={0}; //存放明文

 memset(filename,0,sizeof(filename));
              sprintf(filename,"%s/temp/%s%s.JYRQICWRITE",getenv("HOME"),argv[1],argv[2]);
              sprintf(path,"%s/bin/zylyan",getenv("HOME"));
fp=fopen(filename,"wb");
if(fp==NULL)
    {
        sprintf(recode,"%s","2001");
        sprintf(redesc,"%s","打开读串口文件失败");
        fprintf(fp,"%4s%-40s\n",recode,redesc);
        fclose(fp);
        return 0;
    }
 
sprintf(userID,"%s",argv[3]);
sprintf(psw,"%s",argv[4]);
gasValue=atof(argv[5]);	
bqcs=atoi(argv[6])+1;


   
         if(WriteUCard(path,9600,userID,psw,gasValue,bqcs,errorInfo)){
            //printf("write user card ok.(userID=%s gasValue=%lf bqcs=%d)\n",userID,gasValue,bqcs);
        sprintf(recode,"%s","0000");        
        fprintf(fp,"%4s%-40s\n",recode,"写卡成功！");        
        fclose(fp);
        ExitCard();
        return 0;
        }
        else{
         sprintf(recode,"%s","2003");
        //sprintf(redesc,"%s","打开读串口文件失败");
        fprintf(fp,"%4s%-40s\n",recode,get_errorInfo());
        fclose(fp);
        ExitCard();
        return 0;
        }
    } 	
return 0;



//2
int ret=0;
u8 userID[10]={0};
u8 psw[10]={0};
double gasValue=0.0;    
u8 bqcs=0;
u8 errorInfo[20]={0};
char recode[4+1]={0};
char redesc[40+1]={0};
char redata[1024]={0};
char path[100+1]={0};

int len;
FILE *fp;
