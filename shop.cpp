#include "shop.h"
#include "player.h"
#include "weapon.h"
#include "armor.h"
#include <iostream>
//Made by Lucas Lasecla

using namespace std;

Shop::Shop()
{
	//while loop that offers user different shops to go to
	bool leave = false;
	while (leave == false)
	{
		cout << "\n\nPlease enter the number of the store that you wish to visit-\n[1] Equipment Store\n[2] Item Store\n[3] Upgrade Store\n[4] Exit Store\n";
		int userIn = 0;
		cin >> userIn;
		if (userIn == 1)
		{
			cout << "\nTraveling to the equipment store...";
			equipmentStore();
			cout << "\nTraveling back to the marketplace...";
		}
		else if (userIn == 2)
		{
			cout << "\nTraveling to the item store...";
			itemStore();
			cout << "\nTraveling back to the marketplace...";
		}
		else if (userIn == 3)
		{
			cout << "\nTraveling to the upgrade store...";
			upgradeStore();
			cout << "\nTraveling back to the marketplace...";
		}
		else if (userIn == 4)
		{
			cout << "Leaving marketplace...";
			leave = true;
		}
		else
		{
			cout << "Invalid input, please try again...";
		}
	}

}

Shop::~Shop()
{
}

void Shop::equipmentStore()
{
	//equipment shop to buy swords or armor
	Player player;
	player.loadPlayer();
	Armor armor1;
	Armor armor2;
	Weapon sword1;
	Weapon sword2;
	sword1.setDam();
	sword1.setMat();
	sword1.setName();
	int strength1 = sword1.getDam();
	string weapon1 = sword1.getMat() + " sword of " + sword1.getName();
	sword2.setDam();
	sword2.setMat();
	sword2.setName();
	int strength2 = sword2.getDam();
	string weapon2 = sword2.getMat() + " sword of " + sword2.getName();
	armor1.setProt();
	armor1.setMat();
	armor1.setName();
	int prot1 = armor1.getProt();
	string arm1 = armor1.getMat() + " armor of " + armor1.getName();
	armor2.setProt();
	armor2.setMat();
	armor2.setName();
	int prot2 = armor2.getProt();
	string arm2 = armor2.getMat() + " armor of " + armor2.getName();
	bool leaveE = false;
	cout << "\nWelcome warrior! Please look around at my selection!";
	//sets cost for each of the items
	int cost1 = strength1 * 2 + 5;
	int cost2 = strength2 * 2 + 5;
	int cost3 = prot1 * 2 + 5;
	int cost4 = prot2 * 2 + 5;
	//while loop for the user to buy the equipment
	while (leaveE == false)
	{
		cout << "\n\n[1]\t" << weapon1 << "\n\tDamage = " << strength1 << "\n\tCost = " << cost1;
		cout << "\n[2]\t" << weapon2 << "\n\tDamage = " << strength2 << "\n\tCost = " << cost2;
		cout << "\n[3]\t" << arm1 << "\n\tProtection = " << prot1 << "\n\tCost = " << cost3;
		cout << "\n[4]\t" << arm2 << "\n\tProtection = " << prot2 << "\n\tCost = " << cost4;
		cout << "\n[5]\tExit\n\nYour current Gold: " << player.getGold() << "\n";

		int userIn = 0;
		cin >> userIn;
		if (userIn == 1)
		{
			if (player.getGold() >= cost1)
			{
				cout << "\nI would've bought the same!";
				player.setSword(weapon1);
				player.setStrength(strength1);
				player.subtractGold(cost1);
			}
			else
			{
				cout << "\nI'm sorry my friend, seems you cannot afford that.";
			}
		}
		else if (userIn == 2)
		{
			if (player.getGold() >= cost2)
			{
				cout << "\nA mighty fine choice!";
				player.setSword(weapon2);
				player.setStrength(strength2);
				player.subtractGold(cost2);
			}
			else
			{
				cout << "\nI'm sorry my friend, seems you cannot afford that.";
			}
		}
		else if (userIn == 3)
		{
			if (player.getGold() >= cost3)
			{
				cout << "\nIt's a shame to see that one go.";
				player.setArmor(arm1);
				player.setProt(prot1);
				player.subtractGold(cost3);
			}
			else
			{
				cout << "\nI'm sorry my friend, seems you cannot afford that.";
			}
		}
		else if (userIn == 4)
		{
			if (player.getGold() >= cost4)
			{
				cout << "\nI can already hear the stories!";
				player.setArmor(arm2);
				player.setProt(prot2);
				player.subtractGold(cost4);
			}
			else
			{
				cout << "\nI'm sorry my friend, seems you cannot afford that.";
			}
		}
		else if (userIn == 5)
		{
			cout << "\nGlad you stopped by my shop! Hope to see you in the future!";
			leaveE = true;
		}
		else
		{
			cout << "\nInvalid input, please try again...";
		}

	}
	player.savePlayer();
}

void Shop::itemStore()
{
	//store to seel potions
	Player player;
	player.loadPlayer();
	cout << "\nI know a warrior when I see one, how can I be of service?";
	bool leaveI = false;
	//while loop for the player to make their choices
	while (leaveI == false)
	{
		cout << "\nTake a look at my collection, everything cost five gold.";
		cout << "\n\n[1]\t" << healthP << "\n[2]\t" << strengthP << "\n[3]\t" << dodgeP << "\n[4]\t" << speedP << "\n[5]\tExit\n\nYour current Gold: " << player.getGold() << endl;
		int userIn = 0;
		cin >> userIn;
		if (userIn == 1)
		{
			if (player.getGold() >= 5)
			{
				cout << " \nNothing like a health potion to heal your wounds, great choice!";
				player.addInv(healthP);
				player.subtractGold(5);
			}
			else
			{
				cout << "\nThis isn't the first time someone has tried to scam me. Come back when you have enough gold.";
			}
		}
		else if (userIn == 2)
		{
			if (player.getGold() >= 5)
			{
				cout << " \nYour enemies will regret crossing you after you use this strength potion.";
				player.addInv(strengthP);
				player.subtractGold(5);
			}
			else
			{
				cout << "\nThis isn't the first time someone has tried to scam me. Come back when you have enough gold.";
			}
		}
		else if (userIn == 3)
		{
			if (player.getGold() >= 5)
			{
				cout << " \nNothing will be able to hit you now! It is practically unfair!";
				player.addInv(dodgeP);
				player.subtractGold(5);
			}
			else
			{
				cout << "\nThis isn't the first time someone has tried to scam me. Come back when you have enough gold.";
			}
		}
		else if (userIn == 4)
		{
			if (player.getGold() >= 5)
			{
				cout << " \nYou'll be faster than an arrow fired from a crossbow!";
				player.addInv(speedP);
				player.subtractGold(5);
			}
			else
			{
				cout << "\nThis isn't the first time someone has tried to scam me. Come back when you have enough gold.";
			}
		}
		else if (userIn == 5)
		{
			cout << "\nMay our paths meet again in the future my friend!";
			leaveI = true;
		}
		else
		{
			cout << "\nInvalid input, please try again...";
		}

	}
	player.savePlayer();
}

void Shop::upgradeStore()
{
	//store to upgrade a player's stats
	Player player;
	player.loadPlayer();
	cout << " \nCome in need of some changes, yes?";
	bool leaveU = false;
	//while loop for player to choose specific upgrades
	while (leaveU == false)
	{
		cout << "\nWe will help you for ten gold. No more, no less.";
		cout << "\n\n[1]\tMax Health upgrade\n[2]\tDodge Upgrade\n[3]\tSpeed Upgrade\n[4]\tCrit Upgrade\n[5]\tExit\n\nYour current Gold: " << player.getGold() << endl;
		int userIn = 0;
		cin >> userIn;
		if (userIn == 1)
		{
			if (player.getGold() >= 10)
			{
				if (player.getMaxHealth() < 50)
				{
					cout << " \nHealthiness is overrated to us, but to you, helpful it may be.";
					player.addHealth(5);
					player.subtractGold(10);
				}
				else 
				{
					cout << "\nMuch too healthy for us! We cannot take your gold!";
				}
			}
			else
			{
				cout << "\nNo! No! No! That just won't do! We need more gold!";
			}
		}
		else if (userIn == 2)
		{
			if (player.getGold() >= 10)
			{
				if (player.getDodge() < 10)
				{
					cout << " \nTrust us, every strike from your foes will miss now. Yes, yes.";
					player.addDodge(1);
					player.subtractGold(10);
				}
				else
				{
					cout << "\nIt is much too unfair already! We cannot take your gold!";
				}
			}
			else
			{
				cout << "\nNo! No! No! That just won't do! We need more gold!";
			}
		}
		else if (userIn == 3)
		{
			if (player.getGold() >= 10)
			{
				if (player.getSpeed() < 10)
				{
					cout << " \nYes, yes. now you are the hare versus the tortoise... Or was it the other way around?";
					player.addSpeed(1);
					player.subtractGold(10);
				}
				else
				{
					cout << "\nWe cannot even catch you! We cannot take your gold!";
				}
			}
			else
			{
				cout << "\nNo! No! No! That just won't do! We need more gold!";
			}
		}
		else if (userIn == 4)
		{
			if (player.getGold() >= 10)
			{
				if (player.getCrit() < 10)
				{
					cout << " \nTrying to be the next Hercules?";
					player.addCrit(1);
					player.subtractGold(10);
				}
				else
				{
					cout << "\nToo strong already! We cannot take your gold!";
				}
			}
			else
			{
				cout << "\nNo! No! No! That just won't do! We need more gold!";
			}
		}
		else if (userIn == 5)
		{
			cout << "\nYou will see us again... I promise...";
			leaveU = true;
		}
		else
		{
			cout << "\nInvalid input, please try again...";
		}
	}
	player.savePlayer();
}
