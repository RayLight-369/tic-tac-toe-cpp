#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void drawBoard()
{

  system("cls");

  cout << "   |   |   " << endl;
  cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "  \n";
  cout << "   |   |   " << endl;
  cout << "-----------" << endl;
  cout << "   |   |   " << endl;
  cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "  \n";
  cout << "   |   |   " << endl;
  cout << "-----------" << endl;
  cout << "   |   |   " << endl;
  cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "  \n";
  cout << "   |   |   " << endl;
};

bool addMark(const int &cell, const char &mark)
{
  const int row = (cell - 1) / 3;
  const int column = (cell - 1) % 3;

  if (board[row][column] != 'X' && board[row][column] != 'O' && cell >= 0 && cell <= 9)
  {
    board[row][column] = mark;
    return true;
  }

  return false;
};

bool checkWinning(const char &mark)
{
  if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark)
    return true;
  if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)
    return true;

  for (int i = 0; i < 3; i++)
  {
    if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark)
      return true;
    if (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)
      return true;
  }

  return false;
}

int main()
{

  char currentPlayer = 'X';
  int cell;
  int move;

  for (move = 0; move < 9; move++)
  {

    drawBoard();

    while (1)
    {

      cout << "Enter the cell number: ";
      cin >> cell;

      if (addMark(cell, currentPlayer))
      {
        drawBoard();
        break;
      }
      else
      {
        cout << "Invalid Cell! Please Try Again.\n";
      }
    }

    if (checkWinning(currentPlayer))
    {
      drawBoard();
      cout << "Player " << currentPlayer << " wins!\n";
      break;
    }

    currentPlayer = currentPlayer == 'X' ? 'O' : 'X';
  }

  if (move == 9 && !checkWinning('O') && !checkWinning('X'))
    cout << "Its a Draw , Good Game!!";

  system("pause");

  return 0;
}