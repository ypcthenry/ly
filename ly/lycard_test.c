#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "LYCard_type.h"
#include "LYCard_accessor.h"
#include "LYCard.h"

/*测试函数*/
void islycard_test();
void writepcard_test();
void writeucard_test();
void readucard_test();
void initcard_test();
void checkpswd_test();
void newcardcheck_test();
void exitcard_test();

void main(){
    int op;
    do{
        printf("1.IsLYCard 2.WritePCard 3.WriteUCard 4.InitCard 5.ReadUCard 6.NewCardCheck 7.CheckPswd 0:退出\n>>");
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
            printf("输入出错，请看提示\n\n");
            break;
        }
    }while(op!=0);
}


void islycard_test(){
    u8 errorInfo[20]={0};
    if(IsLYCard("star500x",9600,errorInfo)){
        printf("islycard ok!\n");
    }	
    else{
        printf("islycard fail! (errorCode=%d\terrorInfo=%s)\n",get_errorCode(),get_errorInfo());
    }
}

void writepcard_test(){
    u8 userID[10]={0};
    u8 psw[10]={0};
    double gasValue=15.7;
    u8 bqcs=4;
    int zql=12345;
    u8 errorInfo[20]={0};
    
    printf("请输入密码：\n");
    scanf("%s",psw);

    printf("请输入用户编号：\n");
    scanf("%s",userID);
    
    if(WritePCard("star500x",9600,userID,psw,gasValue,bqcs,zql,errorInfo)){
        printf("write p card ok.(userID=%s gasValue=%lf bqcs=%d zql=%d)\n",userID,gasValue,bqcs,zql);
    }
    else{
        printf("write p card fail (errorCode=%d\terrorInfo=%s)\n",get_errorCode(),get_errorInfo());
    }
}

void writeucard_test(){
    u8 userID[10]={0};
    u8 psw[10]={0};
    double gasValue=31.5;
    u8 bqcs=4;
    u8 errorInfo[20]={0};
    
    printf("请输入密码：\n");
    scanf("%s",psw);

    printf("请输入用户编号：\n");
    scanf("%s",userID);
    
    if(WriteUCard("star500x",9600,userID,psw,gasValue,bqcs,errorInfo)){
        printf("write user card ok.(userID=%s gasValue=%lf bqcs=%d)\n",userID,gasValue,bqcs);
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
    }else{
        printf("read fail! (errorCode=%d\terrorInfo=%s)\n",get_errorCode(),get_errorInfo());
    }
}

void initcard_test(){
    u8 psw[10]={0};
    u8 errorInfo[20]={0};

    printf("请输入密码：\n");
    scanf("%s",psw);

    if(InitCard("star500x",9600,psw,errorInfo)){
        printf("Init card ok!\n");
    }else{
        printf("Init card fail! (errorCode=%d\terrorInfo=%s\n)",get_errorCode(),get_errorInfo());
    }
}
void checkpswd_test(){
    u8 pswd[20]={0};
    u8 errorInfo[25]={0};

    printf("请输入密码：\n");
    scanf("%s",pswd);

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
