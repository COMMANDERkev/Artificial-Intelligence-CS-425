#include "Grid.hpp"
#include "AStar.cpp"
#include <iostream>

int main()
{
    Grid puzzleGrid;
    std::cout << "enter start state: ";
    for (int i = 0; i < 9; i++)
    {
        puzzleGrid.grid[i] = i;
    }
    
    
    std::cout << puzzleGrid.isGoalState() << ", " << heuristicManhattanDistance(puzzleGrid) 
        << std::endl;

    puzzleGrid.printBoard();

    //TODO: test the Move__ functions and Possible moves functions
    std::vector<Grid> tests = PossibleMoves(puzzleGrid);
    for (auto grid : tests)
    {
        grid.printBoard();
    }
    

    return 0;
}
