#include "LYCard_type.h"

/*
注意：
在退出写卡器程序前最好调用ExitCard()。否则有可能导致第二次调用读卡器程序前要重新启动读卡器等问题。具体调用语句为：
ExitCard();
*/

/*公有接口*/
bool IsLYCard(u8 *filename,int br,u8 *eInfo);
bool WritePCard(u8 *filename,int br,u8 *userID,u8 *pswd,double gasValue,u8 bqcs,int zql,u8 *eInfo);
bool WriteUCard(u8 *filename,int br,u8 *userID,u8 *pswd,double gasValue,u8 bqcs,u8 *eInfo);
bool ReadUCard(u8 *filename,int br,u8 *cardID,u8 *userID,u8 *gasValue,u8 *bqcs,u8 *pswd,u8 *factoryID,u8 *eInfo);
bool InitCard(u8 *filename,int br,u8 *pswd,u8 *eInfo);
bool NewCardCheck(u8 *filename,int br,u8 *eInfo);
bool CheckPsw(u8 *filename,int br,u8 *pswd,u8 *eInfo);

void ExitCard();



