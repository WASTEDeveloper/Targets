#include "stdafx.h"
#include "Singleton.h"

// this function does nothing

Owner::~Owner()
{
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++

Owner::Owner() 
{
	boss = person();
}

Owner & Owner::getInstance()
{
	static Owner instance;
	return instance;
}

std::string Owner::getownername() const
{
	return getInstance().boss.getname();
}

std::string Owner::getownersurname() const
{
	return getInstance().boss.getsurname();
}

void Owner::setownername(std::string newname)
{
	getInstance().boss.setname(newname);
}

void Owner::setownersurname(std::string newsurname)
{
	getInstance().boss.setsurname(newsurname);
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++

person::person()
{
	name = "John";
	surname = "de Calle";
}


std::string person::getname() const
{
	return this->name;
}

std::string person::getsurname() const
{
	return this->surname;
}

void person::setname(std::string newname)
{
	this->name = newname;
}

void person::setsurname(std::string newsurname)
{
	this->surname= newsurname;
}
