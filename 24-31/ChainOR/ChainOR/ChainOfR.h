#pragma once

#include <iostream>
#define BANK_FEE 20
#define STATE_FEE 100

enum OperationType {
	state = 1,
	bank,
	exclusive,
	normal
};

class Operation;

class Base {
protected:
	Base * next;
public:
	Base() :next(nullptr) {};
	void add(Base*);
	virtual void handle(Operation*);
};

class Validation : public Base {
public:
	void handle(Operation*) override;
};

class BankFee : public Base {
public:
	void handle(Operation*) override;
};

class StateFee: public Base{
public:
	void handle(Operation*) override;
};

class Accept : public Base {
public:
	void handle(Operation*) override;
};

class NeutralAccept : public Base {
public:
	void handle(Operation*) override;
};

class Operation {
	OperationType type;
	unsigned int ID;
	unsigned int sum;
	int accepted;
public:
	Operation(unsigned int, OperationType = normal, unsigned int = 0);
	
	OperationType get_type() const;
	unsigned int get_ID() const;
	unsigned int get_sum() const;
	void change_sum(int);
	void decline();
	void accept();
	bool is_accepted() const;
};