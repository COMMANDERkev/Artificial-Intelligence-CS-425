#pragma once
#include "SudokuBoard.h"
//#include <utility>

const array<int, 9> domain = { 1,2,3,4,5,6,7,8,9 };

pair<int, int> selectUnassignedVar(SudokuBoard);
pair<int, int> firstFound(SudokuBoard);
pair<int, int> mostConstrainedVar(SudokuBoard);
bool inference(SudokuBoard, pair<int, int>, int);
bool maintainArcConsistency(SudokuBoard, pair<int, int>, int);
