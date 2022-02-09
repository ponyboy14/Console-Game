#pragma once
#ifndef Shop_H
#define Shop_H
#include <string>
//Made by Lucas Lasecla
//Explained in cpp


using namespace std;

class Shop
{
public:
	Shop();
	~Shop();
	void equipmentStore();
	void itemStore();
	void upgradeStore();

private:
	string healthP = "Health Potion";
	string strengthP = "Strength Potion";
	string dodgeP = "Dodge Potion";
	string speedP = "Speed Potion";


};

#endif