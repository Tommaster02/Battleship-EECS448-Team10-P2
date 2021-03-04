#include <iostream>
#include <vector>
#include <string>
#include "Executive.h"
#include "Board.h"
using namespace std;

void TwoPlayerGame()
{
	int shipNum = 0;
	while (true) {
		cout << "Enter the amount of ships you will play with: Enter (1-6) value \n";
		if (cin >> shipNum)
		{
			if (shipNum < 7 && shipNum > 0)
			{
				break;
			}
			else
			{
				cout << "The input range is not valid!\n";
			}
		}
		else
		{
			cout << "input not a number!" << endl;
			cin.clear();
			cin.ignore();
		}
	}
	cout << "\nThe number of ships are:" << shipNum << "\n\n";

	Executive e1(shipNum);
	e1.P1Place();
	e1.P2Place();

	while (true)
	{
		e1.P1Attack();
		if (e1.P1Won())
		{
			cout << "\n----------------------------------------\n";
			cout << "------------PLAYER 1 HAS WON------------";
			cout << "\n----------------------------------------\n";
			break;
		}

		e1.P2Attack();
		if (e1.P2Won())
		{
			cout << "\n----------------------------------------\n";
			cout << "------------PLAYER 2 HAS WON------------";
			cout << "\n----------------------------------------\n";
			break;
		}
	}
}

void OnePlayerGame()
{
	cout << "------------------------------------------------------\n";
	cout << "1 Player Battleship (Player vs. AI)\n\n\n";
	cout << "Select dificulty below:\n";
	cout << "1) Easy\n";
	cout << "2) Medium\n";
	cout << "3) Hard\n";
	int difficulty = 0;
	int error1 = 0;
	do
	{
		cin >> difficulty;
		if (difficulty == 1)
		{
			cout << "---------\n";
			cout << "Easy Mode\n";
			cout << "COMING SOON!\n";
		}
		else if (difficulty == 2)
		{
			cout << "-----------\n";
			cout << "Medium Mode\n";
			cout << "COMING SOON!\n";
		}
		else if (difficulty == 3)
		{
			cout << "---------\n";
			cout << "Hard Mode\n";
			cout << "COMING SOON!\n";
		}
		else
		{
			cout << "Not a valid choice! Please insert an integer (1-3)\n";
			error1 = 1;
		}
	} while (error1 == 1);
}

void SpecialGame()
{
	cout << "------------------------------------------------------\n";
	cout << "2 Player *Special* Battleship (Player vs. Player)\n\n\n";
	cout << "Player 1:\nSelect a leader & their special ability:\n";
	cout << "1) Admiral Ankeey\n";
	cout << "2) Battleship Brandon\n";
	cout << "3) Captain Wilhelm\n";
	cout << "4) Commander Tom\n";

	int leader = 0;
	int error2 = 0;

	do
	{
		cin >> leader;
		if (leader == 1)
		{
			cout << "You selected Admiral Ankeey!\n\n Special ability: ";
			cout << "";
		}
		else if (leader == 2)
		{
			cout << "You selected Battleship Brandon!\n\n Special ability: ";
			cout << "";
		}
		else if (leader == 3)
		{
			cout << "You selected Captain Wilhelm!\n\n Special ability: ";
			cout << "";
		}
		else if (leader == 4)
		{
			cout << "You selected Commander Tom!\n\n Special ability: ";
			cout << "";
		}
		else
		{
			cout << "Not a valid choice! Please insert an integer (1-4)\n";
			error2 = 1;
		}
	} while (error2 == 1);
	cout << endl << "-----------------------------------------\n\n\n\n\n";
	int shipNum = 0;

	while (true) {
		cout << "Enter the amount of ships you will play with: Enter (1-6) value \n";
		if (cin >> shipNum)
		{
			if (shipNum < 7 && shipNum > 0)
			{
				break;
			}
			else
			{
				cout << "The input range is not valid!\n";
			}
		}
		else
		{
			cout << "input not a number!" << endl;
			cin.clear();
			cin.ignore();
		}
	}
	cout << "\nThe number of ships are:" << shipNum << "\n\n";

	Executive e1(shipNum);
	e1.P1Place();
	e1.P2Place();

	while (true)
	{
		e1.P1Attack();
		if (e1.P1Won())
		{
			cout << "\n----------------------------------------\n";
			cout << "------------PLAYER 1 HAS WON------------";
			cout << "\n----------------------------------------\n";
			break;
		}

		e1.P2Attack();
		if (e1.P2Won())
		{
			cout << "\n----------------------------------------\n";
			cout << "------------PLAYER 2 HAS WON------------";
			cout << "\n----------------------------------------\n";
			break;
		}

	}
}

void Rules()
{
	cout << "COMING SOON!\n";
}


void PrintMenu()
{
	int error = 0;
	int choice = 0;
	cout << "------------------------------------------------------\n";
	cout << "Welcome to Battleship!\n\n\n";
	cout << "Pick one of the game modes or a list of rules below:\n";
	cout << "1) 2 Player Battleship (Player vs. Player)\n";
	cout << "2) 1 Player Battleship (Player vs. AI)\n";
	cout << "3) 2 Player *Special* Battleship (Player vs. Player)\n";
	cout << "4) Rules of Modes\n";
	cout << "------------------------------------------------------\n";
	do
	{
		cin >> choice;
		if (choice == 1)
		{
			TwoPlayerGame();
		}
		else if (choice == 2)
		{
			OnePlayerGame();
		}
		else if (choice == 3)
		{
			SpecialGame();
		}
		else if (choice == 4)
		{
			Rules();
		}
		else if (choice < 1 || choice > 4)
		{
			cout << "Not a valid choice! Please insert an integer (1-4)\n";
			error = 1;
		}
	} while (error == 1);
}

int main()
{
	PrintMenu();
}
