#pragma once

#include <iostream>
#include <string>
#include <map>

class Bacteria {
protected:
	std::string type;
	bool status;				// passive/active
	unsigned group;
public:
	virtual ~Bacteria() {};

	std::string get_type() const;
	bool get_stat() const;
	unsigned int get_group() const;
};

class ConcreteBacteria : public Bacteria {
public:
	ConcreteBacteria(unsigned int igroup = 1);

	//void set_status();
};

class BacteriaFactory {
private:
	typedef std::map <unsigned int, const Bacteria *> Bacterias;
	Bacterias colony;
public:
	const Bacteria& getBacteria(unsigned int);

	virtual ~BacteriaFactory();
};