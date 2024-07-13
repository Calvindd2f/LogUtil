# CSharp usage example

Source code is in C++ and compiled with Zig c++.

```cs
using System;
using System.Runtime.InteropServices;
using System.Security;
using System.Runtime.CompilerServices;

internal static class LogUtil
{
    private const string DllName = "logutil.dll"; // or the full path to the DLL

    [SuppressUnmanagedCodeSecurity]
    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    [return: MarshalAs(UnmanagedType.U1)]
    internal static extern bool LogInfo(string shortMessage, [MarshalAs(UnmanagedType.U1)] bool detailedDescription);

    [SuppressUnmanagedCodeSecurity]
    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    [return: MarshalAs(UnmanagedType.U1)]
    internal static extern bool LogError(string shortMessage, [MarshalAs(UnmanagedType.U1)] bool detailedDescription);

    [SuppressUnmanagedCodeSecurity]
    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    [return: MarshalAs(UnmanagedType.U1)]
    internal static extern bool LogWarning(string shortMessage, [MarshalAs(UnmanagedType.U1)] bool detailedDescription);

    [SuppressUnmanagedCodeSecurity]
    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    [return: MarshalAs(UnmanagedType.U1)]
    internal static extern bool LogVerbose(string shortMessage, [MarshalAs(UnmanagedType.U1)] bool detailedDescription);

    [SuppressUnmanagedCodeSecurity]
    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    [return: MarshalAs(UnmanagedType.U1)]
    internal static extern bool LogDebug(string shortMessage, [MarshalAs(UnmanagedType.U1)] bool detailedDescription);
}

class Program
{
    static void Main()
    {
        LogUtil.LogInfo("Test Info", false);
        LogUtil.LogError("Test Error", true);
        LogUtil.LogWarning("Test Warning", false);
        LogUtil.LogVerbose("Test Verbose", true);
        LogUtil.LogDebug("Test Debug", false);

        Console.WriteLine("Logging completed.");
    }
}
```
