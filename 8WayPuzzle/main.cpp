#include "AStar.h"
#include <iostream>

int main()
{
    GridNode puzzleGrid = new Grid;
    int input[9] =
    {
        8, 2, 6,
        5, 1, 3,
        7, 0, 4
    };
    std::cout << "enter start state: ";
    for (int i = 0; i < 9; i++)
    {
        puzzleGrid->grid[i] = input[i];
        // std::cin >> puzzleGrid->grid[i];
    }
   

    GridNode goal = AStar(puzzleGrid);
	TraceSearchPath(goal);

    return 0;
}
