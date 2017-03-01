#pragma once

#include "stdafx.h"
#include <iostream>

class Pool {
protected:
	unsigned int quantity;
	unsigned int limit;
public:

	virtual void add_item(unsigned int) = 0;
	virtual unsigned int get_capacity() const = 0;
	virtual unsigned int get_size() const = 0;
};

class subPool : public Pool {
private:
	//subPool() {};
	//subPool(Pool &) {};
	//subPool(subPool &);
public:
	subPool();
	subPool(const subPool &);
	subPool(unsigned int, unsigned int);

	void add_item(unsigned int);

	unsigned int get_capacity() const;
	unsigned int get_size() const;
};


class PoolProxy {
private:
	static int refAmount;
	subPool item;

	PoolProxy(const PoolProxy &);
public:
	PoolProxy();
	~PoolProxy();

	PoolProxy & operator =(const PoolProxy &);

	unsigned int get_refAmount() const;
	unsigned int get_capacity() const;
	unsigned int get_size() const;
};