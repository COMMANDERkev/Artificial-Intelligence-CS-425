#ifndef SUDOKUBOARD_h
#define SUDOKUBOARD_h
#include <utility>
#include <array>
using namespace std;

// TODO: make typedef for this pair blah called coord ?

struct SudokuBoard
{
	int row = 9;
	int col = 9;
	// begin coordinates of the sudoku squares
	array<pair<int, int>, 9> beginSquares;
	// corresponding end coordinates of the sudoku squares
	array<pair<int, int>, 9> endSquares;
	array<array<int, 9>, 9> board = {}; // TODO: check if this init to zero

	SudokuBoard();
	SudokuBoard(const SudokuBoard&);
	void input();
	void makeBegin();
	void makeEnd();
	void print();
	void placeNum(pair<int, int>, int);
	bool checkRow(int);
	bool checkCol(int);
	bool checkSquare(int);
	const bool checkCoordSpace(pair<int, int>);

	// TODO: make function to check if it is a solution 
};
bool boardCheck(SudokuBoard);

#endif