#pragma once
#ifndef Armor_H
#define Armor_H
#include <string>
#include "equipment.h"
//Made by Lucas Lasecla
//Explained in cpp


using namespace std;

class Armor: public Equipment //inheritence
{
public:
	Armor();
	~Armor();
	void setMat();
	string getMat();
	void setProt();
	int getProt();



private:
	string materials[7];
	string material;
	int protection;

};

#endif

