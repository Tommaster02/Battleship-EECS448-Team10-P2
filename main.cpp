#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "Board.h"

int main()
{

    int shipNum=0;
    bool winCondit=0;
    std::cout<<"Welcome to Battleship!\n";
    std::cout<<"Enter the amount of ships you will play with: ";
    std::cin>>shipNum;
    b1.printBoard();
    Executive e1;
      e1.P1Place(shipNum);
      e1.P2Place(shipnum);

      while(winCondit==0)
      {
        e1.P1Attack();
        if(e1.hasWon()==0)
        {
          e1.P2Attack();
          if(e1.hasWon()==1)
          {
            winCondit==1;
          }
        }
        else
        {
          winCondit==1;

        }

      }
std::cout<<"You won!\n";
}
