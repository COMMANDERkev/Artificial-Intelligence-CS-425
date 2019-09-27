#include <iostream>
#include <string>
#include <locale>
#include <algorithm>
#include "SudokuBoard.h"
using namespace std;


SudokuBoard::SudokuBoard()
{
	makeBegin();
	makeEnd();
}

SudokuBoard::SudokuBoard(const SudokuBoard& sudoku)
{
	makeBegin();
	makeEnd();
	copy(sudoku.board.begin(), sudoku.board.end(), this->board.begin());
}

void SudokuBoard::input()
{
	cout << "enter below the initial board:\n";
	string nums;
	for (int i = 0; i < 9; i++)
	{
		getline(cin, nums);
		// erases spaces from a string
		nums.erase(remove_if(nums.begin(), nums.end(), ::isspace), nums.end());
		for (int j = 0; j < 9; j++)
		{
			board[i][j] = nums[j] - '0';
		}
		
	}
	
	// for (auto elem : board)
	// {
	// 	cin.getline(nums, 9);
	// 	for (int i = 0; i < 9; i++)
	// 	{
	// 		elem[i] = nums[i] - '0';
	// 		i++;
	// 	}
	// }
}

void SudokuBoard::print()
{
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

// these checks are abstracted to check if any values in a row, col or square are equal to one another
bool SudokuBoard::checkRow(int r)
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

// these checks are abstracted to check if any values in a row, col or square are equal to one another
bool SudokuBoard::checkCol(int c)
{
	for (int r = 0; r < row - 1; r++)
	{
		for (int x = r + 1; x < row; x++)
		{
			if (board[r][c] == board[x][c])
			{
				return false;
			}
		}
	}
	return true;
}

// these checks are abstracted to check if any values in a row, col or square are equal to one another
bool SudokuBoard::checkSquare(int square)
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
			if (!checkRow(r) && !checkCol(c))
			{
				return false;
			}
		}
	}
	return true;
}

// TODO: decide if i want to check here 
void SudokuBoard::placeNum(pair<int, int> coord, int num)
{
	int r = coord.first;
	int c = coord.second;
	board[r][c] = num;
}

// this function is not to check the whole board but to do one coord's 3 checks
const bool SudokuBoard::checkCoordSpace(pair<int, int> location)
{
	int r = location.first;
	int c = location.second;
	int square = -1;
	for (int i = 0; i < 9; i++)
	{
		if (r >= beginSquares[i].first && r <= endSquares[i].first)
		{
			if (c >= beginSquares[i].second && c <= endSquares[i].second)
			{
				square = i;
				break;
			}
		}
	}
	return checkRow(r) && checkCol(c) && checkSquare(square);
}


// creating squares for sudoku
void SudokuBoard::makeBegin()
{
	// 1st row of squares
	beginSquares[0] = make_pair(0, 0);
	beginSquares[1] = make_pair(0, 3);
	beginSquares[2] = make_pair(0, 6);
	// 2nd row of squares
	beginSquares[3] = make_pair(3, 0);
	beginSquares[4] = make_pair(3, 3);
	beginSquares[5] = make_pair(3, 6);
	// 3rd row of squares
	beginSquares[6] = make_pair(6, 0);
	beginSquares[7] = make_pair(6, 3);
	beginSquares[8] = make_pair(6, 8);
}
// creating squares for sudoku
void SudokuBoard::makeEnd()
{
	// 1st row of squares
	endSquares[0] = make_pair(2, 2);
	endSquares[1] = make_pair(2, 5);
	endSquares[2] = make_pair(2, 8);
	// 2nd row of squares
	endSquares[3] = make_pair(5, 2);
	endSquares[4] = make_pair(5, 5);
	endSquares[5] = make_pair(5, 8);
	// 3rd row of squares
	endSquares[6] = make_pair(8, 2);
	endSquares[7] = make_pair(8, 5);
	endSquares[8] = make_pair(8, 8);
}

bool boardCheck(SudokuBoard sboard)
{
	for (int i = 0; i < sboard.row; i++)
	{
		int j = i;
		pair<int, int> coord = make_pair(i, j);
		if (!sboard.checkCoordSpace(coord))
		{
			return false;
		}
	}
	return true;
}