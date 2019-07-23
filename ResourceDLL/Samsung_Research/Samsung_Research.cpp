// Samsung_Research.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string.h>
#include<Windows.h>
#include "resource.h"

using namespace std;
/*
int main()
{
	char lang[20] = "korean";
	if( !strcmp(lang,"korean") )
	{
		
	}

	return 0;
}*/
void onCancel(HWND hDlg)
{
  SendMessage(hDlg, WM_CLOSE, 0, 0);
}

void onClose(HWND hDlg)
{
  if(MessageBox(hDlg, TEXT("Close the program?"), TEXT("Close"),
    MB_ICONQUESTION | MB_YESNO) == IDYES)
  {
    DestroyWindow(hDlg);
  }
}
INT_PTR CALLBACK DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch(uMsg) /* more compact, each "case" through a single line, easier on the eyes */
  {
	  case WM_INITDIALOG:
		return TRUE;

  case WM_COMMAND:
    switch(LOWORD(wParam))
    {
    case IDCANCEL: onCancel(hDlg); return TRUE; /* call subroutine */
    }
    break;

  case WM_CLOSE:   onClose(hDlg); return TRUE; /* call subroutine */
  case WM_DESTROY: PostQuitMessage(0); return TRUE;
  }

  return FALSE;
}
int main() 
{ 
   BOOL freeResult, runTimeLinkSuccess = FALSE; 
   HINSTANCE dllHandle = NULL;   
   HWND hDlg;
   //FindArtistType FindArtistPtr = NULL;

   //Load the dll and keep the handle to it
  // dllHandle = LoadLibrary(L"Debug\\Researches.dll");

   // If the handle is valid, try to get the function address. 
//   if (NULL != dllHandle) 
   { 
		 hDlg = CreateDialogParam(dllHandle, MAKEINTRESOURCE(IDD_DIALOG1), 0, DialogProc, 0);
		 //ShowWindow(hDlg, nCmdShow);
   }

   //If unable to call the DLL function, use an alternative. 
   //if(!runTimeLinkSuccess)
   //   printf("message via alternative method\n"); 
   system("pause");
   return 0;
}
