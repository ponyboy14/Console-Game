#include "player.h"
#include <iostream>
#include <fstream>
#include <sstream>
//Made by Lucas Lasecla

using namespace std;

Player::Player()
{
}

Player::~Player()
{
}

void Player::addHealth(int health)
{
	//adds to the max health
	maxHealth = maxHealth + health;
	dataSheet();
}

int Player::getMaxHealth()
{
	//returns max health
	return maxHealth;
}

void Player::setSword(string _sword)
{
	//sets sword name
	sword = _sword;
	dataSheet();
}

string Player::getSword()
{
	//returns sword name
	return sword;
}

void Player::setStrength(int _strength)
{
	//sets damage dealt
	strength = _strength;
	dataSheet();
}

int Player::getStrength()
{
	//returns damage dealt
	return strength;
}

void Player::setArmor(string _armor)
{
	//sets armor name
	armor = _armor;
	dataSheet();
}

string Player::getArmor()
{
	//returns armor name
	return armor;
}

void Player::setProt(int _prot)
{
	//sets protection level
	prot = _prot;
	dataSheet();
}

int Player::getProt()
{
	//returns protection level
	return prot;
}

void Player::addDodge(int _dodge)
{
	//adds to dodge level
	dodge = dodge + _dodge;
	dataSheet();
}

int Player::getDodge()
{
	//returns dodge level
	return dodge;
}

void Player::addSpeed(int _speed)
{
	//adds to speed level
	speed = speed +  _speed;
	dataSheet();
}

int Player::getSpeed()
{
	//return speed level
	return speed;
}

void Player::addCrit(int _crit)
{
	//adds to crit level
	crit = crit + _crit;
	dataSheet();
}

int Player::getCrit()
{
	//returns crit level
	return crit;
}

void Player::addGold(int _gold)
{
	//adds to gold total
	gold = gold + _gold;
	dataSheet();
}

void Player::subtractGold(int _gold)
{
	//removes gold
	gold = gold - _gold;
	if (gold < 0)
	{
		gold = 0;
	}
	dataSheet();
}

int Player::getGold()
{
	//returns int gold
	return gold;
}

void Player::addInv(string item)
{
	//adds item into inventory
	inventory.push_back(item);
	dataSheet();
}

void Player::setInv(vector<string> _Inv)
{
	//sets inventory to recieved vector
	inventory = _Inv;
	dataSheet();
}

vector<string> Player::getInv()
{
	// returns inventory vector
	return inventory;
}

void Player::createPlayer()
{
	//creates a player with base values
	maxHealth = 20;
	sword = "Wooden sword of Beginners";
	strength = 1;
	armor = "Wooden armor of Beginners";
	prot = 1;
	dodge = 1;
	speed = 1;
	gold = 0;
	crit = 1;
	dataSheet();
}

void Player::savePlayer()
{
	//uses a csv to save the player's data
	fstream stats;
	stats.open("stats.csv", std::ofstream::out | std::ofstream::trunc);
	stats.close();
	stats.open("stats.csv", ios::out | ios::app);
	stats << "$ " << maxHealth << "$ " << sword << "$ "  << strength << "$ " << armor << "$ " << prot << "$ " << dodge << "$ " << speed << "$ " << crit << "$ " << gold;
	for (int i = 0; i < inventory.size(); i++)
	{
		stats << "$ " << inventory[i];
	}
	stats.close();
	dataSheet();
}

void Player::loadPlayer()
{
	//reads the data from the csv and sets it equal to player's stats
	//help for csv from https://www.geeksforgeeks.org/csv-file-management-using-c/
	fstream stats;
	stats.open("stats.csv", ios::in);
	vector<string> row;
	string line, word, temp;

	while (stats >> temp)
	{
		row.clear();
		getline(stats, line);
		stringstream s(line);
		while (getline(s, word, '$'))
		{
			row.push_back(word);
		}
	}
	for (int i = 0; i < row.size(); i++)
	{
		row[i].erase(0, 1);
	}
	maxHealth = stoi(row[0]);
	sword = row[1];
	strength = stoi(row[2]);
	armor = row[3];
	prot = stoi(row[4]);
	dodge = stoi(row[5]);
	speed = stoi(row[6]);
	crit = stoi(row[7]);
	gold = stoi(row[8]);
	for (int i = 9; i < row.size(); i++)
	{
		inventory.push_back(row[i]);
	}
}

void Player::dataSheet()
{
	//creates stat sheet for player to look at
	fstream data;
	data.open("StatSheet.txt", std::ofstream::out | std::ofstream::trunc);
	data.close();
	data.open("StatSheet.txt", ios::out | ios::app);
	data << "Player Stats: \nMax Health: " << maxHealth << "\nSword Name: " << sword << "\nSword Damage: " << strength << "\nArmor Name: " << armor
		<< "\nArmor Protection: " << prot << "\nDodge Level: " << dodge << "\nSpeed Level: " << speed << "\nCrit Level: " << crit << "\nGold: "
		<< gold << "\nInventory: ";
	for (int i = 0; i < inventory.size(); i++)
	{
		if (i > 0)
		{
			data << "| ";
		}
		data <<  inventory[i] << " ";
	}
	data.close();
}
