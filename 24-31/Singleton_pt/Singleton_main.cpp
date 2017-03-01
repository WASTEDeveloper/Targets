#include "stdafx.h"
#include <iostream>
#include "Singleton.h"
#include <string>

using namespace std;

int main()
{
	Owner& bossboy = Owner::getInstance();
	cout << bossboy.getownername() << " " << bossboy.getownersurname() << endl;
	bossboy.setownername("Kalel");
	bossboy.setownersurname("Dezmund");
	cout << bossboy.getownername() << " " << bossboy.getownersurname() << endl;
	system("pause");
    return 0;
}

