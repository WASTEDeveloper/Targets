#include <iostream>

#include "Builder.h"
using namespace std;

int main()
{
	string filename = "Document1";
	Director *director = new Director(filename);
	director->convertXML();
	system("pause");
	return 0;
}