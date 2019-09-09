#ifndef PuzzleBoard_hpp
#define PuzzleBoard_hpp
#include <iostream>

class PuzzleBoard
{
private:
    int grid[9];
    int goalGrid[9];
public:
    PuzzleBoard();
    ~PuzzleBoard();
    bool isGoalState();
    int heuristicManhattanDistance();
    void printBoard();
};

PuzzleBoard::PuzzleBoard()
{
    std::cout << "enter start state: ";
    for (int i = 0; i < 9; i++)
    {
        int a;
        std::cin >> a; 
    }

    printBoard();
    
    // functions to compute state (g + h)
}

PuzzleBoard::~PuzzleBoard()
{
}

bool PuzzleBoard::isGoalState()
{
    for (int i = 0; i < 9; i++)
    {
        if (grid[i] != goalGrid[i]) 
        {
            return false;
        }
    }
    return true;    
}

int PuzzleBoard::heuristicManhattanDistance()
{
    int total;

    if (isGoalState())
    {
        return 0;
    }
    
    


    return total;
}

void PuzzleBoard::printBoard()
{
    for (int i = 0; i < 9; i++)
    {
        if (i == 2 || i == 5 || i == 8)
        {
            std::cout << grid[i] << "\n";
        }
        else
        {
            std::cout << grid[i] << " ";
        }
        
    }   
}
#endif