#include "PuzzleBoard.hpp"
#include "DecisionTree.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    int grid [3][3];
    std::cout << "enter start state: ";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cin >> grid[i][j];
        }
    }
    
    BoardTree boardTree;
    PuzzleBoard puzzle;
    // puzzle = boardTree->key;
    puzzle.setGrid(grid);
    puzzle.printBoard();
    std::cout << puzzle.isGoalState() << ", " << puzzle.heuristicManhattanDistance() << std::endl;


    return 0;
}
