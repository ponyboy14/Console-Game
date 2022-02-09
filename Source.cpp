#include "arena.h"
#include "shop.h"
#include "player.h"
#include <iostream>
#include <string>
//Made by Lucas Lasecla
using namespace std;

int main()
{
	Player player;
	bool temp = false;
	//while loop for player to choose to load or create a player
	while (temp == false)
	{
		cout << "Welcome! Would you like to [1] Create New Player or [2] Load a Player?\n";
		int num;
		cin >> num;
		if (num == 1)
		{
			cout << "\nCreating Player...";
			player.createPlayer();
			player.savePlayer();
			cout << "Done!";
			temp = true;
		}
		else if (num == 2)
		{
			cout << "\nLoading Player...";
			player.loadPlayer();
			player.savePlayer();
			cout << "Done!";
			temp = true;
		}
		else
		{
			cout << "\nInvalid response...";
		}
	}
	bool isDone = false;
	//while loop to run the game
	while (isDone == false)
	{
		cout << "\nWhat would you like to do?\n[1] Shop\n[2] Arena\n[3] Exit\n";
		int userIn;
		cin >> userIn;
		if (userIn == 1)
		{
			cout << "\nTravelling to the marketplace...";
			Shop shop;
		}
		else if (userIn == 2)
		{
			cout << "\nTravelling to the arena...";
			Arena arena;
		}
		else if (userIn == 3)
		{
			cout << "\nExiting...";
			isDone = true;
		}
		else
		{
			cout << "\nInvalid response...";
		}


	}
}