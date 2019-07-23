// OperatingSystem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>


int _tmain(int argc, _TCHAR* argv[])
{
    SECURITY_ATTRIBUTES sa;
    sa.nLength = sizeof(sa);
    sa.lpSecurityDescriptor = NULL;
    sa.bInheritHandle = TRUE;       

    HANDLE h = CreateFile(_T("out.log"),
        FILE_APPEND_DATA,
        FILE_SHARE_WRITE | FILE_SHARE_READ,
        &sa,
        OPEN_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL );

    PROCESS_INFORMATION pi; 
    STARTUPINFO si;
    BOOL ret = FALSE; 
    DWORD flags = CREATE_NO_WINDOW;

    ZeroMemory( &pi, sizeof(PROCESS_INFORMATION) );
    ZeroMemory( &si, sizeof(STARTUPINFO) );
    si.cb = sizeof(STARTUPINFO); 
    si.dwFlags |= STARTF_USESTDHANDLES;
    si.hStdInput = NULL;
    si.hStdError = h;
    si.hStdOutput = h;



	
STARTUPINFO si;
PROCESS_INFORMATION pi;
ZeroMemory(&si, sizeof(si));
ZeroMemory(&pi, sizeof(pi));
si.cb = sizeof(si);
 
             CreateProcess( L"c:\\WINDOWS\\system32\\diskpart.exe",
                             L"diskpart.exe /s myScript.txt",
                             NULL,
                             NULL,
                             TRUE,
                             0,
                             NULL,
                             NULL,
                             &si,
                             &pi ) ;





    //TCHAR cmd[]= TEXT("Test.exe 30");
    //ret = CreateProcess(NULL, cmd, NULL, NULL, TRUE, flags, NULL, NULL, &si, &pi);

    if ( ret ) 
    {
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
        return 0;
    }
 	return 0;
}


/*



STARTUPINFO si;
PROCESS_INFORMATION pi;
ZeroMemory(&si, sizeof(si));
ZeroMemory(&pi, sizeof(pi));
si.cb = sizeof(si);
strncpy( command, "diskpart.exe /s myScript.txt", (sizeof(command) - 1) );  

             CreateProcess( "c:\\WINDOWS\\system32\\diskpart.exe",
                             command,
                             NULL,
                             NULL,
                             TRUE,
                             0,
                             NULL,
                             NULL,
                             &si,
                             &pi ) );



*/