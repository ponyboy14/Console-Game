#pragma once
#ifndef Equipment_H
#define Equipment_H
#include <string>
//Made by Lucas Lasecla
//Explained in cpp


using namespace std;

class Equipment
{
public:
	Equipment();
	~Equipment();
	void setName();
	string getName();

private:
	string names[20] = { "Strength", "Endurance", "Victory", "the Future", "the Enemy's Bane", "Life", "the Brotherhood", "the Naive Son", "the Unbreakable Will", "the Expanse",
						 "Courage", "Honor", "Might", "the Gods", "the Chosen One", "the Grand Legion", "the Fallen", "the Forgotten Past", "Hope", "Heroes to Come" };;
	string name;
};

#endif