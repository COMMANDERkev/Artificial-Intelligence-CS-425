#include "Backtracking.h"
#include "ConstraintSatisfaction.h"

SudokuBoard BacktrackingSearch(SudokuBoard initialState)
{
	return Backtrack(initialState, {});
}

// TODO: Decide WTF to do with this assignment list (PROB REMOVE)
SudokuBoard Backtrack(SudokuBoard sboard, vector<pair<pair<int, int>, int>> assignmentList)
{
	// assignment complete ?
	auto unassignedCoordinate = selectUnassignedVar(sboard);
	for (int val : domain) // want to select domain based on non/min conflicts
	{
		// val consistent with assignment ?
		if (sboard.checkCoordSpace(unassignedCoordinate))
		{
			assignmentList.push_back(unassignedCoordinate, val);

			// want to fail fast, so apply some inference logic

			if (inference(sboard, unassignedCoordinate, val))
			{
				sboard.placeNum(assignmentList.back(), val);
				SudokuBoard result = Backtrack(sboard, assignmentList);
				if (boardCheck(result))
				{
					return result;
				}
			}
		}
		


		assignmentList.pop_back();
	}

	return;
}
