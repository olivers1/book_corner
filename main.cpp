// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Core.h"
#include "Page.h"

int main()
{
	Core myCore;
	myCore.Initialize();
	myCore.Execute();

	return 0;
}
