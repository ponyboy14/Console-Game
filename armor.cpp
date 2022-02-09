#include "armor.H"
#include <ctime>
#include <iostream>
//Made by Lucas Lasecla

using namespace std;

Armor::Armor()
{
	//sets base protection as zero for safety
	protection = 0;

}

Armor::~Armor()
{
}

void Armor::setMat()
{
	//assigns material name
	string materials[7] = { "Wooden", "Rusted", "Chainmail", "Steel", "Crystal", "Meteorite", "Magical" };
	material = materials[protection];
}


string Armor::getMat()
{
	//returns material name
	return material;
}

void Armor::setProt()
{
	//randomly sets protection level
	protection = rand() % 7;
}


int Armor::getProt()
{
	//returns protection level
	return protection + 1;
}


