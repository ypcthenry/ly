/**************    commual subroutin  ***********/
extern int ic_init(char *filename,unsigned long baud);
extern int auto_init(char *filename,unsigned long baud);
extern int ic_exit(int icdev);
extern int srd_ver(int icdev, int len,unsigned char *data_buffer);
extern int set_baud(int icdev, unsigned long baud);
extern int cmp_dvsc(int icdev, int len,unsigned char *dta_buffer);
extern int srd_dvsc(int icdev, int len,unsigned char *data_buffer);
extern int swr_dvsc(int icdev, int len,unsigned char *data_buffer);
extern int setsc_md(int icdev, int mode);
extern int turn_on(int icdev);
extern int turn_off(int icdev);
extern int auto_pull(int icdev);
extern int get_status(int icdev,int *state);
extern int srd_snr(int icdev,int len,unsigned char *data_buffer);
extern int val_read(int icdev,unsigned long *p_Value);
extern int val_inc(int icdev, unsigned long _Value);
extern int val_dec(int icdev, unsigned long _Value);
extern int val_set(int icdev, unsigned long _Value);
extern int set_send_mode(int icdev,unsigned char mode);

extern long chk_baud(char *filename);
extern int dv_beep(int icdev, int time);
extern int chk_card(char *filename);
extern int  ic_encrypt( char *key,char *ptrSource, unsigned int msgLen, char *ptrDest);
extern int ic_decrypt( char *key,char *ptrSource, unsigned int msgLen, char *ptrDest);
extern unsigned long DES_Encrypt( unsigned char *Key,int Keyen,unsigned char *Source, unsigned long SrcLen,unsigned char *result);
extern unsigned long DES_Decrypt( unsigned char *Key,int KeyLen,unsigned char *Source, unsigned long SrcLen,unsigned char *result);
extern int lib_ver(char *VerStr);
//**********************    operate sle 4404    **************************
extern int srd_4404(int icdev,int offset,int len,unsigned char *data_buffer);
extern int swr_4404(int icdev,int offset,int len,unsigned char *data_buffer);
extern int csc_4404(int icdev,int len,unsigned char *data_buffer);
extern int wsc_4404(int icdev,int len,unsigned char *data_buffer);
extern int rsc_4404(int icdev,int len,unsigned char *data_buffer);
extern int rsct_4404(int icdev,int *counter);
extern int cesc_4404(int icdev,int len,unsigned char *data_buffer);
extern int wesc_4404(int icdev,int len,unsigned char *data_buffer);
extern int resc_4404(int icdev,int len,unsigned char *data_buffer);
extern int resct_4404(int icdev,int *counter);
extern int ser_4404(int icdev,int offset,int len);
extern int fakefus_4404(int icdev,int mode);
extern int clrpr_4404(int icdev);
extern int clrrd_4404(int icdev);
extern int psnl_4404(int icdev);
extern int chk_4404(int icdev);
//***********************    operate sle 4406    *************************
extern int srd_4406(int icdev,int offset,int len,unsigned char *data_buffer);
extern int swr_4406(int icdev,int offset,int len,unsigned char *data_buffer);
extern int csc_4406(int icdev,int len,unsigned char *data_buffer);
extern int wsc_4406(int icdev,int len,unsigned char *data_buffer);
extern int rsc_4406(int icdev,int len,unsigned char *data_buffer);
extern int rsct_4406(int icdev,int *Counter);
extern int eswc_4406(int icdev,int offset);
extern int psnl_4406(int icdev);
extern int chk_4406(int icdev);
//***********************    operate at88sc102    ************************
extern int srd_102(int icdev,int zone,int offset,int len,unsigned char *data_buffer);
extern int swr_102(int icdev,int zone,int offset,int len,unsigned char *data_buffer);
extern int ser_102(int icdev,int zone,int offset,int len);

extern int csc_102(int icdev,int len,unsigned char *data_buffer);
extern int rsc_102(int icdev,int len,unsigned char *data_buffer);
extern int wsc_102(int icdev,int len,unsigned char *data_buffer);
extern int rsct_102(int icdev,int *counter);

extern int cesc_102(int icdev,int zone,int len,unsigned char *data_buffer);
extern int resc_102(int icdev,int zone,int len,unsigned char *data_buffer);
extern int wesc_102(int icdev,int zone,int len,unsigned char *data_buffer);
extern int resct_102(int icdev,int zone,int *counter);

extern int clrpr_102(int icdev,int zone);
extern int clrrd_102(int icdev,int zone);

extern int fakefus_102(int icdev,int mode);
extern int psnl_102(int icdev);
extern int chk_102(int icdev);
//*********************    operate at88sc1604    **************************
extern int srd_1604(int icdev,int zone,int offset,int len,unsigned char *data_buffer);
extern int swr_1604(int icdev,int zone,int offset,int len,unsigned char *data_buffer);
extern int ser_1604(int icdev,int zone,int offset,int len);

extern int csc_1604(int icdev,int zone,int len,unsigned char *data_buffer);
extern int rsc_1604(int icdev,int zone,int len,unsigned char *data_buffer);
extern int wsc_1604(int icdev,int zone,int len,unsigned char *data_buffer);
extern int rsct_1604(int icdev,int zone,int *counter);

extern int cesc_1604(int icdev,int zone,int len,unsigned char *data_buffer);
extern int resc_1604(int icdev,int zone,int len,unsigned char *data_buffer);
extern int wesc_1604(int icdev,int zone,int len,unsigned char *data_buffer);
extern int resct_1604(int icdev,int zone,int *counter);

extern int clrpr_1604(int icdev,int zone);
extern int clrrd_1604(int icdev,int zone);

extern int fakefus_1604(int icdev,int mode);
extern int psnl_1604(int icdev);
extern int chk_1604(int icdev);
//*********************    operate at88sc1604b    **************************
extern int srd_1604b(int icdev,int zone,int offset,int len,unsigned char *data_buffer);
extern int swr_1604b(int icdev,int zone,int offset,int len,unsigned char *data_buffer);
extern int ser_1604b(int icdev,int zone,int offset,int len);

extern int csc_1604b(int icdev,int zone,int len,unsigned char *data_buffer);
extern int rsc_1604b(int icdev,int zone,int len,unsigned char *data_buffer);
extern int wsc_1604b(int icdev,int zone,int len,unsigned char *data_buffer);
extern int rsct_1604b(int icdev,int zone,int *counter);

extern int cesc_1604b(int icdev,int zone,int len,unsigned char *data_buffer);
extern int resc_1604b(int icdev,int zone,int len,unsigned char *data_buffer);
extern int wesc_1604b(int icdev,int zone,int len,unsigned char *data_buffer);
extern int resct_1604b(int icdev,int zone,int *counter);

extern int clrpr_1604b(int icdev,int zone);
extern int clrrd_1604b(int icdev,int zone);

extern int fakefus_1604b(int icdev,int mode);
extern int psnl_1604b(int icdev);
extern int chk_1604b(int icdev);

//************************    operate at24c01a    ***************************
extern int swr_24c01a(int icdev, int offset, int len,unsigned char *data_buffer);
extern int srd_24c01a(int icdev, int offset, int len,unsigned char *data_buffer);
extern int chk_24c01a(int icdev);
//************************    operate at24c02    ***************************
extern int swr_24c02(int icdev, int offset, int len,unsigned char *data_buffer);
extern int srd_24c02(int icdev, int offset, int len,unsigned char *data_buffer);
int  chk_24c02(int icdev);
//************************    operate at24c04    ***************************
extern int swr_24c04(int icdev, int offset, int len,unsigned char *data_buffer);
extern int srd_24c04(int icdev, int offset, int len,unsigned char *data_buffer);
extern int  chk_24c04(int icdev);
//************************    operate at24c08    ***************************
extern int swr_24c08(int icdev, int offset, int len,unsigned char *data_buffer);
extern int srd_24c08(int icdev, int offset, int len,unsigned char *data_buffer);
extern int  chk_24c08(int icdev);
//************************    operate at24c16    ***************************
extern int swr_24c16(int icdev, int offset, int len,unsigned char *data_buffer);
extern int srd_24c16(int icdev, int offset, int len,unsigned char *data_buffer);
extern int  chk_24c16(int icdev);
//************************    operate at24c64    ***************************
extern int swr_24c64(int icdev, int offset, int len,unsigned char *data_buffer);
extern int srd_24c64(int icdev, int offset, int len,unsigned char *data_buffer);
extern int  chk_24c64(int icdev);
//***********************    operate sle 4418    *************************
extern int srd_4418(int icdev,int offset,int len,unsigned char *data_buffer);
extern int swr_4418(int icdev,int offset,int len,unsigned char *data_buffer);
extern int rdwpb_4418(int icdev,int offset,int len,unsigned char *data_buffer);
extern int wrwpb_4418(int icdev,int offset,int len,unsigned char *data_buffer);
extern int pwr_4418(int icdev,int offset,int len,unsigned char *data_buffer);
extern int chk_4418(int icdev);
//***********************    operate sle 4428    *************************
extern int srd_4428(int icdev,int offset,int len,unsigned char *data_buffer);
extern int swr_4428(int icdev,int offset,int len,unsigned char *data_buffer);
extern int rdwpb_4428(int icdev,int offset,int len,unsigned char *data_buffer);
extern int wrwpb_4428(int icdev,int offset,int len,unsigned char *data_buffer);
extern int pwr_4428(int icdev,int offset,int len,unsigned char *data_buffer);
extern int csc_4428(int icdev,int len,unsigned char *data_buffer);
extern int wsc_4428(int icdev,int len,unsigned char *data_buffer);
extern int rsc_4428(int icdev,int len,unsigned char *data_buffer);
extern int rsct_4428(int icdev,int *counter);
extern int chk_4428(int icdev);
//***********************    operate sle 4442    **************************
extern int srd_4442(int icdev,int offset,int len,unsigned char *data_buffer);
extern int swr_4442(int icdev,int offset,int len,unsigned char *data_buffer);
extern int prd_4442(int icdev,int len,unsigned char *data_buffer);
extern int pwr_4442(int icdev,int offset,int len,unsigned char *data_buffer);
extern int csc_4442(int icdev,int len,unsigned char *data_buffer);
extern int wsc_4442(int icdev,int len,unsigned char *data_buffer);
extern int rsc_4442(int icdev,int len, unsigned char *data_buffer);
extern int rsct_4442(int icdev,int *counter);
extern int chk_4442(int icdev);
//***********************    operate sle 4432    **************************
extern int srd_4432(int icdev,int offset,int len,unsigned char *data_buffer);
extern int swr_4432(int icdev,int offset,int len,unsigned char *data_buffer);
extern int prd_4432(int icdev,int len,unsigned char *data_buffer);
extern int pwr_4432(int icdev,int offset,int len,unsigned char *data_buffer);
extern int csc_4432(int icdev,int len,unsigned char *data_buffer);
extern int wsc_4432(int icdev,int len,unsigned char *data_buffer);
extern int rsc_4432(int icdev,int len,unsigned char *data_buffer); 
extern int rsct_4432(int icdev,int *counter);
extern int chk_4432(int icdev);

//***********************    operate at45d041    *************************
extern int srd_45d041(int icdev,int page,int offset,long len,unsigned char *data_buffer);
extern int swr_45d041(int icdev,int page,int offset,long len,unsigned char *data_buffer);
extern int chk_45d041(int icdev);
//************************    operate at93c46a    ***************************
extern int swr_93c46a(int icdev,int offset, int len,unsigned char *data_buffer);
extern int srd_93c46a(int icdev,int offset, int len, unsigned char *data_buffer);
extern int eral_93c46a(int icdev);
extern int chk_93c46a(int icdev);
//************************    operate at93c46    ***************************
extern int swr_93c46(int icdev,int offset, int len, unsigned char *data_buffer);
extern int srd_93c46(int icdev,int offset, int len, unsigned char *data_buffer);
extern int eral_93c46(int icdev);
extern int chk_93c46(int icdev);
//*********************    operate at88sc1608    **************************
extern int reset_1608(int icdev,int len, unsigned char *data_buffer);
extern int init_auth_1608(int icdev,int len, unsigned char *data_buffer);
extern int callsrd_1608(int icdev,int zone,int offset,int len,unsigned char *data_buffer);
extern int srd_1608(int icdev,int zone,int offset,int len,unsigned char *data_buffer);
extern int srfus_1608(int icdev,int len,unsigned char *data_buffer);
extern int callswr_1608(int icdev,int zone,int offset,int len,unsigned char *data_buffer);
extern int swr_1608(int icdev,int zone,int offset,int len,unsigned char *data_buffer);
extern int csc_1608(int icdev,int zone,int len,int rw,unsigned char *data_buffer);
extern int psnl_1608(int icdev);
extern int wsc_1608(int icdev,int zone,int len, int rw,unsigned char *data_buffer);
extern int rsc_1608(int icdev,int zone,int len,int rw,unsigned char *data_buffer);
extern int rsct_1608(int icdev,int zone,int len, int rw,unsigned char *data_buffer);
extern int rac_1608(int icdev,int zone,int len,unsigned char *data_buffer);
extern int wac_1608(int icdev,int zone,int len,unsigned char *data_buffer);
extern int chk_1608(int icdev);
extern int srdconfig_1608(int icdev,int offset,int len,unsigned char *data_buffer);
extern int swrconfig_1608(int icdev,int offset,int len,unsigned char *data_buffer);
extern void Authenticate(unsigned char *q1,unsigned char *q2);
extern void SetInit(unsigned char *crypto, unsigned char *graine,unsigned char *host);
//*********************    operate at88sc153    **************************

//对153卡复位，len为4，data_buffer为返回的4字节数据
extern int reset_153(int icdev,int len, unsigned char *data_buffer);

//初始化认证，len为16，data_buffer为随机数据P0+其产生数P1，P0在前，P1在后
extern int init_auth_153(int icdev,int len, unsigned char *data_buffer);

//检验读卡器中是否是AT153卡，返回值是0代表是，反之代表否
extern int chk_153(int icdev);

//读153卡用户区数据，zone为0~2，offset为该区偏移地址，len为数据长度，data_buffer为返回数据
extern int srd_153(int icdev,int zone,int offset,int len,unsigned char *data_buffer);

//写153卡用户区数据，zone为0~2，offset为该区偏移地址，len为数据长度，data_buffer为需写入数据
extern int swr_153(int icdev,int zone,int offset,int len,unsigned char *data_buffer);

//读153卡配置区数据，offset为该区偏移地址，len为数据长度，data_buffer为返回数据
extern int srdconfig_153(int icdev,int offset,int len,unsigned char *data_buffer);

//写153卡配置区数据，offset为该区偏移地址，len为数据长度，data_buffer为需写入数据
extern int swrconfig_153(int icdev,int offset,int len,unsigned char *data_buffer);

//读AR（用户区访问权限寄存器），zone为0~2，len为1，data_buffer为返回值
extern int rac_153(int icdev,int zone,int len,unsigned char *data_buffer);

//写AR（用户区访问权限寄存器），zone为0~2，len为1，data_buffer为设置的值
//AR控制密码与用户区的对应关系，请仔细设置
extern int wac_153(int icdev,int zone,int len,unsigned char *data_buffer);

//读AAC（认证错误计数器），len为1，data_buffer为返回计数器值
extern int rautht_153(int icdev,int len, unsigned char *data_buffer);

//读DCR（设备配置寄存器），len为1，data_buffer为返回值
extern int rdcr_153(int icdev,int len,unsigned char *data_buffer);

//写DCR（设备配置寄存器），len为1，data_buffer为写入值
extern int wdcr_153(int icdev,int len,unsigned char *data_buffer);

//校验读写密码，psw_set 为0~1，len为3， rw=0选择写密码，rw=1选择读密码，data_buffer为密码
extern int csc_153(int icdev,int psw_set,int rw,int len,unsigned char *data_buffer);

//读卡中读写密码，psw_set 为0~1，len为3， rw=0选择写密码，rw=1选择读密码，data_buffer为返回密码
extern int rsc_153(int icdev,int psw_set,int rw,int len,unsigned char *data_buffer);

//写卡中读写密码，psw_set 为0~1，len为3， rw=0选择写密码，rw=1选择读密码，data_buffer为写入密码
extern int wsc_153(int icdev,int psw_set,int rw,int len,unsigned char *data_buffer);

//读卡中读写密码错误计数器，psw_set 为0~1，len为1， rw=0选择写密码错误计数器，rw=1选择读密码错误计数器，data_buffer为返回计数器值
extern int rsct_153(int icdev,int psw_set,int rw,int len,unsigned char *data_buffer);

//读熔断操作位，len为1，data_buffer为返回操作位的值
//fuse byte：00000F2F1F0，F0——芯片商熔断（0代表熔断），F1——卡片生产商熔断（0代表熔断），F2——发行商熔断（0代表熔断）
extern int srfus_153(int icdev,int len,unsigned char *data_buffer);

//写熔断操作位，data_fus为写入操作位的值,写入1熔断F0,写入2熔断F1,写入4熔断F2,必须依次熔断
//fuse byte：00000F2F1F0，F0——芯片商熔断（0代表熔断），F1——卡片生产商熔断（0代表熔断），F2——发行商熔断（0代表熔断）
extern int swfus_153(int icdev,unsigned char data_fus);

//153卡个人化
extern int psnl_153(int icdev);

//********************** cpu card ****************************************//
extern int cpu_reset(int icdev,unsigned char *receive_data);
extern int cpu_protocol(int icdev,int len, unsigned char *send_data,unsigned char *receive_data);
extern int cpu_comres(int icdev,int len, unsigned char *send_data,unsigned char *receive_data);
//********************** sam card ****************************************
extern int set_card_baud(int icdev, unsigned char CardType,unsigned char BaudCode);
extern int sam_power_on(int icdev);
extern int sam_power_down(int icdev);
extern int sam_reset(int icdev,int *len,unsigned char *receive_data);
extern int sam_select(int icdev, unsigned char SelectCard);
extern int sam_protocol(int icdev,int sLen, unsigned char *send_cmd, unsigned char *receive_data);
extern int sam_comres(int icdev,int sLen, unsigned char *send_cmd, unsigned char *receive_data);
