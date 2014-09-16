
#include "LYCard_accessor.h"

/*
本来以下变量为全局变量，但是把它们设计成只能通过访问器子程序访问，而外部不可以直接访问变量，设计方法如下：（该文件类似与面向对象语言的一个类）
*/

static int _icdev=-1;
static int _errorCode=0;

static const char _n_lysid[]="FFFFFFFFFFFF";

const char* _errorInfo[]={
    /*0*/"一切正常",
    /*1*/"写卡器未连接",
    /*2*/"写卡器状态错误",
    /*3*/"IC卡未插入",
    /*4*/"卡类型不正确",
    /*5*/"非用户卡",
    /*6*/"读密码错误计数失败",
    /*7*/"该IC卡已无法继续使用",
    /*8*/"IC卡密码核对错误",
    /*9*/"修改IC卡密码错误",
    /*10*/"写卡异常",
    /*11*/"读卡异常",
    /*12*/"IC卡用户编号存在",
    /*13*/"卡用户编号错误",
    /*14*/"非蓝焰IC卡",
    /*15*/"对卡下电失败",
    /*16*/"对卡上电失败",
    /*17*/"密码格式错误（0-9a-f）",
    /*18*/"",
    /*19*/"",
    /*20*/"这不是一张新卡"
};


void set_icdev(int dev){
    _icdev=dev;  
}
int get_icdev(){
    return _icdev;
}

void set_errorCode(int eCode){
    _errorCode=eCode;
}
int get_errorCode(){
    return _errorCode;
}

const char* get_errorInfo(){
    return _errorInfo[_errorCode];
}

const char* get_n_lysid(){
    return _n_lysid;
}



