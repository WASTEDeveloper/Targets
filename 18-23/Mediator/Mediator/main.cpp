// Mediator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Mediator.h"
#include <string>

int main()
{
	using namespace std;

	ConcreteMediator * mediator = new ConcreteMediator();


	GroupA * A = new GroupA(mediator);
	GroupB * B = new GroupB(mediator);
	mediator->A = A;
	mediator->B = B;

	string out = A->send_request(RequestType::attack, B);
	cout << out << endl;
	out = B->send_request(RequestType::cover, A);
	cout << out << endl;
	out = B->send_request(RequestType::attack, A);
	cout << out << endl;
	out = A->send_request(RequestType::cover, B);
	cout << out << endl;

	system("pause");
    return 0;
}

