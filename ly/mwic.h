//card type
#define CARD_UNKNOW	0
#define CARD_24C01A	1
#define CARD_24C02	2
#define CARD_24C04	3
#define CARD_24C08	4
#define CARD_24C16	5
#define CARD_24C32	6
#define CARD_24C64	7
#define CARD_45D041	10
#define CARD_4432	20
#define CARD_4442	21
#define CARD_4418	30
#define CARD_4428	31
#define CARD_4404	40
#define CARD_4406	41
#define CARD_101	50
#define CARD_102	51
#define CARD_1604	52
#define CARD_1604B	53
#define CARD_1608	54
#define CARD_153	55
#define CARD_93C46A	60
#define CARD_93C46	61
#define CARD_93C57	62
//end card type

/**************    commual subroutin  ***********/
extern int ic_init(char *filename,unsigned long baud);
extern int auto_init(char *filename,unsigned long baud);
extern int ic_exit(int icdev);
extern int set_send_mode(int icdev, unsigned char mode);
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

extern long chk_baud(char *filename);
extern int dv_beep(int icdev, int time);
extern int chk_card(int icdev);
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

//��153����λ��lenΪ4��data_bufferΪ���ص�4�ֽ�����
extern int reset_153(int icdev,int len, unsigned char *data_buffer);

//��ʼ����֤��lenΪ16��data_bufferΪ�������P0+�������P1��P0��ǰ��P1�ں�
extern int init_auth_153(int icdev,int len, unsigned char *data_buffer);

//������������Ƿ���AT153��������ֵ��0�����ǣ���֮������
extern int chk_153(int icdev);

//��153���û������ݣ�zoneΪ0~2��offsetΪ����ƫ�Ƶ�ַ��lenΪ���ݳ��ȣ�data_bufferΪ��������
extern int srd_153(int icdev,int zone,int offset,int len,unsigned char *data_buffer);

//д153���û������ݣ�zoneΪ0~2��offsetΪ����ƫ�Ƶ�ַ��lenΪ���ݳ��ȣ�data_bufferΪ��д������
extern int swr_153(int icdev,int zone,int offset,int len,unsigned char *data_buffer);

//��153�����������ݣ�offsetΪ����ƫ�Ƶ�ַ��lenΪ���ݳ��ȣ�data_bufferΪ��������
extern int srdconfig_153(int icdev,int offset,int len,unsigned char *data_buffer);

//д153�����������ݣ�offsetΪ����ƫ�Ƶ�ַ��lenΪ���ݳ��ȣ�data_bufferΪ��д������
extern int swrconfig_153(int icdev,int offset,int len,unsigned char *data_buffer);

//��AR���û�������Ȩ�޼Ĵ�������zoneΪ0~2��lenΪ1��data_bufferΪ����ֵ
extern int rac_153(int icdev,int zone,int len,unsigned char *data_buffer);

//дAR���û�������Ȩ�޼Ĵ�������zoneΪ0~2��lenΪ1��data_bufferΪ���õ�ֵ
//AR�����������û����Ķ�Ӧ��ϵ������ϸ����
extern int wac_153(int icdev,int zone,int len,unsigned char *data_buffer);

//��AAC����֤�������������lenΪ1��data_bufferΪ���ؼ�����ֵ
extern int rautht_153(int icdev,int len, unsigned char *data_buffer);

//��DCR���豸���üĴ�������lenΪ1��data_bufferΪ����ֵ
extern int rdcr_153(int icdev,int len,unsigned char *data_buffer);

//дDCR���豸���üĴ�������lenΪ1��data_bufferΪд��ֵ
extern int wdcr_153(int icdev,int len,unsigned char *data_buffer);

//У���д���룬psw_set Ϊ0~1��lenΪ3�� rw=0ѡ��д���룬rw=1ѡ������룬data_bufferΪ����
extern int csc_153(int icdev,int psw_set,int rw,int len,unsigned char *data_buffer);

//�����ж�д���룬psw_set Ϊ0~1��lenΪ3�� rw=0ѡ��д���룬rw=1ѡ������룬data_bufferΪ��������
extern int rsc_153(int icdev,int psw_set,int rw,int len,unsigned char *data_buffer);

//д���ж�д���룬psw_set Ϊ0~1��lenΪ3�� rw=0ѡ��д���룬rw=1ѡ������룬data_bufferΪд������
extern int wsc_153(int icdev,int psw_set,int rw,int len,unsigned char *data_buffer);

//�����ж�д��������������psw_set Ϊ0~1��lenΪ1�� rw=0ѡ��д��������������rw=1ѡ�����������������data_bufferΪ���ؼ�����ֵ
extern int rsct_153(int icdev,int psw_set,int rw,int len,unsigned char *data_buffer);

//���۶ϲ���λ��lenΪ1��data_bufferΪ���ز���λ��ֵ
//fuse byte��00000F2F1F0��F0����оƬ���۶ϣ�0�����۶ϣ���F1������Ƭ�������۶ϣ�0�����۶ϣ���F2�����������۶ϣ�0�����۶ϣ�
extern int srfus_153(int icdev,int len,unsigned char *data_buffer);

//д�۶ϲ���λ��data_fusΪд�����λ��ֵ,д��1�۶�F0,д��2�۶�F1,д��4�۶�F2,���������۶�
//fuse byte��00000F2F1F0��F0����оƬ���۶ϣ�0�����۶ϣ���F1������Ƭ�������۶ϣ�0�����۶ϣ���F2�����������۶ϣ�0�����۶ϣ�
extern int swfus_153(int icdev,unsigned char data_fus);

//153�����˻�
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
