/*********************************************************************
** Author:        Zoe Gershuny
** Date:          August 25, 2019
** Description:   This file holds the constructors and function
				  				definitions for the TicTacToe class.
*********************************************************************/

#include "TicTacToe.hpp"
#include <iostream>

/*********************************************************************
** Description: Default Constructor initializing the game
*********************************************************************/

TicTacToe::TicTacToe()
{

  // Initialize the Empty Board
  for (int row = 0; row < 3; row++)
  {
    for (int col = 0; col < 3; col++)
    {
      board[row][col] = '*';
    }
      std::cout << std::endl;
  }

    // Initialize Enums
    status = UNFINISHED;
    player = X_TURN;
}

/*********************************************************************
** Description: Menu Options to Play
*********************************************************************/

void TicTacToe::menu()
{
  int choice;
  std::cout << "Menu Options: " << std::endl;
  std::cout << "1. Play Tic Tac Toe" << std::endl;
  std::cout << "2. Exit" << std::endl;
  do
  {
    std::cout << "Enter 1 or 2: ";
    std::cin >> choice;
  } while (choice != 1 and choice != 2);

  std::cout << std::endl;

  if(choice == 1)
  {
    play();
  }
  exit(0); // Exit Program
}

/*********************************************************************
** Description: Print the Board
*********************************************************************/

void TicTacToe::print()
{
  std::cout << "  ";
  for (int col = 0; col < 3; col++)
  {
    std::cout << col;
  }
  std::cout << std::endl;

  for (int row = 0; row < 3; row++)
  {
    std::cout << row << " ";
    for (int col = 0; col < 3; col++)
    {
      std::cout << board[row][col];
    }
    std::cout << std::endl;
  }
}

/*********************************************************************
** Description: Clear the Board
*********************************************************************/

void TicTacToe::clearBoard()
{
  for (int row = 0; row < 3; row++)
  {
    for (int col = 0; col < 3; col++)
    {
      board[row][col] = '*';
    }
    std::cout << std::endl;
  }

  // Initialize Enums
  status = UNFINISHED;
  player = X_TURN;
}

/*********************************************************************
** Description: Get and Validate Move from the Player
*********************************************************************/

void TicTacToe::play()
{
  print();

  do
  {
    int row, col;
    std::cout << "Player " << getTurn() << " Turn" << std::endl;

    // Validate Row in Bounds
    do {
      std::cout << "Enter Row: ";
      std::cin >> row;
    } while (row > 2 or row < 0);

    // Validate Col in Bounds
    do {
      std::cout << "Enter Col: ";
      std::cin >> col;
    } while (col > 2 or col < 0);
    std::cout << std::endl;

    // Validate the Square
    if(board[row][col] == '*')
    {
      board[row][col] = getTurn();

      // Check Victory Validations
      if (checkRow() or checkCol() or checkDiags())
      {
        winner();
      }
      else if (checkStalemate())
      {
        status = FINISHED;
        std::cout << "Stalemate. Game Over." << std::endl;
        clearBoard();
        menu();
      }
      else // No One Won, next turn
      {
        changeTurn();
      }
    }
    else
    {
      std::cout << "Invalid Move. Please Try Again." << std::endl;
    }
    print();
  } while (status == UNFINISHED);
}

/*********************************************************************
** Description: Get Whose Turn It Is
*********************************************************************/

char TicTacToe::getTurn()
{
  if(player == X_TURN)
  {
    return 'X';
  }
  else
  {
    return 'O';
  }
}

/*********************************************************************
** Description: Get Whose Turn It Is
*********************************************************************/

void TicTacToe::changeTurn()
{
  {
    if(player == X_TURN)
    {
      player = O_TURN;
    }
    else
    {
      player = X_TURN;
    }
  }
}

/*********************************************************************
** Description: Check Rows for Victory
*********************************************************************/

bool TicTacToe::checkRow()
{
  for (int rowCheck = 0; rowCheck < 3; rowCheck++) {
    if (board[rowCheck][0] == getTurn() and
        board[rowCheck][1] == getTurn() and
        board[rowCheck][2] == getTurn())
    {
      return true;
    }
  }
  return false;
}

/*********************************************************************
** Description: Check Columns for Victory
*********************************************************************/

bool TicTacToe::checkCol()
{
  for (int col = 0; col < 3; col++)
  {
    if(board[0][col] == getTurn() and
       board[1][col] == getTurn() and
       board[2][col] == getTurn())
    {
      return true;
    }
  }
  return false;
}

/*********************************************************************
** Description: Check Diagonals for Victory
*********************************************************************/

bool TicTacToe::checkDiags() {
  int colDiag1 = 0, colDiag2 = 2;
  int colDiag1Counter = 0, ColDiag2Counter = 0;
  for (int rowDiag = 0; rowDiag < 3; rowDiag++)
  {
    if (board[rowDiag][colDiag1] == getTurn())
    {
      colDiag1 += 1;
      colDiag1Counter += 1;
    }
  }

  for (int rowDiag = 0; rowDiag < 3; rowDiag++)
  {
    if (board[rowDiag][colDiag2] == getTurn())
    {
      colDiag2 -= 1;
      ColDiag2Counter += 1;
    }
  }

  if (colDiag1Counter == 3 or ColDiag2Counter == 3)
  {
    return true;
  }
  else
  {
    return false;
  }
}

/*********************************************************************
** Description: Check for Stalemate
*********************************************************************/

bool TicTacToe::checkStalemate() {
  int stalemateCounter = 0;
  for (int rowS = 0; rowS < 3; rowS++)
  {
    for (int colS = 0; colS < 3; colS++) {
      if (board[rowS][colS] == 'X' or board[rowS][colS] == 'O') {
        stalemateCounter += 1;
      }
    }
    if (stalemateCounter == 9)
    {
      return true;
    }
  }
  return false;
}

/*********************************************************************
** Description: Announce the Winner and Display Menu
*********************************************************************/

void TicTacToe::winner()
{
  print();
  status = FINISHED;
  std::cout << "Player " << getTurn() << " Won." << std::endl;
  clearBoard();
  menu();
}