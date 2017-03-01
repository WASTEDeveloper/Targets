#pragma once

#include "stdafx.h"
#include <iostream>

class Weapon {
	unsigned int fire_rate;
public: 
	virtual void aim() = 0;
	virtual void fire() const;

	unsigned int get_rate() const;
	~Weapon();
protected:
	void set_rate(unsigned int);
};

class StandardWeapon: public Weapon {
	unsigned int zoom;
public:
	StandardWeapon();
	~StandardWeapon();

	void aim();
	void fire() const;
	unsigned int get_aim() const;
};


class WeaponDecorator: public Weapon {
	Weapon * gun;
public:
	WeaponDecorator();
	WeaponDecorator(Weapon *);
	~WeaponDecorator();
	
	void aim();
	void fire() const;
};

class Zoom: public WeaponDecorator {
	unsigned int zoom;

	void set_zoom(unsigned int);
public:
	Zoom(Weapon *);
	~Zoom();

	void aim();
	unsigned int get_aim() const;
};

class Silencer: public WeaponDecorator {
	unsigned int dB;

	void set_dB(unsigned int);
public:
	Silencer(Weapon *);
	~Silencer();

	void fire();
	unsigned int get_dB() const;
};

class AttGrenade : public WeaponDecorator {
	unsigned int gr_dist;
public:
	AttGrenade(Weapon *);
	~AttGrenade();

	void fireG();
	unsigned int get_gr_distance();
};