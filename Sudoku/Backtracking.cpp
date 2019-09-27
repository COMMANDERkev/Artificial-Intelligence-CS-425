#include "Backtracking.h"
#include "ConstraintSatisfaction.cpp"
#include "ConstraintSatisfaction.h"
#include <iostream>
using namespace std;

SudokuBoard BacktrackingSearch(SudokuBoard initialState)
{
	return Backtrack(initialState);
}

SudokuBoard Backtrack(SudokuBoard sboard)
{
	// assignment complete ?
	cout << "sourPls\n";
	pair<int, int> unassignedCoordinate = selectUnassignedVar(sboard);
	for (int val : domain) // want to select domain based on non/min conflicts
	{
		// val consistent with assignment ?
		if (sboard.checkCoordSpace(unassignedCoordinate))
		{	
			sboard.placeNum(unassignedCoordinate, val);

			// want to fail fast, so apply some inference logic
			if (inference(sboard, unassignedCoordinate, val))
			{
				SudokuBoard result = Backtrack(sboard);
				if (boardCheck(result))
				{
					cout << "the solution is:\n";
					result.print();
					return result;
				}
			}
			else
			{
				sboard.placeNum(unassignedCoordinate, 0);
			}
		}
	}

	cout << "welp\n";
	SudokuBoard blank;
	return blank;
}
