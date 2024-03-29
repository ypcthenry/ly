#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iconv.h>
#include "LYCard_type.h"
#include "LYCard_accessor.h"
#include "LYCard.h"

#define DEBUG

/*���Ժ���*/
void islycard_test();
void writepcard_test();
void writeucard_test();
void readucard_test();
void initcard_test();
void checkpswd_test();
void newcardcheck_test();
void exitcard_test();

char pswd1[]="b62307";
char userid1[]="12345678";

void main(){
    int op;
    char sop[10];
    do{
    printf("1.IsLYCard 2.WritePCard 3.WriteUCard 4.InitCard 5.ReadUCard 6.NewCardCheck 7.CheckPswd 0:�˳�\n>>");
    scanf("%d",&op);
    switch(op){
    case 0:
	break;
    case 1:
	islycard_test();
	break;
    case 2:
	writepcard_test();
	break;
    case 3:
	writeucard_test();
	break;
    case 4:
	initcard_test();
	break;
    case 5:
	readucard_test();
	break;
    case 6:
	newcardcheck_test();
	break;
    case 7:
	checkpswd_test();
	break;
	//exitcard_test();
    default:
	printf("����������뿴��ʾ\n\n");
	break;
    }
    }while(op!=0);
    exitcard_test();
}

char* ConvertEnc(char* fromCode,char* toCode,const char* text)
{
    static char bufout[3072],*sin,*sout;
    int length_in,length_out,err;
    iconv_t c_pt;       
    c_pt=iconv_open(toCode,fromCode);
    if(c_pt==(iconv_t)-1)
    {
#ifdef _DEBUG_XML_
	printf("iconv_open failed:%s==>%s\n ",fromCode,toCode);
#endif
	return NULL;
    }
    iconv(c_pt,NULL,NULL,NULL,NULL);
    length_in=strlen(text)+1;
    length_out=3072;
    sin=(char*)text;
    sout=bufout;
    err=iconv(c_pt,&sin,(size_t*)&length_in,&sout,(size_t*)&length_out);
    if(err==-1)
    {
	printf("converting failed\n");
	return NULL;
    }
    iconv_close(c_pt);
    return bufout;
}

void islycard_test(){
    FILE *fp;
	
    char filename[100+1]={0}; //�������
	
    memset(filename,0,sizeof(filename));
    // sprintf(filename,"%s/temp/jycardlog.txt",getenv("HOME"));
    //fp=fopen(filename,"wb");
    
    u8 errorInfo[20]={0};
    if(IsLYCard("star500x",9600,errorInfo)){
        //fprintf(fp,"islycard ok!\n");    
        printf("islycard ok!\n");
        // printf("errorCode=%d\terrorInfo=%s)\n",get_errorCode(),get_errorInfo());
    }	
    else{
        //fprintf(fp,"islycard fail! (errorCode=%d\terrorInfo=%s)\n",get_errorCode(),get_errorInfo());    
        printf("islycard fail! (errorCode=%d\terrorInfo=%s)\n",get_errorCode(),get_errorInfo());
    }
    fclose(fp);
}

void writepcard_test(){
    u8 userID[10]={0};
    u8 psw[10]={0};
    double gasValue=900;
    u8 bqcs=0;
    int zql=4;
    u8 errorInfo[20]={0};
    
    printf("password��\n");
    scanf("%s",psw);
    //strcpy(psw,pswd1);

    printf("userid��\n");
    scanf("%s",userID);
    
    //strcpy(userID,userid1);
    /* printf("input gasvalue, bqcs,zql:\n"); */
    /* scanf("%lf %c %d",&gasValue,&bqcs,&zql); */

    /* printf("bqcs:\n"); */
    /* scanf("%c",&bqcs); */

    /* printf ("zql:\n"); */
    /* scanf("%d",&zql); */
    
    printf("write user card ok.(befoare info:userID=%s passwd=%s gasValue=%lf bqcs=%d)\n",userID,psw,gasValue,bqcs);
    
    if(WritePCard("star500x",9600,userID,psw,gasValue,bqcs,zql,errorInfo)){
        printf("write user card ok.(info:userID=%s passwd=%s gasValue=%lf bqcs=%d)\n",userID,psw,gasValue,bqcs);
    }
    else{
        printf("write p card fail (errorCode=%d\terrorInfo=%s)\n",get_errorCode(),get_errorInfo());
    }
}

void writeucard_test(){
    u8 userID[10]="123456";
    u8 psw[10]={0};
    double gasValue=0.0;
    u8 bqcs=0;
    u8 errorInfo[20]={0};
    
    printf("���������룺\n");
    scanf("%s",psw);
    //strcpy(psw,pswd1);

    printf("�������û���ţ�\n");
    scanf("%s",userID);
    //strcpy(userID,userid1);
    printf("input gasValue:\n");
    scanf("%lf",&gasValue);
    printf("input bqcs\n");
    scanf("%d",&bqcs);
    
    printf("write user card ok.(before info:userID=%s passwd=%s gasValue=%lf bqcs=%d)\n",userID,psw,gasValue,bqcs);
    
    if(WriteUCard("star500x",9600,userID,psw,gasValue,bqcs,errorInfo)){
        printf("write user card ok.(after info:userID=%s passwd=%s gasValue=%lf bqcs=%d)\n",userID,psw,gasValue,bqcs);
#ifdef DEBUG
    printf("print\n");
#endif
    }

    else{
        printf("write user card fail! (errorCode=%d\terrorInfo=%s)\n",get_errorCode(),get_errorInfo());
    }
}

void readucard_test(){
    u8 id[10]={0};
    u8 userID[10]={0};
    u8 gasValue[10]={0};
    u8 bqcs[3]={0};
    u8 mmcd[3]={0};
    u8 factoryID[10]={0};
    u8 errorInfo[20]={0};

    if(ReadUCard("star500x",9600,id,userID,gasValue,bqcs,mmcd,factoryID,errorInfo)){
        printf("read ok! (id=%s userID=%s gasValue=%s bqcs=%s mmcd=%s factoryID=%s)\n",id,userID,gasValue,bqcs,mmcd,factoryID);
#ifdef DEBUG
        printf("sss\n");
#endif
    }else{
        printf("read fail! (errorCode=%d\terrorInfo=%s)\n",get_errorCode(),get_errorInfo());
    }
}

void initcard_test(){
    u8 psw[10]={0};
    u8 errorInfo[20]={0};

    printf("���������룺\n");
    scanf("%s",psw);
    //strcpy(psw,pswd1);

    if(InitCard("star500x",9600,psw,errorInfo)){
        printf("Init card ok!\n");
    }else{
        printf("Init card fail! (errorCode=%d\terrorInfo=%s\n)",get_errorCode(),get_errorInfo());
    }
}
void checkpswd_test(){
    u8 pswd[20]={0};
    u8 errorInfo[25]={0};

    printf("���������룺\n");
    scanf("%s",pswd);
    //strcpy(pswd,pswd1);

    if(CheckPsw("star500x",9600,pswd,errorInfo)){
        printf("password(%s) check pass!\n",pswd);
    }else{
        printf("password check fail!(errorCode=%d\terrorInfo=%s)\n",get_errorCode(),get_errorInfo());
    }
}

void newcardcheck_test(){
    u8 errorInfo[20]={0};
    if(NewCardCheck("star500x",9600,errorInfo)){
        printf("NewCardCheck: ok!\n");
    }else{
        printf("NewCardCheck: fail!(errorCode=%d\terrorInfo=%s)\n",get_errorCode(),get_errorInfo());
    }
}

void exitcard_test(){
    ExitCard();
}
