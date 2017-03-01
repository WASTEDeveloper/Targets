#ifndef SINGLETON
#define SINGLETON

#include "stdafx.h"
#include <string>

struct person final
{
	std::string name;
	std::string surname;

	person();

	std::string getname() const;
	std::string getsurname() const;
	void setname(std::string);
	void setsurname(std::string);

};

class Owner final
{
private:
	person boss;

	Owner& operator=(Owner&) = delete;
	Owner(Owner const&) = delete;

	Owner();
	~Owner();
public:
	static Owner& getInstance();

	std::string getownername() const;
	std::string Owner::getownersurname() const;
	void setownername(std::string);
	void setownersurname(std::string);
};

#endif // SINGLETON
