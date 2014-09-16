
#include "LYCard_accessor.h"

/*
�������±���Ϊȫ�ֱ��������ǰ�������Ƴ�ֻ��ͨ���������ӳ�����ʣ����ⲿ������ֱ�ӷ��ʱ�������Ʒ������£������ļ�����������������Ե�һ���ࣩ
*/

static int _icdev=-1;
static int _errorCode=0;

static const char _n_lysid[]="FFFFFFFFFFFF";

const char* _errorInfo[]={
    /*0*/"һ������",
    /*1*/"д����δ����",
    /*2*/"д����״̬����",
    /*3*/"IC��δ����",
    /*4*/"�����Ͳ���ȷ",
    /*5*/"���û���",
    /*6*/"������������ʧ��",
    /*7*/"��IC�����޷�����ʹ��",
    /*8*/"IC������˶Դ���",
    /*9*/"�޸�IC���������",
    /*10*/"д���쳣",
    /*11*/"�����쳣",
    /*12*/"IC���û���Ŵ���",
    /*13*/"���û���Ŵ���",
    /*14*/"������IC��",
    /*15*/"�Կ��µ�ʧ��",
    /*16*/"�Կ��ϵ�ʧ��",
    /*17*/"�����ʽ����0-9a-f��",
    /*18*/"",
    /*19*/"",
    /*20*/"�ⲻ��һ���¿�"
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



