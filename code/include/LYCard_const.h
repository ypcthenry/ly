

/*以下位通用定义*/
//#define DEBUG

#define true 1
#define false (!true)

#define null 0


/*以下位针对本项目定义的常量*/
#define W_BUFFER_SIZE (256-32)
#define R_BUFFER_SIZE (256-32) 

#define USER_CARD_FLAG (0xDD)
/*no usercard is 0x32*/
#define MMCD_FLAG 0xAA
#define INDUSTRY_FLAG '1'
#define PRECISION 2

#define INIT_USER_CARD_OFFSET 32
#define INIT_USER_CARD_LENGTH 20
#define WRITE_USER_CARD_OFFSET 32
#define WRITE_USER_CARD_LENGTH 20
#define READ_USER_CARD_OFFSET 32
#define READ_USER_CARD_LENGTH 20
#define READ_CARD_ID_OFFSET 10
#define READ_CARD_ID_LENGTH 6
