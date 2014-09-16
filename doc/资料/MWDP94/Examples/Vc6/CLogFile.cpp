#include "stdafx.h"
#include "CLogFile.h"
#include "stdlib.h"
#include <time.h>
//chang long type(8 byte) of store sequence between PC and handset 
#define DEBUG_Log	1
__int16 __stdcall hex_a(unsigned char *hex,unsigned char *asc,long length)
{
	UCHAR hLowbit,hHighbit;
    long i;
	for(i=0;i<length*2;i=i+2)
	{
	  hLowbit=hex[i/2]&0x0f;
	  hHighbit=hex[i/2]/16;
	  if(hHighbit>=10)
	    asc[i]=hHighbit+'7';
	  else
	    asc[i]=hHighbit+'0';
	  if(hLowbit>=10)
	    asc[i+1]=hLowbit+'7';
	  else
	    asc[i+1]=hLowbit+'0';
	}
	asc[length*2]='\0';
	return 0;
}

CLogFile::CLogFile()
{
	Open_Logfile();
}

CLogFile::~CLogFile()
{
	Close_Logfile();
}
/*	
	函数功能：	建立数据库
	返回：	0成功，-1 失败；
*/
void CLogFile::Open_Logfile()
{
#if DEBUG_Log
	char strFileName[200]="\0";

	//CTime tm = CTime::GetCurrentTime();
	char timebuf[128],datebuf[128];
	_tzset();

	_strtime( timebuf );    
    _strdate( datebuf );

	
	sprintf(strFileName,"c:\\SSSELog_%s.txt",timebuf);//c:\\SSSELog_13:40:40.txt
	strFileName[13]=' ';
	strFileName[16]=' ';

	
	//if(!LogFile.Open(strFileName,CFile::modeWrite|CFile::modeRead))
	if( (stream = fopen( strFileName, "w+t" )) == NULL )
	{
		MessageBox(  NULL, strFileName, "日志文件", MB_OK|MB_ICONEXCLAMATION  );
		return ;
	}
#endif
	
}
void CLogFile::Close_Logfile()
{
#if DEBUG_Log
	fclose( stream );
#endif
}
void CLogFile::Write_Logfile(char* strDisp)
{
#if DEBUG_Log
	fseek( stream, 0, SEEK_END);
	fwrite(strDisp,sizeof(char),strlen(strDisp),stream); 
#endif
}
void CLogFile::Write_Logfile(unsigned char* strDisp,int len)
{
#if DEBUG_Log
	unsigned char temp[20000]="\0";
	if(len>0)
	{
		hex_a(strDisp,temp,len);
		fseek( stream, 0, SEEK_END);
		fwrite((char*)temp,sizeof(char),strlen((char*)temp),stream); 
	}
#endif
}