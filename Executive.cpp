#include "Executive.h"
#include"Board.h"
#include "string"
#include <cctype>
#include <ctime>
using namespace std;

Executive::Executive(int num)
{
	m_shipNum = num;
	P1Board1.setShipNum(num);
	P1Board1.setShipsVector(num);
	P1Board1.setShipsLeft(num);
	P2Board2.setShipNum(num);
	P2Board2.setShipsVector(num);
	P2Board2.setShipsLeft(num);
}

void Executive::P1Place()
{
	bool placing = true;
	int count = m_shipNum;

	while (placing)
	{
		cout << "\n----------------------------------------\n";
		cout << "           --Player 1 board--             \n";
		cout << "\n----------------------------------------\n";
		P1Board1.printBoard();
		int c;

		while ((c = getchar()) != '\n' && c != EOF);

		if (count == m_shipNum)//count=6
		{
			cout << "\n ----------------------------------------\n";
			cout << "\nLet's start with the 1x1 ship!\n";
			cout << "Player 1, What row would you like to place the 1x1 ship: ";
			row2 = row1 = inputNumber(1, 10);

			cout << "Player 1, What column would you like to place the 1x1 ship: ";
			col2 = col1 = inputAlphabet('A', 'J');
		}
		else
		{
			cout << "\n----------------------------------------\nThis is a 1x" << (m_shipNum - count) + 1 << " ship.\n";
			cout << "Player 1, What row would you like to place the front of the ship: ";
			row1 = inputNumber(1, 10);

			cout << "Player 1, What column would you like to place the front of the ship: ";
			col1 = inputAlphabet('A', 'J');

			cout << "Player 1, What row would you like to place the back of the ship: ";
			row2 = inputNumber(1, 10);

			cout << "Player 1, What column would you like to place the back of the ship: ";
			col2 = inputAlphabet('A', 'J');
		}

		bool check1xN = P1Board1.checkForShips(row1, col1, row2, col2, count);

		if (check1xN == 0)
		{
			cout << "Invalid placement, please try again\n";
		}
		else
		{

			P1Board1.placeShips(row1, col1, row2, col2, m_shipNum - count);
			P1Board1.printBoard();
			cout << "\n----------------------------------------\n";
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
			count--;
		}
		//6 5 4 3 2 1
		if (count == 0)
		{
			placing = false;
		}
	}
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void Executive::P2Place()
{
	bool placing = true;
	int count = m_shipNum;
	while (placing)
	{
		cout << "\n----------------------------------------\n";
		cout << "           --Player 2 board--             \n";
		cout << "\n----------------------------------------\n";
		P2Board2.printBoard();
		int c;

		while ((c = getchar()) != '\n' && c != EOF);

		if (count == m_shipNum)//count=6
		{
			cout << "\n ----------------------------------------\n";
			cout << "\nLet's start with the 1x1 ship!\n";
			cout << "Player 2, What row would you like to place the 1x1 ship: ";
			row2 = row1 = inputNumber(1, 10);

			cout << "Player 2, What column would you like to place the 1x1 ship: ";
			col2 = col1 = inputAlphabet('A', 'J');
		}
		else
		{
			cout << "\n----------------------------------------\nThis is a 1x" << (m_shipNum - count) + 1 << " ship.\n";//count=(6-5)+1=2
			cout << "Player 2, What row would you like to place the front of the ship: ";
			row1 = inputNumber(1, 10);

			cout << "Player 2, What column would you like to place the front of the ship: ";
			col1 = inputAlphabet('A', 'J');

			cout << "Player 2, What row would you like to place the back of the ship: ";
			row2 = inputNumber(1, 10);

			cout << "Player 2, What column would you like to place the back of the ship: ";
			col2 = inputAlphabet('A', 'J');
		}

		bool check1xN = P2Board2.checkForShips(row1, col1, row2, col2, count);

		if (check1xN == 0)
		{
			cout << "\nInvalid placement, please try again\n\n----------------------------------------\n";
		}
		else
		{

			P2Board2.placeShips(row1, col1, row2, col2, m_shipNum - count);
			P2Board2.printBoard();
			std::cout << "\n----------------------------------------\n";
			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";

			count--;//count=5
		}

		if (count == 0)
		{
			placing = false;
		}
	}
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void Executive::P1Attack(int mode, int leader)
{
	int row;
	int col;
	bool attack = true;
	cout << "\n----------------------------------------\n";
	cout << "           --Player 1 board--             \n";
	cout << "\n----------------------------------------\n";
	cout << "--This is location of Your ships--\n";
	P1Board1.printBoard();
	cout << "\n\n--This is what you attacked--\n";
	P1AttackBoard.printBoard();
	cout << "\n----------------------------------------\n";
	while (attack)
	{
		cout << "Player 1 turn to attack" << endl
			<< "Select Row number: ";

		row = inputNumber(1, 10);

		cout << "\nSelect Column letter: ";

		col = inputAlphabet('A', 'J');
		if (mode == 3)
		{
		AbilityPrompt(leader);
		}
		cout << "Value: " << P1AttackBoard.checkCoordinates(row - 1, col - 1) << "\n";
		if (P1AttackBoard.checkCoordinates(row - 1, col - 1) == 'M' || P1AttackBoard.checkCoordinates(row - 1, col - 1) == 'H')
		{
			cout << "You have already hit or miss here! Choose a new coordinate \n";
			continue;
		}
		else if (P2Board2.checkCoordinates(row - 1, col - 1) == 'S')
		{
			cout << "You hit a ship!\n";
			P1AttackBoard.update(row - 1, col - 1, 'H');
			P2Board2.update(row - 1, col - 1, 'H');
			if (P2Board2.isSunk(row - 1, col - 1))
			{
				P2Board2.sinkShip();
				cout << "You have sunk a ship!\n";
			}

			if (P2Board2.getShipsLeft() == 0)
			{
				player1Won = true;
			}
		}
		else
		{
			P1AttackBoard.update(row - 1, col - 1, 'M');
			cout << "You missed!\n";
		}

		cout << "\n----------------------------------------\n";
		cout << "--This is location of your own ships--\n";
		P1Board1.printBoard();
		cout << "\n\n--This is what you attacked--\n";
		P1AttackBoard.printBoard();
		cout << "\n----------------------------------------\n";
		attack = false;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}
}

void Executive::P2Attack(int mode, int leader)
{
	int row;
	int col;
	bool attack = true;
	cout << "\n----------------------------------------\n";
	cout << "           --Player 2 board--             \n";
	cout << "\n----------------------------------------\n";
	cout << "--This is location of your own ships--\n";
	P2Board2.printBoard();
	cout << "\n\n--This is what you attacked--\n";
	P2AttackBoard.printBoard();
	cout << "\n----------------------------------------\n";
	while (attack)
	{
		cout << "Player 2 turn to attack" << endl
			<< "Select Row number: ";

		row = inputNumber(1, 10);

		cout << "\nSelect Column letter: ";

		col = inputAlphabet('A', 'J');

		cout << "Value: " << P2AttackBoard.checkCoordinates(row - 1, col - 1) << "\n";
		if (P2AttackBoard.checkCoordinates(row - 1, col - 1) == 'M' || P2AttackBoard.checkCoordinates(row - 1, col - 1) == 'H')
		{
			cout << "You have already hit or miss here! Choose a new coordinate \n";
			continue;
		}
		else if (P1Board1.checkCoordinates(row - 1, col - 1) == 'S')
		{
			cout << "You hit a ship!\n";
			P2AttackBoard.update(row - 1, col - 1, 'H');
			P1Board1.update(row - 1, col - 1, 'H');
			if (P1Board1.isSunk(row - 1, col - 1))
			{
				P1Board1.sinkShip();
				cout << "You have sunk a ship!\n";

			}

			if (P1Board1.getShipsLeft() == 0)
			{
				player2Won = true;
			}
		}
		else
		{
			P2AttackBoard.update(row - 1, col - 1, 'M');
			cout << "You missed!\n";
		}
		cout << "\n----------------------------------------\n";
		cout << "--This is location of your own ships--\n";
		P2Board2.printBoard();
		cout << "\n\n--This is what you attacked--\n";
		P2AttackBoard.printBoard();
		cout << "\n----------------------------------------\n";
		attack = false;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}
}

bool Executive::P1Won()
{
	return player1Won;
}

bool Executive::P2Won()
{
	return player2Won;
}

//Fix the row input.
int Executive::inputNumber(int begin, int end)
{
	int v;
	while (true) {
		if (cin >> v) {
			if (v >= begin && v <= end) {
				break;
			}
			else {
				cout << "The input range is not valid! please retry input!" << endl;
			}
		}
		else {
			cout << "input not a number! please retry input!" << endl;
			cin.clear();
			cin.ignore();
		}
	}
	return v;
}

//Convert char to number, and also check if the input in a valid range
int Executive::inputAlphabet(char begin, char end) {
	char v;
	while (true) {
		if (cin >> v)
		{
			//Convert lower case to uppercase
			if (islower(v))
			{
				v = toupper(v);
			}
			if (v >= begin && v <= end) {
				break;
			}
			else {
				cout << "The input range is not valid! please retry input!" << endl;
			}
		}
		else {
			cout << "input not a alphabet! please retry input!" << endl;
			cin.clear();
			cin.ignore();
		}
	}
	return (v - begin) + 1;
}


void Executive::AIPlacement()
{
	bool placing = true;
	int count = m_shipNum;
	srand(time(0));

	while (placing)
	{
		row1 = rand() % 10 + 1;
		col1 = rand() % 10 + 1;
		int orientation = rand() % 2;

		if (orientation == 0)
		{
			row2 = row1 + (m_shipNum - count);
			col2 = col1;
		}
		else
		{
			col2 = col1 + (m_shipNum - count);
			row2 = row1;
		}

		bool check1xN = P2Board2.checkForShips(row1, col1, row2, col2, count);
		if ((col1 + (m_shipNum - count) + 1 > 10) && (orientation == 1))
		{
			check1xN = false;
		}
		else if ((row1 + (m_shipNum - count) + 1 > 10) && (orientation == 0))
		{
			check1xN = false;
		}

		if (check1xN == true)
		{
			P2Board2.placeShips(row1, col1, row2, col2, m_shipNum - count);
			count--;
		}
		if (count == 0)
		{
			placing = false;
		}
		P2Board2.printBoard();
	}
	cout << "AI Ships have been placed." << endl;
}

void Executive::LaserH(int row)
{

}
void Executive::LaserV(int col)
{

}

void Executive::AbilityPrompt(int leader)
{
	int error = 0;
	string useability = "";
	string abilityname = "";
	cout << "Would you like to use your ability:";
	if (leader == 1)
	{
		cout << "Laser\n";
		abilityname = "Laser\n";
	}
	else if (leader == 2)
	{
		cout << "Shotgun\n";
		abilityname = "Shotgun\n";
	}
	else if (leader == 3)
	{
		cout << "Rain of Death\n";
		abilityname = "Rain of Death\n";
	}
	else if (leader == 4)
	{
		cout << "Ring of Fire\n";
		abilityname = "Ring of Fire\n";
	}
	else
	{
		cout << "An error has occured.\n";
		abilityname = "ERROR\n";
	}

	do
	{
		cin >> useability;
		if (useability == "y" || useability == "yes")
		{
			cout << "You have chosen to use the ability: " << abilityname;
		}
		else if (useability == "n" || useability == "no")
		{
			cout << "Your ability has grown by"; //ADD MORE HERE
		}
		else
		{
			error = 1;
			cout << "Not a valid choice! Please input 'y' or 'n'\n";
		}
	} while (error == 1);
}

void Executive::clrscn() {
	;
}

Point Executive::AIAttack(int difficulty, Point previous, vector<vector<pair<int, int>>> cheat, int& ship, int& hit)
{
	int row = 0;
	int col = 0;
	bool attack = true;
	if (difficulty == 1)
	{
		while (attack)
		{
			row = rand() % 10 + 1;
			col = rand() % 10 + 1;
			while (P2AttackBoard.checkCoordinates(row - 1, col - 1) == 'M' || P2AttackBoard.checkCoordinates(row - 1, col - 1) == 'H')
			{
				row = rand() % 10 + 1;
				col = rand() % 10 + 1;
			}
			if (P1Board1.checkCoordinates(row - 1, col - 1) == 'S')
			{
				P2AttackBoard.update(row - 1, col - 1, 'H');
				P1Board1.update(row - 1, col - 1, 'H');
				if (P1Board1.isSunk(row - 1, col - 1))
				{
					P1Board1.sinkShip();
				}

				if (P1Board1.getShipsLeft() == 0)
				{
					player2Won = true;
				}
			}
			else
			{
				P2AttackBoard.update(row - 1, col - 1, 'M');
			}
			cout << "This is what the AI has tried to hit" << endl;
			P2AttackBoard.printBoard();
			attack = false;
		}
	}
	else if (difficulty == 2)
	{
		if (previous.h == 0 && previous.s == 0)
		{
			while (attack)
			{
				row = rand() % 10 + 1;
				col = rand() % 10 + 1;
				while (P2AttackBoard.checkCoordinates(row - 1, col - 1) == 'M' || P2AttackBoard.checkCoordinates(row - 1, col - 1) == 'H')
				{
					row = rand() % 10 + 1;
					col = rand() % 10 + 1;
				}
				if (P1Board1.checkCoordinates(row - 1, col - 1) == 'S')
				{
					P2AttackBoard.update(row - 1, col - 1, 'H');
					P1Board1.update(row - 1, col - 1, 'H');
					previous.h = 1;
					previous.s = 1;
					previous.hx = row;
					previous.hy = col;
					previous.firstx = row;
					previous.firsty = col;
					if (P1Board1.isSunk(row - 1, col - 1))
					{
						P1Board1.sinkShip();
						previous.s = 0;
						previous.h = 0;
						previous.hx = 0;
						previous.hy = 0;
						previous.firstx = 0;
						previous.firsty = 0;
					}

					if (P1Board1.getShipsLeft() == 0)
					{
						player2Won = true;
					}
				}
				else
				{
					P2AttackBoard.update(row - 1, col - 1, 'M');
					previous.h = 0;
				}
				cout << "This is what the AI has tried to hit" << endl;
				P2AttackBoard.printBoard();
				attack = false;
			}
		}
		else
		{
			row = previous.hx;
			col = previous.hy;
			int i = 0;
			while (P2AttackBoard.checkCoordinates(row - 1, col - 1) == 'M' || P2AttackBoard.checkCoordinates(row - 1, col - 1) == 'H')
			{
				if (i == 0)
				{
					row = previous.hx;
					col = previous.hy + 1;
				}
				else if (i == 1)
				{
					row = previous.hx;
					col = previous.hy - 1;
				}
				else if (i == 2)
				{
					row = previous.hx - 1;
					col = previous.hy;
				}
				else if (i == 3)
				{
					row = previous.hx + 1;
					col = previous.hy;
				}
				if (i > 3)
				{
					row = previous.firstx;
					col = previous.firsty;
					int j = 0;
					while (P2AttackBoard.checkCoordinates(row - 1, col - 1) == 'M' || P2AttackBoard.checkCoordinates(row - 1, col - 1) == 'H')
					{
						if (j == 0)
						{
							row = previous.firstx;
							col = previous.firsty + 1;
						}
						else if (j == 1)
						{
							row = previous.firstx;
							col = previous.firsty - 1;
						}
						else if (j == 2)
						{
							row = previous.firstx - 1;
							col = previous.firsty;
						}
						else if (j == 3)
						{
							row = previous.firstx + 1;
							col = previous.firsty;
						}
						j++;
					}
				}
				i++;
			}
			if (P1Board1.checkCoordinates(row - 1, col - 1) == 'S')
			{
				P2AttackBoard.update(row - 1, col - 1, 'H');
				P1Board1.update(row - 1, col - 1, 'H');
				previous.h = 1;
				previous.s = 1;
				previous.hx = row;
				previous.hy = col;
				if (P1Board1.isSunk(row - 1, col - 1))
				{
					P1Board1.sinkShip();
					previous.s = 0;
					previous.h = 0;
					previous.hx = 0;
					previous.hy = 0;
					previous.firstx = 0;
					previous.firsty = 0;
				}

				if (P1Board1.getShipsLeft() == 0)
				{
					player2Won = true;
				}
			}
			else
			{
				P2AttackBoard.update(row - 1, col - 1, 'M');
				previous.h = 0;
			}
			cout << "This is what the AI has tried to hit" << endl;
			P2AttackBoard.printBoard();
			attack = false;
		}
	}
	else if (difficulty == 3)
	{
		row = cheat[ship][hit].first;
		col = cheat[ship][hit].second;
		cout << row << " " << col << endl;
		if (P1Board1.checkCoordinates(row, col) == 'S')
		{
			P2AttackBoard.update(row, col, 'H');
			P1Board1.update(row, col, 'H');
			hit++;
			if (P1Board1.isSunk(row, col))
			{
				P1Board1.sinkShip();
				ship++;
				hit = 0;
			}

			if (P1Board1.getShipsLeft() == 0)
			{
				player2Won = true;
			}
		}

		cout << "This is what the AI has tried to hit" << endl;
		P2AttackBoard.printBoard();
	}
	previous.x = row;
	previous.y = col;
	return previous;
}

vector<vector<pair<int, int>>> Executive::cheatGet()
{
	return P1Board1.getCoordinates();
}