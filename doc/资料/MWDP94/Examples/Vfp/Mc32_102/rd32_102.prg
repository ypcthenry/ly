declare integer auto_init in c:\windows\system\mwic_32.dll short port,integer baud
declare integer  ic_init in c:\windows\system\mwic_32.dll short port,integer baud
declare short ic_exit in c:\windows\system\mwic_32.dll  integer icdev
declare short get_status in c:\windows\system\mwic_32.dll integer icdev,integer @status

declare short chk_102  in c:\windows\system\mwic_32.dll integer icdev
declare short srd_102  in c:\windows\system\mwic_32.dll integer icdev, short zone,short offset,short len,string @buffer
declare short swr_102  in c:\windows\system\mwic_32.dll integer icdev, short zone,short offset,short len,string @buffer
declare short ser_102  in c:\windows\system\mwic_32.dll integer icdev, short zone,short offset,short len
declare short csc_102   in c:\windows\system\mwic_32.dll integer icdev, short len,string @buffer
declare short wsc_102   in c:\windows\system\mwic_32.dll integer icdev, short len,string @buffer
declare short rsc_102   in c:\windows\system\mwic_32.dll integer icdev, short len,string @buffer
declare short rsct_102   in c:\windows\system\mwic_32.dll integer icdev, integer @counter

declare short ic_encrypt in c:\windows\system\mwic_32.dll  string @buffer, string buffer1,short len,string @buffer2
declare short ic_decrypt in c:\windows\system\mwic_32.dll  string @buffer, string @buffer1,short len,string @buffer2

declare short asc_hex in c:\windows\system\mwic_32.dll string @buffer, string @buffer1,integer  len
declare short hex_asc in c:\windows\system\mwic_32.dll string @buffer, string @buffer1,integer len


icdev=auto_init(0,9600)             &&��ʼ������һ�����д��������Ϊ9600��
&&icdev=ic_init(0,9600)
if icdev<0
    ? "init error."
    retu
endif
? "init ok."

status=0                           &&����д�����Ƿ��п���status=0��ʾ�޿���=1��ʾ�п���
st=get_status(icdev,@status)
if st<>0
    ?"status error."
	retu
endif
?"status ok."+str(status)


st=chk_102(icdev)     &&�⿨���������ο�,
if st<>0                &&����:��Ӧ���������������Ƶķ����̴�������⿨
    ? "chk card error."
     retu
endif
? "chk card ok."

&&password1=chr(240)+chr(240)

password="F0F0"                        &&  У������
password1=space(2)
st=asc_hex(password,@password1,2)
st=csc_102(icdev,2,password1)
if st<>0
    ? "check password error."
    retu
endif
? "check password ok."  

counter=0                        && ����������������
st=rsct_102(icdev,@counter)
if st<>0 then
   ? "rest_102 error."
   retu
endif
? "counter="+str(counter)


st=ser_102(icdev,1,0,64)        && ��������
if st<>0
   ? "ser_102 error."
   retu
endif
? "ser_102 ok."


zone=1
offset=2                          && ��ASC��ʽ���ж���д��          
le=8
data1="abcdefgh"
st=swr_102(icdev,zone,offset,le,@data1)
if st<>0
    ? "write error."
   retu
endif
? "write ok."

data2=space(8)
st=srd_102(icdev,zone,offset,le,@data2)   
if st<>0
    ? "read error."
   retu
endif
? "read ok"
? 'data: '+data2   


offset=12                          &&��ʮ��������ʽ���ж���д��          
le=10
data1="31323334353637383930"
hexdata1=space(20)
st=asc_hex(data1,@hexdata1,10)
st=swr_102(icdev,zone,offset,le,@hexdata1)
if st<>0
    ? "write_hex error."
   retu
endif
? "write_hex ok."


data3=space(10)
hexdata3=space(20)
st=srd_102(icdev,zone,offset,le,@data3)   
if st<>0
    ? "read error."
   retu
endif

st=hex_asc(@data3,@hexdata3,10)
? "read_hex ok"
? "hexdata3: "+hexdata3   

dest=space(16)
source=space(16)
st=ic_encrypt("12345678","������˾��������",16,@dest)
if st<>0 
  ? "encrypt error."
  retu
endif  
? "Ciphertext: "+dest

st=ic_decrypt("12345678",@dest,16,@source)
if st<>0
   ? "decrypt error."
   retu
endif
? "Plaintext:"+ source


st=ic_exit(icdev)
if st<>0
    ? "exit error."
    retu
endif
? "exit ok."

retu
