Imports System
Imports System.Runtime.InteropServices

Public Class IC

    <DllImport("mwic_32.dll", EntryPoint:="ic_init", SetLastError:=True, CharSet:=CharSet.Auto, ExactSpelling:=True, CallingConvention:=CallingConvention.StdCall)> _
    Public Shared Function ic_init(ByVal port As Int16, ByVal baud As Integer) As Integer
    End Function

    <DllImport("mwic_32.dll", EntryPoint:="ic_exit", SetLastError:=True, CharSet:=CharSet.Auto, ExactSpelling:=True, CallingConvention:=CallingConvention.StdCall)> _
    Public Shared Function ic_exit(ByVal icdev As Integer) As Int16
    End Function

    <DllImport("mwic_32.dll", EntryPoint:="dv_beep", SetLastError:=True, CharSet:=CharSet.Auto, ExactSpelling:=True, CallingConvention:=CallingConvention.StdCall)> _
    Public Shared Function dv_beep(ByVal icdev As Integer, ByVal msec As Integer) As Int16
    End Function

    <DllImport("mwic_32.dll", EntryPoint:="get_status", SetLastError:=True, CharSet:=CharSet.Auto, ExactSpelling:=True, CallingConvention:=CallingConvention.StdCall)> _
    Public Shared Function get_status(ByVal icdev As Integer, ByRef status As Int16) As Int16
    End Function

    <DllImport("mwic_32.dll", EntryPoint:="lib_ver", SetLastError:=True, CharSet:=CharSet.Auto, ExactSpelling:=True, CallingConvention:=CallingConvention.StdCall)> _
    Public Shared Function lib_ver(<MarshalAs(UnmanagedType.LPArray)> ByVal ver() As Byte) As Int16
    End Function

    <DllImport("mwic_32.dll", EntryPoint:="srd_ver", SetLastError:=True, CharSet:=CharSet.Auto, ExactSpelling:=True, CallingConvention:=CallingConvention.StdCall)> _
    Public Shared Function srd_ver(ByVal icdev As Integer, ByVal len As Int16, <MarshalAs(UnmanagedType.LPArray)> ByVal databuff() As Byte) As Int16
    End Function

    <DllImport("mwic_32.dll", EntryPoint:="asc_hex", SetLastError:=True, CharSet:=CharSet.Auto, ExactSpelling:=True, CallingConvention:=CallingConvention.StdCall)> _
    Public Shared Function asc_hex(<MarshalAs(UnmanagedType.LPArray)> ByVal asc() As Byte, <MarshalAs(UnmanagedType.LPArray)> ByVal hex() As Byte, ByVal pair_len As Integer) As Int16
    End Function

    <DllImport("mwic_32.dll", EntryPoint:="hex_asc", SetLastError:=True, CharSet:=CharSet.Auto, ExactSpelling:=True, CallingConvention:=CallingConvention.StdCall)> _
    Public Shared Function hex_asc(<MarshalAs(UnmanagedType.LPArray)> ByVal hex() As Byte, <MarshalAs(UnmanagedType.LPArray)> ByVal asc() As Byte, ByVal len As Integer) As Int16
    End Function

End Class
