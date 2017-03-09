#include "stdafx.h"
#include <iostream>
#include "State.h"

using namespace std;

int main()
{
	State* stat = new Created();
	Grant item = Grant(stat);

	cout << item.get_status() << endl;

	item.Deny();

	cout << item.get_status() << endl;
	item.Process();
	cout << item.get_status() << endl;
	item.Delayed();
	cout << item.get_status() << endl;
	item.Process();
	cout << item.get_status() << endl;
	item.Accept();
	cout << item.get_status() << endl;
	item.Recall();
	cout << item.get_status() << endl;
	system("pause");
	return 0;
}