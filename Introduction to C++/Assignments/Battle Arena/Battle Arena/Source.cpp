#include <iostream>
#include "player.h"
#include "enemy.h"
#include <stdlib.h>
using namespace std;

int nPlayerInput; // Player Input.
int nTurn = 0; // Number of turns.
int randAction = rand() % 100 + 1; // Random AI action.

void bubbleSort(enemy* pEnemy[], int n) // Sorts enemies by their health.
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (pEnemy[j]->getHealth() > pEnemy[j + 1]->getHealth())
			{
				enemy* temp = pEnemy[j];
				pEnemy[j] = pEnemy[j + 1];
				pEnemy[j + 1] = temp;
			}
		}
	}
}

int tutorial(enemy* pEnemy, player* pPlayer)
{
	char kTutorialBattle;
	system("cls");
	cout << endl; cout << "                           Welcome to Battle Arena!" << endl; cout << endl;
	cout << "In this game you will fight through enemies until you reach the end." << endl; cout << "You will be able to choose from several actions for dealing with different enemies:" << endl; cout << endl;
	cout << "Attack - Deals damage to the enemy." << endl; cout << "Block - Decreases the amount of damage taken and increases your STAMINA slightly." << endl; cout << "Run - Evade all damage at the cost of STAMINA." << endl; cout << "Bandage - Heals you by 30." << endl; cout << endl;
	cout << "To select an action, type the number corresponding to the action. ( Attack = 1 , Block = 2 , Run = 3 , Bandage = 4 )" << endl;
	cout << "Each enemy has different stats, meaning that they all act differently from one another." << endl;
	cout << "Your HEALTH will be displayed after every round of attacks as well as your STAMINA." << endl;
	cout << "They will appear like this:" << endl; cout << endl;
	cout << "Health : " << pPlayer->getHealth() << endl;
	cout << "Stamina : " << pPlayer->getStamina() << endl; cout << endl;
	cout << "Your HEALTH and STAMINA will decrease depending on the actions undertaken." << endl;
	cout << "Running will decrease your STAMINA more compared to attacking." << endl;
	cout << "STAMINA will increase over time while HEALTH will only be increased by using a bandage." << endl;
	cout << "Becareful as you only have a certain amount of bandages before you run out." << endl;
	cout << "Would you like to start the tutorial battle? Selecting no will start the game. ( y / n )" << endl;
	cin >> kTutorialBattle;
	
	if (kTutorialBattle == 'y') // If player selects yes to stating the tutorial battle.
	{
		do
		{ 
			nTurn++;
			if (pPlayer->getStamina() < 100)
				pPlayer->setStamina(pPlayer->getStamina() + 5); // Increment stamina by 5 per turn.
			if (pPlayer->getStamina() > 100)
				pPlayer->setStamina(100);
			// Failsafe if player stamina is higher than the max of 100.

			if (pEnemy->getStamina() < 100)
				pEnemy->setStamina(pEnemy->getStamina() + 5); // Increment stamina by 5 per turn.
			if (pEnemy->getStamina() > 100)
				pEnemy->setStamina(100);
			// Failsafe if enemy stamina is higher than the max of 100.

			system("cls");
			cout << endl; cout << "                           Tutorial Battle!" << endl;
			cout << "                                Turn " << nTurn << endl;
			cout << "A WILD " << pEnemy->getName() << " APPROACHES!" << endl; cout << endl;
			cout << pEnemy->getName() <<"'s Stats" << endl;
			cout << "Health : " << pEnemy->getHealth() << " | " << "Stamina : " << pEnemy->getStamina() << endl; cout << endl; cout << endl;
			cout << "Your Stats" << endl;
			cout << "Health : " << pPlayer->getHealth() << " | " << "Stamina : " << pPlayer->getStamina() << " | " << "Bandages : " << pPlayer->getBandage() << endl; cout << endl; cout << endl;
			// Displayed stats of both the player and enemy.

			randAction = rand() % 100 + 1; // Random AI action.

			do
			{
				cout << "What would you like to do ( 1 = attack | 2 = block | 3 = run | 4 = bandage ) : "; cin >> nPlayerInput;
				if (nPlayerInput != 1 && nPlayerInput != 2 && nPlayerInput != 3 && nPlayerInput != 4 || cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "Please input a valid action." << endl;
				}
				
				if (nPlayerInput == 1 && pPlayer->getStamina() < 25)
				{
					cin.clear();
					cin.ignore();
					cout << "You don't have enough stamina to attack." << endl;
				}

				if (nPlayerInput == 3 && pPlayer->getStamina() < 50)
				{
					cin.clear();
					cin.ignore();
					cout << "You don't have enough stamina to run." << endl;
				}

				if (nPlayerInput == 4 && pPlayer->getBandage() == 0)
				{
					cin.clear();
					cin.ignore();
					cout << "You don't have any bandages." << endl;
				}
			} while (nPlayerInput != 1 && nPlayerInput != 2 && nPlayerInput != 3 && nPlayerInput != 4 || cin.fail());

			if (nPlayerInput == 1 && pPlayer->getStamina() >= 25) // Player attacks.
			{
				if (randAction <= 50 && pEnemy->getStamina() >= 25) // Enemy attacks.
				{
					cout << "You attack the " << pEnemy->getName() << " and deal " << pPlayer->getDamage() << " damage." << endl;
					cout << "Your attack has decreased your stamina." << endl;
					pEnemy->setHealth(pEnemy->getHealth() - pPlayer->getDamage());
					pPlayer->setStamina(pPlayer->getStamina() - 25);

					cout << "The " << pEnemy->getName() << " has decided to ATTACK, it has delt " << pEnemy->getDamage() << " damage." << endl;
					pEnemy->setStamina(pEnemy->getStamina() - 25);
					cout << "Its stamina has been decreased." << endl;
					pPlayer->setHealth(pPlayer->getHealth() - pEnemy->getDamage());
					system("pause");
				}
				else if (randAction <= 50 && pEnemy->getStamina() < 25) // Enemy blocks if not enough stamina.
				{
					cout << "The " << pEnemy->getName() << " has decided to BLOCK. Its stamina has been increased and the damage from your attack has been reduced." << endl;
					cout << "You attack the chicken and deal " << pPlayer->getBlockDamage() << " damage." << endl;
					cout << "Your attack has decreased your stamina." << endl;
					pEnemy->setHealth(pEnemy->getHealth() - pPlayer->getBlockDamage());
					pPlayer->setStamina(pPlayer->getStamina() - 25);
					pEnemy->setStamina(pEnemy->getStamina() + 20);
					system("pause");
				}
				else if (randAction <= 76 && randAction >= 51) // Enemy blocks.
				{
					cout << "The " << pEnemy->getName() << " has decided to BLOCK. Its stamina has been increased and the damage from your attack has been reduced." << endl;
					cout << "You attack the chicken and deal " << pPlayer->getBlockDamage() << " damage." << endl;
					cout << "Your attack has decreased your stamina." << endl;
					pEnemy->setHealth(pEnemy->getHealth() - pPlayer->getBlockDamage());
					pPlayer->setStamina(pPlayer->getStamina() - 25);
					pEnemy->setStamina(pEnemy->getStamina() + 20);
					system("pause");
				}
				else if (randAction <= 100 && randAction >= 77 && pEnemy->getStamina() >= 50) // Enemy runs.
				{
					cout << "The " << pEnemy->getName() << " has decided to RUN. It has evaded all damage but its stamina has been significantly decreased." << endl;
					pEnemy->setStamina(pEnemy->getStamina() - 50);
					cout << "Your attack has missed and has reduced your stamina." << endl;
					pPlayer->setStamina(pPlayer->getStamina() - 25);
					system("pause");
				}
				else if (randAction <= 100 && randAction >= 77 && pEnemy->getStamina() < 50) // Enemy blocks if not enough stamina.
				{
					cout << "The " << pEnemy->getName() << " has decided to BLOCK. Its stamina has been increased and the damage from your attack has been reduced." << endl;
					cout << "You attack the chicken and deal " << pPlayer->getBlockDamage() << " damage." << endl;
					cout << "Your attack has decreased your stamina." << endl;
					pEnemy->setHealth(pEnemy->getHealth() - pPlayer->getBlockDamage());
					pPlayer->setStamina(pPlayer->getStamina() - 25);
					pEnemy->setStamina(pEnemy->getStamina() + 20);
				}
			}

			if (nPlayerInput == 2) // Player blocks.
			{
				if (randAction <= 50 && pEnemy->getStamina() >= 25) // Enemy attacks.
				{
					cout << "Your block has reduced the damage from the " << pEnemy->getName() << " and has increased your stamina." << endl;

					cout << "The " << pEnemy->getName() << " has decided to ATTACK, it has delt " << pEnemy->getBlockDamage() << " damage." << endl;
					cout << "Its stamina has been decreased." << endl;
					pEnemy->setStamina(pEnemy->getStamina() - 25);
					pPlayer->setStamina(pPlayer->getStamina() + 20);
					pPlayer->setHealth(pPlayer->getHealth() - pEnemy->getBlockDamage());
					system("pause");
				}
				else if (randAction <= 50 && pEnemy->getStamina() < 25) // Enemy blocks if not enough stamina.
				{
					cout << "The " << pEnemy->getName() << " has decided to BLOCK. Its stamina has been increased." << endl;
					cout << "Your block has increased your stamina." << endl;
					pEnemy->setStamina(pEnemy->getStamina() + 20);
					pPlayer->setStamina(pPlayer->getStamina() + 20);
					system("pause");
				}
				else if (randAction <= 76 && randAction >= 51) // Enemy blocks.
				{
					cout << "The " << pEnemy->getName() << " has decided to BLOCK. Its stamina has been increased." << endl;
					cout << "Your block has increased your stamina." << endl;
					pEnemy->setStamina(pEnemy->getStamina() + 20);
					pPlayer->setStamina(pPlayer->getStamina() + 20);
					system("pause");
				}
				else if (randAction <= 100 && randAction >= 77 && pEnemy->getStamina() >= 50) // Enemy runs.
				{
					cout << "The " << pEnemy->getName() << " has decided to RUN. Its stamina has been significantly decreased." << endl;
					cout << "Your block has increased your stamina." << endl;
					pEnemy->setStamina(pEnemy->getStamina() - 50);
					pPlayer->setStamina(pPlayer->getStamina() + 20);
					system("pause");
				}
				else if (randAction <= 100 && randAction >= 77 && pEnemy->getStamina() < 50) // Enemy blocks if not enough stamina.
				{
					cout << "The " << pEnemy->getName() << " has decided to BLOCK. Its stamina has been increased." << endl;
					cout << "Your block has increased your stamina." << endl;
					pEnemy->setStamina(pEnemy->getStamina() + 20);
					pPlayer->setStamina(pPlayer->getStamina() + 20);
					system("pause");
				}
			}

			if (nPlayerInput == 3 && pPlayer->getStamina() >= 50) // Player runs.
			{
				if (randAction <= 50 && pEnemy->getStamina() >= 25) // Enemy attacks.
				{
					cout << "The " << pEnemy->getName() << " has decided to ATTACK, however you are too quick and it misses." << endl;
					cout << "Its stamina has been reduced." << endl;
					cout << "Your stamina has been significantly decreased." << endl;
					pPlayer->setStamina(pPlayer->getStamina() - 50);
					pEnemy->setStamina(pEnemy->getStamina() - 25);
					system("pause");
				}
				else if (randAction <= 50 && pEnemy->getStamina() < 25) // Enemy blocks if not enough stamina.
				{
					cout << "The " << pEnemy->getName() << " has decided to BLOCK, its stamina has been increased." << endl;
					cout << "Your stamina has been significantly decreased." << endl;
					pPlayer->setStamina(pPlayer->getStamina() - 50);
					pEnemy->setStamina(pEnemy->getStamina() + 20);
					system("pause");
				}
				else if (randAction <= 76 && randAction >= 51) // Enemy blocks.
				{
					cout << "The " << pEnemy->getName() << " has decided to BLOCK, its stamina has been increased." << endl;
					cout << "Your stamina has been significantly decreased." << endl;
					pPlayer->setStamina(pPlayer->getStamina() - 50);
					pEnemy->setStamina(pEnemy->getStamina() + 20);
					system("pause");
				}
				else if (randAction <= 100 && randAction >= 77 && pEnemy->getStamina() >= 50) // Enemy runs.
				{
					cout << "The " << pEnemy->getName() << " has decided to RUN, its stamina has significantly decreased." << endl;
					cout << "Your stamina has been significantly decreased." << endl;
					pPlayer->setStamina(pPlayer->getStamina() - 50);
					pEnemy->setStamina(pEnemy->getStamina() - 50);
					system("pause");
				}
				else if (randAction <= 100 && randAction >= 77 && pEnemy->getStamina() >= 50) // Enemy blocks if not enough stamina.
				{
					cout << "The " << pEnemy->getName() << " has decided to BLOCK, its stamina has been increased." << endl;
					cout << "Your stamina has been significantly decreased." << endl;
					pPlayer->setStamina(pPlayer->getStamina() - 50);
					pEnemy->setStamina(pEnemy->getStamina() + 20);
					system("pause");
				}
			}
			if (nPlayerInput == 4 && pPlayer->getBandage() != 0) // Player bandages.
			{
				if (randAction <= 50 && pEnemy->getStamina() >= 25) // Enemy attacks.
				{
					pPlayer->setHealth(pPlayer->getHealth() + 35);
					pPlayer->setBandage(pPlayer->getBandage() - 1);

					if (pPlayer->getHealth() > 100)
					{
						pPlayer->setHealth(100);
					}
					cout << "You bandage yourself, your health is now " << pPlayer->getHealth() << endl;
					cout << "The " << pEnemy->getName() << " has decided to ATTACK, it has delt " << pEnemy->getDamage() << " damage." << endl;
					cout << "Its stamina has been decreased." << endl;
					pPlayer->setHealth(pPlayer->getHealth() - pEnemy->getDamage());
					pEnemy->setStamina(pEnemy->getStamina() - 25);
					system("pause");
				}
				else if (randAction <= 50 && pEnemy->getStamina() < 25) // Enemy blocks if not enough stamina.
				{
					pPlayer->setHealth(pPlayer->getHealth() + 35);
					pPlayer->setBandage(pPlayer->getBandage() - 1);

					if (pPlayer->getHealth() > 100)
					{
						pPlayer->setHealth(100);
					}
					cout << "You bandage yourself, your health is now " << pPlayer->getHealth() << endl;
					cout << "The " << pEnemy->getName() << " has decided to BLOCK, its stamina has been increased." << endl;
					pEnemy->setStamina(pEnemy->getStamina() + 20);
					system("pause");
				}
				else if (randAction <= 76 && randAction >= 51) // Enemy blocks. 
				{
					pPlayer->setHealth(pPlayer->getHealth() + 35);
					pPlayer->setBandage(pPlayer->getBandage() - 1);

					if (pPlayer->getHealth() > 100)
					{
						pPlayer->setHealth(100);
					}
					cout << "You bandage yourself, your health is now " << pPlayer->getHealth() << endl;
					cout << "The " << pEnemy->getName() << " has decided to BLOCK, its stamina has been increased." << endl;
					pEnemy->setStamina(pEnemy->getStamina() + 20);
					system("pause");
				}
				else if (randAction <= 100 && randAction >= 67 && pEnemy->getStamina() >= 50) // Enemy runs.
				{
					pPlayer->setHealth(pPlayer->getHealth() + 35);
					pPlayer->setBandage(pPlayer->getBandage() - 1);

					if (pPlayer->getHealth() > 100)
					{
						pPlayer->setHealth(100);
					}
					cout << "You bandage yourself, your health is now " << pPlayer->getHealth() << endl;
					cout << "The " << pEnemy->getName() << " has decided to RUN, its stamina has been significantly reduced." << endl;
					pEnemy->setStamina(pEnemy->getStamina() - 50);
					system("pause");
				}
				else if (randAction <= 100 && randAction >= 67 && pEnemy->getStamina() < 50) // Enemy blocks if not enough stamina.
				{
					pPlayer->setHealth(pPlayer->getHealth() + 35);
					pPlayer->setBandage(pPlayer->getBandage() - 1);

					if (pPlayer->getHealth() > 100)
					{
						pPlayer->setHealth(100);
					}
					cout << "You bandage yourself, your health is now " << pPlayer->getHealth() << endl;
					cout << "The " << pEnemy->getName() << " has decided to BLOCK, its stamina has been increased." << endl;
					pEnemy->setStamina(pEnemy->getStamina() + 20);
					system("pause");
				}
			}
		} while (pEnemy->getHealth() > 0 && pPlayer->getHealth() > 0); // Break loop when either enemy or player health becomes 0.
		
		if (pEnemy->getHealth() <= 0)
		{
			pEnemy->setHealth(0); // Sets health to 0 if the current health is below 0.
			system("cls");
			cout << endl; cout << "                           Tutorial Battle!" << endl;
			cout << "                                Turn " << nTurn << endl;
			cout << "A WILD " << pEnemy->getName() << " APPROACHES!" << endl; cout << endl;
			cout << pEnemy->getName() << "'s Stats" << endl;
			cout << "Health : " << pEnemy->getHealth() << " | " << "Stamina : " << pEnemy->getStamina() << endl; cout << endl; cout << endl;
			cout << "Your Stats" << endl;
			cout << "Health : " << pPlayer->getHealth() << " | " << "Stamina : " << pPlayer->getStamina() << " | " << "Bandages : " << pPlayer->getBandage() << endl; cout << endl; cout << endl;
			nTurn = 0;
			cout << "           Congratulations! You defeated the " << pEnemy->getName() << "!" << endl;
			cout << "You are now ready to start." << endl;
			system("pause");
		}
		else if (pPlayer->getHealth() <= 0)
		{
			pPlayer->setHealth(0); // Sets health to 0 if the current health is below 0.
			system("cls");
			cout << endl; cout << "                           Tutorial Battle!" << endl;
			cout << "                                Turn " << nTurn << endl;
			cout << "A WILD " << pEnemy->getName() << " APPROACHES!" << endl; cout << endl;
			cout << pEnemy->getName() << "'s Stats" << endl;
			cout << "Health : " << pEnemy->getHealth() << " | " << "Stamina : " << pEnemy->getStamina() << endl; cout << endl; cout << endl;
			cout << "Your Stats" << endl;
			cout << "Health : " << pPlayer->getHealth() << " | " << "Stamina : " << pPlayer->getStamina() << " | " << "Bandages : " << pPlayer->getBandage() << endl; cout << endl; cout << endl;
			nTurn = 0;
			cout << "           You were defeated by the " << pEnemy->getName() << "!" << endl;
			
			return 0;
			system("pause");
		}
	}
}	
int levelOne(enemy* pEnemy, player* pPlayer)
{
	pPlayer->setHealth(100); // Resets player health to 100.
	pPlayer->setStamina(100); // Resets player stamina to 100.
	do
	{
		nTurn++;
		if (pPlayer->getStamina() < 100)
			pPlayer->setStamina(pPlayer->getStamina() + 5); // Increment stamina by 5 per turn.
		if (pPlayer->getStamina() > 100)
			pPlayer->setStamina(100);
		// Failsafe if player stamina is higher than the max of 100.

		if (pEnemy->getStamina() < 100)
			pEnemy->setStamina(pEnemy->getStamina() + 5); // Increment stamina by 5 per turn.
		if (pEnemy->getStamina() > 100)
			pEnemy->setStamina(100);
		// Failsafe if enemy stamina is higher than the max of 100.

		system("cls");
		cout << endl; cout << "                           LEVEL ONE!" << endl;
		cout << "                                Turn " << nTurn << endl;
		cout << "A WILD " << pEnemy->getName() << " APPROACHES!" << endl; cout << endl;
		cout << pEnemy->getName() << "'s Stats" << endl;
		cout << "Health : " << pEnemy->getHealth() << " | " << "Stamina : " << pEnemy->getStamina() << endl; cout << endl; cout << endl;
		cout << "Your Stats" << endl;
		cout << "Health : " << pPlayer->getHealth() << " | " << "Stamina : " << pPlayer->getStamina() << " | " << "Bandages : " << pPlayer->getBandage() << endl; cout << endl; cout << endl;
		// Displayed stats of both the player and enemy.

		randAction = rand() % 100 + 1; // Random AI action.

		do
		{
			cout << "What would you like to do ( 1 = attack | 2 = block | 3 = run | 4 = bandage ) : "; cin >> nPlayerInput;
			if (nPlayerInput != 1 && nPlayerInput != 2 && nPlayerInput != 3 && nPlayerInput != 4 || cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "Please input a valid action." << endl;
			}

			if (nPlayerInput == 1 && pPlayer->getStamina() < 25)
			{
				cin.clear();
				cin.ignore();
				cout << "You don't have enough stamina to attack." << endl;
			}

			if (nPlayerInput == 3 && pPlayer->getStamina() < 50)
			{
				cin.clear();
				cin.ignore();
				cout << "You don't have enough stamina to run." << endl;
			}

			if (nPlayerInput == 4 && pPlayer->getBandage() == 0)
			{
				cin.clear();
				cin.ignore();
				cout << "You don't have any bandages." << endl;
			}
		} while (nPlayerInput != 1 && nPlayerInput != 2 && nPlayerInput != 3 && nPlayerInput != 4 || cin.fail());

		if (nPlayerInput == 1 && pPlayer->getStamina() >= 25) // Player attacks.
		{
			if (randAction <= 50 && pEnemy->getStamina() >= 25) // Enemy attacks.
			{
				cout << "You attack the " << pEnemy->getName() << " and deal " << pPlayer->getDamage() << " damage." << endl;
				cout << "Your attack has decreased your stamina." << endl;
				pEnemy->setHealth(pEnemy->getHealth() - pPlayer->getDamage());
				pPlayer->setStamina(pPlayer->getStamina() - 25);

				cout << "The " << pEnemy->getName() << " has decided to ATTACK, it has delt " << pEnemy->getDamage() << " damage." << endl;
				pEnemy->setStamina(pEnemy->getStamina() - 25);
				cout << "Its stamina has been decreased." << endl;
				pPlayer->setHealth(pPlayer->getHealth() - pEnemy->getDamage());
				system("pause");
			}
			else if (randAction <= 50 && pEnemy->getStamina() < 25) // Enemy blocks if not enough stamina.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK. Its stamina has been increased and the damage from your attack has been reduced." << endl;
				cout << "You attack the chicken and deal " << pPlayer->getBlockDamage() << " damage." << endl;
				cout << "Your attack has decreased your stamina." << endl;
				pEnemy->setHealth(pEnemy->getHealth() - pPlayer->getBlockDamage());
				pPlayer->setStamina(pPlayer->getStamina() - 25);
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 76 && randAction >= 51) // Enemy blocks.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK. Its stamina has been increased and the damage from your attack has been reduced." << endl;
				cout << "You attack the chicken and deal " << pPlayer->getBlockDamage() << " damage." << endl;
				cout << "Your attack has decreased your stamina." << endl;
				pEnemy->setHealth(pEnemy->getHealth() - pPlayer->getBlockDamage());
				pPlayer->setStamina(pPlayer->getStamina() - 25);
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 100 && randAction >= 77 && pEnemy->getStamina() >= 50) // Enemy runs.
			{
				cout << "The " << pEnemy->getName() << " has decided to RUN. It has evaded all damage but its stamina has been significantly decreased." << endl;
				pEnemy->setStamina(pEnemy->getStamina() - 50);
				cout << "Your attack has missed and has reduced your stamina." << endl;
				pPlayer->setStamina(pPlayer->getStamina() - 25);
				system("pause");
			}
			else if (randAction <= 100 && randAction >= 77 && pEnemy->getStamina() < 50) // Enemy blocks if not enough stamina.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK. Its stamina has been increased and the damage from your attack has been reduced." << endl;
				cout << "You attack the chicken and deal " << pPlayer->getBlockDamage() << " damage." << endl;
				cout << "Your attack has decreased your stamina." << endl;
				pEnemy->setHealth(pEnemy->getHealth() - pPlayer->getBlockDamage());
				pPlayer->setStamina(pPlayer->getStamina() - 25);
				pEnemy->setStamina(pEnemy->getStamina() + 20);
			}
		}

		if (nPlayerInput == 2) // Player blocks.
		{
			if (randAction <= 50 && pEnemy->getStamina() >= 25) // Enemy attacks.
			{
				cout << "Your block has reduced the damage from the " << pEnemy->getName() << " and has increased your stamina." << endl;

				cout << "The " << pEnemy->getName() << " has decided to ATTACK, it has delt " << pEnemy->getBlockDamage() << " damage." << endl;
				cout << "Its stamina has been decreased." << endl;
				pEnemy->setStamina(pEnemy->getStamina() - 25);
				pPlayer->setStamina(pPlayer->getStamina() + 20);
				pPlayer->setHealth(pPlayer->getHealth() - pEnemy->getBlockDamage());
				system("pause");
			}
			else if (randAction <= 50 && pEnemy->getStamina() < 25) // Enemy blocks if not enough stamina.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK. Its stamina has been increased." << endl;
				cout << "Your block has increased your stamina." << endl;
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				pPlayer->setStamina(pPlayer->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 76 && randAction >= 51) // Enemy blocks.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK. Its stamina has been increased." << endl;
				cout << "Your block has increased your stamina." << endl;
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				pPlayer->setStamina(pPlayer->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 100 && randAction >= 77 && pEnemy->getStamina() >= 50) // Enemy runs.
			{
				cout << "The " << pEnemy->getName() << " has decided to RUN. Its stamina has been significantly decreased." << endl;
				cout << "Your block has increased your stamina." << endl;
				pEnemy->setStamina(pEnemy->getStamina() - 50);
				pPlayer->setStamina(pPlayer->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 100 && randAction >= 77 && pEnemy->getStamina() < 50) // Enemy blocks if not enough stamina.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK. Its stamina has been increased." << endl;
				cout << "Your block has increased your stamina." << endl;
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				pPlayer->setStamina(pPlayer->getStamina() + 20);
				system("pause");
			}
		}

		if (nPlayerInput == 3 && pPlayer->getStamina() >= 50) // Player runs.
		{
			if (randAction <= 50 && pEnemy->getStamina() >= 25) // Enemy attacks.
			{
				cout << "The " << pEnemy->getName() << " has decided to ATTACK, however you are too quick and it misses." << endl;
				cout << "Its stamina has been reduced." << endl;
				cout << "Your stamina has been significantly decreased." << endl;
				pPlayer->setStamina(pPlayer->getStamina() - 50);
				pEnemy->setStamina(pEnemy->getStamina() - 25);
				system("pause");
			}
			else if (randAction <= 50 && pEnemy->getStamina() < 25) // Enemy blocks if not enough stamina.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK, its stamina has been increased." << endl;
				cout << "Your stamina has been significantly decreased." << endl;
				pPlayer->setStamina(pPlayer->getStamina() - 50);
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 76 && randAction >= 51) // Enemy blocks.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK, its stamina has been increased." << endl;
				cout << "Your stamina has been significantly decreased." << endl;
				pPlayer->setStamina(pPlayer->getStamina() - 50);
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 100 && randAction >= 77 && pEnemy->getStamina() >= 50) // Enemy runs.
			{
				cout << "The " << pEnemy->getName() << " has decided to RUN, its stamina has significantly decreased." << endl;
				cout << "Your stamina has been significantly decreased." << endl;
				pPlayer->setStamina(pPlayer->getStamina() - 50);
				pEnemy->setStamina(pEnemy->getStamina() - 50);
				system("pause");
			}
			else if (randAction <= 100 && randAction >= 77 && pEnemy->getStamina() >= 50) // Enemy blocks if not enough stamina.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK, its stamina has been increased." << endl;
				cout << "Your stamina has been significantly decreased." << endl;
				pPlayer->setStamina(pPlayer->getStamina() - 50);
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				system("pause");
			}
		}
		if (nPlayerInput == 4 && pPlayer->getBandage() != 0) // Player bandages.
		{
			if (randAction <= 50 && pEnemy->getStamina() >= 25) // Enemy attacks.
			{
				pPlayer->setHealth(pPlayer->getHealth() + 35);
				pPlayer->setBandage(pPlayer->getBandage() - 1);

				if (pPlayer->getHealth() > 100)
				{
					pPlayer->setHealth(100);
				}
				cout << "You bandage yourself, your health is now " << pPlayer->getHealth() << endl;
				cout << "The " << pEnemy->getName() << " has decided to ATTACK, it has delt " << pEnemy->getDamage() << " damage." << endl;
				cout << "Its stamina has been decreased." << endl;
				pPlayer->setHealth(pPlayer->getHealth() - pEnemy->getDamage());
				pEnemy->setStamina(pEnemy->getStamina() - 25);
				system("pause");
			}
			else if (randAction <= 50 && pEnemy->getStamina() < 25) // Enemy blocks if not enough stamina.
			{
				pPlayer->setHealth(pPlayer->getHealth() + 35);
				pPlayer->setBandage(pPlayer->getBandage() - 1);

				if (pPlayer->getHealth() > 100)
				{
					pPlayer->setHealth(100);
				}
				cout << "You bandage yourself, your health is now " << pPlayer->getHealth() << endl;
				cout << "The " << pEnemy->getName() << " has decided to BLOCK, its stamina has been increased." << endl;
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 76 && randAction >= 51) // Enemy blocks. 
			{
				pPlayer->setHealth(pPlayer->getHealth() + 35);
				pPlayer->setBandage(pPlayer->getBandage() - 1);

				if (pPlayer->getHealth() > 100)
				{
					pPlayer->setHealth(100);
				}
				cout << "You bandage yourself, your health is now " << pPlayer->getHealth() << endl;
				cout << "The " << pEnemy->getName() << " has decided to BLOCK, its stamina has been increased." << endl;
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 100 && randAction >= 67 && pEnemy->getStamina() >= 50) // Enemy runs.
			{
				pPlayer->setHealth(pPlayer->getHealth() + 35);
				pPlayer->setBandage(pPlayer->getBandage() - 1);

				if (pPlayer->getHealth() > 100)
				{
					pPlayer->setHealth(100);
				}
				cout << "You bandage yourself, your health is now " << pPlayer->getHealth() << endl;
				cout << "The " << pEnemy->getName() << " has decided to RUN, its stamina has been significantly reduced." << endl;
				pEnemy->setStamina(pEnemy->getStamina() - 50);
				system("pause");
			}
			else if (randAction <= 100 && randAction >= 67 && pEnemy->getStamina() < 50) // Enemy blocks if not enough stamina.
			{
				pPlayer->setHealth(pPlayer->getHealth() + 35);
				pPlayer->setBandage(pPlayer->getBandage() - 1);

				if (pPlayer->getHealth() > 100)
				{
					pPlayer->setHealth(100);
				}
				cout << "You bandage yourself, your health is now " << pPlayer->getHealth() << endl;
				cout << "The " << pEnemy->getName() << " has decided to BLOCK, its stamina has been increased." << endl;
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				system("pause");
			}
		}
	} while (pEnemy->getHealth() > 0 && pPlayer->getHealth() > 0); // Break loop when either enemy or player health becomes 0.

	if (pEnemy->getHealth() <= 0)
	{
		pEnemy->setHealth(0); // Sets health to 0 if the current health is below 0.
		system("cls");
		cout << endl; cout << "                           LEVEL ONE!" << endl;
		cout << "                                Turn " << nTurn << endl;
		cout << "A WILD " << pEnemy->getName() << " APPROACHES!" << endl; cout << endl;
		cout << pEnemy->getName() << "'s Stats" << endl;
		cout << "Health : " << pEnemy->getHealth() << " | " << "Stamina : " << pEnemy->getStamina() << endl; cout << endl; cout << endl;
		cout << "Your Stats" << endl;
		cout << "Health : " << pPlayer->getHealth() << " | " << "Stamina : " << pPlayer->getStamina() << " | " << "Bandages : " << pPlayer->getBandage() << endl; cout << endl; cout << endl;
		nTurn = 0;
		cout << "           Congratulations! You defeated the " << pEnemy->getName() << "!" << endl;
		system("pause");
	}
	else if (pPlayer->getHealth() <= 0)
	{
		pPlayer->setHealth(0); // Sets health to 0 if the current health is below 0.
		system("cls");
		cout << endl; cout << "                           LEVEL ONE!" << endl;
		cout << "                                Turn " << nTurn << endl;
		cout << "A WILD " << pEnemy->getName() << " APPROACHES!" << endl; cout << endl;
		cout << pEnemy->getName() << "'s Stats" << endl;
		cout << "Health : " << pEnemy->getHealth() << " | " << "Stamina : " << pEnemy->getStamina() << endl; cout << endl; cout << endl;
		cout << "Your Stats" << endl;
		cout << "Health : " << pPlayer->getHealth() << " | " << "Stamina : " << pPlayer->getStamina() << " | " << "Bandages : " << pPlayer->getBandage() << endl; cout << endl; cout << endl;
		nTurn = 0;
		cout << "           You were defeated by the " << pEnemy->getName() << "!" << endl;

		return 0;
		system("pause");
	}
}
int levelTwo(enemy* pEnemy, player* pPlayer)
{
	pPlayer->setHealth(100);
	pPlayer->setStamina(100);
	do
	{
		nTurn++;
		if (pPlayer->getStamina() < 100)
			pPlayer->setStamina(pPlayer->getStamina() + 5); // Increment stamina by 5 per turn.
		if (pPlayer->getStamina() > 100)
			pPlayer->setStamina(100);
		// Failsafe if player stamina is higher than the max of 100.

		if (pEnemy->getStamina() < 100)
			pEnemy->setStamina(pEnemy->getStamina() + 5); // Increment stamina by 5 per turn.
		if (pEnemy->getStamina() > 100)
			pEnemy->setStamina(100);
		// Failsafe if enemy stamina is higher than the max of 100.

		system("cls");
		cout << endl; cout << "                           LEVEL TWO!" << endl;
		cout << "                                Turn " << nTurn << endl;
		cout << "A WILD " << pEnemy->getName() << " APPROACHES!" << endl; cout << endl;
		cout << pEnemy->getName() << "'s Stats" << endl;
		cout << "Health : " << pEnemy->getHealth() << " | " << "Stamina : " << pEnemy->getStamina() << endl; cout << endl; cout << endl;
		cout << "Your Stats" << endl;
		cout << "Health : " << pPlayer->getHealth() << " | " << "Stamina : " << pPlayer->getStamina() << " | " << "Bandages : " << pPlayer->getBandage() << endl; cout << endl; cout << endl;
		// Displayed stats of both the player and enemy.

		randAction = rand() % 100 + 1; // Random AI action.

		do
		{
			cout << "What would you like to do ( 1 = attack | 2 = block | 3 = run | 4 = bandage ) : "; cin >> nPlayerInput;
			if (nPlayerInput != 1 && nPlayerInput != 2 && nPlayerInput != 3 && nPlayerInput != 4 || cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "Please input a valid action." << endl;
			}

			if (nPlayerInput == 1 && pPlayer->getStamina() < 25)
			{
				cin.clear();
				cin.ignore();
				cout << "You don't have enough stamina to attack." << endl;
			}

			if (nPlayerInput == 3 && pPlayer->getStamina() < 50)
			{
				cin.clear();
				cin.ignore();
				cout << "You don't have enough stamina to run." << endl;
			}

			if (nPlayerInput == 4 && pPlayer->getBandage() == 0)
			{
				cin.clear();
				cin.ignore();
				cout << "You don't have any bandages." << endl;
			}
		} while (nPlayerInput != 1 && nPlayerInput != 2 && nPlayerInput != 3 && nPlayerInput != 4 || cin.fail());

		if (nPlayerInput == 1 && pPlayer->getStamina() >= 25) // Player attacks.
		{
			if (randAction <= 50 && pEnemy->getStamina() >= 25) // Enemy attacks.
			{
				cout << "You attack the " << pEnemy->getName() << " and deal " << pPlayer->getDamage() << " damage." << endl;
				cout << "Your attack has decreased your stamina." << endl;
				pEnemy->setHealth(pEnemy->getHealth() - pPlayer->getDamage());
				pPlayer->setStamina(pPlayer->getStamina() - 25);

				cout << "The " << pEnemy->getName() << " has decided to ATTACK, it has delt " << pEnemy->getDamage() << " damage." << endl;
				pEnemy->setStamina(pEnemy->getStamina() - 25);
				cout << "Its stamina has been decreased." << endl;
				pPlayer->setHealth(pPlayer->getHealth() - pEnemy->getDamage());
				system("pause");
			}
			else if (randAction <= 50 && pEnemy->getStamina() < 25) // Enemy blocks if not enough stamina.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK. Its stamina has been increased and the damage from your attack has been reduced." << endl;
				cout << "You attack the chicken and deal " << pPlayer->getBlockDamage() << " damage." << endl;
				cout << "Your attack has decreased your stamina." << endl;
				pEnemy->setHealth(pEnemy->getHealth() - pPlayer->getBlockDamage());
				pPlayer->setStamina(pPlayer->getStamina() - 25);
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 76 && randAction >= 51) // Enemy blocks.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK. Its stamina has been increased and the damage from your attack has been reduced." << endl;
				cout << "You attack the chicken and deal " << pPlayer->getBlockDamage() << " damage." << endl;
				cout << "Your attack has decreased your stamina." << endl;
				pEnemy->setHealth(pEnemy->getHealth() - pPlayer->getBlockDamage());
				pPlayer->setStamina(pPlayer->getStamina() - 25);
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 100 && randAction >= 77 && pEnemy->getStamina() >= 50) // Enemy runs.
			{
				cout << "The " << pEnemy->getName() << " has decided to RUN. It has evaded all damage but its stamina has been significantly decreased." << endl;
				pEnemy->setStamina(pEnemy->getStamina() - 50);
				cout << "Your attack has missed and has reduced your stamina." << endl;
				pPlayer->setStamina(pPlayer->getStamina() - 25);
				system("pause");
			}
			else if (randAction <= 100 && randAction >= 77 && pEnemy->getStamina() < 50) // Enemy blocks if not enough stamina.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK. Its stamina has been increased and the damage from your attack has been reduced." << endl;
				cout << "You attack the chicken and deal " << pPlayer->getBlockDamage() << " damage." << endl;
				cout << "Your attack has decreased your stamina." << endl;
				pEnemy->setHealth(pEnemy->getHealth() - pPlayer->getBlockDamage());
				pPlayer->setStamina(pPlayer->getStamina() - 25);
				pEnemy->setStamina(pEnemy->getStamina() + 20);
			}
		}

		if (nPlayerInput == 2) // Player blocks.
		{
			if (randAction <= 50 && pEnemy->getStamina() >= 25) // Enemy attacks.
			{
				cout << "Your block has reduced the damage from the " << pEnemy->getName() << " and has increased your stamina." << endl;

				cout << "The " << pEnemy->getName() << " has decided to ATTACK, it has delt " << pEnemy->getBlockDamage() << " damage." << endl;
				cout << "Its stamina has been decreased." << endl;
				pEnemy->setStamina(pEnemy->getStamina() - 25);
				pPlayer->setStamina(pPlayer->getStamina() + 20);
				pPlayer->setHealth(pPlayer->getHealth() - pEnemy->getBlockDamage());
				system("pause");
			}
			else if (randAction <= 50 && pEnemy->getStamina() < 25) // Enemy blocks if not enough stamina.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK. Its stamina has been increased." << endl;
				cout << "Your block has increased your stamina." << endl;
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				pPlayer->setStamina(pPlayer->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 76 && randAction >= 51) // Enemy blocks.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK. Its stamina has been increased." << endl;
				cout << "Your block has increased your stamina." << endl;
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				pPlayer->setStamina(pPlayer->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 100 && randAction >= 77 && pEnemy->getStamina() >= 50) // Enemy runs.
			{
				cout << "The " << pEnemy->getName() << " has decided to RUN. Its stamina has been significantly decreased." << endl;
				cout << "Your block has increased your stamina." << endl;
				pEnemy->setStamina(pEnemy->getStamina() - 50);
				pPlayer->setStamina(pPlayer->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 100 && randAction >= 77 && pEnemy->getStamina() < 50) // Enemy blocks if not enough stamina.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK. Its stamina has been increased." << endl;
				cout << "Your block has increased your stamina." << endl;
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				pPlayer->setStamina(pPlayer->getStamina() + 20);
				system("pause");
			}
		}

		if (nPlayerInput == 3 && pPlayer->getStamina() >= 50) // Player runs.
		{
			if (randAction <= 50 && pEnemy->getStamina() >= 25) // Enemy attacks.
			{
				cout << "The " << pEnemy->getName() << " has decided to ATTACK, however you are too quick and it misses." << endl;
				cout << "Its stamina has been reduced." << endl;
				cout << "Your stamina has been significantly decreased." << endl;
				pPlayer->setStamina(pPlayer->getStamina() - 50);
				pEnemy->setStamina(pEnemy->getStamina() - 25);
				system("pause");
			}
			else if (randAction <= 50 && pEnemy->getStamina() < 25) // Enemy blocks if not enough stamina.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK, its stamina has been increased." << endl;
				cout << "Your stamina has been significantly decreased." << endl;
				pPlayer->setStamina(pPlayer->getStamina() - 50);
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 76 && randAction >= 51) // Enemy blocks.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK, its stamina has been increased." << endl;
				cout << "Your stamina has been significantly decreased." << endl;
				pPlayer->setStamina(pPlayer->getStamina() - 50);
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 100 && randAction >= 77 && pEnemy->getStamina() >= 50) // Enemy runs.
			{
				cout << "The " << pEnemy->getName() << " has decided to RUN, its stamina has significantly decreased." << endl;
				cout << "Your stamina has been significantly decreased." << endl;
				pPlayer->setStamina(pPlayer->getStamina() - 50);
				pEnemy->setStamina(pEnemy->getStamina() - 50);
				system("pause");
			}
			else if (randAction <= 100 && randAction >= 77 && pEnemy->getStamina() >= 50) // Enemy blocks if not enough stamina.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK, its stamina has been increased." << endl;
				cout << "Your stamina has been significantly decreased." << endl;
				pPlayer->setStamina(pPlayer->getStamina() - 50);
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				system("pause");
			}
		}
		if (nPlayerInput == 4 && pPlayer->getBandage() != 0) // Player bandages.
		{
			if (randAction <= 50 && pEnemy->getStamina() >= 25) // Enemy attacks.
			{
				pPlayer->setHealth(pPlayer->getHealth() + 35);
				pPlayer->setBandage(pPlayer->getBandage() - 1);

				if (pPlayer->getHealth() > 100)
				{
					pPlayer->setHealth(100);
				}
				cout << "You bandage yourself, your health is now " << pPlayer->getHealth() << endl;
				cout << "The " << pEnemy->getName() << " has decided to ATTACK, it has delt " << pEnemy->getDamage() << " damage." << endl;
				cout << "Its stamina has been decreased." << endl;
				pPlayer->setHealth(pPlayer->getHealth() - pEnemy->getDamage());
				pEnemy->setStamina(pEnemy->getStamina() - 25);
				system("pause");
			}
			else if (randAction <= 50 && pEnemy->getStamina() < 25) // Enemy blocks if not enough stamina.
			{
				pPlayer->setHealth(pPlayer->getHealth() + 35);
				pPlayer->setBandage(pPlayer->getBandage() - 1);

				if (pPlayer->getHealth() > 100)
				{
					pPlayer->setHealth(100);
				}
				cout << "You bandage yourself, your health is now " << pPlayer->getHealth() << endl;
				cout << "The " << pEnemy->getName() << " has decided to BLOCK, its stamina has been increased." << endl;
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 76 && randAction >= 51) // Enemy blocks. 
			{
				pPlayer->setHealth(pPlayer->getHealth() + 35);
				pPlayer->setBandage(pPlayer->getBandage() - 1);

				if (pPlayer->getHealth() > 100)
				{
					pPlayer->setHealth(100);
				}
				cout << "You bandage yourself, your health is now " << pPlayer->getHealth() << endl;
				cout << "The " << pEnemy->getName() << " has decided to BLOCK, its stamina has been increased." << endl;
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 100 && randAction >= 67 && pEnemy->getStamina() >= 50) // Enemy runs.
			{
				pPlayer->setHealth(pPlayer->getHealth() + 35);
				pPlayer->setBandage(pPlayer->getBandage() - 1);

				if (pPlayer->getHealth() > 100)
				{
					pPlayer->setHealth(100);
				}
				cout << "You bandage yourself, your health is now " << pPlayer->getHealth() << endl;
				cout << "The " << pEnemy->getName() << " has decided to RUN, its stamina has been significantly reduced." << endl;
				pEnemy->setStamina(pEnemy->getStamina() - 50);
				system("pause");
			}
			else if (randAction <= 100 && randAction >= 67 && pEnemy->getStamina() < 50) // Enemy blocks if not enough stamina.
			{
				pPlayer->setHealth(pPlayer->getHealth() + 35);
				pPlayer->setBandage(pPlayer->getBandage() - 1);

				if (pPlayer->getHealth() > 100)
				{
					pPlayer->setHealth(100);
				}
				cout << "You bandage yourself, your health is now " << pPlayer->getHealth() << endl;
				cout << "The " << pEnemy->getName() << " has decided to BLOCK, its stamina has been increased." << endl;
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				system("pause");
			}
		}
	} while (pEnemy->getHealth() > 0 && pPlayer->getHealth() > 0); // Break loop when either enemy or player health becomes 0.

	if (pEnemy->getHealth() <= 0)
	{
		pEnemy->setHealth(0); // Sets health to 0 if the current health is below 0.
		system("cls");
		cout << endl; cout << "                           LEVEL TWO!" << endl;
		cout << "                                Turn " << nTurn << endl;
		cout << "A WILD " << pEnemy->getName() << " APPROACHES!" << endl; cout << endl;
		cout << pEnemy->getName() << "'s Stats" << endl;
		cout << "Health : " << pEnemy->getHealth() << " | " << "Stamina : " << pEnemy->getStamina() << endl; cout << endl; cout << endl;
		cout << "Your Stats" << endl;
		cout << "Health : " << pPlayer->getHealth() << " | " << "Stamina : " << pPlayer->getStamina() << " | " << "Bandages : " << pPlayer->getBandage() << endl; cout << endl; cout << endl;
		nTurn = 0;
		cout << "           Congratulations! You defeated the " << pEnemy->getName() << "!" << endl;
		system("pause");
	}
	else if (pPlayer->getHealth() <= 0)
	{
		pPlayer->setHealth(0); // Sets health to 0 if the current health is below 0.
		system("cls");
		cout << endl; cout << "                           LEVEL TWO!" << endl;
		cout << "                                Turn " << nTurn << endl;
		cout << "A WILD " << pEnemy->getName() << " APPROACHES!" << endl; cout << endl;
		cout << pEnemy->getName() << "'s Stats" << endl;
		cout << "Health : " << pEnemy->getHealth() << " | " << "Stamina : " << pEnemy->getStamina() << endl; cout << endl; cout << endl;
		cout << "Your Stats" << endl;
		cout << "Health : " << pPlayer->getHealth() << " | " << "Stamina : " << pPlayer->getStamina() << " | " << "Bandages : " << pPlayer->getBandage() << endl; cout << endl; cout << endl;
		nTurn = 0;
		cout << "           You were defeated by the " << pEnemy->getName() << "!" << endl;

		return 0;
		system("pause");
	}
}
int levelThree(enemy* pEnemy, player* pPlayer)
{
	pPlayer->setHealth(100);
	pPlayer->setStamina(100);
	do
	{
		nTurn++;
		if (pPlayer->getStamina() < 100)
			pPlayer->setStamina(pPlayer->getStamina() + 5); // Increment stamina by 5 per turn.
		if (pPlayer->getStamina() > 100)
			pPlayer->setStamina(100);
		// Failsafe if player stamina is higher than the max of 100.

		if (pEnemy->getStamina() < 100)
			pEnemy->setStamina(pEnemy->getStamina() + 5); // Increment stamina by 5 per turn.
		if (pEnemy->getStamina() > 100)
			pEnemy->setStamina(100);
		// Failsafe if enemy stamina is higher than the max of 100.

		system("cls");
		cout << endl; cout << "                           LEVEL THREE!" << endl;
		cout << "                                Turn " << nTurn << endl;
		cout << "A WILD " << pEnemy->getName() << " APPROACHES!" << endl; cout << endl;
		cout << pEnemy->getName() << "'s Stats" << endl;
		cout << "Health : " << pEnemy->getHealth() << " | " << "Stamina : " << pEnemy->getStamina() << endl; cout << endl; cout << endl;
		cout << "Your Stats" << endl;
		cout << "Health : " << pPlayer->getHealth() << " | " << "Stamina : " << pPlayer->getStamina() << " | " << "Bandages : " << pPlayer->getBandage() << endl; cout << endl; cout << endl;
		// Displayed stats of both the player and enemy.

		randAction = rand() % 100 + 1; // Random AI action.

		do
		{
			cout << "What would you like to do ( 1 = attack | 2 = block | 3 = run | 4 = bandage ) : "; cin >> nPlayerInput;
			if (nPlayerInput != 1 && nPlayerInput != 2 && nPlayerInput != 3 && nPlayerInput != 4 || cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "Please input a valid action." << endl;
			}

			if (nPlayerInput == 1 && pPlayer->getStamina() < 25)
			{
				cin.clear();
				cin.ignore();
				cout << "You don't have enough stamina to attack." << endl;
			}

			if (nPlayerInput == 3 && pPlayer->getStamina() < 50)
			{
				cin.clear();
				cin.ignore();
				cout << "You don't have enough stamina to run." << endl;
			}

			if (nPlayerInput == 4 && pPlayer->getBandage() == 0)
			{
				cin.clear();
				cin.ignore();
				cout << "You don't have any bandages." << endl;
			}
		} while (nPlayerInput != 1 && nPlayerInput != 2 && nPlayerInput != 3 && nPlayerInput != 4 || cin.fail());

		if (nPlayerInput == 1 && pPlayer->getStamina() >= 25) // Player attacks.
		{
			if (randAction <= 50 && pEnemy->getStamina() >= 25) // Enemy attacks.
			{
				cout << "You attack the " << pEnemy->getName() << " and deal " << pPlayer->getDamage() << " damage." << endl;
				cout << "Your attack has decreased your stamina." << endl;
				pEnemy->setHealth(pEnemy->getHealth() - pPlayer->getDamage());
				pPlayer->setStamina(pPlayer->getStamina() - 25);

				cout << "The " << pEnemy->getName() << " has decided to ATTACK, it has delt " << pEnemy->getDamage() << " damage." << endl;
				pEnemy->setStamina(pEnemy->getStamina() - 25);
				cout << "Its stamina has been decreased." << endl;
				pPlayer->setHealth(pPlayer->getHealth() - pEnemy->getDamage());
				system("pause");
			}
			else if (randAction <= 50 && pEnemy->getStamina() < 25) // Enemy blocks if not enough stamina.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK. Its stamina has been increased and the damage from your attack has been reduced." << endl;
				cout << "You attack the chicken and deal " << pPlayer->getBlockDamage() << " damage." << endl;
				cout << "Your attack has decreased your stamina." << endl;
				pEnemy->setHealth(pEnemy->getHealth() - pPlayer->getBlockDamage());
				pPlayer->setStamina(pPlayer->getStamina() - 25);
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 76 && randAction >= 51) // Enemy blocks.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK. Its stamina has been increased and the damage from your attack has been reduced." << endl;
				cout << "You attack the chicken and deal " << pPlayer->getBlockDamage() << " damage." << endl;
				cout << "Your attack has decreased your stamina." << endl;
				pEnemy->setHealth(pEnemy->getHealth() - pPlayer->getBlockDamage());
				pPlayer->setStamina(pPlayer->getStamina() - 25);
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 100 && randAction >= 77 && pEnemy->getStamina() >= 50) // Enemy runs.
			{
				cout << "The " << pEnemy->getName() << " has decided to RUN. It has evaded all damage but its stamina has been significantly decreased." << endl;
				pEnemy->setStamina(pEnemy->getStamina() - 50);
				cout << "Your attack has missed and has reduced your stamina." << endl;
				pPlayer->setStamina(pPlayer->getStamina() - 25);
				system("pause");
			}
			else if (randAction <= 100 && randAction >= 77 && pEnemy->getStamina() < 50) // Enemy blocks if not enough stamina.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK. Its stamina has been increased and the damage from your attack has been reduced." << endl;
				cout << "You attack the chicken and deal " << pPlayer->getBlockDamage() << " damage." << endl;
				cout << "Your attack has decreased your stamina." << endl;
				pEnemy->setHealth(pEnemy->getHealth() - pPlayer->getBlockDamage());
				pPlayer->setStamina(pPlayer->getStamina() - 25);
				pEnemy->setStamina(pEnemy->getStamina() + 20);
			}
		}

		if (nPlayerInput == 2) // Player blocks.
		{
			if (randAction <= 50 && pEnemy->getStamina() >= 25) // Enemy attacks.
			{
				cout << "Your block has reduced the damage from the " << pEnemy->getName() << " and has increased your stamina." << endl;

				cout << "The " << pEnemy->getName() << " has decided to ATTACK, it has delt " << pEnemy->getBlockDamage() << " damage." << endl;
				cout << "Its stamina has been decreased." << endl;
				pEnemy->setStamina(pEnemy->getStamina() - 25);
				pPlayer->setStamina(pPlayer->getStamina() + 20);
				pPlayer->setHealth(pPlayer->getHealth() - pEnemy->getBlockDamage());
				system("pause");
			}
			else if (randAction <= 50 && pEnemy->getStamina() < 25) // Enemy blocks if not enough stamina.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK. Its stamina has been increased." << endl;
				cout << "Your block has increased your stamina." << endl;
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				pPlayer->setStamina(pPlayer->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 76 && randAction >= 51) // Enemy blocks.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK. Its stamina has been increased." << endl;
				cout << "Your block has increased your stamina." << endl;
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				pPlayer->setStamina(pPlayer->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 100 && randAction >= 77 && pEnemy->getStamina() >= 50) // Enemy runs.
			{
				cout << "The " << pEnemy->getName() << " has decided to RUN. Its stamina has been significantly decreased." << endl;
				cout << "Your block has increased your stamina." << endl;
				pEnemy->setStamina(pEnemy->getStamina() - 50);
				pPlayer->setStamina(pPlayer->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 100 && randAction >= 77 && pEnemy->getStamina() < 50) // Enemy blocks if not enough stamina.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK. Its stamina has been increased." << endl;
				cout << "Your block has increased your stamina." << endl;
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				pPlayer->setStamina(pPlayer->getStamina() + 20);
				system("pause");
			}
		}

		if (nPlayerInput == 3 && pPlayer->getStamina() >= 50) // Player runs.
		{
			if (randAction <= 50 && pEnemy->getStamina() >= 25) // Enemy attacks.
			{
				cout << "The " << pEnemy->getName() << " has decided to ATTACK, however you are too quick and it misses." << endl;
				cout << "Its stamina has been reduced." << endl;
				cout << "Your stamina has been significantly decreased." << endl;
				pPlayer->setStamina(pPlayer->getStamina() - 50);
				pEnemy->setStamina(pEnemy->getStamina() - 25);
				system("pause");
			}
			else if (randAction <= 50 && pEnemy->getStamina() < 25) // Enemy blocks if not enough stamina.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK, its stamina has been increased." << endl;
				cout << "Your stamina has been significantly decreased." << endl;
				pPlayer->setStamina(pPlayer->getStamina() - 50);
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 76 && randAction >= 51) // Enemy blocks.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK, its stamina has been increased." << endl;
				cout << "Your stamina has been significantly decreased." << endl;
				pPlayer->setStamina(pPlayer->getStamina() - 50);
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 100 && randAction >= 77 && pEnemy->getStamina() >= 50) // Enemy runs.
			{
				cout << "The " << pEnemy->getName() << " has decided to RUN, its stamina has significantly decreased." << endl;
				cout << "Your stamina has been significantly decreased." << endl;
				pPlayer->setStamina(pPlayer->getStamina() - 50);
				pEnemy->setStamina(pEnemy->getStamina() - 50);
				system("pause");
			}
			else if (randAction <= 100 && randAction >= 77 && pEnemy->getStamina() >= 50) // Enemy blocks if not enough stamina.
			{
				cout << "The " << pEnemy->getName() << " has decided to BLOCK, its stamina has been increased." << endl;
				cout << "Your stamina has been significantly decreased." << endl;
				pPlayer->setStamina(pPlayer->getStamina() - 50);
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				system("pause");
			}
		}
		if (nPlayerInput == 4 && pPlayer->getBandage() != 0) // Player bandages.
		{
			if (randAction <= 50 && pEnemy->getStamina() >= 25) // Enemy attacks.
			{
				pPlayer->setHealth(pPlayer->getHealth() + 35);
				pPlayer->setBandage(pPlayer->getBandage() - 1);

				if (pPlayer->getHealth() > 100)
				{
					pPlayer->setHealth(100);
				}
				cout << "You bandage yourself, your health is now " << pPlayer->getHealth() << endl;
				cout << "The " << pEnemy->getName() << " has decided to ATTACK, it has delt " << pEnemy->getDamage() << " damage." << endl;
				cout << "Its stamina has been decreased." << endl;
				pPlayer->setHealth(pPlayer->getHealth() - pEnemy->getDamage());
				pEnemy->setStamina(pEnemy->getStamina() - 25);
				system("pause");
			}
			else if (randAction <= 50 && pEnemy->getStamina() < 25) // Enemy blocks if not enough stamina.
			{
				pPlayer->setHealth(pPlayer->getHealth() + 35);
				pPlayer->setBandage(pPlayer->getBandage() - 1);

				if (pPlayer->getHealth() > 100)
				{
					pPlayer->setHealth(100);
				}
				cout << "You bandage yourself, your health is now " << pPlayer->getHealth() << endl;
				cout << "The " << pEnemy->getName() << " has decided to BLOCK, its stamina has been increased." << endl;
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 76 && randAction >= 51) // Enemy blocks. 
			{
				pPlayer->setHealth(pPlayer->getHealth() + 35);
				pPlayer->setBandage(pPlayer->getBandage() - 1);

				if (pPlayer->getHealth() > 100)
				{
					pPlayer->setHealth(100);
				}
				cout << "You bandage yourself, your health is now " << pPlayer->getHealth() << endl;
				cout << "The " << pEnemy->getName() << " has decided to BLOCK, its stamina has been increased." << endl;
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				system("pause");
			}
			else if (randAction <= 100 && randAction >= 67 && pEnemy->getStamina() >= 50) // Enemy runs.
			{
				pPlayer->setHealth(pPlayer->getHealth() + 35);
				pPlayer->setBandage(pPlayer->getBandage() - 1);

				if (pPlayer->getHealth() > 100)
				{
					pPlayer->setHealth(100);
				}
				cout << "You bandage yourself, your health is now " << pPlayer->getHealth() << endl;
				cout << "The " << pEnemy->getName() << " has decided to RUN, its stamina has been significantly reduced." << endl;
				pEnemy->setStamina(pEnemy->getStamina() - 50);
				system("pause");
			}
			else if (randAction <= 100 && randAction >= 67 && pEnemy->getStamina() < 50) // Enemy blocks if not enough stamina.
			{
				pPlayer->setHealth(pPlayer->getHealth() + 35);
				pPlayer->setBandage(pPlayer->getBandage() - 1);

				if (pPlayer->getHealth() > 100)
				{
					pPlayer->setHealth(100);
				}
				cout << "You bandage yourself, your health is now " << pPlayer->getHealth() << endl;
				cout << "The " << pEnemy->getName() << " has decided to BLOCK, its stamina has been increased." << endl;
				pEnemy->setStamina(pEnemy->getStamina() + 20);
				system("pause");
			}
		}
	} while (pEnemy->getHealth() > 0 && pPlayer->getHealth() > 0); // Break loop when either enemy or player health becomes 0.

	if (pEnemy->getHealth() <= 0)
	{
		pEnemy->setHealth(0); // Sets health to 0 if the current health is below 0.
		system("cls");
		cout << endl; cout << "                           LEVEL THREE!" << endl;
		cout << "                                Turn " << nTurn << endl;
		cout << "A WILD " << pEnemy->getName() << " APPROACHES!" << endl; cout << endl;
		cout << pEnemy->getName() << "'s Stats" << endl;
		cout << "Health : " << pEnemy->getHealth() << " | " << "Stamina : " << pEnemy->getStamina() << endl; cout << endl; cout << endl;
		cout << "Your Stats" << endl;
		cout << "Health : " << pPlayer->getHealth() << " | " << "Stamina : " << pPlayer->getStamina() << " | " << "Bandages : " << pPlayer->getBandage() << endl; cout << endl; cout << endl;
		nTurn = 0;
		cout << "           Congratulations! You defeated the " << pEnemy->getName() << "!" << endl;
		system("pause");
	}
	else if (pPlayer->getHealth() <= 0)
	{
		pPlayer->setHealth(0); // Sets health to 0 if the current health is below 0.
		system("cls");
		cout << endl; cout << "                           LEVEL THREE!" << endl;
		cout << "                                Turn " << nTurn << endl;
		cout << "A WILD " << pEnemy->getName() << " APPROACHES!" << endl; cout << endl;
		cout << pEnemy->getName() << "'s Stats" << endl;
		cout << "Health : " << pEnemy->getHealth() << " | " << "Stamina : " << pEnemy->getStamina() << endl; cout << endl; cout << endl;
		cout << "Your Stats" << endl;
		cout << "Health : " << pPlayer->getHealth() << " | " << "Stamina : " << pPlayer->getStamina() << " | " << "Bandages : " << pPlayer->getBandage() << endl; cout << endl; cout << endl;
		nTurn = 0;
		cout << "           You were defeated by the " << pEnemy->getName() << "!" << endl;

		return 0;
		system("pause");
	}
}

int main()
{
	enemy** pEnemy = new enemy*[4];
	for (int i = 0; i < 4; ++i)
	{
		pEnemy[i] = new enemy(); // Creates 4 enemies.
	}
	pEnemy[0]->setName("ZOMBIE"); // Initialize name.
	pEnemy[0]->setHealth(120); // Initialize health.
	pEnemy[0]->setStamina(100); // Initialize stamina.
	pEnemy[0]->setDamage(20); // Initialize damage.
	pEnemy[0]->setBlockDamage((pEnemy[0]->getDamage() * 25) / 100); // Initialize block damage.

	pEnemy[1]->setName("SKELETON"); // Initialize name.
	pEnemy[1]->setHealth(150); // Initialize health.
	pEnemy[1]->setStamina(100); // Initialize stamina.
	pEnemy[1]->setDamage(25); // Initialize damage.
	pEnemy[1]->setBlockDamage((pEnemy[1]->getDamage() * 25) / 100); // Initialize block damage.

	pEnemy[2]->setName("HOUND"); // Initialize name.
	pEnemy[2]->setHealth(175); // Initialize health.
	pEnemy[2]->setStamina(100); // Initialize stamina.
	pEnemy[2]->setDamage(35); // Initialize damage.
	pEnemy[2]->setBlockDamage((pEnemy[2]->getDamage() * 25) / 100); // Initialize block damage.

	pEnemy[3]->setName("CHICKEN"); // Initialize name.
	pEnemy[3]->setHealth(75); // Initialize health.
	pEnemy[3]->setStamina(100); // Initialize stamina.
	pEnemy[3]->setDamage(15); // Initialize damage.
	pEnemy[3]->setBlockDamage((pEnemy[3]->getDamage() * 25) / 100); // Initialize block damage.

	player* pPlayer = new player(); // Creates player.
	pPlayer->setHealth(100);
	pPlayer->setStamina(100);
	pPlayer->setDamage(35);
	pPlayer->setBandage(3);
	pPlayer->setBlockDamage((pPlayer->getDamage() * 25) / 100);

	char szTutorialStart; // Player input for starting the tutorial.

	cout << endl; cout << "                           Welcome to Battle Arena!" << endl; cout << endl;
	cout << "Would you like to play the tutorial? ( y / n )" << endl;
	cin >> szTutorialStart;

	if (szTutorialStart == 'y')
	{
		tutorial(pEnemy[3], pPlayer); // Tutorial will start first if player selects yes.
		bubbleSort(pEnemy, 4);
		levelOne(pEnemy[0], pPlayer); // Level one.
		bubbleSort(pEnemy, 4);
		levelTwo(pEnemy[1], pPlayer); // Level two.
		bubbleSort(pEnemy, 4);
		levelThree(pEnemy[2], pPlayer); // Level three.
		bubbleSort(pEnemy, 4);
	}
	else if (szTutorialStart == 'n')
	{
		levelOne(pEnemy[0], pPlayer); // Level one.
		bubbleSort(pEnemy, 4);
		levelTwo(pEnemy[1], pPlayer); // Level two.
		bubbleSort(pEnemy, 4);
		levelThree(pEnemy[2], pPlayer); // Level three.
		bubbleSort(pEnemy, 4);
	}
	system("pause");

	for (int i = 0; i < 4; ++i)
	{
		delete pEnemy[i];
	}
	delete[] pEnemy;
	delete pPlayer;
	return 0;
}