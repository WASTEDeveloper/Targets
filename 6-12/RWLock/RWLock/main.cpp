#include <iostream>
#include <thread>
#include <mutex>
#include <functional>
#include <string>
#include "RWLock.h"

using namespace std;

string common;

int main()
{
	std::function<std::string()>read = []()->std::string {return common; };
	std::function<void(std::string)>write = [](std::string toWrite) mutable {common = toWrite; };

	common = "someText";
	string text = "abc";
	string text2 = "text2";
	string towrite = "toWrite";
	string tolongwrite = "loooooooooooong";

	Blackbox *box = new Blackbox();
	box->reader_count = 0;
	thread reading1(ts_read, box, ref(text), read);
	reading1.join();
	cout << text;

	thread writing(ts_write, box, towrite, write);
	writing.join();

	thread reading2(ts_read, box, ref(text2), read);
	reading2.join();

	cout << text2;
	system("pause");
	return 0;
}