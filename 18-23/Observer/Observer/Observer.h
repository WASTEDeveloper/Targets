#pragma once

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

class Subscriber;

class Post {
	std::string newsname;
	std::vector<Subscriber *> subs;
public:
	Post();
	void AddSub(Subscriber *);
	void RemoveSub(Subscriber *);
	void Notify();
	void SetName(std::string);

	Subscriber * GetSub(unsigned int);

	std::string GetName() const;
};

class Subscriber {
	Post * post;
public:
	Subscriber(Post*);

	virtual void HandleNotify() = 0;
	virtual ~Subscriber();
};

class ConcrSubscriber: public Subscriber {
public:
	ConcrSubscriber(Post * npost) : Subscriber(npost) {};
	void HandleNotify();

	virtual ~ConcrSubscriber();
};