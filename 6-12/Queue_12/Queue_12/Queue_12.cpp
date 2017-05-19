#include "stdafx.h"
#include <iostream>
#include "mQueue.h"

using namespace std;

int main()
{
	mQueue mQ;
	int arr[] = { 1,2,3,4,5,6,7 };
	for (int i = 0; i < 7; i++)
	{
		mQ.push(arr[i]);
	}

	for (int i = 6; i >= 0; i--)
	{
		int re = mQ.pop();
		//Assert::AreEqual(re, arr[i]);
		cout << re << " ";
	}

	try 
	{
		mQ.pop();
	}
	catch (std::out_of_range &ex)
	{
		cout << ex.what() << endl;
	}
	system("pause");
    return 0;
}

