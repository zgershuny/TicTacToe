/*********************************************************************
** Author:        Zoe Gershuny
** Date:          August 25, 2019
** Description:   This program has a class TicTacToe where player x
				  				and o are trying to be the first to have three
				  				consecutive pieces in a row, column, or diagonal.
*********************************************************************/

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

// GameState
enum gameState {FINISHED, UNFINISHED};
enum turn {X_TURN, O_TURN};

// TicTacToe Class
class TicTacToe
{

private:
    char board[3][3]; // Board Size
    gameState status;
    turn player;

public:
    TicTacToe(); // Default Constructor

    // Board
    void menu();
    void print(); // Print the board
    void clearBoard(); // Reset the Game

    // Game Play
    void play(); // Play the Game
    char getTurn(); // Get Player
    void changeTurn(); // Change Turn

    // Victory Conditions
    bool checkRow();
    bool checkCol();
    bool checkDiags();
    bool checkStalemate();
    void winner();
};

#endif // TICTACTOE_HPP