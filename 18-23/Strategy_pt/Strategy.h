#pragma once

#include "stdafx.h"
#include <iostream>

#define STEP 5

enum class moveType : int {
	Walk,
	Fly,
	Both
};

struct hero {
	std::string name;
	unsigned int attack;
	hero(std::string iname = "Greg",unsigned int iattack = 1);
};

// Abstract Strategy
class Reposition {
public:
	virtual void set_coordinates(int &, int &, int &, std::string);
	virtual void Move(int &, int &, int &, std::string) = 0;
};

class Walk : public Reposition {
public:
	void Move(int &, int &, int &, std::string);
};

class Fly : public Reposition {
public:
	void Move(int &, int &, int &, std::string);
};

class Race {
	hero item;
	// position characterized with 3 values x, y - ground level, z - air
	moveType movement;

protected:
	int x, y, z;

	void set_attack(int);
	void set_pos(int, int, int);
	void set_movet(moveType);
	moveType get_moveT();

	Race(std::string iname = "Greg", int iattack = 1);
	Race(const Race &) {};

	friend class UnitTest1;
public:
	unsigned int Attack();
	void Customize(std::string);

	virtual std::string Roar() = 0;

	virtual void Move(std::string c) = 0;

	void get_pos(int &, int &, int &); 
	std::string get_name() const;

};

class Magician: public Race {
	Walk walk;
	Fly fly;
public:
	Magician();

	std::string Roar();

	void Move(std::string);
};

class Orc: public Race {
	Walk walk;
public:
	Orc();

	std::string Roar();

	void Move(std::string);
};

class Harpy : public Race {
	Fly fly;
public:
	Harpy();

	std::string Roar();

	void Move(std::string);
};

int * parse(std::string);