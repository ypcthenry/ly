Imports System
Imports System.Runtime.InteropServices

Public Class IC4442

    <DllImport("mwic_32.dll", EntryPoint:="srd_4442", SetLastError:=True, CharSet:=CharSet.Auto, ExactSpelling:=True, CallingConvention:=CallingConvention.StdCall)> _
    Public Shared Function srd_4442(ByVal icdev As Integer, ByVal offset As Int16, ByVal len As Int16, <MarshalAs(UnmanagedType.LPArray)> ByVal databuff() As Byte) As Int16
    End Function

    <DllImport("mwic_32.dll", EntryPoint:="swr_4442", SetLastError:=True, CharSet:=CharSet.Auto, ExactSpelling:=True, CallingConvention:=CallingConvention.StdCall)> _
    Public Shared Function swr_4442(ByVal icdev As Integer, ByVal offset As Int16, ByVal len As Int16, <MarshalAs(UnmanagedType.LPArray)> ByVal databuff() As Byte) As Int16
    End Function

    <DllImport("mwic_32.dll", EntryPoint:="prd_4442", SetLastError:=True, CharSet:=CharSet.Auto, ExactSpelling:=True, CallingConvention:=CallingConvention.StdCall)> _
    Public Shared Function prd_4442(ByVal icdev As Integer, ByVal len As Int16, <MarshalAs(UnmanagedType.LPArray)> ByVal databuff() As Byte) As Int16
    End Function

    <DllImport("mwic_32.dll", EntryPoint:="pwr_4442", SetLastError:=True, CharSet:=CharSet.Auto, ExactSpelling:=True, CallingConvention:=CallingConvention.StdCall)> _
    Public Shared Function pwr_4442(ByVal icdev As Integer, ByVal offset As Int16, ByVal len As Int16, <MarshalAs(UnmanagedType.LPArray)> ByVal databuff() As Byte) As Int16
    End Function

    <DllImport("mwic_32.dll", EntryPoint:="csc_4442", SetLastError:=True, CharSet:=CharSet.Auto, ExactSpelling:=True, CallingConvention:=CallingConvention.StdCall)> _
    Public Shared Function csc_4442(ByVal icdev As Integer, ByVal len As Int16, <MarshalAs(UnmanagedType.LPArray)> ByVal databuff() As Byte) As Int16
    End Function

    <DllImport("mwic_32.dll", EntryPoint:="wsc_4442", SetLastError:=True, CharSet:=CharSet.Auto, ExactSpelling:=True, CallingConvention:=CallingConvention.StdCall)> _
    Public Shared Function wsc_4442(ByVal icdev As Integer, ByVal len As Int16, <MarshalAs(UnmanagedType.LPArray)> ByVal databuff() As Byte) As Int16
    End Function

    <DllImport("mwic_32.dll", EntryPoint:="rsc_4442", SetLastError:=True, CharSet:=CharSet.Auto, ExactSpelling:=True, CallingConvention:=CallingConvention.StdCall)> _
    Public Shared Function rsc_4442(ByVal icdev As Integer, ByVal len As Int16, <MarshalAs(UnmanagedType.LPArray)> ByVal databuff() As Byte) As Int16
    End Function

    <DllImport("mwic_32.dll", EntryPoint:="rsct_4442", SetLastError:=True, CharSet:=CharSet.Auto, ExactSpelling:=True, CallingConvention:=CallingConvention.StdCall)> _
    Public Shared Function rsct_4442(ByVal icdev As Integer, ByRef counter As Int16) As Int16
    End Function

    <DllImport("mwic_32.dll", EntryPoint:="chk_4442", SetLastError:=True, CharSet:=CharSet.Auto, ExactSpelling:=True, CallingConvention:=CallingConvention.StdCall)> _
    Public Shared Function chk_4442(ByVal icdev As Integer, ByRef counter As Int16) As Int16
    End Function

End Class
