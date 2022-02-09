#include "weapon.H"
#include <ctime>
#include <iostream>
//Made by Lucas Lasecla

using namespace std;

Weapon::Weapon()
{
	//safety sets damage to 0
	srand(time(0));
	int damage = 0;

}

Weapon::~Weapon()
{
}

void Weapon::setMat()
{
	//sets material
	string materials[7] = { "Rubber", "Wood", "Stone", "Steel", "Crystal", "Meteorite", "Dark Matter" };
	material = materials[damage];
}


string Weapon::getMat()
{
	//returns material
	return material;
}

void Weapon::setDam()
{
	//sets damage randomly
	damage = rand() % 7;
}


int Weapon::getDam()
{
	//returns damage
	return damage + 1;
}


