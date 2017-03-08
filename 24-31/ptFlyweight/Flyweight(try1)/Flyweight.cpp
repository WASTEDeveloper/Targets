#include "stdafx.h"
#include "Flyweight.h"


ConcreteBacteria::ConcreteBacteria(unsigned int igroup)
{
	type = "Procaryota";
	status = true;
	group = igroup;
}

std::string Bacteria::get_type() const
{
	return type;
}

bool Bacteria::get_stat() const
{
	return status;
}

unsigned int Bacteria::get_group() const
{
	return group;
}

const Bacteria& BacteriaFactory::getBacteria(unsigned int group)
{
	Bacterias::const_iterator it = colony.find(group);
	if (colony.end() == it)
	{
		const Bacteria * instance = new ConcreteBacteria(group);
		colony[group] = instance;
		return *instance;
	}
	else {
		return *it->second;
	}
}

BacteriaFactory::~BacteriaFactory()
{
	for (Bacterias::const_iterator it = colony.begin(); it != colony.end(); ++it)
		delete it->second;
}

