#include "ChainOfR.h"

Operation::Operation(unsigned int _ID, OperationType _type, unsigned int _sum)
{
	type = _type;
	ID = _ID;
	sum = _sum;
	accepted = 0;
}

OperationType Operation::get_type() const
{
	return type;
}

unsigned int Operation::get_ID() const
{
	return ID;
}

unsigned int Operation::get_sum() const
{
	return sum;
}

void Operation::change_sum(int operand)
{
	operand > sum ? sum = 0 : sum -= operand;
}

void Operation::decline()
{
	accepted = false;
}

void Operation::accept()
{
	accepted = true;
}

bool Operation::is_accepted() const
{
	return accepted > 0 ? true : false;
}

void Base::add(Base* _next)
{
	if (next)
		next->add(_next);
	else
		next = _next;
}

void Base::handle(Operation * operation)
{
	if (!operation)
		return;
	if (!next)
	{
		operation->decline();
		return;
	}
	next->handle(operation);
}

void Validation::handle(Operation* operation)
{
	if (!operation)
		return;
	if (!next)
	{
		operation->decline();
		return;
	}
	if (operation->get_type() != bank)
	{
		if (operation->get_ID() % 2)
		{
			operation->decline();
			return;
		}
	}
	Base::handle(operation); 
}

void BankFee::handle(Operation* operation)
{
	if (!operation)
		return;
	if (!next)
	{
		operation->decline();
		return;
	}
	if (operation->get_type() != bank && operation->get_type() != state)
	{
		operation->change_sum(BANK_FEE);
	}
	Base::handle(operation);
}

void StateFee::handle(Operation* operation)
{
	if (!operation)
		return;
	if (!next)
	{
		operation->decline();
		return;
	}
	if (operation->get_type() != state && operation->get_type() != exclusive)
	{
		operation->change_sum(STATE_FEE);
	}
	Base::handle(operation);
}

void Accept::handle(Operation* operation)
{
	if (!operation)
		return;
	if (next)
	{
		next = nullptr;
	}
	operation->accept();
	operation->change_sum(-(int)operation->get_sum());
}

void NeutralAccept::handle(Operation* operation)
{
	if (!operation)
		return;
	if (next)
		next = nullptr;
	operation->accept();
}