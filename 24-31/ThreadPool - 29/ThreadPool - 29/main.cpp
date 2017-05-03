#include <iostream>
#include <string>
#include "ThreadPool.h"

using namespace std;

double multiplyRandom()
{
	srand(time(NULL));
	auto a = rand() % 20;
	auto b = rand() % 10;
	return a * b;
}

int sum(int a, int b)
{
	return a + b;
}


int main() 
{
	ThreadPool pool;

	auto first = pool.runAsync<double>(&multiplyRandom);
	auto second = pool.runAsync<int>(&sum, 0, 77);

	while (!first->isReady);  
	cout << first->data << endl;
	while (!second->isReady);
	cout << second->data << endl;
	
	system("pause");
	return 0;
}