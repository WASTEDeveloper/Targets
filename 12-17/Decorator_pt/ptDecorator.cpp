#include "stdafx.h"
#include "ptDecorator.h"


void Weapon::fire() const
{
	std::cout << "fire rate " << get_rate();
}

unsigned int Weapon::get_rate() const
{
	return fire_rate;
}

void Weapon::set_rate(unsigned int irate)
{
	fire_rate = irate;
}

Weapon::~Weapon()
{
}

StandardWeapon::StandardWeapon()
{
	set_rate(60);
	zoom = 10;
}

void StandardWeapon::aim()
{
	std::cout << "Zoom lvl: " << get_aim() << "% ";
}

unsigned int StandardWeapon::get_aim() const
{
	return zoom;
}

void StandardWeapon::fire() const
{
	Weapon::fire();
}

StandardWeapon::~StandardWeapon()
{
}


WeaponDecorator::WeaponDecorator()
{
	this->gun = new StandardWeapon();
}

WeaponDecorator::WeaponDecorator(Weapon * gun)
{
	this->gun = gun;
}

void WeaponDecorator::aim() 
{
	gun->aim();
}

void WeaponDecorator::fire() const
{
	gun->fire();
}

WeaponDecorator::~WeaponDecorator()
{
}


void Zoom::aim()
{
	std::cout << "Zooming... \n Zoom: " << get_aim() << "% ";
}

Zoom::Zoom(Weapon * gun)
{	
	set_zoom(40);
	set_rate(gun->get_rate());
}

void Zoom::set_zoom(unsigned int izoom) 
{
	zoom = izoom;
}

unsigned int Zoom::get_aim() const
{
	return zoom;
}

Zoom::~Zoom()
{
}


Silencer::Silencer(Weapon * gun)
{
	set_dB(80); 
	set_rate(gun->get_rate());
}

void Silencer::set_dB(unsigned int idB)
{
	dB = idB;
}

unsigned int Silencer::get_dB() const
{
	return dB;
}

void Silencer::fire()
{
	std::cout << "fire rate" << get_rate() << "b/m, dB: " << get_dB();
}

Silencer::~Silencer()
{
}


AttGrenade::AttGrenade(Weapon * gun)
{
	set_rate(gun->get_rate());
	gr_dist = 50;
}

void AttGrenade::fireG()
{
	std::cout << "grenade thrown. distance - "<< get_gr_distance() <<" metres";
}

unsigned int AttGrenade::get_gr_distance()
{
	return gr_dist;
}

AttGrenade::~AttGrenade()
{
}