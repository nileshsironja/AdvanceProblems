
#include<iostream>
using namespace std;

#if defined(XYZLIBRARY_EXPORT) // inside DLL
#   define XYZAPI   __declspec(dllexport)
#else // outside DLL
#   define XYZAPI   __declspec(dllimport)
#endif  // XYZLIBRARY_EXPORT


class XYZAPI TestLib : public TestVir
{
 public:
     void init();
	 void display();
};
 