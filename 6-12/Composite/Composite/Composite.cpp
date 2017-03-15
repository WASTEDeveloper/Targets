// Composite.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Calculator.h"

using namespace std;
using namespace calculator;

int main()
{
	string expr;
	cin >> expr;
	cout << parse(expr)->execute();
	system("pause");
    return 0;
}

