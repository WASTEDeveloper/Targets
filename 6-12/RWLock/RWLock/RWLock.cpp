#include "RWLock.h"

void ts_read(Blackbox *b, std::string &readTo, std::function<std::string()>readfunc)
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

void ts_write(Blackbox *b, std::string writeFrom, std::function<void(std::string)>writefunc)
{
	bool written = false;

	while (!written)		// wait until there is no readers and writers
	{
		if (b->write_lock.try_lock())
		{
			if (b->reader_count == 0)
			{
				writefunc(writeFrom);
				written = true;
			}
		}
		b->write_lock.unlock();
	}
}