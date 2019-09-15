#ifndef GRID_H
#define GRID_H
#include <vector>
using namespace std;

struct Grid
{
    int grid[9];
    int totalState, gStep, hManhattan;
    Grid *parent;
    bool isGoalState() const;
    void printBoard() const;
    void setState(int, int);
    void setGrid(int *);
};
typedef Grid* GridNode;

bool isEqual(GridNode, GridNode);
vector<GridNode> PossibleMoves(GridNode);
vector<GridNode> PossibleMoves(int, GridNode);
GridNode MoveLeft(GridNode, int);
GridNode MoveRight(GridNode, int);
GridNode MoveUp(GridNode, int);
GridNode MoveDown(GridNode, int);


#endif