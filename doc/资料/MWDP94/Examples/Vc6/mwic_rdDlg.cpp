// mwic_rdDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mwic_rd.h"
#include "mwic_rdDlg.h"
#include "mwic_32.h"
#include "CLogFile.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
CLogFile   Clog;
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMwic_rdDlg dialog

CMwic_rdDlg::CMwic_rdDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMwic_rdDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMwic_rdDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CMwic_rdDlg::~CMwic_rdDlg ()
{
	st=ic_exit(icdev);
}

void CMwic_rdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMwic_rdDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMwic_rdDlg, CDialog)
	//{{AFX_MSG_MAP(CMwic_rdDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_MENUITEMEXIT, OnMenuitemexit)
	ON_COMMAND(ID_MENUITEM24C01A, OnMenuitem24c01a)
	ON_COMMAND(ID_MENUITEM24c02, OnMENUITEM24c02)
	ON_COMMAND(ID_MENUITEM24c04, OnMENUITEM24c04)
	ON_COMMAND(ID_MENUITEM24c16, OnMENUITEM24c16)
	ON_COMMAND(ID_MENUITEM24c64, OnMENUITEM24c64)
	ON_COMMAND(ID_MENUITEMCONN, OnMenuitemconn)
	ON_COMMAND(ID_MENUITEM4442, OnMenuitem4442)
	ON_COMMAND(ID_MENUITEMcpu, OnMENUITEMcpu)
	ON_COMMAND(DES, OnDES)
	ON_COMMAND(ID_MENUITEMSamCard, OnMENUITEMSamCard)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMwic_rdDlg message handlers

BOOL CMwic_rdDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
    HMENU hmnu;
	hmnu=LoadMenu(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MENU1));
	::SetMenu(m_hWnd,hmnu);
	unsigned char testbuf[100]="\0";
	memcpy(testbuf,"\0x00\0x84\0x00\0x00\0x08",5);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMwic_rdDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMwic_rdDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMwic_rdDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMwic_rdDlg::OnMenuitemexit() 
{
	// TODO: Add your command handler code here
   st=ic_exit(icdev);
   OnOK();
}

void CMwic_rdDlg::OnMenuitem24c01a() 
{
	// TODO: Add your command handler code here
	l=0;
	m_list.ResetContent();
	st = chk_24c01a(icdev);
    if (st == 0) 
    { 
		m_list.InsertString (l,"chk_24c01a()  Ok!");
	    l++;
	}
    else
    {
		m_list.InsertString (l,"chk_24c01a()  error!");
		l++;
	    goto end;
	}
    
 
    offset = 0;
    lenth = 10;
    memcpy(data1 ,"1234567890",10);
    st = swr_24c01a(icdev, offset, lenth, data1);
  if (st == 0) 
    { 
		m_list.InsertString (l,"swr_24c01a()  Ok!");
	    l++;
	}
    else
    {
		m_list.InsertString (l,"swr_24c01a()  error!");
		l++;
	    goto end;
	}

	st = srd_24c01a(icdev, offset, lenth, data2);
    if (st == 0) 
    { 
		m_list.InsertString (l,"srd_24c01a()  Ok!");
	    l++;
	}
    else
    {
		m_list.InsertString (l,"srd_24c01a()  error!");
		l++;
	    goto end;
	}
end: ;	
}

void CMwic_rdDlg::OnMENUITEM24c02() 
{
	// TODO: Add your command handler code here
	l=0;
	m_list.ResetContent();
	st = chk_24c02(icdev);
    if (st == 0) 
    { 
		m_list.InsertString (l,"chk_24c02()  Ok!");
	    l++;
	}
    else
    {
		m_list.InsertString (l,"chk_24c02()  error!");
		l++;
	    goto end;
	}
    
 
    offset = 128;
    lenth = 10;
    memcpy(data1 ,"1234567890",10);
    st = swr_24c02(icdev, offset, lenth, data1);
    if (st == 0) 
    { 
		m_list.InsertString (l,"swr_24c02()  Ok!");
	    l++;
	}
    else
    {
		m_list.InsertString (l,"swr_24c02()  error!");
		l++;
	    goto end;
	}

	st = srd_24c02(icdev, offset, lenth, data2);
    if (st == 0) 
    { 
		m_list.InsertString (l,"srd_24c02()  Ok!");
	    l++;
	}
    else
    {
		m_list.InsertString (l,"srd_24c02()  error!");
		l++;
	    goto end;
	}
end: ;
		
}

void CMwic_rdDlg::OnMENUITEM24c04() 
{
	// TODO: Add your command handler code here
    l=0;
	m_list.ResetContent();
	st = chk_24c04(icdev);
    if (st == 0) 
    { 
		m_list.InsertString (l,"chk_24c04()  Ok!");
	    l++;
	}
    else
    {
		m_list.InsertString (l,"chk_24c04()  error!");
		l++;
	    goto end;
	}
    
 
    offset = 128;
    lenth = 10;
    memcpy(data1 ,"1234567890",10);
    st = swr_24c04(icdev, offset, lenth, data1);
    if (st == 0) 
    { 
		m_list.InsertString (l,"swr_24c04()  Ok!");
	    l++;
	}
    else
    {
		m_list.InsertString (l,"swr_24c04()  error!");
		l++;
	    goto end;
	}

	st = srd_24c04(icdev, offset, lenth, data2);
    if (st == 0) 
    { 
		m_list.InsertString (l,"srd_24c04()  Ok!");
	    l++;
	}
    else
    {
		m_list.InsertString (l,"srd_24c04()  error!");
		l++;
	    goto end;
	}
end: ;		
}


void CMwic_rdDlg::OnMENUITEM24c16() 
{
	// TODO: Add your command handler code here
	l=0;
	m_list.ResetContent();
	st = chk_24c16(icdev);
    if (st == 0) 
    { 
		m_list.InsertString (l,"chk_24c16()  Ok!");
	    l++;
	}
    else
    {
		m_list.InsertString (l,"chk_24c16()  error!");
		l++;
	    goto end;
	}
    
 
    offset = 128;
    lenth = 10;
    memcpy(data1 ,"1234567890",10);
    st = swr_24c16(icdev, offset, lenth, data1);
    if (st == 0) 
    { 
		m_list.InsertString (l,"swr_24c16()  Ok!");
	    l++;
	}
    else
    {
		m_list.InsertString (l,"swr_24c16()  error!");
		l++;
	    goto end;
	}

	st = srd_24c16(icdev, offset, lenth, data2);
    if (st == 0) 
    { 
		m_list.InsertString (l,"srd_24c16()  Ok!");
	    l++;
	}
    else
    {
		m_list.InsertString (l,"srd_24c16()  error!");
		l++;
	    goto end;
	}
end: ;		
}

void CMwic_rdDlg::OnMENUITEM24c64() 
{
	// TODO: Add your command handler code here
    l=0;
	m_list.ResetContent();
	st = 0;//chk_24c64(icdev);
    if (st == 0) 
    { 
		m_list.InsertString (l,"chk_24c64()  Ok!");
	    l++;
	}
    else
    {
		m_list.InsertString (l,"chk_24c64()  error!");
		l++;
	    goto end;
	}
    
 
    offset = 0;
    lenth = 8191;

	st = srd_24c64(icdev, offset, lenth, data2);
    if (st == 0) 
    { 
		m_list.InsertString (l,"srd_24c64()  Ok!");
	    l++;
	}
    else
    {
		m_list.InsertString (l,"srd_24c64()  error!");
		l++;
	    goto end;
	}
	Clog.Write_Logfile((unsigned char*)data2,2000);
end: ;		
}

void CMwic_rdDlg::OnMenuitemconn() 
{
	// TODO: Add your command handler code here
	FILE *stream;

	char strFileName[200]="\0";

	//CTime tm = CTime::GetCurrentTime();
	char timebuf[128],datebuf[128];
	//_tzset();

	//_strtime( timebuf );    
    //_strdate( datebuf );

	
	//sprintf(strFileName,"SSSELog%s.txt",timebuf);
	
	//if(!LogFile.Open(strFileName,CFile::modeWrite|CFile::modeRead))
	//if( (stream = fopen( strFileName, "w+t" )) == NULL )
	//{
		//AfxMessageBox(  NULL, strFileName, "日志文件", MB_OK|MB_ICONEXCLAMATION  );
			//return ;
	//}

 l=0;
 m_list.ResetContent();
 port=3;    //COM2
 baud=9600;//115200;
 status=0;
 l=0;
 icdev=ic_init(port,baud);
 if (icdev<0)
 {
   m_list.InsertString(l,"ic_init() error!");
   l++;
   goto end;
 }
 else
 {
   m_list.InsertString(l,"ic_init() ok");
   l++;
 }

 st=get_status(icdev,&status);
 if (st<0) 
 {
	m_list.InsertString(l,"get_status() error!");
    l++;
	goto end;
 }
 else
 {
	m_list.InsertString(l,"get_status() ok!");
    l++;
 }
end: ;		
}

void CMwic_rdDlg::OnMenuitem4442() 
{
	// TODO: Add your command handler code here
	l=0;
	m_list.ResetContent ();
	st=chk_4442(icdev);
	if (st!=0) 
	{
       m_list.InsertString(l,"chk_4442() error!");
	   l++;
	   goto end;
	}
	else
	{
		m_list.InsertString(l,"chk_4442() ok!");
        l++;
	}
	key[0]=0xb6;
    key[1]=0x23;
	key[2]=0x7;
	st=csc_4442(icdev,3,key);
	if (st!=0) 
	{
		m_list.InsertString (l,"csc_4442() error!");
        l++;
		goto end;
	}
	else
	{
		m_list.InsertString (l,"csc_4442() ok!");
        l++;
    }

	st=rsc_4442(icdev,3,key);
	if (st!=0)
	{
		m_list.InsertString (l,"rsc_4442() error!");
		l++;
		goto end;
	}
	else
	{
		memset(c3,0x20,200);
		memcpy(c3,"rsc_4442() ok! The key is:",26);
		hex_asc(key,c1,6);
		memcpy(c3+27,c1,6);
		m_list.InsertString (l, c3);
		l++;
    }
	
	key[0] = 0xB6;
    key[1] = 0x23;
    key[2] = 0x7;
    st = wsc_4442(icdev, 3, key);
    if (st != 0) 
	{
		m_list.InsertString (l,"wsc_4442() error!");
        l++;
        goto end;
	}
	else
  	{
        m_list.InsertString (l,"wsc_4442() ok!");
        l++;
    }

    st = rsct_4442(icdev,&counter);
    if (st!= 0)
    {
		m_list.InsertString (l,"rsct_4442() error");
        l++;
	    goto end;
	}
    else
	{
		
        memset(c3,0x20,200);
		memcpy(c3,"rsct_4442() ok! The counter is:",31);
		_itoa(counter,c3+31,2);
		m_list.InsertString (l,c3);
		l++;
    }
        
    offset = 40;
    lenth = 10;
    memcpy(data1, "1234567890",10);
    st = swr_4442(icdev, offset, lenth, data1);
    if (st != 0) 
    {     
	   m_list.InsertString (l,"swr_4442() error!");
        l++;
	   goto end;
	}
	else 
	{
	    m_list.InsertString (l,"swr_4442() ok! Write 1234567890");
        l++;
    }
 
    st = srd_4442(icdev, offset, lenth, data2);
    if (st !=0) 
    {
        m_list.InsertString (l,"srd_4442() error! Read ");
        l++;
        goto end;
	}
    else
	{
        memset(c3,0x20,200);
		memcpy(c3,"srd_4442() ok! Read:",20);
		memcpy(c3+21,data2,10);
		m_list.InsertString (l,c3);
        l++;
    }


    proval =0x36;
    //st = swr_4442(icdev, 30, 1, &proval);
    if (st != 0) 
    {
        m_list.InsertString (l,"swr_4442() error!");
        l++;
        goto end;
	}	
    else
	{
        m_list.InsertString (l,"swr_4442() ok! Write 6");
        l++;
    }
    //st = pwr_4442(icdev, 30, 1, &proval);
    if (st != 0) 
    {
        m_list.InsertString (l,"pwr_4442() error!");
        l++;
        goto end;
	}	
    else
	{
        m_list.InsertString (l,"pwr_4442() ok! Write 6");
        l++;
    }
	  
    st = prd_4442(icdev, 4, &proval);
    if (st != 0) 
	{
        m_list.InsertString (l,"prd_4442()  error! ");
		l++;
        goto end;
    }
	else
	{
         memset(c3,0x20,200);
		 memcpy(c3,"prd_4442() ok! Read:",20);
		 _itoa(proval,c3+21,2);
		 m_list.InsertString (l,c3);
         l++;
    }
end:;
	
}

void CMwic_rdDlg::OnMENUITEMcpu() 
{
	// TODO: Add your command handler code here
    l=0;
    m_list.ResetContent();
	//复位
	memset(icRead,0xff,200);
	if ((st=cpu_reset(icdev,icRead))!=0)
	{
		memset(c3,0x00,200);
		_itoa(st,c3+4,10);
		memcpy(c3,"error",5);
		m_list.InsertString(l,c3);
		l++;
		goto end;
	}
	else
	{
		for(st=0;st<200;st++)
		{
			if ((icRead[st]==0xff)&&(icRead[st+1]==0xff)&&(icRead[st+2]==0xff))
			break;
		}
		hex_asc(icRead,c1,st*2);
		memset(c3,0x20,200);
		memcpy(c3,"Reset:",6);
		memcpy(c3+8,c1,st*2);
		m_list.InsertString(l,c3);
		l++;
        
	}
	//取随机数
	icWrite[0]=0x00;
	icWrite[1]=0x40;
	icWrite[2]=0x05;
	icWrite[3]=0x00;
	icWrite[4]=0x84;
	icWrite[5]=0x00;
	icWrite[6]=0x00;
	icWrite[7]=0x08;
	icWrite[8]=0x00;


	for (st=0;st<8;st++)
		icWrite[8]=icWrite[8]^icWrite[st];
	if ((st=cpu_protocol(icdev,9,icWrite,icRead))!=0)
	{
		memset(c3,0x00,16);
		_itoa(st,c3+4,10);
		memcpy(c3,"get random error",16);
		m_list.InsertString(l,c3);
		l++;
		goto end;
	}
	else
	{
		lenth=icRead[2];
		memset(c3,0x20,200);
		hex_asc(icRead,c1,(lenth+3)*2);
		memcpy(c3,"Get random",10);
		memcpy(c3+31,c1+6+(lenth-2)*2,4);
		memcpy(c3+13,c1+6,(lenth-2)*2);
		m_list.InsertString(l,c3);
		l++;
	}
end: ;
}


void CMwic_rdDlg::OnDES() 
{
	// TODO: Add your command handler code here

	unsigned char Key[16]={0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66};
	unsigned char Scr[16]={0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66};
	unsigned char result[16]="\0";	

	char Rand[8]={0x1C,0xE9,0x40,0x80,0x01,0xA7,0xDD,0x36},KEY06[20]={0x3C,0xED,0xFD,0xD3,0xB0,0x4B,0xF0,0x2C,0xA3,0xB0,0x18,0xD2,0x75,0x4E,0x89,0xA3};
	char result1[20]="\0",result2[20]="\0",result3[20]="\0";
	ic_encrypt(KEY06,Rand, 8,result1);
	ic_encrypt(&KEY06[8],result1, 8,result2);
	ic_decrypt(KEY06,result2, 8,result3);

  l=0;
  m_list.ResetContent();
  memcpy(keya,"12345678",8);
  memcpy(source,"mwic_cpu",8);

  DES_Encrypt( Key,16,Scr,16,result);

  st=ic_encrypt(keya,source,8,destin);
  if (st==0)
  {
	  memset(c3,0x20,200);
	  memcpy(c3,"ic_encrypt ok!",15);
	  m_list.InsertString(l,c3);
	  l++;
  }
  else
  {
	  m_list.InsertString(l,"ic_encrypt error! ");
	  l++;
	  goto end;

  }   
  
  st=ic_decrypt(keya,destin,8,source);
  if (st==0)
  {
	  memset(c3,0x20,200);
	  memcpy(c3,"ic_decrypt ok!",15);
	  m_list.InsertString(l,c3);
	  l++;
  }
  else
  {
	  m_list.InsertString(l,"ic_decrypt error!");
	  l++;
	  
  }   
end: ;

}

void CMwic_rdDlg::OnMENUITEMSamCard() 
{
	__int16 rlen;
	l=0;
    m_list.ResetContent();
	//复位
	memset(icRead,0,200);
	//DP函数
	/*CardType:0--上卡座
			 1-	下大卡座(sam1)
		     2-	小卡座(sam2)
		     3-	小卡座(sam3)*/
	if ((st=sam_slt_reset(icdev,1,&rlen,icRead))!=0)
	{
		memset(c3,0x00,200);
		_itoa(st,c3+4,10);
		memcpy(c3,"error",5);
		m_list.InsertString(l,c3);
		l++;
		goto end;
	}
	else
	{
		hex_asc(icRead,c1,rlen);
		memset(c3,0x20,200);
		memcpy(c3,"Reset:",6);
		memcpy(c3+8,c1,rlen*2);
		m_list.InsertString(l,c3);
		l++;
        
	}
	//取随机数
	icWrite[0]=0x00;
	icWrite[1]=0x40;
	icWrite[2]=0x05;
	icWrite[3]=0x00;
	icWrite[4]=0x84;
	icWrite[5]=0x00;
	icWrite[6]=0x00;
	icWrite[7]=0x08;
	icWrite[8]=0x00;


	for (st=0;st<8;st++)
		icWrite[8]=icWrite[8]^icWrite[st];
	if ((st=sam_slt_protocol(icdev,1,9,icWrite,&rlen,icRead))!=0)
	{
		memset(c3,0x00,16);
		_itoa(st,c3+4,10);
		memcpy(c3,"get random error",16);
		m_list.InsertString(l,c3);
		l++;
		goto end;
	}
	else
	{
		lenth=icRead[2];
		memset(c3,0x20,200);
		hex_asc(&icRead[3],c1,rlen);
		memcpy(c3,"Get random",10);
		memcpy(c3+13,c1,rlen*2);
		m_list.InsertString(l,c3);
		l++;
	}
end: ;
	
}
