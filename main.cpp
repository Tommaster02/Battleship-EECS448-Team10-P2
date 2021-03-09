#include <iostream>
#include <vector>
#include <string>
#include "Executive.h"
#include "Board.h"
using namespace std;


void TwoPlayerGame()
{
	int turn = 0;
	int turn2 = 0;
	int mode = 1;
	int leader = 0;
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
			cin.ignore(1000, '\n');
		}
	}
	cout << "\nThe number of ships are:" << shipNum << "\n\n";

	Executive e1(shipNum);
	e1.P1Place();
	e1.P2Place();

	while (true)
	{
		e1.P1Attack(mode, leader, turn);
		if (e1.P1Won())
		{
			cout << "\n----------------------------------------\n";
			cout << "------------PLAYER 1 HAS WON------------";
			cout << "\n----------------------------------------\n";
			break;
		}

		e1.P2Attack(mode, leader, turn2);
		if (e1.P2Won())
		{
			cout << "\n----------------------------------------\n";
			cout << "------------PLAYER 2 HAS WON------------";
			cout << "\n----------------------------------------\n";
			break;
		}
	}
}

void Play(int d)
{
	int turn = 0;
	int shipNum = 0;
	int mode = 1;
	int leader = 0;
	int difficulty = d;
	int ship = 0;
	int hit = 0;
	vector<vector<pair<int, int>>> cheat;
	struct Point p1 { 0, 0, 0, 0, 0, 0, 0, 0};
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
			cin.ignore(1000, '\n');
		}
	}
	cout << "\nThe number of ships are:" << shipNum << "\n\n";

	Executive e1(shipNum);
	e1.P1Place();
	e1.AIPlacement();

	cheat = e1.cheatGet();

	while (true)
	{
		e1.P1Attack(mode, leader, turn);
		if (e1.P1Won())
		{
			cout << "\n----------------------------------------\n";
			cout << "------------PLAYER 1 HAS WON------------";
			cout << "\n----------------------------------------\n";

			break;
		}

		p1 = e1.AIAttack(difficulty, p1, cheat, ship, hit);
		if (e1.P2Won())
		{
			cout << "\n----------------------------------------\n";
			cout << "------------AI HAS WON------------";
			cout << "\n----------------------------------------\n";
			break;
		}
	}
}

void OnePlayerGame()
{
	int mode = 2;
	int leader = 0;
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
			Play(difficulty);
		}
		else if (difficulty == 2)
		{
			cout << "-----------\n";
			cout << "Medium Mode\n";
			Play(difficulty);
		}
		else if (difficulty == 3)
		{
			cout << "---------\n";
			cout << "Hard Mode\n";
			Play(difficulty);
		}
		else
		{
			cout << "Not a valid choice! Please insert an integer (1-3)\n";
			cin.clear();
			cin.ignore(1000, '\n');
			error1 = 1;
		}
	} while (error1 == 1);
}

void SpecialGame()
{
	int mode = 3;
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
			cout << "Laser";
		}
		else if (leader == 2)
		{
			cout << "You selected Battleship Brandon!\n\n Special ability: ";
			cout << "Shotgun";
		}
		else if (leader == 3)
		{
			cout << "You selected Captain Wilhelm!\n\n Special ability: ";
			cout << "Rain of Death";
		}
		else if (leader == 4)
		{
			cout << "You selected Commander Tom!\n\n Special ability: ";
			cout << "Ring of Fire";
		}
		else
		{
			cout << "Not a valid choice! Please insert an integer (1-4)\n";
			cin.clear();
			cin.ignore(1000, '\n');
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
		int turn = 1;
		cout << "Player 1 Turn " << turn << endl;
		e1.P1Attack(mode, leader, turn);
		turn++;

		if (e1.P1Won())
		{
			cout << "\n----------------------------------------\n";
			cout << "------------PLAYER 1 HAS WON------------";
			cout << "\n----------------------------------------\n";
			break;
		}
		int turn2 = 1;
		cout << "Player 2 Turn " << turn2 << endl;
		e1.P2Attack(mode, leader, turn2);
		turn2++;

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
	int error0 = 0;
	int choice0 = 0;
	string c;
	do
	{
		cout << "WHICH MODE WOULD YOU LIKE HELP WITH? (1-3) \n";
		cout << "1) 2 Player Battleship (Player vs. Player)\n";
		cout << "2) 1 Player Battleship (Player vs. AI)\n";
		cout << "3) 2 Player *Special* Battleship (Player vs. Player)\n";
		cin >> choice0;
		if (choice0 == 1)
		{
			cout << "player vs player.txt \n";
			cout << "Would you like help with another gamemode? (Enter N to exit from Help menu) \n";
			cin >> c;
			if ((c == "N")||(c =="n")) {
				cout << "Returning you to the main menu\n";
				return;
			}
			else{
				Rules();
				return;
			}
		}
		else if (choice0 == 2)
		{
			cout << "player vs AI.txt";
			cout << "Would you like help with another gamemode? (Enter N to exit from Help menu) \n";
			cin >> c;
			if ((c == "N") || (c == "n")) {
				cout << "Returning you to the main menu\n";
				return;
			}
			else {
				Rules();
				return;
			}
		}
		else if (choice0 == 3)
		{
			cout << "player vs player special mode.txt";
			cout << "Would you like help with another gamemode? (Enter N to exit from Help menu) \n";
			cin >> c;
			if ((c == "N") || (c == "n")) {
				cout << "Returning you to the main menu\n";
				return;
			}
			else {
				Rules();
				return;
			}
		}
		else if (choice0 < 1 || choice0 > 3)
		{
			cout << "Not a valid choice! Please insert an integer (1-3)\n";
			cin.clear();
			cin.ignore(1000, '\n');
			error0 = 1;
		}
	} while (error0 == 1);
}


void PrintMenu()
{
	int error = 0;
	int choice = 0;
	do
	{
		cout << "------------------------------------------------------\n";
		cout << "Welcome to Battleship!\n\n\n";
		cout << "Pick one of the game modes or a list of rules below:\n";
		cout << "1) 2 Player Battleship (Player vs. Player)\n";
		cout << "2) 1 Player Battleship (Player vs. AI)\n";
		cout << "3) 2 Player *Special* Battleship (Player vs. Player)\n";
		cout << "4) Rules of Modes\n";
		cout << "------------------------------------------------------\n";
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
			cin.clear();
			cin.ignore(1000, '\n');
			error = 1;
		}
	} while (error == 1);
}

int main()
{
	PrintMenu();
}
