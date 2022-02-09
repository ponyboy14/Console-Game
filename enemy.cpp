#include "enemy.H"
#include "weapon.H"
#include "armor.H"
#include <ctime>
#include <iostream>
//Made by Lucas Lasecla

using namespace std;

Enemy::Enemy()
{
	//initializes sword and armor assigning them to variables for the enemy
	Armor armor1;
	Weapon sword;
	armor1.setProt();
	armor1.setMat();
	armor1.setName();
	armor = armor1.getMat() + " armor of " + armor1.getName();
	prot = armor1.getProt();
	sword.setDam();
	sword.setMat();
	sword.setName();
	weapon = sword.getMat() + " sword of " + sword.getName();
	strength = sword.getDam();

}

Enemy::~Enemy()
{
}

string Enemy::getArmor()
{
	//returns armor name
	return armor;
}

int Enemy::getProt()
{
	//returns protection level
	return prot;
}

string Enemy::getWeapon()
{
	//returns sword name
	return weapon;
}


int Enemy::getStrength()
{
	//returns strength level
	return strength;
}

void Enemy::setHealth()
{
	//randomly assigns enemy health level
	srand(time(0));
	health = rand() % 30;
}

int Enemy::getHealth()
{
	// returns enemy health
	return 10 + health;
}

void Enemy::setName()
{
	//randomly assign enemy name
	string names[10] = { "Azrog", "Zarog", "Da'try", "Rok", "Grimfang", "Bagul", "Gollik", "Ongne", "Rotstuf", "Ronkros" };
	string namesAdj[10] = { "Defiler", "Conquerer", "Undefeated", "Vicious", "Savage", "Ugly", "Old", "Feared", "Stinger", "Hellborn" };
	srand(time(0));
	int temp1 = rand() % 10;
	int temp2 = rand() % 10;
	name = names[temp1] + " the " + namesAdj[temp2];
}

string Enemy::getName()
{
	//returns enemy name
	return name;
}
