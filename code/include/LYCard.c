

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "LYCard_type.h"
#include "LYCard_const.h"
#include "LYCard_util.h"
#include "LYCard_accessor.h"
#include "mwic.h"
#include "LYCard.h"

#define DEBUG

#ifdef DEBUG
char buffer[W_BUFFER_SIZE];
#endif

//静态变量
static const char _init_password[]="b62307";

/*自己实现与该项目相关的具体函数*/
static const char* get_init_password();

static bool InitICCard(int icdev,u8 *psw);
static bool WriteUserCard(int icdev,int bh,double ql,u8 bqcs,int zql,u8 *psw,bool mmcd);
static bool ReadCardID(int icdev,u8 *cardID);
static bool ReadUserCard(int icdev,u8 *cardID,int *userID,double *ql,int *zql,u8 *bqcs,bool *mmcd);
static bool CheckNewCard(int icdev);
static bool CheckICPswd(int icdev,const u8 *pswd);
static bool ChangePswd(int icdev,const u8 *pswd);

static bool WriteData2Card(int icdev,int offset,int length,u8 *data);
static bool ReadDataFromCard(int icdev,int offset,int length,u8 *data);

static void SetCardFlag(u8 *flag,u8 c_flag);
static bool IsUserCard(u8 c_userCardFlag);

static void SetUserID(u8 *sUserID,int userID);
static int GetUserID(const u8 *sUserID);

static void SetPswd(u8 *d_pswd,const u8*s_pswd,bool mmcd);

static void SetCardQL(u8 *sQL,double ql,bool isIndustryCard);
static double GetCardQL(u8 *sQL,bool isIndustryCard);

static void SetCardSRZL(u8 *sSRZL,int srzl,bool isIndustryCard);
static double GetCardSRZL(u8 *sSRZL,bool isIndustryCard);

static void SetMMCD(u8 *mmcd,bool b_mmcd);
static bool IsMMCD(u8 c_mmcd);

static void SetBQCS(u8 *s_bqcs,u8 u_bqcs);
static int GetBQCS(u8 c_bqcs);

static bool IsIndustryCard(u8 *cardID);

static bool DeviceOk(u8 *filename,int br);
static bool ConnectionOk(u8 *filename,int br);
static bool HasCard(int icdev);
static bool IsCard4442(int icdev);

/*
  功能：
  判断是否为蓝焰IC卡。根据要求，目前没有作是否为蓝焰卡的判断
  参数：
  filename:配置文件名
  br:波特率（一般为9600）
  eInfo:错误信息
  返回值：
  是蓝焰卡返回true,
  否则返回false,具体错误信息记录在eInfo中
*/
bool IsLYCard(u8 *filename,int br,u8 *eInfo){
  u8 sid[20];
  u8 buffer[20];
  int iyr;

  if(!DeviceOk(filename,br)){
    strcpy(eInfo,get_errorInfo());
    return false;
  }

  if(!ReadCardID(get_icdev(),sid)){
    strcpy(eInfo,get_errorInfo());
    return false;
  }
  if(strcmp(sid,get_n_lysid())==0){
    set_errorCode(14);
    strcpy(eInfo,get_errorInfo());
    return false;
  }

  /* buffer[0]=0; */

  /* StringNCopy(buffer,sid,3,2); */
  /* Str2Int(&iyr,buffer); */
  /* if(iyr<0 || 99<iyr){ */
  /*     set_errorCode(14); */
  /*     strcpy(eInfo,get_errorInfo()); */
  /*     return false; */
  /* } */

  return true;
}

/*
  功能：
  写密码传递卡  
  参数：
  filename:配置文件名（相对路径或绝对路径）
  br:波特率（9600）
  userID:用户编号
  pswd:密码
  ql:气量
  bqcs:补气次数
  zql:总气量
  eInfo:错误信息
  返回值：
  如果处理过程一切正常，则返回true，
  否则返回false，具体错误信息记录在eInfo中
*/
bool WritePCard(u8 *filename,int br,const u8 *userID,const u8 *pswd,double ql,u8 bqcs,int zql,u8 *eInfo){
  int i_userID;
  char tmp_userID[12];
  strcpy(tmp_userID,userID);

  if(!DeviceOk(filename,br)){
    strcpy(eInfo,get_errorInfo());
    return false;
  }

  Str2Int(&i_userID,Trim(tmp_userID,true,true));
  if(!WriteUserCard(get_icdev(),i_userID,ql,bqcs,zql,pswd,true)){
    strcpy(eInfo,get_errorInfo());
    return false;
  }
  return true;
}


/*
  功能：
  写正常充值卡  
  参数：
  filename:用户
  br:波特率（9600）
  userID:用户编号
  pswd:密码
  ql:气量
  bqcs:补气次数
  eInfo:错误信息
  返回值：
  如果处理过程一切正常，则返回true，
  否则返回false，错误信息记录在eInfo中
*/
bool WriteUCard(u8 *filename,int br,const u8 *userID,const u8 *pswd,double ql,u8 bqcs,u8 *eInfo){
  int i_userID;
  char tmp_userID[12];
  strcpy(tmp_userID,userID);

  if(!DeviceOk(filename,br)){
    strcpy(eInfo,get_errorInfo());
    return false;
  }

  Str2Int(&i_userID,Trim(tmp_userID,true,true));
  if(!WriteUserCard(get_icdev(),i_userID,ql,bqcs,0,pswd,false)){
    strcpy(eInfo,get_errorInfo());
    return false;
  }
  return true;
}


/*
  功能：
  读用户卡  
  参数：
  filename:配置文件名
  br:波特率
  cardID:卡唯一标示
  userID:用户编号
  gasValue:气量
  bqcs:补气次数
  mmcd:密码传递卡（是：“1”；否：“0“）
  factoryID:保留参数
  eInfo:错误信息
  返回值：
  如果处理过程一切正常，则返回true，
  否则返回false，错误信息记录在eInfo中
*/
bool ReadUCard(u8 *filename,int br,u8 *cardID,u8 *userID,u8 *gasValue,u8 *bqcs,u8 *mmcd,u8 *factoryID,u8 *eInfo){
  u8 u_facID[10]="0000";
  int i_userID;
  double d_gasValue;
  int i_zql;
  u8 u_bqcs;
  bool b_mmcd=false;

  if(!DeviceOk(filename,br)){
    strcpy(eInfo,get_errorInfo());
    return false;
  }
 
  if(!ReadUserCard(get_icdev(),cardID,&i_userID,&d_gasValue,&i_zql,&u_bqcs,&b_mmcd)){
    strcpy(eInfo,get_errorInfo());
    return false;
  }
    
  strcpy(factoryID,u_facID);

  Int2Str(userID,i_userID);
  Trim(userID,true,true);
  InsertNChar(userID,'0',0,8-strlen(userID));

  Float2Str(gasValue,d_gasValue,PRECISION);
  Trim(gasValue,true,true);

  Int2Str(bqcs,u_bqcs);

  if(b_mmcd==true){
    strcpy(mmcd,"1");
  }else{
    strcpy(mmcd,"0");
  }
  return true;
}

/*
  功能：
  初始化卡
  参数：
  filename:配置文件名
  br:波特率
  pswd:密码
  eInfo:错误信息
  返回值：
  如果处理过程一切正常，则返回true，
  否则返回false，错误信息记录在eInfo中
*/
bool InitCard(u8 *filename,int br,u8 *pswd,u8 *eInfo){
  if(!DeviceOk(filename,br)){
    strcpy(eInfo,get_errorInfo());
    return false;
  }

  if(!InitICCard(get_icdev(),pswd)){
    strcpy(eInfo,get_errorInfo());
    return false;
  }
  return true;
}

/*
  功能：
  新卡核对
  参数：
  filename:配置文件名
  br:波特率
  eInfo:错误信息
  返回值：
  如果处理过程一切正常，则返回true，
  否则返回false，错误信息记录在eInfo中
*/
bool NewCardCheck(u8 *filename,int br,u8 *eInfo){
  if(!DeviceOk(filename,br)){
    strcpy(eInfo,get_errorInfo());
    return false;
  }

  if(!CheckNewCard(get_icdev())){
    strcpy(eInfo,get_errorInfo());
    return false;
  }
  return true;
}

/*
  功能：
  核对IC卡密码
  参数：
  filename:配置文件
  br:波特率
  pswd:密码
  eInfo:错误信息
  返回值：
  如果处理过程一切正常，则返回true，
  否则返回false，错误信息记录在eInfo中
*/
bool CheckPsw(u8 *filename,int br,u8 *pswd,u8 *eInfo){
  if(!DeviceOk(filename,br)){
    return false;
  }

  if(!CheckICPswd(get_icdev(),pswd)){
    strcpy(eInfo,get_errorInfo());
    return false;
  }
  return true;
}

void ExitCard(){
  if(get_icdev()>=0){
    ic_exit(get_icdev());
  }
}


static const char* get_init_password(){
  return _init_password;
}

/*
  功能：
  初始化用户卡
  参数：
  icdev:设备号
  pswd:密码
  返回值：
  如果处理过程一切正常，则返回true，
  否则返回false，错误信息记录在eInfo中
*/
static bool InitICCard(int icdev,u8 *pswd){
  bool pass;
  int status,st;
  u8 password[3];
  u8 wbuff[W_BUFFER_SIZE+1];
  int i;

  /*验证密码*/
  if(!CheckICPswd(get_icdev(),pswd)){
    return false;
  }
  /*把密码修改为初始化密码*/
  if(!ChangePswd(get_icdev(),get_init_password())){
    return false;
  }

  /*修改用户区数据*/
  for(i=0;i<INIT_USER_CARD_LENGTH;i++){
    wbuff[i]=0;
  }
  /*
    wbuff[0]=USER_CARD_FLAG;
  */
  SetCardFlag(&wbuff[0],USER_CARD_FLAG);

  StringInit(&wbuff[5],0xAA,3);

  /*写数据，执行修改*/
  if(!WriteData2Card(icdev,INIT_USER_CARD_OFFSET,INIT_USER_CARD_LENGTH,wbuff)){
    return false;
  }

  dv_beep(icdev,20);
  return true;
}

/*
  功能：
  写用户卡
  参数：
  userID：用户编号
  ql：气量
  bqcs：补气次数
  zql：总气量
  psw：密码
  mmcd：密码传递
  eInfo：错误信息
  返回值：
  如果处理过程一切正常，则返回true，
  否则返回false
*/
static bool WriteUserCard(int icdev,int userID,double ql,u8 bqcs,int zql,u8 *psw,bool mmcd){
  u8 wbuff[W_BUFFER_SIZE+1];
  u8 cardID[20];
  u8 ec[2];
  bool isIndustryCard=false;

#ifndef DEBUG
  /*验证密码*/
  if(mmcd){/*密码传递卡*/
    if(!CheckICPswd(get_icdev(),get_init_password())){
      return false;
    }
    if(!ChangePswd(get_icdev(),psw)){
      return false;
    }
  }
  else{/*非密码传递卡*/
      if(!CheckICPswd(get_icdev(),psw)){
      return false;
      }
  }
    
  /*读卡唯一编号*/
  if(!ReadCardID(icdev,wbuff)){
    return false;
  }
#endif
    
  strcpy(cardID,wbuff);
    
  /*判断是否为工业表*/
  isIndustryCard=IsIndustryCard(cardID);

  /*写卡*/
  StringInit(wbuff,'0',W_BUFFER_SIZE+1);

  /*用户卡wbuff[0]*/
  /*
    wbuff[0]=USER_CARD_FLAG;
  */
  SetCardFlag(&wbuff[0],USER_CARD_FLAG);
    
  /*用户编号wbuff[1-4]*/
  SetUserID(&wbuff[1],userID);

  /*密码wbuff[5-7]*/
  SetPswd(&wbuff[5],psw,mmcd);
  /*
    if(mmcd){
    Hexs2Str(&wbuff[5],psw,6);
    }
  */
  /*else 初始化为字符‘0’*/

  /*用户卡气量wbuff[8-10]*/
  SetCardQL(&wbuff[8],ql,isIndustryCard);
    
  /*wbuff[11-13]未用，初始化为字符‘0’*/

  /*输入总量区wbuff[14-16]*/
  SetCardSRZL(&wbuff[14],zql,isIndustryCard);
    
  /*wbuff[17]未用，初始化为字符‘0’*/

  /*密码传递标志wbuff[18]*/
  SetMMCD(&wbuff[18],mmcd);
  /*
    if(mmcd){
    wbuff[18]=MMCD_FLAG;
    }
  */
  /*else 初始化为字符‘0’*/

  /*补气次数wbuff[19]*/
  SetBQCS(&wbuff[19],bqcs);
  /*
    wbuff[19]=(u8)bqcs;
  */
#ifdef DEBUG
  memcpy(buffer,wbuff,W_BUFFER_SIZE);
#else
  if(!WriteData2Card(icdev,WRITE_USER_CARD_OFFSET,INIT_USER_CARD_LENGTH,wbuff)){
    return false;
  }

  dv_beep(icdev,20);
#endif
  return true;
}

/*
  功能：
  读卡唯一编号
  参数：
  icdev：设备号
  sid：设备编号
  返回值：
  如果处理过程一切正常，则返回true，
  否则返回false 
*/
static bool ReadCardID(int icdev,u8 *sid){
  u8 rbuff[READ_CARD_ID_LENGTH];
  u8 str[5];
  int index;

  /*读唯一标示号*/
  if(!ReadDataFromCard(icdev,READ_CARD_ID_OFFSET,READ_CARD_ID_LENGTH,rbuff)){
    return false;
  }

  for(index=0;index<READ_CARD_ID_LENGTH;index++){
    Char2Hexs(str,rbuff[index]);
    strncpy(sid+2*index,str,2);
  }
  *(sid+2*READ_CARD_ID_LENGTH)=0;/*字符串结束标志*/

  return true;
}

/*
  功能：
  读用户卡
  参数：
  icdev：设备
  userID：用户编号
  gasValue：气量
  zql:总气量
  bqcs：补气次数
  mmcd：是否为密码传递卡
  返回值：
  如果处理过程一切正常，则返回true，
  否则返回false 
*/
static bool ReadUserCard(int icdev,u8 *cardID,int *userID,double *gasValue,int *zql,u8 *bqcs,bool *mmcd){
  u8 rbuff[R_BUFFER_SIZE+1];
  u8 str[5];
  bool isIndustryCard;

#ifdef DEBUG
  memcpy(rbuff,buffer,R_BUFFER_SIZE);
  isIndustryCard=false;
#else
  if(!ReadCardID(icdev,rbuff)){
    return false;
  }
  strcpy(cardID,rbuff);

  /*是否为工业表*/
  isIndustryCard=IsIndustryCard(cardID);

  /*读卡上用户数据*/
  if(!ReadDataFromCard(icdev,READ_USER_CARD_OFFSET,READ_USER_CARD_LENGTH,rbuff)){
    return false;
  }
#endif
    
  /*是否为用户卡*/
  if(!IsUserCard(rbuff[0])){
    set_errorCode(5);
    return false;
  }
    
  /*用户编号*/
  *userID=GetUserID(&rbuff[1]);
  //气量
  *gasValue=GetCardQL(&rbuff[8],isIndustryCard);
  //总气量
  *zql=GetCardSRZL(&rbuff[14],isIndustryCard);

  /*是否为密码传递卡*/
  *mmcd=IsMMCD(rbuff[18]);

  /*补气次数*/
  *bqcs=GetBQCS(rbuff[19]);
  /*
   *bqcs=Char2Int(rbuff[19]);//fc:=Ord(rbuff[19]);
   */
#ifdef DEBUG
  printf("cardid=%s,userid=%s,ql=%f,zql=%d,bqcs=%d\n",cardID,userID,*gasValue,*zql,*bqcs);
#else
  dv_beep(icdev,20);
 #endif
  
  return true;
}

/*
  功能：
  判断是否为新卡
  参数：
  icdev：设备编号
  返回值：
  如果处理过程一切正常，则返回true；
  否则返回false 
*/
static bool CheckNewCard(int icdev){
  int st;
  u8 rbuff[R_BUFFER_SIZE+1];
  u8 str[5];
  int userID;

  if(!ReadDataFromCard(icdev,READ_USER_CARD_OFFSET,READ_USER_CARD_LENGTH,rbuff)){
    return false;
  }
  
  //判断是否为用户卡
  if(!IsUserCard(rbuff[0])){
    set_errorCode(5);
    return false;
  }

  //获得用户编号
  userID=GetUserID(&rbuff[1]);

  if(userID!=0){
    set_errorCode(12);
    return false;
  }

  if(!CheckICPswd(get_icdev(),get_init_password())){
    if(get_errorCode()==8){/*如果密码核对没有通过，则表示该卡不是新卡*/
      set_errorCode(20);
    }
    return false;
  }

  return true;
}

/*
  功能：
  密码验证，同提供的参考程序有差别（CheckCardStatus(psw,false)）。
  在调用该程序的时候要注意！！！
  参数：
  icdev：设备编号
  pswd:密码
  返回值：
  如果处理过程一切正常且密码核对正确，返回true，
  否则返回false
*/
static bool CheckICPswd(int icdev,const u8 *pswd){
  /* return CheckCardStatus(psw,false); */
  u8 password[10];
  int counter;
  int st;

  /*读密码错误计数，为0则表示卡已无法使用*/
#ifndef DEBUG
  st=rsct_4442(icdev,&counter);
  if(st<0){
    set_errorCode(6);
    return false;
  }
  if(counter==0){
    set_errorCode(7);
    return false;
  }
  #endif


  /*核对IC卡密码*/
  //掉电
  st=turn_off(icdev);
  if(st!=0){
    set_errorCode(15);
    return false;
  }
  //上电
  st=turn_on(icdev);
  if(st!=0){
    set_errorCode(16);
    return false;
  }

  Hexs2Str(password,pswd,6);  
    
  st=csc_4442(icdev,3,password);
  if(st!=0){
    set_errorCode(8);
    return false;
    }
  return true;
}

/*
  功能：
  修改设备密码
  参数：
  icdev：设备
  psw：新密码
  返回值：
  如果处理过程一切正常，则返回true，
  否则返回false
*/
static bool ChangePswd(int icdev,const u8 *psw){
  u8 password[5];
  int st;

  //asc_hex(psw,password,3);
  if(!Hexs2Str(password,psw,6)){
    set_errorCode(17);
    return false;
  }
  st=wsc_4442(icdev,3,password);
  if(st!=0){
    set_errorCode(9);
    return false;
  }
  return true;
}

/*
  功能：
  向指定设备指定的指定偏移写入指定长度的数据
  参数：
  icdev：设备号
  offset：偏移
  length：写入数据长度
  data：输出参数，写入的数据
  返回值：
  如果处理过程一切正常，则返回true，
  否则返回false
*/
static bool WriteData2Card(int icdev,int offset,int length,u8 *data){
  int st;

  st=swr_4442(icdev,offset,length,data);
  if(st<0){
    set_errorCode(10);
    return false;
  }
  return true;
}

/*
  功能：
  从指定设备的指定偏移读出指定长度的数据
  参数：
  icdev：设备号
  offset：偏移
  length：读出数据长度
  data：输出参数，写入的数据
  返回值：
  如果处理过程一切正常，则返回true，
  否则返回false
*/
static bool ReadDataFromCard(int icdev,int offset,int length,u8 *data){
  int st;

  st=srd_4442(icdev,offset,length,data);
  if(st!=0){
    set_errorCode(11);
    return false;
  }
  return true;
}

/*
  功能：
  对设备进行通用的检查，主要包括设备是否连接、是否有卡及是否是4442卡
  参数：
  filename:配置文件
  br:波特率
  返回值：
  设备通用检查通过返回true，
  否则返回false
*/
static bool DeviceOk(u8 *filename,int br){
#ifdef DEBUG
  return true;
#else
  /*检测写卡器连接是否正常*/
  if(!ConnectionOk(filename,br)){
    return false;
  }
    
  /*检测读写器中是否有卡*/
  if(!HasCard(get_icdev())){
    return false;
  }
    
  /*检测是否4442卡*/
  if(!IsCard4442(get_icdev())){
    return false;
  }
  return true;
#endif
}

/*
  功能：
  检测写卡器是否连接
  参数：
  filename:配置文件
  br:波特率
  返回值：
  如果写卡器连接正常，则返回true，
  否则返回false
*/
static bool ConnectionOk(u8 *filename,int br){
  if(get_icdev()<0){
    set_icdev(ic_init(filename,br));
  }

  if(get_icdev()<0){
    set_errorCode(1);
    return false;
  }
  return true;
}

/*
  功能：
  检测写卡器中是否有卡
  参数：
  icdev:设备
  返回值：
  如果写卡器有卡且处理过程一切正常，则返回true，
  否则返回false
*/
static bool HasCard(int icdev){
  int st,status;
  status=0;
  st=get_status(icdev,&status);
  if(st==0){
    if(status==0){/*没有卡*/
      set_errorCode(3);
      dv_beep(icdev,1);
      return false;
    }
  }
  else{
    set_errorCode(2);
    return false;
  }
  return true;
}

/*
  功能：
  检测是否是4442卡
  参数：
  icdev:设备
  返回值：
  如果是4442卡且处理过程一切正常，则返回true，
  否则返回false
*/
static bool IsCard4442(int icdev){
  int st;
  st=chk_4442(icdev);
  if(st!=0){
    set_errorCode(4);
    dv_beep(icdev,1);
    return false;
  }
  return true;
}

static void SetCardFlag(u8 *flag,u8 c_flag){
  *flag=c_flag;
}

static bool IsUserCard(u8 c_userCardFlag){
  return c_userCardFlag==USER_CARD_FLAG;
}

static void SetUserID(u8 *sUserID,int userID){
  *(sUserID+0)=Int2Char(userID/1000000);
  *(sUserID+1)=Int2Char( (userID/10000) % 100);
  *(sUserID+2)=Int2Char( (userID/100) % 100);
  *(sUserID+3)=Int2Char( userID %100 );
}

static int GetUserID(const u8 *sUserID){
  return Char2Int(*(sUserID+0))*1000000
      +Char2Int(*(sUserID+1))*10000
      +Char2Int(*(sUserID+2))*100
      +Char2Int(*(sUserID+3));
}

static void SetPswd(u8 *d_pswd,const u8*s_pswd,bool mmcd){
  if(mmcd){
    Hexs2Str(d_pswd,s_pswd,6);
  }
  else{
    StringInit(d_pswd,0,3);
  }
}

/*
  功能：
  根据卡的类型（工业卡和非工业卡）设置气量
  参数：
  sQL：对应的写入卡的数据
  ql：气量的数值
  cardStyle：卡的类型（工业卡和非工业卡）
  返回值：
  （无）
*/
static void SetCardQL(u8 *sQL,double ql, bool isIndustryCard){
  int partQL=0;
  if(isIndustryCard){/*该部分作用？？cardStyle=1表示什么？？*/
    assert(0<=ql && ql<=9999.99);

    partQL=(int)(ql/100);
    *sQL=partQL;

    partQL=((int)ql) % 100;
    *(sQL+1)=partQL;
        
    partQL=((int)(ql*100)) %100;
    if(((int)(ql*1000))%10>=5){
      ++partQL;
    }
    *(sQL+2)=partQL;
  }
  else{
    assert(0<=ql && ql<=999.9);
        
    partQL=((int)(ql/100));
    *sQL=partQL;

    partQL=((int)ql) % 100;
    *(sQL+1)=partQL;
        
    partQL=((int)(ql*10)) %10;
    if((((int)(ql*100)) %10)>=5){
      ++partQL;
    }
    *(sQL+2)=partQL;
  }
}

static double GetCardQL(u8 *sQL,bool isIndustryCard){
  double ql=0;
  if(isIndustryCard){
    /*气量*/
    /*gasvalue:=Ord(rbuff[8])*1000+Ord(rbuff[9])*10+Ord(rbuff[10])/10;*/
    ql=Char2Int(sQL[0])*1000
       +Char2Int(sQL[1])*10
       +Char2Int(sQL[2])/10;
  }
  else{
    /*
      gasvalue:=Ord(rbuff[8])*100+Ord(rbuff[9])+Ord(rbuff[10])/10;*/
    ql=Char2Int(sQL[0])*100
       +Char2Int(sQL[1])
       +Char2Int(sQL[2])/10.0;
  }
  return ql;
}


/*
  功能：
  根据卡类型把int型的总气量转化为字符串型的总气量，用于向设备总写入数据
  参数：
  sSRZL:由数据型总气量转化生成的字符串型总气量
  srzl:待转化的数据型总气量
  cardStyle:卡类型
  返回值：
  （无）
*/
static void SetCardSRZL(u8 *sSRZL,int srzl,bool isIndustryCard){
  if(isIndustryCard){
    assert(0<=srzl && srzl<=999999);
  }
  else{
    assert(0<=srzl && srzl<=99999);
  }

  *(sSRZL)=srzl/10000;
  *(sSRZL+1)=(srzl / 100) %100;
  *(sSRZL+2)=(srzl % 100);
}

/*
  总气量
*/
static double GetCardSRZL(u8 *sSRZL,bool isIndustryCard){
  int zql;
  if(isIndustryCard){
    zql=-1;
  }
  else{
    zql=Char2Int(sSRZL[14])*10000
        +Char2Int(sSRZL[15])*100
        +Char2Int(sSRZL[16]);
  }
  return zql;
}

/*
  密码传递
*/
static void SetMMCD(u8 *mmcd,bool b_mmcd){
  if(b_mmcd){
    *mmcd=MMCD_FLAG;
  }
  else{
    *mmcd=0;
  }
}

/*
  是否为密码传递卡
*/
static bool IsMMCD(u8 c_mmcd){
  return c_mmcd==MMCD_FLAG;
}

/*
  补气次数
  避免出现 0 的情况
*/
static void SetBQCS(u8 *s_bqcs,u8 u_bqcs){
  *s_bqcs=u_bqcs;
}

/*
  补气次数
  写入时增1，在此处还原（-1）
*/
static int GetBQCS(u8 c_bqcs){
  return c_bqcs;
}

/*
  功能：
  判断是否为工业卡
  参数：
  cardID:卡唯一标示号
  返回值：
  如果处理过程一切正常，则返回true，
  否则返回false
*/
static bool IsIndustryCard(u8 *cardID){
  u8 strCardStyle[2]={0};
  bool isIndustryCard;

  StringNCopy(strCardStyle,cardID,7,1);

  isIndustryCard=(strCardStyle[0]==INDUSTRY_FLAG)?true:false;

  return isIndustryCard;
}
