#ifndef Grid_hpp
#define Grid_hpp
#include <iostream>
#include <vector>

class CompareGridState
{
 public:
    bool operator() (Grid a, Grid b)
    {
        return a.state < b.state;
    }
};

struct Grid
{
    int grid[9];
    int state;
    bool isGoalState() const;
    void printBoard() const;
    void setGrid(int *);
};

bool Grid::isGoalState() const
{
    for (int i = 1; i < 9; i++)
    {
        if (grid[i] != i)
        {
            return false;
        }   
    }
    return true;
}

void Grid::setGrid(int *input)
{
    for (int i = 0; i < 9; i++)
    {
        grid[i] = input[i];
    }
}

void Grid::printBoard() const
{
    for (int i = 0; i < 9; i++)
    {
        if ((i + 1) % 3 == 0)
        {
            std::cout << grid[i] << "\n----------\n";
        }
        else
        {
            if (grid[i] == 0)
            {
                std::cout << " ";
            }
            else
            {
                std::cout << grid[i];
            }
            std::cout << " | ";
        }       
    }   
}

// returns the possible moves after finding zero/empty location
std::vector<Grid> PossibleMoves(Grid parent)
{
    int zeroLocation;
    for (int i = 0; i < 9; i++)
    {
        if (parent.grid[i] == 0)
        {
            zeroLocation = i;
            break;
        }
    }
    return PossibleMoves(zeroLocation);
}

// these functions swap the numbers in the direction stated, relative to the zero or empty position
Grid MoveLeft(Grid parent, int zeroLocation)
{
    Grid tmp = parent;
    int swap = tmp.grid[zeroLocation - 1];
    tmp.grid[zeroLocation - 1] = tmp.grid[zeroLocation];
    tmp.grid[zeroLocation] = swap;
    return tmp;
}
Grid MoveRight(Grid parent, int zeroLocation)
{
    Grid tmp = parent;
    int swap = tmp.grid[zeroLocation + 1];
    tmp.grid[zeroLocation + 1] = tmp.grid[zeroLocation];
    tmp.grid[zeroLocation] = swap;
    return tmp; 
}
Grid MoveUp(Grid parent, int zeroLocation)
{
    Grid tmp = parent;
    int swap = tmp.grid[zeroLocation - 3];
    tmp.grid[zeroLocation - 3] = tmp.grid[zeroLocation];
    tmp.grid[zeroLocation] = swap;
    return tmp;
}
Grid MoveDown(Grid parent, int zeroLocation)
{
    Grid tmp = parent;
    int swap = tmp.grid[zeroLocation + 3];
    tmp.grid[zeroLocation + 3] = tmp.grid[zeroLocation];
    tmp.grid[zeroLocation] = swap;
    return tmp;
}

// overloaded function holds logic to encact the possible moves
std::vector<Grid> PossibleMoves(int zeroLocation)
{
    //TODO: check that these are right, i was definitely sleepy writing them (also don't need break with return)
    // for each zeroLocation case this moves the zero into those locations and returns those possible 
    // moves into the returned vector
    switch (zeroLocation)
    {
    case 0:
        // move right and down
        return {}; // some possible grids
        break;
    case 1:
        // move left, right and down
        break;
    case 2:
        // move left, down
        break;
    case 3:
        // move up, down and right
        break;
    case 4:
        // move all four directions
        break;
    case 5:
        // move left, up, down
        break;
    case 6:
        // move up, right
        break;
    case 7:
        // move up, left and right
        break;
    case 8:
        // move left, up
        break;
    default:
        // should never default unless zero location is not found
        std::cout << "\nZERO LOCATION NOT FOUND\n";
        break;
    }
}

#endif