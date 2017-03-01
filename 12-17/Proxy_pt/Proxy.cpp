#include "stdafx.h"
#include "Proxy.h"

subPool::subPool()
{
	quantity = 0;
	limit = 100;
}

subPool::subPool(const subPool & node)
{
	quantity = node.quantity;
	limit = node.limit;
}

subPool::subPool(unsigned int stlimit, unsigned int stAmount)
{
	quantity = stAmount;
	limit = stlimit;
}

void subPool::add_item(unsigned int amount)
{
	quantity += amount;
}

unsigned int subPool::get_capacity() const
{
	return limit;
}

unsigned int subPool::get_size() const
{
	return quantity;
}

int PoolProxy::refAmount = 0;

PoolProxy::PoolProxy()
{
	if (!refAmount)
		item = subPool();
	refAmount++;
}

PoolProxy::PoolProxy(const PoolProxy & node)
{
	refAmount++;

	this->item = node.item;
}

PoolProxy::~PoolProxy()
{
	if (refAmount > 0)
		refAmount--;
	else if (refAmount <= 0)
		std::cerr << "No longer exists!";
}

PoolProxy & PoolProxy::operator=(const PoolProxy & it)
{
	//if (this == &it)
		//return *this;
	//this->item = it.item;
	//refAmount = it.refAmount;
	return *this;

}

unsigned int PoolProxy::get_refAmount() const
{
	return refAmount;
}

unsigned int PoolProxy::get_capacity() const 
{
	return item.get_capacity();
}

unsigned int PoolProxy::get_size() const
{
	return item.get_size();
}
