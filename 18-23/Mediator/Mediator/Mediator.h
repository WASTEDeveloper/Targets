#pragma once

#include "stdafx.h"
#include <iostream>

class Mediator;

enum RequestType {
	attack,
	cover
};

class Group {
private:
	Mediator * _mediator;
	std::string groupName;
public:
	std::string send_request(RequestType,Group *);
	std::string get_name();
	virtual std::string attack() = 0;
	virtual std::string cover(std::string) = 0;

	Group();
	Group(Mediator * mediator, std::string name) : _mediator(mediator), groupName(name) {};
	virtual ~Group();
};

class GroupA : public Group {
public:
	std::string attack();
	std::string cover(std::string);

	GroupA() :Group() {};
	GroupA(Mediator * mediator) :Group(mediator, "A") {};

	virtual ~GroupA() {};
};

class GroupB : public Group {
public:

	std::string attack();
	std::string cover(std::string);

	GroupB() :Group() {};
	GroupB(Mediator * mediator) :Group(mediator, "B") {};

	virtual ~GroupB() {};
};


class Mediator {
public:
	GroupA * A;
	GroupB * B;

	Mediator() : A(nullptr), B(nullptr) {};
	Mediator(GroupA * iA, GroupB * iB) :A(iA), B(iB) {};

	virtual std::string send_request(RequestType, Group *, std::string) = 0;

	virtual ~Mediator();
};

class ConcreteMediator: public Mediator {
public:
	std::string send_request(RequestType, Group *, std::string);
};