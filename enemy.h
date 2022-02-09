#pragma once
#ifndef Enemy_H
#define Enemy_H
#include <string>
//Made by Lucas Lasecla
//Explained in cpp


using namespace std;

class Enemy
{
public:
	Enemy();
	~Enemy();
	//void setArmorT();
	string getArmor();
	//void setProt();
	int getProt();
	//void setWeaponT();
	string getWeapon();
	//void setStrength();
	int getStrength();
	void setHealth();
	int getHealth();
	void setName();
	string getName();

private: 
	string armor;
	string weapon;
	int prot;
	int strength;
	string names[11];
	string namesAdj[11];
	string name;
	int health;
};

#endif