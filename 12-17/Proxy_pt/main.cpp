#include "stdafx.h"
#include "Proxy.h"

using namespace std;

// the only way to use PoolProxy as an argument
void fun(PoolProxy &item)
{
	cout << "bla-bla" << endl;
	PoolProxy y;
	cout << "fun function!" << " Pool capacity: " << item.get_capacity() << ". And size: " << item.get_size() << endl << item.get_refAmount() << endl; 
	cout << "fun function!" << " Pool capacity: " << y.get_capacity() << ". And size: " << y.get_size() << endl << y.get_refAmount() << endl;
	cout << endl;
	cout << endl;
}

int main()
{
	PoolProxy example;
	cout << "Pool capacity: " << example.get_capacity() << ". And size: " << example.get_size() << endl;
	PoolProxy ex2;
	PoolProxy ex3;
	PoolProxy ex4;

	fun(example);

	cout << "Amount of proxies: " << example.get_refAmount() << endl;
	ex2 = ex3;
	cout << "Amount of proxies: " << example.get_refAmount() << endl;

	

	system("pause");
    return 0;
}