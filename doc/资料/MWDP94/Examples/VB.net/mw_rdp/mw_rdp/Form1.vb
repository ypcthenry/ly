
Public Class Form1
    Inherits System.Windows.Forms.Form

#Region " Windows 窗体设计器生成的代码 "

    Public Sub New()
        MyBase.New()

        '该调用是 Windows 窗体设计器所必需的。
        InitializeComponent()

        '在 InitializeComponent() 调用之后添加任何初始化
        comboPort.Items.Add("COM1")
        comboPort.Items.Add("COM2")
        comboPort.Items.Add("COM3")
        comboPort.Items.Add("COM4")
        comboBaud.Items.Add("9600")
        comboBaud.Items.Add("19200")
        comboBaud.Items.Add("38400")
        comboBaud.Items.Add("57600")
        comboBaud.Items.Add("115200")
        comboPort.SelectedIndex = 0
        comboBaud.SelectedIndex = 4

        textKey.Text = "ffffff"
        textData.Text = "00112233445566778899aabbccddeeff"

    End Sub

    '窗体重写 dispose 以清理组件列表。
    Protected Overloads Overrides Sub Dispose(ByVal disposing As Boolean)
        If disposing Then
            If Not (components Is Nothing) Then
                components.Dispose()
            End If
        End If
        MyBase.Dispose(disposing)
    End Sub

    'Windows 窗体设计器所必需的
    Private components As System.ComponentModel.IContainer

    '注意: 以下过程是 Windows 窗体设计器所必需的
    '可以使用 Windows 窗体设计器修改此过程。
    '不要使用代码编辑器修改它。
    Friend WithEvents lbSoftVer As System.Windows.Forms.Label
    Friend WithEvents lbHardVer As System.Windows.Forms.Label
    Friend WithEvents label2 As System.Windows.Forms.Label
    Friend WithEvents lbBaud As System.Windows.Forms.Label
    Friend WithEvents lbPort As System.Windows.Forms.Label
    Friend WithEvents comboBaud As System.Windows.Forms.ComboBox
    Friend WithEvents comboPort As System.Windows.Forms.ComboBox
    Friend WithEvents label1 As System.Windows.Forms.Label
    Friend WithEvents btnDisconnect As System.Windows.Forms.Button
    Friend WithEvents btnConnect As System.Windows.Forms.Button
    Friend WithEvents groupBox1 As System.Windows.Forms.GroupBox
    Friend WithEvents btnBeep As System.Windows.Forms.Button
    Friend WithEvents lbResult As System.Windows.Forms.Label
    Friend WithEvents label3 As System.Windows.Forms.Label
    Friend WithEvents groupBox2 As System.Windows.Forms.GroupBox
    Friend WithEvents btnWriteData As System.Windows.Forms.Button
    Friend WithEvents btnReadData As System.Windows.Forms.Button
    Friend WithEvents textData As System.Windows.Forms.TextBox
    Friend WithEvents label6 As System.Windows.Forms.Label
    Friend WithEvents textKey As System.Windows.Forms.TextBox
    Friend WithEvents label5 As System.Windows.Forms.Label
    Friend WithEvents btnVerify As System.Windows.Forms.Button
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents lbData As System.Windows.Forms.Label
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Me.lbSoftVer = New System.Windows.Forms.Label
        Me.lbHardVer = New System.Windows.Forms.Label
        Me.label2 = New System.Windows.Forms.Label
        Me.lbBaud = New System.Windows.Forms.Label
        Me.lbPort = New System.Windows.Forms.Label
        Me.comboBaud = New System.Windows.Forms.ComboBox
        Me.comboPort = New System.Windows.Forms.ComboBox
        Me.label1 = New System.Windows.Forms.Label
        Me.btnDisconnect = New System.Windows.Forms.Button
        Me.btnConnect = New System.Windows.Forms.Button
        Me.groupBox1 = New System.Windows.Forms.GroupBox
        Me.btnBeep = New System.Windows.Forms.Button
        Me.lbResult = New System.Windows.Forms.Label
        Me.label3 = New System.Windows.Forms.Label
        Me.groupBox2 = New System.Windows.Forms.GroupBox
        Me.Label4 = New System.Windows.Forms.Label
        Me.btnWriteData = New System.Windows.Forms.Button
        Me.btnReadData = New System.Windows.Forms.Button
        Me.btnVerify = New System.Windows.Forms.Button
        Me.textData = New System.Windows.Forms.TextBox
        Me.label6 = New System.Windows.Forms.Label
        Me.textKey = New System.Windows.Forms.TextBox
        Me.label5 = New System.Windows.Forms.Label
        Me.lbData = New System.Windows.Forms.Label
        Me.groupBox1.SuspendLayout()
        Me.groupBox2.SuspendLayout()
        Me.SuspendLayout()
        '
        'lbSoftVer
        '
        Me.lbSoftVer.Location = New System.Drawing.Point(120, 152)
        Me.lbSoftVer.Name = "lbSoftVer"
        Me.lbSoftVer.Size = New System.Drawing.Size(192, 20)
        Me.lbSoftVer.TabIndex = 20
        Me.lbSoftVer.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'lbHardVer
        '
        Me.lbHardVer.Location = New System.Drawing.Point(120, 120)
        Me.lbHardVer.Name = "lbHardVer"
        Me.lbHardVer.Size = New System.Drawing.Size(192, 20)
        Me.lbHardVer.TabIndex = 19
        Me.lbHardVer.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'label2
        '
        Me.label2.Location = New System.Drawing.Point(32, 152)
        Me.label2.Name = "label2"
        Me.label2.Size = New System.Drawing.Size(72, 20)
        Me.label2.TabIndex = 18
        Me.label2.Text = "软件版本号"
        Me.label2.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'lbBaud
        '
        Me.lbBaud.Location = New System.Drawing.Point(32, 80)
        Me.lbBaud.Name = "lbBaud"
        Me.lbBaud.Size = New System.Drawing.Size(72, 20)
        Me.lbBaud.TabIndex = 16
        Me.lbBaud.Text = "波特率"
        Me.lbBaud.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'lbPort
        '
        Me.lbPort.Location = New System.Drawing.Point(32, 40)
        Me.lbPort.Name = "lbPort"
        Me.lbPort.Size = New System.Drawing.Size(72, 20)
        Me.lbPort.TabIndex = 15
        Me.lbPort.Text = "端口"
        Me.lbPort.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'comboBaud
        '
        Me.comboBaud.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.comboBaud.Location = New System.Drawing.Point(120, 80)
        Me.comboBaud.Name = "comboBaud"
        Me.comboBaud.Size = New System.Drawing.Size(121, 20)
        Me.comboBaud.TabIndex = 14
        '
        'comboPort
        '
        Me.comboPort.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.comboPort.Location = New System.Drawing.Point(120, 40)
        Me.comboPort.Name = "comboPort"
        Me.comboPort.Size = New System.Drawing.Size(121, 20)
        Me.comboPort.TabIndex = 13
        '
        'label1
        '
        Me.label1.Location = New System.Drawing.Point(32, 120)
        Me.label1.Name = "label1"
        Me.label1.Size = New System.Drawing.Size(72, 20)
        Me.label1.TabIndex = 17
        Me.label1.Text = "硬件版本号"
        Me.label1.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'btnDisconnect
        '
        Me.btnDisconnect.Location = New System.Drawing.Point(320, 80)
        Me.btnDisconnect.Name = "btnDisconnect"
        Me.btnDisconnect.TabIndex = 12
        Me.btnDisconnect.Text = "断开连接"
        '
        'btnConnect
        '
        Me.btnConnect.Location = New System.Drawing.Point(320, 40)
        Me.btnConnect.Name = "btnConnect"
        Me.btnConnect.TabIndex = 11
        Me.btnConnect.Text = "连接"
        '
        'groupBox1
        '
        Me.groupBox1.Controls.Add(Me.btnBeep)
        Me.groupBox1.Location = New System.Drawing.Point(16, 16)
        Me.groupBox1.Name = "groupBox1"
        Me.groupBox1.Size = New System.Drawing.Size(408, 176)
        Me.groupBox1.TabIndex = 21
        Me.groupBox1.TabStop = False
        Me.groupBox1.Text = "初始化串口"
        '
        'btnBeep
        '
        Me.btnBeep.Location = New System.Drawing.Point(304, 104)
        Me.btnBeep.Name = "btnBeep"
        Me.btnBeep.TabIndex = 0
        Me.btnBeep.Text = "蜂鸣"
        '
        'lbResult
        '
        Me.lbResult.Location = New System.Drawing.Point(104, 384)
        Me.lbResult.Name = "lbResult"
        Me.lbResult.Size = New System.Drawing.Size(288, 23)
        Me.lbResult.TabIndex = 24
        '
        'label3
        '
        Me.label3.Location = New System.Drawing.Point(16, 384)
        Me.label3.Name = "label3"
        Me.label3.Size = New System.Drawing.Size(72, 23)
        Me.label3.TabIndex = 23
        Me.label3.Text = "状态提示："
        Me.label3.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'groupBox2
        '
        Me.groupBox2.Controls.Add(Me.Label4)
        Me.groupBox2.Controls.Add(Me.btnWriteData)
        Me.groupBox2.Controls.Add(Me.btnReadData)
        Me.groupBox2.Controls.Add(Me.btnVerify)
        Me.groupBox2.Controls.Add(Me.textData)
        Me.groupBox2.Controls.Add(Me.label6)
        Me.groupBox2.Controls.Add(Me.textKey)
        Me.groupBox2.Controls.Add(Me.label5)
        Me.groupBox2.Controls.Add(Me.lbData)
        Me.groupBox2.Location = New System.Drawing.Point(16, 208)
        Me.groupBox2.Name = "groupBox2"
        Me.groupBox2.Size = New System.Drawing.Size(408, 160)
        Me.groupBox2.TabIndex = 22
        Me.groupBox2.TabStop = False
        Me.groupBox2.Text = "SLE4442卡操作"
        '
        'Label4
        '
        Me.Label4.Location = New System.Drawing.Point(16, 112)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(64, 23)
        Me.Label4.TabIndex = 15
        Me.Label4.Text = "数据"
        Me.Label4.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'btnWriteData
        '
        Me.btnWriteData.Location = New System.Drawing.Point(320, 112)
        Me.btnWriteData.Name = "btnWriteData"
        Me.btnWriteData.TabIndex = 13
        Me.btnWriteData.Text = "写数据"
        '
        'btnReadData
        '
        Me.btnReadData.Location = New System.Drawing.Point(320, 72)
        Me.btnReadData.Name = "btnReadData"
        Me.btnReadData.TabIndex = 12
        Me.btnReadData.Text = "读数据"
        '
        'btnVerify
        '
        Me.btnVerify.Location = New System.Drawing.Point(320, 32)
        Me.btnVerify.Name = "btnVerify"
        Me.btnVerify.TabIndex = 11
        Me.btnVerify.Text = "密码校验"
        '
        'textData
        '
        Me.textData.Location = New System.Drawing.Point(88, 112)
        Me.textData.Name = "textData"
        Me.textData.Size = New System.Drawing.Size(224, 21)
        Me.textData.TabIndex = 10
        Me.textData.Text = ""
        '
        'label6
        '
        Me.label6.Location = New System.Drawing.Point(16, 72)
        Me.label6.Name = "label6"
        Me.label6.Size = New System.Drawing.Size(64, 23)
        Me.label6.TabIndex = 5
        Me.label6.Text = "数据"
        Me.label6.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'textKey
        '
        Me.textKey.Location = New System.Drawing.Point(88, 32)
        Me.textKey.Name = "textKey"
        Me.textKey.Size = New System.Drawing.Size(136, 21)
        Me.textKey.TabIndex = 4
        Me.textKey.Text = ""
        '
        'label5
        '
        Me.label5.Location = New System.Drawing.Point(16, 32)
        Me.label5.Name = "label5"
        Me.label5.Size = New System.Drawing.Size(64, 23)
        Me.label5.TabIndex = 3
        Me.label5.Text = "密码"
        Me.label5.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'lbData
        '
        Me.lbData.Location = New System.Drawing.Point(88, 72)
        Me.lbData.Name = "lbData"
        Me.lbData.Size = New System.Drawing.Size(224, 24)
        Me.lbData.TabIndex = 1
        Me.lbData.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'Form1
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(6, 14)
        Me.ClientSize = New System.Drawing.Size(440, 421)
        Me.Controls.Add(Me.lbResult)
        Me.Controls.Add(Me.label3)
        Me.Controls.Add(Me.groupBox2)
        Me.Controls.Add(Me.lbSoftVer)
        Me.Controls.Add(Me.lbHardVer)
        Me.Controls.Add(Me.label2)
        Me.Controls.Add(Me.lbBaud)
        Me.Controls.Add(Me.lbPort)
        Me.Controls.Add(Me.comboBaud)
        Me.Controls.Add(Me.comboPort)
        Me.Controls.Add(Me.label1)
        Me.Controls.Add(Me.btnDisconnect)
        Me.Controls.Add(Me.btnConnect)
        Me.Controls.Add(Me.groupBox1)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.groupBox1.ResumeLayout(False)
        Me.groupBox2.ResumeLayout(False)
        Me.ResumeLayout(False)

    End Sub

#End Region

    Dim icdev As Integer
    Dim st As Int16
    Dim sec As Integer
    Dim i As Integer
    Private Sub btnConnect_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnConnect.Click
        Dim baudarray(5) As Integer
        Dim ver(30) As Byte
        Dim sver As String
        Dim port As Int16
        Dim baud As Integer
        st = 0
        i = 0

        baudarray(0) = 9600
        baudarray(1) = 19200
        baudarray(2) = 38400
        baudarray(3) = 57600
        baudarray(4) = 115200

        For i = 0 To 29
            ver(i) = 0
        Next

        st = IC.lib_ver(ver)
        sver = System.Text.Encoding.ASCII.GetString(ver)
        lbSoftVer.Text = sver

        port = 0
        baud = 9600
        port = comboPort.SelectedIndex
        Dim nitem As Integer
        nitem = comboBaud.SelectedIndex
        baud = baudarray(nitem)

        icdev = IC.ic_init(port, baud)
        If icdev > 0 Then
            lbResult.Text = "打开串口成功！"
            Dim status As Int16

            st = IC.get_status(icdev, status)
            If st <> 0 Then
                lbResult.Text = "获取设备状态失败！"
                Return
            End If

            st = IC.srd_ver(icdev, 18, ver)
            If st <> 0 Then
                lbResult.Text = "读取硬件版本号失败！"
                Return
            End If
            lbHardVer.Text = System.Text.Encoding.ASCII.GetString(ver)

            Return
        End If

        lbResult.Text = "打开串口失败！"
    End Sub

    Private Sub btnDisconnect_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnDisconnect.Click
        st = IC.ic_exit(icdev)
        '        If st <> 0 Then
        '       lbResult.Text = "断开连接失败！"
        '      Return
        '     End If
        '    lbResult.Text = "断开连接成功！"
        If st = 0 Then
            lbResult.Text = "断开连接成功！"
            Return
        End If
        lbResult.Text = "断开连接失败！"
    End Sub

    Private Sub btnBeep_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnBeep.Click
        st = IC.dv_beep(icdev, 10)
        If st <> 0 Then
            lbResult.Text = "蜂鸣失败！"
            Return
        End If
        lbResult.Text = "蜂鸣成功！"
    End Sub


    Private Sub btnReadData_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnReadData.Click
        Dim data(16) As Byte
        Dim buff(32) As Byte
        For i = 0 To 15
            data(i) = 0
        Next
        For i = 0 To 31
            buff(i) = 0
        Next

        st = IC4442.srd_4442(icdev, 64, 16, data)
        If st <> 0 Then
            lbResult.Text = "读数据失败！"
        Else
            IC.hex_asc(data, buff, 16)
            lbData.Text = System.Text.Encoding.ASCII.GetString(buff)
            lbResult.Text = "读数据成功！"
        End If
    End Sub

    Private Sub btnWriteData_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnWriteData.Click
        Dim databuff(16) As Byte
        Dim buff(32) As Byte
        Dim data As String
        For i = 0 To 15
            databuff(i) = 0
        Next
        For i = 0 To 31
            buff(i) = 0
        Next
        data = ""

        If textData.TextLength <> 32 Then
            lbResult.Text = "请正确输入数据，数据长度必须为16字节！"
            Return
        End If
        data = textData.Text
        For i = 0 To data.Length - 1
            If System.Char.IsLetter(data.Chars(i)) Then
                If System.Char.IsLower(data.Chars(i)) Then
                    If data.Chars(i) < "a" Then
                        Exit For
                    End If
                    If data.Chars(i) > "f" Then
                        Exit For
                    End If
                Else
                    If data.Chars(i) < "A" Then
                        Exit For
                    End If
                    If data.Chars(i) > "F" Then
                        Exit For
                    End If
                End If
            End If
        Next

        If i <> data.Length Then
            lbResult.Text = "数据必须为十六进制数！"
            Return
        End If

        buff = System.Text.Encoding.ASCII.GetBytes(data)
        IC.asc_hex(buff, databuff, 16)
        st = IC4442.swr_4442(icdev, 64, 16, databuff)
        If st <> 0 Then
            lbResult.Text = "写数据失败！"
        Else
            lbResult.Text = "写数据成功！"
        End If
    End Sub

    Protected Overrides Sub Finalize()
        If icdev > 0 Then
            IC.ic_exit(icdev)
        End If
        MyBase.Finalize()
    End Sub


    Private Sub btnVerify_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnVerify.Click
        Dim key1(7) As Byte
        Dim key2(4) As Byte
        For i = 0 To 6
            key1(i) = 0
        Next
        For i = 0 To 3
            key2(i) = 0
        Next

        Dim skey As String
        skey = ""
        skey = textKey.Text
        Dim keylen As Integer
        keylen = 0
        keylen = textKey.TextLength
        If keylen <> 6 Then
            lbResult.Text = "请正确输入密码，密码长度必须为3字节！"
            Return
        End If

        For i = 0 To keylen - 1
            If System.Char.IsLetter(skey.Chars(i)) Then
                If System.Char.IsLower(skey.Chars(i)) Then
                    If skey.Chars(i) < "a" Then
                        Exit For
                    End If
                    If skey.Chars(i) > "f" Then
                        Exit For
                    End If
                Else
                    If skey.Chars(i) < "A" Then
                        Exit For
                    End If
                    If skey.Chars(i) > "F" Then
                        Exit For
                    End If
                End If
            End If
        Next


        If i <> keylen Then
            lbResult.Text = "密码必须为十六进制数！"
            Return
        End If

        key1 = System.Text.Encoding.ASCII.GetBytes(skey)
        IC.asc_hex(key1, key2, 3)
        st = IC4442.csc_4442(icdev, 3, key2)
        If st <> 0 Then
            lbResult.Text = "密码校验失败！"
            Return
        End If
        lbResult.Text = "密码校验成功！"

    End Sub


End Class
