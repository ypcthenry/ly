VERSION 5.00
Begin VB.Form MC32_10 
   Caption         =   "MC32_10"
   ClientHeight    =   3825
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5775
   LinkTopic       =   "Form1"
   ScaleHeight     =   3825
   ScaleWidth      =   5775
   StartUpPosition =   3  'Windows Default
   Begin VB.ListBox List1 
      Height          =   2400
      Left            =   360
      TabIndex        =   1
      Top             =   1080
      Width           =   2655
   End
   Begin VB.CommandButton Command6 
      Caption         =   "102"
      Height          =   375
      Left            =   3840
      TabIndex        =   0
      Top             =   1920
      Width           =   1215
   End
   Begin VB.PictureBox Picture1 
      Height          =   2895
      Left            =   120
      ScaleHeight     =   2835
      ScaleWidth      =   5475
      TabIndex        =   2
      Top             =   840
      Width           =   5535
   End
   Begin VB.Label Label1 
      Caption         =   "10ϵ�к�����������"
      BeginProperty Font 
         Name            =   "����"
         Size            =   18
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   495
      Left            =   1560
      TabIndex        =   3
      Top             =   120
      Width           =   3495
   End
End
Attribute VB_Name = "MC32_10"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim oldpass As String * 4

Dim Data1 As String * 16
Dim Data2 As String * 16
Dim offset As Integer
Dim length As Integer
Dim status As Integer
Dim password(1) As Byte
Dim pass(6) As Byte
Dim proval As String * 8
Dim counter As Integer
Dim databuff1(7) As Byte
Dim databuff2(7) As Byte
Dim erapass As String * 12
Dim ptrdest(16) As Byte
Dim ptrsource As String * 16

Private Sub Command6_Click()
'**************�⿨����,�ɸ�����Ҫѡ��**************************
st = chk_102(icdev)
If st = 0 Then
    List1.AddItem ("chk Ok")
Else
    List1.AddItem ("chk card error")
    Exit Sub
End If
'***************�˶�����f0f0***************************
'password(0) = &HF0
'password(1) = &HF0
oldpass = "f0f0"
st = asc_hex(oldpass, password(0), 2)
st = csc_102(icdev, 2, password(0))
If st < 0 Then
    List1.AddItem ("csc error")
    Exit Sub
Else
    List1.AddItem ("csc  ok")
    
End If


'***************��������f0f0*****************************
st = rsc_102(icdev, 2, password(0))
 
If st < 0 Then
    List1.AddItem ("rsc error")
    Exit Sub
Else
    List1.AddItem ("rsc  ok")
    
End If

'***************�޸�����Ϊf0f0******************************
password(0) = &HF0
password(1) = &HF0
st = wsc_102(icdev, 2, password(0))
If st < 0 Then
    List1.AddItem ("wsc error")
    Exit Sub
Else
    List1.AddItem ("wsc  ok")
End If

'***************����������������Ϊ4��********************
st = rsct_102(icdev, counter)
If st < 0 Then
    List1.AddItem ("rsct error")
    Exit Sub
    
Else
    List1.AddItem ("rsct  ok")
    List1.AddItem (Str(counter))
End If
'***************�˶Բ�������ffffffffffff*******************
'pass(0) = &HFF
'pass(1) = &HFF
'pass(2) = &HFF
'pass(3) = &HFF
'pass(4) = &HFF
'pass(5) = &HFF
erapass = "ffffffffffff"
st = asc_hex(erapass, pass(0), 6)
st = cesc_102(icdev, 1, 6, pass(0))
If st < 0 Then
    List1.AddItem ("cesc error")
    Exit Sub
Else
    List1.AddItem ("cesc  ok")
End If
'**************��������������ffffffffffff***************
st = resc_102(icdev, 1, 6, pass(0))
If st < 0 Then
    List1.AddItem ("resc error")
    Exit Sub
Else
    List1.AddItem ("resc  ok")
End If
'**************��������������������******************
st = resct_102(icdev, 2, counter)
If st < 0 Then
    List1.AddItem ("resct error")
    Exit Sub
Else
    List1.AddItem ("resct  ok")
End If
'**************����1��ƫ�Ƶ�ַ��30��ʼ������10���ֽ�******************************
st = ser_102(icdev, 1, 30, 10)
If st < 0 Then
    List1.AddItem ("ser error")
    Exit Sub
Else
    List1.AddItem ("ser  ok")
End If
'**************��ASC��ʽ��ƫ�Ƶ�ַ30��ʼ������10���ֽڶ�д��**********
offset = 30
length = 10
Data1 = "1234567890"
st = swr_102(icdev, 1, offset, length, Data1)
If st < 0 Then
  List1.AddItem ("write_102_asc error")
  Exit Sub
Else
  List1.AddItem ("write_102_asc ok")
End If

st = srd_102(icdev, 1, offset, length, Data2)
If st < 0 Then
   List1.AddItem ("read_102_asc error")
   Exit Sub
Else
   List1.AddItem ("read_102_asc OK")
   List1.AddItem (Data2)
End If
'**************����1��ƫ�Ƶ�ַ��46��ʼ������8���ֽ�******************************
st = ser_102(icdev, 1, 46, 8)
If st < 0 Then
    List1.AddItem ("ser error")
    Exit Sub
Else
    List1.AddItem ("ser  ok")
End If
'*************��ʮ��������ʽ��ƫ�Ƶ�ַ46��ʼ������8���ֽڽ��ж�д����**
offset = 46
length = 8
Data1 = "abcdef0123456789"
st = asc_hex(Data1, databuff1(0), 8)
If st < 0 Then
    List1.AddItem ("asc_hex error")
    Exit Sub
Else
    List1.AddItem ("asc_hex ok")
End If
    
st = swr_102_hex(icdev, 1, offset, length, databuff1(0))
If st < 0 Then
  List1.AddItem ("write_102_hex error")
  Exit Sub
Else
  List1.AddItem ("write_102_hex ok")
End If


st = srd_102_hex(icdev, 1, offset, length, databuff2(0))
If st < 0 Then
  List1.AddItem ("read_102_hex error")
  Exit Sub
Else
  st = hex_asc(databuff2(0), Data2, 8)
  List1.AddItem ("read_102_hex OK")
  List1.AddItem (Data2)
End If
'**************д����λ��0,���ܶ�Ӧ����1����д����*************
st = clrpr_102(icdev, 1)
If st < 0 Then
  List1.AddItem ("clrpr error")
  Exit Sub
Else
  List1.AddItem ("clrpr ok")
End If
'*************������λ��0,�˶�����ǰ���ܶ�Ӧ����1���ж�����*****
st = clrrd_102(icdev, 1)
If st < 0 Then
  List1.AddItem ("clrrd error")
  Exit Sub
Else
  List1.AddItem ("clrrd ok")
End If
'***********************DES�㷨���ܽ���********************
st = ic_encrypt("12345678", "����������������", 16, ptrdest(0))
If st < 0 Then
    List1.AddItem ("ic_encrypt error")
    Exit Sub
Else
    List1.AddItem ("ic_encrypt ok")
End If

st = ic_decrypt("12345678", ptrdest(0), 16, ptrsource)
If st < 0 Then
    List1.AddItem ("ic_decrypt error")
    Exit Sub
Else
    List1.AddItem ("ic_decrypt ok")
    List1.AddItem (ptrsource)
End If
'**********************************************************

End Sub
 
Private Sub Form_Load()
icdev& = auto_init(0, 9600)    '��ʼ������1,������Ϊ9600
If icdev& <= 0 Then
    List1.AddItem ("Init error!")
    Exit Sub
  Else
    List1.AddItem ("Init OK")
  End If
  
st = get_status(icdev, status)  '��ȡ�豸״̬
If st = 0 Then
  List1.AddItem ("Status OK")
Else
  List1.AddItem ("Status Error")
  Exit Sub
End If
End Sub

Private Sub Form_Unload(Cancel As Integer)
st = ic_exit(icdev)
End Sub

