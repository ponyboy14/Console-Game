#pragma once
#ifndef Player_H
#define Player_H
#include <string>
#include <vector>
//Made by Lucas Lasecla
//Explained in cpp


using namespace std;

class Player
{
public:
	Player();
	~Player();
	void addHealth(int health);
	int getMaxHealth();
	void setSword(string _sword);
	string getSword();
	void setStrength(int _strength);
	int getStrength();
	void setArmor(string _armor);
	string getArmor();
	void setProt(int _prot);
	int getProt();
	void addDodge(int _dodge);
	int getDodge();
	void addSpeed(int _speed);
	int getSpeed();
	void addCrit(int _crit);
	int getCrit();
	void addGold(int _gold);
	void subtractGold(int _gold);
	int getGold();
	void addInv(string item);
	void setInv(vector<string> _Inv);
	vector<string> getInv();
	void createPlayer();
	void savePlayer();
	void loadPlayer();
	void dataSheet();


private: 
	int maxHealth;
	string sword;
	int strength;
	string armor;
	int prot;
	int dodge;
	int speed;
	int crit;
	int gold;
	vector<string> inventory;

};

#endif