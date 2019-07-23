// Client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>
#include<Windows.h>
#include"..\Library\ShareLib.h"
//#include"..\Library\Library.h"
using namespace std;
 
typedef TestVir* create_t();
typedef void destroy_t(TestVir*);
//typedef VOID (*DLLPROC) (LPTSTR); 


//TestVir* (__cdecl *create_t)();

int main()
{
    HINSTANCE handle = LoadLibrary(L"Library.dll");
    if (!handle)
    {
		cout<<"The error is in create "<<GetLastError();
    }
	

    create_t* creat=(create_t*)GetProcAddress(handle,"create");
    //create_t = (TestVir* (__cdecl *)())GetProcAddress(handle,"create");
    
	/*typedef void* (*pvFunc)();
	pvFunc creat;

	creat = (pvFunc)GetProcAddress( handle, "create" );*/

    if (!creat)
    {
        cout<<"The error is in create "<<GetLastError();
		return 0;
    }
	

	//destroy_t* destroy=(destroy_t*)GetProcAddress(handle,"destroy");
    
	/*if (!destroy)
    {
           cout<<"The error is in destroy %s"<<GetLastError();
		   return 0;
    }
 */
	TestVir* tst = creat();
	tst->display();
	//destroy(tst);
    return 0 ;
}


/*

typedef VOID (*DLLPROC) (LPTSTR);
...
HINSTANCE hinstDLL;
DLLPROC HelloWorld;
BOOL fFreeDLL;

hinstDLL = LoadLibrary("sampleDLL.dll");

if (hinstDLL != NULL)
{
   HelloWorld = (DLLPROC) GetProcAddress(hinstDLL, "HelloWorld");
	
   if (HelloWorld != NULL)
      (HelloWorld);

   fFreeDLL = FreeLibrary(hinstDLL);
}

*/