#pragma once
#include <utility>
#include <array>
using namespace std;


struct SudokuBoard
{
	int row, col;
	row = col = 9;
	// begin coordinates of the sudoku squares
	array<pair<int, int>, 9> beginSquares;
	// corresponding end coordinates of the sudoku squares
	array<pair<int, int>, 9> endSquares;
	int board[row][row];
	SudokuBoard();
	void print();
	bool checkRow(int);
	bool checkCol(int);
	bool checkSquare(int);
	void placeNum(int, int, int);
};