#pragma once
#include "SudokuBoard.h"
#include <vector>

SudokuBoard BacktrackingSearch(SudokuBoard);
// TODO: make typedef for this long vector pair blah
SudokuBoard Backtrack(SudokuBoard, vector<pair<pair<int, int>, int>>);