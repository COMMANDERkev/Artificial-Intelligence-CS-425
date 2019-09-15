#ifndef ASTAR_CPP
#define ASTAR_CPP
#include "AStar.h"
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

GridNode AStar(GridNode startingBoard)
{
	bool goal = false;

	vector<GridNode> frontier = {startingBoard};
	startingBoard->totalState = computeState(startingBoard);
	vector<GridNode> closedAndSeen;
	GridNode current;
	vector<GridNode> expandedNodes;


	while(!frontier.empty() && !goal)
	{
		current = findLowestState(frontier);
		frontier = pop(frontier, current);

		if (current->isGoalState())
		{
			cout << "\n\n~~~Goal~~~";
			return current;
		}
		else
		{
			expandedNodes = PossibleMoves(current);
			
			for (auto child : expandedNodes)
			{
				child->totalState = computeState(child);

				if (child->isGoalState())
				{
					return child;
				}

				GridNode sameNode = isIn(frontier, child);
				if (sameNode && sameNode->totalState < child->totalState)
				{
					continue;
				}

				sameNode = isIn(closedAndSeen, child);
				if (sameNode && sameNode->totalState < child->totalState)
				{
					continue;
				}
				else
				{
					frontier.push_back(child);
				}
			}
		}
		closedAndSeen.push_back(current);
	}
}

GridNode findLowestState(vector<GridNode> list)
{
	GridNode lowest;
	lowest->totalState = 100;
	for (auto node : list)
	{
		if (lowest->totalState > node->totalState)
		{
			lowest = node;
		}
	}
	return lowest;
}

GridNode isIn(vector<GridNode> list, GridNode node)
{
	for (auto elem : list)
	{
		if (isEqual(node, elem))
		{
			return elem;
		}
	}
	return nullptr;
}

// admissable heuristic chosen is manhattan distance
int heuristicManhattanDistance(GridNode node)
{
    int totalManhattanDistance = 0;

    if (node->isGoalState())
    {
        return totalManhattanDistance;
    }

    for (int i = 0; i < 9; i++)
    {
        // using current position convert single array index  to 2d array index for row and col
        int rowActual = i / 3;     
        int colActual = i % 3; 

        // similar action to get the goal index for row and col
        // in relation to the number at the position because to tell where that 
        // number should be
        int rowGoal = node->grid[i] / 3;
        int colGoal = node->grid[i] % 3;

        // calculating manhattan distance requires you to take the absolute value of the differences
        // between the y and x grid positions then add them together
        totalManhattanDistance += std::abs((rowGoal - rowActual)) + std::abs((colGoal - colActual));
        // for each position in the grid we calculate manhattan distance and add to the total
    }
    return totalManhattanDistance;
}

int computeState(GridNode node)
{
	if (node->parent)
	{
		node->gStep = node->parent->gStep + 1;
	}
	else
	{
		node->gStep = 0;
	}
	node->hManhattan = heuristicManhattanDistance(node);
	return node->gStep + node->hManhattan;
}

vector<GridNode> pop(vector<GridNode> list, GridNode node)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i] == node)
		{
			list.erase(list.begin() + i);
		}
	}
	return list;
}

void TraceSearchPath(GridNode child)
{
	vector<GridNode> path;
	GridNode current = child;
	path.push_back(child);
	int j = 1;
	while (current->parent)
	{
		path.push_back(current->parent);
		current = current->parent;
		j++;
	}

	for (int i = j; i >= 0; i--)
	{
		cout << "\n\nStep " << j - i + 1 << endl;
		path[i]->printBoard();
	}
}

#endif