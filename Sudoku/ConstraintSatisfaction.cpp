#include "ConstraintSatisfaction.h"

pair<int, int> selectUnassignedVar(SudokuBoard sboard)
{
	return firstFound(sboard);
}

pair<int, int> firstFound(SudokuBoard sboard)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (sboard.board[i][j] == 0)
			{
				return make_pair(i, j);
			}
		}
	}
	return pair<int, int>();
}

pair<int, int> mostConstrainedVar(SudokuBoard sboard)
{
	return pair<int, int>();
}

bool inference(SudokuBoard sboard, pair<int, int> coord, int val)
{
	return maintainArcConsistency(sboard, coord, val);
}

bool maintainArcConsistency(SudokuBoard sboard, pair<int, int> coord, int val)
{
	return true;
}
