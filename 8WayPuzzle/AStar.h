#ifndef ASTAR_H
#define ASTAR_H
#include "Grid.h"

int heuristicManhattanDistance(GridNode);
int computeState(GridNode);
GridNode AStar(GridNode);
GridNode findLowestState(vector<GridNode>);
GridNode isIn(vector<GridNode>, GridNode);
vector<GridNode> pop(vector<GridNode>, GridNode);
void TraceSearchPath (GridNode);


#endif