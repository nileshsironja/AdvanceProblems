// Library.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"


#include <iostream>
#include "Library.h"
#include "ShareLib.h"
using namespace std;

/*extern "C" __declspec(dllexport)*/void TestLib::init()
{
   cout<<"TestLib::init: Hello World!! "<<endl ;
}
 
//Define functions with C symbols (create/destroy TestLib instance).
extern "C" __declspec(dllexport) TestLib* create()
{
    return new TestLib;
}
extern "C" __declspec(dllexport) void destroy(TestLib* Tl)
{
   delete Tl ;
}
/*extern "C" __declspec(dllexport) */void TestVir::display()
{
	cout<<"Hi this is nilesh";
}
