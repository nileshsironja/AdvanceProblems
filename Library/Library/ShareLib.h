#include<iostream>

//
//#if defined(XYZLIBRARY_EXPORT) // inside DLL
//#   define XYZAPI   __declspec(dllexport)
//#else // outside DLL
//#   define XYZAPI   __declspec(dllimport)
//#endif  // XYZLIBRARY_EXPORT



class /*XYZAPI*/ TestVir
{
public:
  virtual void init()=0;
  virtual void display()=0;
};
 
  