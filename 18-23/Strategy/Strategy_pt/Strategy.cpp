#include "stdafx.h"
#include "Strategy.h"
#include <iostream>

int * parse(std::string c)
{
	int * res = new int[3];

	int x, y, z;
	x = y = z = 0;
	for (std::string::iterator it = c.begin(); it != c.end(); ++it)
	{
		switch (*it)
		{
		case 'E':
			z = STEP;
			break;
		case 'R':
			z = -STEP;
			break;
		case 'W':
			y = -STEP;
			break;
		case 'S':
			y = STEP;
			break;
		case 'A':
			x = -STEP;
			break;
		case 'D':
			x = STEP;
			break;
		default:
			break;
		}
	}

	res[0] = x;
	res[1] = y;
	res[2] = z;

	return res;
}

void Race::set_attack(int iattack)
{
	item.attack = iattack;
}

void Race::set_pos(int ix, int iy, int iz)
{
	x = ix;
	y = iy;
	z = iz;
}

void Race::set_movet(moveType)
{
	movement = moveType::Walk;
}

moveType Race::get_moveT()
{
	return movement;
}

std::string Race::get_name() const
{
	return item.name;
}

Race::Race(std::string iname, int iattack)
{
	item.name = iname;
	item.attack = iattack;

	x = y = z = 0;

	movement = moveType::Walk;
}

unsigned int Race::Attack()
{
	return item.attack;
}

void Race::Customize(std::string iname)
{
	item.name = iname;
}

void Race::get_pos(int & ix, int & iy, int & iz)
{
	ix = x;
	iy = y;
	iz = z;
}

Magician::Magician()
{
	Customize("Gendalf");
	set_attack(1);
	set_movet(moveType::Both);
}

std::string Magician::Roar()
{
	std::string shout = "I am 3000-years-old magician, called" + get_name();
	return shout;
}

void Magician::Move(std::string c)
{
	if (c[0] != 'E' && c[0] != 'R')
	{
		walk.Move(x, y, z, c);
	}
	else {
		fly.Move(x, y, z, c);
	}
}

Orc::Orc()
{
	Customize("Gul'dan");
	set_attack(3);
	set_movet(moveType::Walk);
}

std::string Orc::Roar()
{
	std::string shout = "Does anyone know when these spikes grew out of my back ? You would think I would remember something like that.";
	return shout;
}

void Orc::Move(std::string c)
{
	walk.Move(x, y, z, c);
}

Harpy::Harpy()
{
	Customize("Alkonost");
	set_attack(2);
	set_movet(moveType::Fly);
}

std::string Harpy::Roar()
{
	std::string shout = "Homer wrote that a harpy was the mother of the two horses of Achilles sired by the West Wind Zephyrus";
	return shout;
}

void Harpy::Move(std::string c)
{
	fly.Move(x, y, z, c);
}

hero::hero(std::string iname, unsigned int iattack)
{
	name = iname;
	attack = iattack;
}

void Reposition::set_coordinates(int &x, int &y, int &z, std::string c)
{
	int * vec = parse(c);

	x += vec[0];
	y += vec[1];
	z += vec[2];
}

void Walk::Move(int &x, int &y, int &z, std::string c)
{
	int * steps = new int[3];

	steps = parse(c);
	x += steps[0];
	y += steps[1];

	delete steps;
}

void Fly::Move(int &x, int &y, int &z, std::string c)
{
	int * steps = new int[3];

	steps = parse(c);

	x += steps[0];
	y += steps[1];
	z += steps[2];

	delete steps;
}
