#include "stdafx.h"
#include <iostream>
#include "Visitor.h"

using namespace std;

int main()
{
	Actio* actions[] = { new MicrosoftActio(), new AppleActio() };
	ProgonsisVisitor newPrognosis;
	InfoVisitor Info;
	for (int i = 0; i < 2; i++)
	{
		actions[i]->accept(newPrognosis);
		cout << endl;
	}
	for (int i = 0; i < 2; i++)
	{
		actions[i]->accept(Info);
		cout << endl;
	}
	system("pause");
	return 0;
}