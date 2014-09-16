#if !defined(_CLogFiles_H_)
#define _CLogFile_H_

#include <windows.h>
#include "stdio.h"

class CLogFile
{
public:
	//CFile LogFile;
	

	CLogFile();
	~CLogFile();
	void Open_Logfile();
	void Close_Logfile();
	void Write_Logfile(char* strDisp);
	void Write_Logfile(unsigned char* strDisp,int len);
	FILE *stream;

//protected:

//private:

};
#endif