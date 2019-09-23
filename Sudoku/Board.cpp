#include <iostream>
#include "Board.h"
using namespace std;


Board::Board()
{
	// creating squares for sudoku

	// 1st row of squares
	beginSquares[0] = make_pair(0, 0);
	endSquares[0] = make_pair(2, 2);
	beginSquares[1] = make_pair(0, 3);
	endSquares[1] = make_pair(2, 5);
	beginSquares[2] = make_pair(0, 6);
	endSquares[2] = make_pair(2, 8);

	// 2nd row of squares
	beginSquares[3] = make_pair(3, 0);
	endSquares[3] = make_pair(5, 2);
	beginSquares[4] = make_pair(3, 3);
	endSquares[4] = make_pair(5, 5);
	beginSquares[5] = make_pair(3, 6);
	endSquares[5] = make_pair(5, 8);

	// 3rd row of squares
	beginSquares[6] = make_pair(6, 0);
	endSquares[6] = make_pair(8, 2);
	beginSquares[7] = make_pair(6, 3);
	endSquares[7] = make_pair(8, 5);
	beginSquares[8] = make_pair(6, 8);
	endSquares[8] = make_pair(8, 8);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			board[i][j] = 0;
		}
	}
}

void Board::print()
{
	cout << "the solution is:\n";

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] != 0)
			{
				cout << board[i][j];
			}
			else
			{
				cout << " ";
			}
			cout << " ";
		}
		cout << "\n";
	}
}

bool Board::checkRow(int r)
{
	for (int c = 0; c < col - 1; c++)
	{
		for (int x = c + 1; x < col; x++)
		{
			if (board[r][c] == board[r][x])
			{
				return false;
			}
		}
	}
	return true;
}

bool Board::checkCol(int c)
{
	for (int r = 0; r < row; r++)
	{
		for (int x = 0; x < row; x++)
		{
			if (board[r][c] == board[x][c])
			{
				return false;
			}
		}
	}
	return true;
}

bool Board::checkSquare(int square)
{
	// square indicates which region of the square we should examine starting from 0
	// after we get the beginning 
	

	int r, c;
	r = c = 3 * square;
	int rLimit, cLimit;
	rLimit = cLimit = r + 3;

	for (r = 0; r < rLimit; r++)
	{
		for (c = 0; c < cLimit; c++)
		{

		}
	}
}

void Board::placeNum(int c, int r, int num)
{
	// if nothing there...
	// check board?
	board[r][c] = num;
}
