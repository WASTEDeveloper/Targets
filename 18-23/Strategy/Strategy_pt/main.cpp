// Strategy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Strategy.h"

using namespace std;


int main()
{
	Magician Dumbledore;
	string shout = Dumbledore.Roar();
	string move1 = "EWA";
	string move2 = "RSD";
	string move3 = "RRRRR";
	int attack = Dumbledore.Attack();
	int x, y, z;
	Dumbledore.Move(move1);
	Dumbledore.Move(move1);
	Dumbledore.get_pos(x, y, z);
	char c = '3';

	cout << shout << endl << attack << endl << x << " " << y << " " << z << endl;
	Dumbledore.Move(move2);
	Dumbledore.get_pos(x, y, z);
	cout << x << " " << y << " " << z << endl;
	Dumbledore.Move(move3);
	Dumbledore.get_pos(x, y, z);
	cout << x << " " << y << " " << z << endl;

	system("pause");
    return 0;
}

