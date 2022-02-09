#include "equipment.H"
#include <ctime>
#include <time.h>
#include <chrono>
#include <iostream>
//Made by Lucas Lasecla

using namespace std;

Equipment::Equipment()
{

}

Equipment::~Equipment()
{
}

void Equipment::setName()
{
	//adds a name for the piece of equipment using a random number generator
	srand(clock());
	int index;
	index = rand() % 20;
	cout << index << endl;
	name = names[index];
}

string Equipment::getName()
{
	// returns name of equipment
	return name;
}
