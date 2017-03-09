#pragma once

#include "stdafx.h"
#include <iostream>

class State;

enum status {
	created,
	processing,
	delayed,
	accepted,
	denyed,
	recalled
};

class Grant {
	State* _state;
public:
	Grant(State*);

	status get_status();

	void Process();
	void Delayed();
	void Accept();
	void Deny();
	void Recall();
};

class State {
protected:
	status _status;
public:
	status get_status() const;

	virtual State* Create();
	virtual State* Process();
	virtual State* Delay();
	virtual State* Accept();
	virtual State* Deny();
	virtual State* Recall();
};

class Created : public State {
public:
	Created();
	State* Process();
	State* Delay();
};

class Processed : public State {
public:
	Processed();
	State* Delay();
	State* Accept();
	State* Deny();
};

class Delayed : public State {
public:
	Delayed();
	State* Process();
};

class Accepted : public State {
public:
	Accepted();
	State* Recall();
};

class Denyed : public State {
public:
	Denyed();
};

class Recalled : public State {
public:
	Recalled();
};