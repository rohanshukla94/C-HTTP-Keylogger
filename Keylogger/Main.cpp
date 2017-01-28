#define _SCL_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include "StdInc.hpp"
/*
You'll die as you lived in a flash of the blade in a corner forgotten the way.
*/

/*
No one deserves better treatment than others, or more respect. 
No one is inferior or superior. Everyone is nothing. No soul is superior. 
All men are created equal. All people are equal to bugs. All inherit an equal soul. 
No one deserves special treatment. No one deserves anything more than anything else. 
It all cancels out, and leaves life to be just nothing. It's true.
Google: Truth Contest for the truth of life.﻿

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