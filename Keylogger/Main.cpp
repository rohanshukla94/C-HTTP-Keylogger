#define _SCL_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include "StdInc.hpp"
/*
You'll die as you lived in a flash of the blade in a corner forgotten the way.
*/


using namespace std;

int main()
{
	MSG Msg;

	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return 0;
}
