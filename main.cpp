/*********************************************************************
** Author:        Zoe Gershuny
** Date:          August 25, 2019
** Description:   This program provides the rules to TicTacToe and
                  starts the game.
*********************************************************************/

#include "TicTacToe.hpp"
#include <iostream>


int main()
{
    TicTacToe ttt;

    std::cout << "Tic Tac Toe Game" << std::endl;
    std::cout << "Player X starts. Alternate turns." << std::endl;
    std::cout << "First to have three of the same" << std::endl;
    std::cout << "in a row or col or diagonal wins.\n" << std::endl;

    ttt.menu();

    return 0;

}