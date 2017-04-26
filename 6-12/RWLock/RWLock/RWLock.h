#pragma once

#include <thread>
#include <mutex>
#include <string>

typedef struct blackbox {
	volatile int reader_count;
	std::mutex read_lock;
	std::mutex write_lock;
	blackbox() : reader_count(0) { std::mutex read_lock; std::mutex write_lock; };
} Blackbox;

void ts_read(Blackbox *b, std::string &readTo, std::function<std::string()>readfunc);

void ts_write(Blackbox *b, std::string writeFrom, std::function<void(std::string)>writefunc);