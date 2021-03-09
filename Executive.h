#include<iostream>
#include<string>
#include"Board.h"
#include <vector>

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

struct Point
{
	int x, y, h, s, hx, hy, firstx, firsty;
};

class Executive
{
private:
	int row1, row2, col1, col2;
	Board P1Board1;
	Board P2Board2;
	Board P1AttackBoard;
	Board P2AttackBoard;

	bool player1Won = false;
	bool player2Won = false;
	int m_shipNum;

public:

	/**
	* Executive Class constructor, Initialize variables and functions
	*
	* @param int - The number of ships
	* @return Nothing
	**/
	Executive(int num);

	/**
	* Print out a board that player 1 can place their ships in order of 1X1, 1X2, 1X3 and etc.
	*
	* @param None
	* @return Nothing
	**/
	void P1Place();
	/**
	  * Print out a board that player 2 can place their ships in order of 1X1, 1X2, 1X3 and etc.
	  *
	  * @param None
	  * @return Nothing
	  **/
	void P2Place();

	/**
	* Player 1 attacks Player 2 ships and updates Player 1 attack board to let player see if they hit or miss
	*
	* @return Nothing
	**/
	void P1Attack(int mode, int leader, int turn);
	/**
	  * Player 2 attacks Player 1 ships and updates Player 2 attack board to let player see if they hit or miss
	  *
	  * @return Nothing
	  **/
	void P2Attack(int mode, int leader, int turn2);

	/**
	* Determine if Player 1 Won.
  *
	* @return Bool - True for win, false to continue
	**/
	bool P1Won();
	/**
	  *  Determine if Player 2 Won.
	*
	  * @return Bool - True for win, false to continue
	  **/
	bool P2Won();

	/**
	* Takes in user input, it must a number or else user must enter new input.
	*
	* @param int - Beggining of valid input range
	* @param int - End valid input range
	* @return int - Returns valid user input
	**/
	int inputNumber(int begin, int end);
	/**
	  * Takes in user input, it must a letter that will be converted to a number
	  *
	  * @param char - Beggining of valid input range
	  * @param char - End valid input range
	  * @return int - Returns valid user input
	  **/
	int inputAlphabet(char begin, char end);
	/**
	  * Randomly populates the AI's board
	  *
	  * @return Nothing
	  **/
	void AIPlacement();
	/**
	  * Allows the AI to attack based on the difficulty.
	  *
	  * @parm int - Gives the difficulty
	  * @parm Point - The previous point the AI tried to hit.
	  * @return Point - Returns the previous point the AI tried to hit.
	  **/
	Point AIAttack(int difficulty, Point, vector<vector<pair<int, int>>>, int&, int&);

	/**
	  * Gets the cheat coordinates for the hardest difficulty.
	  *
	  * @return Point - Returns the vector with the ship's coordinates.
	  **/
	vector<vector<pair<int, int>>> cheatGet();

	void LaserH(int row); //Horizontal Laser attack
	void LaserV(int col); //Vertical Laser attack
	bool AbilityPrompt(int leader, bool abilityused);
	/**
	  * Hits the opponent board with a laser that hits a whole row.
	  *
	  * @parm int - Gives the row the player would like to hit
	  * @parm int - Gives the player that used the attack
	  * @return Nothing
	  **/
	void LaserH(int row, int player); //Horizontal Laser attack

	/**
	  * Hits the opponent board with a laser that hits a whole column.
	  *
	  * @parm int - Gives the column the player would like to hit
	  * @parm int - Gives the player that used the attack
	  * @return Nothing
	  **/
	void LaserV(int col, int player); //Vertical Laser attack
=======

	/**
	  * Hits the opponent board with 10 random attacks.
	  *
	  * @parm int - Gives the player that used the attack
	  * @return Nothing
	  **/
	void rainOfDeath(int player);

	void AbilityPrompt(int leader);
>>>>>>> ca79554888acc7f226c0d864f37fb740c0bfef2b
	void clrscn();
};
#endif
