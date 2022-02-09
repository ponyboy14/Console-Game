#include "enemy.H"
#include "player.H"
#include "arena.H"
#include <iostream>
//Made by Lucas Lasecla

using namespace std;

Arena::Arena()
{
	//sets stats for both player and the enemy
	Enemy enemy;
	enemy.setName();
	enemy.setHealth();
	Player player;
	player.loadPlayer();
	eStrength = enemy.getStrength();
	eName = enemy.getName();
	eHealth = enemy.getHealth();
	eWeapon = enemy.getWeapon();
	eArmor = enemy.getArmor();
	eProt = enemy.getProt();
	pStrength = player.getStrength();
	pMaxHealth = player.getMaxHealth();
	pHealth = player.getMaxHealth();
	pDodge = player.getDodge();
	pSpeed = player.getSpeed();
	pCrit = player.getCrit();
	pProt = player.getProt();
	pArmor = player.getArmor();
	pWeapon = player.getSword();
	pInv = player.getInv();;
	vector<string> nullInv;
	isPDead = false;
	isEDead = false;
	cout << "\nBattling " << eName << " who wields " << eWeapon << " and wears " << eArmor << "\nStrength: " << eStrength << "\nProtection: " << eProt << "\nHealth: " << eHealth << endl;
	int choiceBool = false;
	//option for player to run from fight
	while (choiceBool == false)
	{
		int choice;
		cout << "\n\n[1] Run \n[2] Fight\n";
		cin >> choice;
		if (choice == 1)
		{
			cout << "\nRunning from fight...\n";
			choiceBool = true;
		}
		else if (choice == 2)
		{
			//while loop for fight
			while (isPDead == false && isEDead == false)
			{
				playerTurn();
				srand(clock());
				int skip = rand() % (20 - pSpeed);
				if (skip != 1 && isEDead == false)
				{
					enemyTurn();
				}
				else
				{
					cout << "\nEnemy skipped!\n";
				}
			}
			if (isPDead == false)
			{
				//player won, saves data
				int prize = enemy.getHealth() / 3;
				cout << "\nYou have defeated " << eName << "!! \nCongrats! You won " << prize << " gold!\n";
				player.addGold(prize);
				player.setInv(pInv);
				player.savePlayer();
			}
			else
			{
				//player lost, resets data
				cout << "\n" << eName << " stands victorious as our champion has been defeated.";
				player.createPlayer();
				player.setInv(nullInv);
				player.savePlayer();
				cout << "\nA new warrior has taken our champions place. We will see how they fair in the future.";
			}
			choiceBool = true;
		}
		else
		{
			cout << "\nInalid input...";
		}
	}
	cout << "\n\nLeaving the arena...";
}

Arena::~Arena()
{
}

void Arena::playerTurn()
{
	//player's turn
	srand(clock());
	Player player;
	player.loadPlayer();
	bool pTurn = true;
	//while loop for player to make a choide
	while (pTurn == true)
	{
		cout << "\nYour Turn!\n[1] Attack\n[2] Use Item\n";
		int userIn;
		cin >> userIn;
		if (userIn == 1)
		{
			//player attacks enemy with different variables affecting the damage
			int critHit = rand() % (20 - pCrit);
			if (critHit == 1)
			{
				cout << "\nCritical hit! " << pStrength + 2 << " damage dealt!";
				eHealth = eHealth - pStrength - 2;
				pTurn = false;
				cout << "\nEnemy health: " << eHealth << "\nYour health: " << pHealth;
			}
			else
			{
				int prot = rand() % (14 - eProt);
				int tempDam;
				if (prot == 1)
				{
					cout << "\nThe enemies armor held up!";
					tempDam = pStrength - 2;
					if (tempDam < 0)
					{
						tempDam = 0;
					}
				}
				else
				{
					tempDam = pStrength;
				}
				cout << "\n" << tempDam << " damage dealt!";
				eHealth = eHealth - tempDam;
				pTurn = false;
				cout << "\nEnemy health: " << eHealth << "\nYour health: " << pHealth;
			}
		}
		else if (userIn == 2)
		{
			bool iTurn = true;
			//while loop for player to use item 
			while (iTurn == true)
			{
				int temp = 1;
				cout << "\nDisplaying your inventory...";
				for (int i = 0; i < pInv.size(); i++)
				{
					cout << "\n[" << i + 1 << "] " << pInv[i];
					temp++;
				}
				cout << "\n[" << temp << "] Cancel\n";
				int iChoice;
				cin >> iChoice;
				iChoice = iChoice - 1;
				if (iChoice == temp - 1)
				{
					cout << "\nReturning to your turn...";
					iTurn = false;
				}
				else if (iChoice < 0 || iChoice > pInv.size())
				{
					cout << "\nInvalid input";
				}
				else
				{
					string item = pInv[iChoice];
					if (item == healthP)
					{
						pHealth = pHealth + 5;
						if (pHealth > pMaxHealth)
						{
							pHealth = pMaxHealth;
						}
						cout << "\nPotion used! \nEnemy health: " << eHealth << "\nYour health: " << pHealth;
					}
					else if (item == strengthP)
					{
						pStrength = pStrength + 1;
						cout << "\nPotion used! \nNew strength for fight: " << pStrength << " \nEnemy health: " << eHealth << "\nYour health: " << pHealth;
					}
					else if (item == speedP)
					{
						pSpeed = pSpeed + 1;
						cout << "\nPotion used! \nNew speed for fight: " << pSpeed << " \nEnemy health: " << eHealth << "\nYour health: " << pHealth;
					}
					else if (item == dodgeP)
					{
						pSpeed = pSpeed + 1;
						cout << "\nPotion used! \nNew dodge for fight: " << pDodge << " \nEnemy health: " << eHealth << "\nYour health: " << pHealth;
					}
					removeInv(item);
					iTurn = false;
					pTurn = false;
				}
			}

		}
	}
	if (eHealth <= 0)
	{
		isEDead = true;
	}

}

void Arena::enemyTurn()
{
	//enemy's turn
	cout << "\nEnemy's turn!";
	srand(clock());
	int dodge = rand() % (20 - pDodge);
	//if else statement to choose how much damage the player recieves
	if (dodge == 1)
	{
		cout << "\nAttacked dodged!";
		cout << "\nEnemy health: " << eHealth << "\nYour health: " << pHealth;
	}
	else
	{
		int prot = rand() % (14 - pProt);
		int tempDam;
		if (prot == 1)
		{
			cout << "\nYour armor held up!";
			tempDam = eStrength - 2;
			if (tempDam < 0)
			{
				tempDam = 0;
			}
		}
		else
		{
			tempDam = eStrength;
		}
		cout << "\n" << tempDam << " damage recieved!";
		pHealth = pHealth - tempDam;
		cout << "\nEnemy health: " << eHealth << "\nYour health: " << pHealth;
	}
	if (pHealth <= 0)
	{
		isPDead = true;
	}
}

void Arena::removeInv(string item)
{
	//function that removes an item from the inventory once the item is used
		int index = 0;
		bool isThere;
		for (int i = 0; i < pInv.size(); i++)
		{
			if (pInv[i] == item)
			{
				index = i;
				isThere = true;
				break;
			}
			else
			{
				isThere = false;
			}
		}
		if (isThere == true)
		{
			pInv.erase(pInv.begin() + index);
		}
		else
		{
			cout << "Item not found." << endl;
		}
}
