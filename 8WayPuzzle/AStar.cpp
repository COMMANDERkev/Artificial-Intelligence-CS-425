// AStar calculates the cost to get to each node with the cost to get to the goal state
// heuristics function h(n) = total manhattan distance
// i.e. summation(# of squares from desired location of each tile)
#ifndef AStar_cpp
#define AStar_cpp
#include "Grid.hpp"
#include <vector>
#include <queue>

// admissable heuristic chosen is manhattan distance
int heuristicManhattanDistance(const Grid puzzleGrid)
{
    int totalManhattanDistance = 0;

    if (puzzleGrid.isGoalState())
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
        int rowGoal = puzzleGrid.grid[i] / 3;
        int colGoal = puzzleGrid.grid[i] % 3;

        // calculating manhattan distance requires you to take the absolute value of the differences
        // between the y and x grid positions then add them together
        totalManhattanDistance += std::abs((rowGoal - rowActual)) + std::abs((colGoal - colActual));
        // for each position in the grid we calculate manhattan distance and add to the total
    }
    return totalManhattanDistance;
}

// adding the step cost to the heuristic: g + h
int computeState(int stepCostG, const Grid g)
{
    return stepCostG + heuristicManhattanDistance(g);
}

void AStar(Grid puzzleBoard)
{
    int stepCost = 0;
    // Creating a priority queue that orders Nodes by their cost --> heuristic + step cost
    std::priority_queue< Grid, std::vector<Grid>, CompareGridState > frontier;
    // creating a list of previously seen grid configs so that they don't repeat
    std::vector<Grid> seenConfigurations;

    puzzleBoard.state = computeState(stepCost, puzzleBoard);
    frontier.push(puzzleBoard);

    while (!frontier.top().isGoalState())
    {
        stepCost++;
        // compare current board to board on top of queue
        // create the other configurations of nodes ~ Expand


    }
    
    std::cout << "\n~~~~GOAL~~~~\n";
    frontier.top().printBoard();

}
#endif