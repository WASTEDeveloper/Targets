#pragma once

#include "stdafx.h"
#include <iostream>
#include <string>

class Visitor;

class Actio {
public:
	virtual ~Actio() {};
	virtual void accept(Visitor &) = 0;

	std::string get_owner() const;
	unsigned int get_quantity() const;

protected:
	Actio() :owner("Greg Fields"), quantity(1) {};
	Actio(std::string iowner, unsigned int iquantity) :owner(iowner), quantity(iquantity) {};
private:
	std::string owner;
	unsigned int quantity;
};


class MicrosoftActio: public Actio {
public:
	virtual ~MicrosoftActio() {};
	MicrosoftActio(std::string iowner = "Greg Fields", unsigned int iquantity = 1) :Actio(iowner, iquantity) {};

	void accept(Visitor &) override;
};

class AppleActio: public Actio {
public:
	virtual ~AppleActio() {};
	AppleActio(std::string iowner = "Greg Fields", unsigned int iquantity = 1) : Actio(iowner, iquantity) {};

	void accept(Visitor &) override;
};


class Visitor {
public:
	virtual void visit(MicrosoftActio *) = 0;
	virtual void visit(AppleActio *) = 0;
};

class ProgonsisVisitor: public Visitor {
public:
	virtual void visit(MicrosoftActio *) override;
	virtual void visit(AppleActio *) override;
};

class InfoVisitor: public Visitor {
public:
	virtual void visit(MicrosoftActio *) override;
	virtual void visit(AppleActio *) override;
};