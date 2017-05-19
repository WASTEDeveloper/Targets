#pragma once

#include "stdafx.h"
#include <iostream>
#include <exception>

struct Node
{
	int data;
	Node* next;
};

class mQueue
{
	Node* Head, *Tail;
public:
	void push(int data);
	int pop();
	mQueue();
	~mQueue();
};