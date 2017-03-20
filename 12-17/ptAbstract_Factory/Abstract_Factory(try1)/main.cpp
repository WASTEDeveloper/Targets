// Abstract_Factory(try1).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Abstract_Factory.h"

int main()
{
	using namespace std;

	Distributor * dA = new DistributorA();
	Subtitles * EAsubs = dA->EnglishSubs();
	std::string subs = EAsubs->get_subs("Oda Nobunaga");
	cout << subs << endl;
	Subtitles * FAsubs = dA->FrenchSubs();
	subs = FAsubs->get_subs("Charles DeGolle");
	cout << subs << endl;
	system("pause");
    return 0;
}