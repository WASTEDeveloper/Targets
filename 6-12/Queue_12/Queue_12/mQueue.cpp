#include "stdafx.h"
#include "mQueue.h"


mQueue::mQueue()
{
	Head = new Node;
	Head->next = NULL;
	Head->data = 0;
	Tail = Head;
}

void mQueue::push(int data)
{
	Node* tmp = new Node;
	tmp->next = NULL;
	tmp->data = data;
	while (Tail->next)
		Tail = Tail->next;
	Tail->next = tmp;
	Tail = tmp;
}

int mQueue::pop()
{
	if (Head == Tail)
	{
		if (Head->next)
		{
			while (Tail->next)
				Tail = Tail->next;
		}
		else
		{
			throw std::out_of_range("Out of range!");
		}
	}
	Node* ptr = Head;
	Head = Head->next;
	delete ptr;
	return Head->data;
}

mQueue::~mQueue()
{
	while (Head->next)
	{
		Node* ptr = Head;
		Head = Head->next;
		delete ptr;
	}
}