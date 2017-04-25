#include <iostream>
#include <thread>
#include <mutex>
#include <functional>
#include <string>

using namespace std;

string someText;
string read()
{
	return someText;
}

void write(string toWrite)
{
	someText = toWrite;
}


typedef struct blackbox {
	volatile int reader_count;
	mutex read_lock;
	mutex write_lock;
} Blackbox;

void ts_read(Blackbox *b, string &readTo, string (*readfunc)())
{
	b->read_lock.lock();
	b->reader_count++;
	if (b->reader_count == 1)
		b->write_lock.lock();
	b->read_lock.unlock();

	readTo = readfunc();

	b->read_lock.lock();
	b->reader_count--;
	if (b->reader_count == 0)
		b->write_lock.unlock();
	b->read_lock.unlock();
}

void ts_write(Blackbox *b, string writeFrom, void (*writefunc)(string))
{
	bool written = false;

	while (!written)		// wait until there is no readers and writers
	{
		if (b->write_lock.try_lock())
		{
			if (b->reader_count == 0)
			{
				write(writeFrom);
				written = true;
			}
		}
		b->write_lock.unlock();
	}
}


int main()
{
	someText = "someText";
	string text = "abc";
	string text2 = "text2";
	string towrite = "toWrite";
	string tolongwrite = "loooooooooooong";

	Blackbox *box = new Blackbox();
	box->reader_count = 0;
	thread reading1(ts_read, box, ref(text), &read);
	reading1.join();
	cout << text;

	thread writing(ts_write, box, towrite, &write);
	writing.join();

	thread reading2(ts_read, box, ref(text2), &read);
	reading2.join();

	cout << text2;
	system("pause");
	return 0;
}