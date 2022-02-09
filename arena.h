#pragma once
#ifndef Arena_H
#define Arena_H
#include <string>
#include <vector>
//Made by Lucas Lasecla
//Explained in cpp

using namespace std;

class Arena
{
public:
	Arena();
	~Arena();
	void playerTurn();
	void enemyTurn();
	void removeInv(string item);
private:
	int eStrength;
	string eName;
	int eHealth;
	string eWeapon;
	string eArmor;
	int eProt;
	int pStrength;
	int pMaxHealth;
	int pHealth;
	int pDodge;
	int pSpeed;
	int pCrit;
	int pProt;
	string pArmor;
	string pWeapon;
	vector<string> pInv;
	bool isPDead;
	bool isEDead;
	string healthP = "Health Potion";
	string strengthP = "Strength Potion";
	string dodgeP = "Dodge Potion";
	string speedP = "Speed Potion";

};

#endif
