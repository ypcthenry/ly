using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;

using System.Runtime.InteropServices;
using System.Text;

namespace mw_rdp
{
	/// <summary>
	/// Form1 的摘要说明。
	/// </summary>
	public class Form1 : System.Windows.Forms.Form
	{
		private System.Windows.Forms.Button btnConnect;
		private System.Windows.Forms.Button btnDisconnect;
		private System.Windows.Forms.Label lbPort;
		private System.Windows.Forms.Label lbBaud;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Label lbHardVer;
		private System.Windows.Forms.Label lbSoftVer;
		private System.Windows.Forms.GroupBox groupBox1;
		private System.Windows.Forms.Button btnBeep;
		private System.Windows.Forms.GroupBox groupBox2;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.Label lbResult;
		private System.Windows.Forms.Label label5;
		private System.Windows.Forms.Label label6;
		private System.Windows.Forms.Button btnReadData;
		private System.Windows.Forms.Button btnWriteData;
		private System.Windows.Forms.ComboBox comboPort;
		private System.Windows.Forms.ComboBox comboBaud;
		private System.Windows.Forms.TextBox textKey;
		private System.Windows.Forms.TextBox textData;
		private System.Windows.Forms.Label lbData;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.Button btnVerify;
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		private System.ComponentModel.Container components = null;

		public Form1()
		{
			//
			// Windows 窗体设计器支持所必需的
			//
			InitializeComponent();

			//
			// TODO: 在 InitializeComponent 调用后添加任何构造函数代码
			//
			comboPort.Items.Add("COM1");
			comboPort.Items.Add("COM2");
			comboPort.Items.Add("COM3");
			comboPort.Items.Add("COM4");
			comboBaud.Items.Add("9600");
			comboBaud.Items.Add("19200");
			comboBaud.Items.Add("38400");
			comboBaud.Items.Add("57600");
			comboBaud.Items.Add("115200");
			comboPort.SelectedIndex=0;
			comboBaud.SelectedIndex=4;

			textKey.Text="ffffff";
			textData.Text="00112233445566778899aabbccddeeff";

		}

		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		protected override void Dispose( bool disposing )
		{
			if( disposing )
			{
				if (components != null) 
				{
					components.Dispose();
				}
			}
			base.Dispose( disposing );
		}

		#region Windows 窗体设计器生成的代码
		/// <summary>
		/// 设计器支持所需的方法 - 不要使用代码编辑器修改
		/// 此方法的内容。
		/// </summary>
		private void InitializeComponent()
		{
			this.btnConnect = new System.Windows.Forms.Button();
			this.btnDisconnect = new System.Windows.Forms.Button();
			this.comboPort = new System.Windows.Forms.ComboBox();
			this.comboBaud = new System.Windows.Forms.ComboBox();
			this.lbPort = new System.Windows.Forms.Label();
			this.lbBaud = new System.Windows.Forms.Label();
			this.label1 = new System.Windows.Forms.Label();
			this.label2 = new System.Windows.Forms.Label();
			this.lbHardVer = new System.Windows.Forms.Label();
			this.lbSoftVer = new System.Windows.Forms.Label();
			this.groupBox1 = new System.Windows.Forms.GroupBox();
			this.btnBeep = new System.Windows.Forms.Button();
			this.groupBox2 = new System.Windows.Forms.GroupBox();
			this.label4 = new System.Windows.Forms.Label();
			this.btnWriteData = new System.Windows.Forms.Button();
			this.btnReadData = new System.Windows.Forms.Button();
			this.btnVerify = new System.Windows.Forms.Button();
			this.textData = new System.Windows.Forms.TextBox();
			this.label6 = new System.Windows.Forms.Label();
			this.textKey = new System.Windows.Forms.TextBox();
			this.label5 = new System.Windows.Forms.Label();
			this.lbData = new System.Windows.Forms.Label();
			this.label3 = new System.Windows.Forms.Label();
			this.lbResult = new System.Windows.Forms.Label();
			this.groupBox1.SuspendLayout();
			this.groupBox2.SuspendLayout();
			this.SuspendLayout();
			// 
			// btnConnect
			// 
			this.btnConnect.Location = new System.Drawing.Point(312, 32);
			this.btnConnect.Name = "btnConnect";
			this.btnConnect.TabIndex = 0;
			this.btnConnect.Text = "连接";
			this.btnConnect.Click += new System.EventHandler(this.btnConnect_Click);
			// 
			// btnDisconnect
			// 
			this.btnDisconnect.Location = new System.Drawing.Point(312, 72);
			this.btnDisconnect.Name = "btnDisconnect";
			this.btnDisconnect.TabIndex = 1;
			this.btnDisconnect.Text = "断开连接";
			this.btnDisconnect.Click += new System.EventHandler(this.btnDisconnect_Click);
			// 
			// comboPort
			// 
			this.comboPort.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.comboPort.Location = new System.Drawing.Point(120, 32);
			this.comboPort.Name = "comboPort";
			this.comboPort.Size = new System.Drawing.Size(121, 20);
			this.comboPort.TabIndex = 2;
			// 
			// comboBaud
			// 
			this.comboBaud.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.comboBaud.Location = new System.Drawing.Point(120, 72);
			this.comboBaud.Name = "comboBaud";
			this.comboBaud.Size = new System.Drawing.Size(121, 20);
			this.comboBaud.TabIndex = 3;
			// 
			// lbPort
			// 
			this.lbPort.Location = new System.Drawing.Point(24, 32);
			this.lbPort.Name = "lbPort";
			this.lbPort.Size = new System.Drawing.Size(72, 20);
			this.lbPort.TabIndex = 4;
			this.lbPort.Text = "端口";
			this.lbPort.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
			// 
			// lbBaud
			// 
			this.lbBaud.Location = new System.Drawing.Point(24, 72);
			this.lbBaud.Name = "lbBaud";
			this.lbBaud.Size = new System.Drawing.Size(72, 20);
			this.lbBaud.TabIndex = 5;
			this.lbBaud.Text = "波特率";
			this.lbBaud.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
			// 
			// label1
			// 
			this.label1.Location = new System.Drawing.Point(24, 112);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(80, 20);
			this.label1.TabIndex = 6;
			this.label1.Text = "硬件版本号";
			this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
			// 
			// label2
			// 
			this.label2.Location = new System.Drawing.Point(24, 144);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(72, 20);
			this.label2.TabIndex = 7;
			this.label2.Text = "软件版本号";
			this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
			// 
			// lbHardVer
			// 
			this.lbHardVer.Location = new System.Drawing.Point(120, 112);
			this.lbHardVer.Name = "lbHardVer";
			this.lbHardVer.Size = new System.Drawing.Size(184, 20);
			this.lbHardVer.TabIndex = 8;
			this.lbHardVer.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
			// 
			// lbSoftVer
			// 
			this.lbSoftVer.Location = new System.Drawing.Point(120, 144);
			this.lbSoftVer.Name = "lbSoftVer";
			this.lbSoftVer.Size = new System.Drawing.Size(184, 20);
			this.lbSoftVer.TabIndex = 9;
			this.lbSoftVer.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
			// 
			// groupBox1
			// 
			this.groupBox1.Controls.Add(this.btnBeep);
			this.groupBox1.Location = new System.Drawing.Point(8, 8);
			this.groupBox1.Name = "groupBox1";
			this.groupBox1.Size = new System.Drawing.Size(408, 176);
			this.groupBox1.TabIndex = 10;
			this.groupBox1.TabStop = false;
			this.groupBox1.Text = "初始化串口";
			// 
			// btnBeep
			// 
			this.btnBeep.Location = new System.Drawing.Point(304, 104);
			this.btnBeep.Name = "btnBeep";
			this.btnBeep.TabIndex = 0;
			this.btnBeep.Text = "蜂鸣";
			this.btnBeep.Click += new System.EventHandler(this.btnBeep_Click);
			// 
			// groupBox2
			// 
			this.groupBox2.Controls.Add(this.label4);
			this.groupBox2.Controls.Add(this.btnWriteData);
			this.groupBox2.Controls.Add(this.btnReadData);
			this.groupBox2.Controls.Add(this.btnVerify);
			this.groupBox2.Controls.Add(this.textData);
			this.groupBox2.Controls.Add(this.label6);
			this.groupBox2.Controls.Add(this.textKey);
			this.groupBox2.Controls.Add(this.label5);
			this.groupBox2.Controls.Add(this.lbData);
			this.groupBox2.Location = new System.Drawing.Point(8, 200);
			this.groupBox2.Name = "groupBox2";
			this.groupBox2.Size = new System.Drawing.Size(408, 168);
			this.groupBox2.TabIndex = 11;
			this.groupBox2.TabStop = false;
			this.groupBox2.Text = "SLE4442卡操作";
			// 
			// label4
			// 
			this.label4.Location = new System.Drawing.Point(16, 72);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(64, 23);
			this.label4.TabIndex = 15;
			this.label4.Text = "数据";
			this.label4.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
			// 
			// btnWriteData
			// 
			this.btnWriteData.Location = new System.Drawing.Point(320, 120);
			this.btnWriteData.Name = "btnWriteData";
			this.btnWriteData.TabIndex = 13;
			this.btnWriteData.Text = "写数据";
			this.btnWriteData.Click += new System.EventHandler(this.btnWriteData_Click);
			// 
			// btnReadData
			// 
			this.btnReadData.Location = new System.Drawing.Point(320, 72);
			this.btnReadData.Name = "btnReadData";
			this.btnReadData.TabIndex = 12;
			this.btnReadData.Text = "读数据";
			this.btnReadData.Click += new System.EventHandler(this.btnReadData_Click);
			// 
			// btnVerify
			// 
			this.btnVerify.Location = new System.Drawing.Point(320, 24);
			this.btnVerify.Name = "btnVerify";
			this.btnVerify.TabIndex = 11;
			this.btnVerify.Text = "密码验证";
			this.btnVerify.Click += new System.EventHandler(this.btnVerify_Click);
			// 
			// textData
			// 
			this.textData.Location = new System.Drawing.Point(96, 120);
			this.textData.Name = "textData";
			this.textData.Size = new System.Drawing.Size(216, 21);
			this.textData.TabIndex = 10;
			this.textData.Text = "";
			// 
			// label6
			// 
			this.label6.Location = new System.Drawing.Point(16, 120);
			this.label6.Name = "label6";
			this.label6.Size = new System.Drawing.Size(64, 23);
			this.label6.TabIndex = 5;
			this.label6.Text = "数据";
			this.label6.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
			// 
			// textKey
			// 
			this.textKey.Location = new System.Drawing.Point(96, 24);
			this.textKey.Name = "textKey";
			this.textKey.Size = new System.Drawing.Size(120, 21);
			this.textKey.TabIndex = 4;
			this.textKey.Text = "";
			// 
			// label5
			// 
			this.label5.Location = new System.Drawing.Point(16, 24);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(64, 23);
			this.label5.TabIndex = 3;
			this.label5.Text = "密码";
			this.label5.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
			// 
			// lbData
			// 
			this.lbData.Location = new System.Drawing.Point(104, 72);
			this.lbData.Name = "lbData";
			this.lbData.Size = new System.Drawing.Size(208, 20);
			this.lbData.TabIndex = 1;
			this.lbData.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
			// 
			// label3
			// 
			this.label3.Location = new System.Drawing.Point(8, 384);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(72, 23);
			this.label3.TabIndex = 12;
			this.label3.Text = "状态提示：";
			this.label3.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
			// 
			// lbResult
			// 
			this.lbResult.Location = new System.Drawing.Point(96, 384);
			this.lbResult.Name = "lbResult";
			this.lbResult.Size = new System.Drawing.Size(288, 23);
			this.lbResult.TabIndex = 13;
			// 
			// Form1
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(6, 14);
			this.ClientSize = new System.Drawing.Size(432, 429);
			this.Controls.Add(this.lbResult);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.groupBox2);
			this.Controls.Add(this.lbSoftVer);
			this.Controls.Add(this.lbHardVer);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.lbBaud);
			this.Controls.Add(this.lbPort);
			this.Controls.Add(this.comboBaud);
			this.Controls.Add(this.comboPort);
			this.Controls.Add(this.btnDisconnect);
			this.Controls.Add(this.btnConnect);
			this.Controls.Add(this.groupBox1);
			this.Name = "Form1";
			this.Text = "Form1";
			this.groupBox1.ResumeLayout(false);
			this.groupBox2.ResumeLayout(false);
			this.ResumeLayout(false);

		}
		#endregion

		/// <summary>
		/// 应用程序的主入口点。
		/// </summary>
		[STAThread]
		static void Main() 
		{
			Application.Run(new Form1());
		}

		public int icdev ; // 通讯设备标识符
		public Int16 st;
		public int sec;
		private void btnConnect_Click(object sender, System.EventArgs e)
		{
			st=0;
			byte[] ver=new byte[30];
			byte[] hard_ver=new byte[30];
			int[] baudarray=new int[5];
		    baudarray[0]=9600;
			baudarray[1]=19200;
			baudarray[2]=38400;
			baudarray[3]=57600;
			baudarray[4]=115200;
				
			st = IC.lib_ver(ver);
			string sver=System.Text.Encoding.ASCII.GetString(ver);
			lbSoftVer.Text=sver;

			Int16 port=0;
			int baud=9600;
			port=(Int16)comboPort.SelectedIndex;
			int nitem=comboBaud.SelectedIndex;
			baud = baudarray[nitem];

		    icdev = IC.ic_init(port, baud);
			if(icdev>0)
			{
				lbResult.Text="打开串口成功！";
				byte[] status=new byte[5];
				st = IC.get_status(icdev, status);
				if(st != 0)
					lbResult.Text="获取设备状态失败！";
				st = IC.srd_ver(icdev, 18, hard_ver);
				if(st == 0)
                    lbHardVer.Text=System.Text.Encoding.ASCII.GetString(hard_ver);
				else 
					lbResult.Text="读取硬件版本号失败！";
			}
			else
				lbResult.Text="打开串口失败！";	
		}

		private void btnDisconnect_Click(object sender, System.EventArgs e)
		{
		    st = IC.ic_exit(icdev);
			if(st==0)
				lbResult.Text="断开连接成功！";
			else
				lbResult.Text="断开连接失败！";
		}

		private void btnBeep_Click(object sender, System.EventArgs e)
		{
		    st = IC.dv_beep(icdev, 10);
			if(st==0)
				lbResult.Text="蜂鸣成功！";
			else
				lbResult.Text="蜂鸣失败！";
		}

		private void btnReadData_Click(object sender, System.EventArgs e)
		{
			int i=0;
			byte[] data=new byte[16];
			byte[] databuff=new byte[32];
			
			for(i=0;i<16;i++)
				data[i]=0;
			for(i=0;i<32;i++)
				databuff[i]=0;

			st = IC4442.srd_4442(icdev, 64, 16, data);
			if(st==0)
			{
				st = IC.hex_asc(data, databuff, 16);
				lbData.Text=System.Text.Encoding.ASCII.GetString(databuff);
				lbResult.Text="读数据成功！";
			}
			else
				lbResult.Text="读数据失败！";
		}

		private void btnWriteData_Click(object sender, System.EventArgs e)
		{
			int i=0;
			byte[] databuff=new byte[20];
			byte[] buff=new byte[40];

			if(textData.TextLength!=32)
			{
				lbResult.Text="请正确输入数据，数据长度必须为16字节！";
				return;
			}
			string data=textData.Text;
			for( i=0;i<data.Length;i++)
			{
				if(data[i]>='0'&&data[i]<='9')
					continue;
				if(data[i]<='a'&&data[i]<='f')
					continue;
				if(data[i]<='A'&&data[i]<='F')
					continue;
			}
			if(i!=data.Length)
			{
				lbResult.Text="数据必须为十六进制数！";
				return;
			}

			buff = Encoding.ASCII.GetBytes(data);
			IC.asc_hex(buff,databuff,32);
			st = IC4442.swr_4442(icdev, 64, 16, databuff);
			if(st==0)
				lbResult.Text="写数据成功！";
			else
				lbResult.Text="写数据失败！";
		}

		private void btnVerify_Click(object sender, System.EventArgs e)
		{
			byte[] key1=new byte[20];
			byte[] key2=new byte[20];
			int i=0;
			string skey=textKey.Text;
			int keylen=textKey.TextLength;
			if(keylen!=6)
			{
				lbResult.Text="请正确输入密码，密码长度不对！";
				return;
			}
			
			for( i=0;i<keylen;i++)
			{
				if(skey[i]>='0'&&skey[i]<='9')
					continue;
				if(skey[i]<='a'&&skey[i]<='f')
					continue;
				if(skey[i]<='A'&&skey[i]<='F')
					continue;
			}
			if(i!=keylen)
			{
				lbResult.Text="密码必须为十六进制数！";
				return;
			}

			key1=Encoding.ASCII.GetBytes(skey);
			IC.asc_hex(key1,key2,6);
			st = IC4442.csc_4442(icdev, 3, key2);
			if(st==0)
				lbResult.Text="密码校验成功！";
			else
				lbResult.Text="密码校验失败！";

		}


	}
}
