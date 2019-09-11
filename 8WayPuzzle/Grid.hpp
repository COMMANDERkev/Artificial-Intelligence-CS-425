#ifndef Grid_hpp
#define Grid_hpp
#include <iostream>
#include <vector>


struct Grid
{
    int grid[9];
    int state;
    bool isGoalState() const;
    void printBoard() const;
    void setGrid(int *);
};

std::vector<Grid> PossibleMoves(Grid);
std::vector<Grid> PossibleMoves(int, Grid);
Grid MoveLeft(Grid, int);
Grid MoveRight(Grid, int);
Grid MoveUp(Grid, int);
Grid MoveDown(Grid, int);

class CompareGridState
{
 public:
    bool operator() (Grid a, Grid b)
    {
        return a.state < b.state;
    }
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
    std::cout << "\n";
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
    std::cout << "\n";
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
    return PossibleMoves(zeroLocation, parent);
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
std::vector<Grid> PossibleMoves(int zeroLocation, Grid parent)
{
    //TODO: check that these are right, i was definitely sleepy writing them (also don't need break with return)
    // for each zeroLocation case this moves the zero into those locations and returns those possible 
    // moves into the returned vector --> {Left, Right, Up, Down}
    switch (zeroLocation)
    {
    case 0:
        // move right and down
        return {MoveRight(parent, zeroLocation), MoveDown(parent, zeroLocation)};
        break;
    case 1:
        // move left, right and down
        return {MoveLeft(parent, zeroLocation), MoveRight(parent, zeroLocation), MoveDown(parent, zeroLocation)};
        break;
    case 2:
        // move left, down
        return {MoveLeft(parent, zeroLocation), MoveDown(parent, zeroLocation)};
        break;
    case 3:
        // move up, down and right
        return {MoveRight(parent, zeroLocation), MoveUp(parent, zeroLocation)};
        break;
    case 4:
        // move all four directions
        return {MoveLeft(parent, zeroLocation), MoveRight(parent, zeroLocation), MoveUp(parent, zeroLocation), MoveDown(parent, zeroLocation)};
        break;
    case 5:
        // move left, up, down
        return {MoveLeft(parent, zeroLocation), MoveUp(parent, zeroLocation), MoveDown(parent, zeroLocation)};
        break;
    case 6:
        // move up, right
        return {MoveRight(parent, zeroLocation), MoveUp(parent, zeroLocation)};
        break;
    case 7:
        // move up, left and right
        return {MoveLeft(parent, zeroLocation), MoveRight(parent, zeroLocation), MoveUp(parent, zeroLocation)};
        break;
    case 8:
        // move left, up
        return {MoveLeft(parent, zeroLocation), MoveUp(parent, zeroLocation)};
        break;
    default:
        // should never default unless zero location is not found
        std::cout << "\nZERO LOCATION NOT FOUND\n";
        break;
    }
    return {};
}


#endif