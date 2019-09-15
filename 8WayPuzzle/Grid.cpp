#ifndef GRID_CPP
#define GRID_CPP
#include "Grid.h"
#include <iostream>
#include <vector>
using namespace std;

bool isEqual(GridNode a, GridNode b)
{
	bool c = true;
    for (int i = 0; i < 9; i++)
    {
        c = a->grid[i] == b->grid[i];
        if (!c)
        {
        	return false;
        }
    }
	return c;
}

bool Grid::isGoalState() const
{
    for (int i = 0; i < 9; i++)
    {
        if (this->grid[i] != i)
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
    cout << "\n";
    for (int i = 0; i < 9; i++)
    {
        if (grid[i] == 0)
        {
            cout << " ";
        }
        else
        {
            cout << grid[i];
        }
        
        if ((i + 1) % 3 == 0 && i != 8)
        {
            cout << "\n----------\n";
        }
        else if (i != 8)
        {
            cout << " | ";
        }
    }   
    cout << "\n";
}

// these functions swap the numbers in the direction stated, relative to the zero or empty position
GridNode MoveLeft(GridNode original, int zeroLocation)
{
	GridNode tmp = new Grid;
	tmp->parent = original;
	tmp->setGrid(original->grid);
    int swap = tmp->grid[zeroLocation - 1];
    tmp->grid[zeroLocation - 1] = tmp->grid[zeroLocation];
    tmp->grid[zeroLocation] = swap;
    return tmp;
}
GridNode MoveRight(GridNode original, int zeroLocation)
{
	GridNode tmp = new Grid;
	tmp->parent = original;
	tmp->setGrid(original->grid);
    int swap = tmp->grid[zeroLocation + 1];
    tmp->grid[zeroLocation + 1] = tmp->grid[zeroLocation];
    tmp->grid[zeroLocation] = swap;
    return tmp; 
}
GridNode MoveUp(GridNode original, int zeroLocation)
{
	GridNode tmp = new Grid;
	tmp->parent = original;
	tmp->setGrid(original->grid);
    int swap = tmp->grid[zeroLocation - 3];
    tmp->grid[zeroLocation - 3] = tmp->grid[zeroLocation];
    tmp->grid[zeroLocation] = swap;
    return tmp;
}
GridNode MoveDown(GridNode original, int zeroLocation)
{
	GridNode tmp = new Grid;
	tmp->parent = original;
	tmp->setGrid(original->grid);
    int swap = tmp->grid[zeroLocation + 3];
    tmp->grid[zeroLocation + 3] = tmp->grid[zeroLocation];
    tmp->grid[zeroLocation] = swap;
    return tmp;
}


// overloaded function holds logic to encact the possible moves
vector<GridNode> PossibleMoves(int zeroLocation, GridNode original)
{
    // for each zeroLocation case this moves the zero into those locations and returns those possible 
    // moves into the returned vector --> {Left, Right, Up, Down}
    switch (zeroLocation)
    {
    case 0:
        // move right and down
        return {MoveRight(original, zeroLocation), MoveDown(original, zeroLocation)};
        break;
    case 1:
        // move left, right and down
        return {MoveLeft(original, zeroLocation), MoveRight(original, zeroLocation), MoveDown(original, zeroLocation)};
        break;
    case 2:
        // move left, down
        return {MoveLeft(original, zeroLocation), MoveDown(original, zeroLocation)};
        break;
    case 3:
        // move up, down and right
        return {MoveRight(original, zeroLocation), MoveUp(original, zeroLocation)};
        break;
    case 4:
        // move all four directions
        return {MoveLeft(original, zeroLocation), MoveRight(original, zeroLocation), 
        	MoveUp(original, zeroLocation), MoveDown(original, zeroLocation)};
        break;
    case 5:
        // move left, up, down
        return {MoveLeft(original, zeroLocation), MoveUp(original, zeroLocation), 
        	MoveDown(original, zeroLocation)};
        break;
    case 6:
        // move up, right
        return {MoveRight(original, zeroLocation), MoveUp(original, zeroLocation)};
        break;
    case 7:
        // move up, left and right
        return {MoveLeft(original, zeroLocation), MoveRight(original, zeroLocation), 
        	MoveUp(original, zeroLocation)};
        break;
    case 8:
        // move left, up
        return {MoveLeft(original, zeroLocation), MoveUp(original, zeroLocation)};
        break;
    default:
        // should never default unless zero location is not found
        cout << "\nZERO LOCATION NOT FOUND\n";
        break;
    }
    return {};
}

// returns the possible moves after finding zero/empty location
vector<GridNode> PossibleMoves(GridNode original)
{
    int zeroLocation;
    for (int i = 0; i < 9; i++)
    {
        if (original->grid[i] == 0)
        {
            zeroLocation = i;
            break;
        }
    }
    return PossibleMoves(zeroLocation, original);
}

#endif