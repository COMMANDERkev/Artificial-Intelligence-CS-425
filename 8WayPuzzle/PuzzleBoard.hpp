#ifndef PuzzleBoard_hpp
#define PuzzleBoard_hpp
#include <iostream>
#include <cmath>

class PuzzleBoard
{
private:
    int grid[3][3];
    int goalGrid[3][3] = 
    {
        {0, 1, 2},  
        {3, 4, 5},
        {6, 7, 8} 
    };
    int heuristicValue;
    
    int manhattanDistance(int, int);
public:
    PuzzleBoard();
    void setGrid(int [3][3]);
    bool isGoalState();
    int heuristicManhattanDistance();
    void printBoard();
};

PuzzleBoard::PuzzleBoard()
{
    heuristicValue = heuristicManhattanDistance();
}

void PuzzleBoard::setGrid(int input[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid[i][j] = input[i][j];
        }
    }
}

bool PuzzleBoard::isGoalState()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] != goalGrid[i][j])
            {
                return false;
            };
        }
    }
    return true;    
}

int PuzzleBoard::manhattanDistance(int rowActual, int colActual)
{
    int rowGoal, colGoal;
    int num = grid[rowActual][colActual];
    rowGoal = num / 3;
    colGoal = num % 3;
    return std::abs((rowGoal - rowActual)) + std::abs((colGoal - colActual));
}

int PuzzleBoard::heuristicManhattanDistance()
{
    int total = 0;

    if (isGoalState())
    {
        return total;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // finding manhattan distance for each tile on the grid
            total += manhattanDistance(i, j);
        }
    }
       
    return total;
}

void PuzzleBoard::printBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            std::cout << grid[i][j] << " | ";
        }
        std::cout << grid[i][2]<<"\n----------\n"; 
    }
}
#endif