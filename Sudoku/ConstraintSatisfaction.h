#pragma once
#include "SudokuBoard.h"
//#include <utility>

int selectUnassignedVar(SudokuBoard, pair<int, int>);
int mostConstrainedVar(SudokuBoard, pair<int, int>);
bool inference(SudokuBoard, int, int);
bool maintainArcConsistency(SudokuBoard, int, int);
// TODO: define domain of values (1-9)