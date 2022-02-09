#pragma once
#ifndef Weapon_H
#define Weapon_H
#include <string>
#include "equipment.h"
//Made by Lucas Lasecla
//Explained in cpp


using namespace std;

class Weapon: public Equipment //inheritence
{
public:
	Weapon();
	~Weapon();
	void setMat();
	string getMat();
	void setDam();
	int getDam();

	
private:
	string materials[7];
	string material;
	int damage;


};

#endif
