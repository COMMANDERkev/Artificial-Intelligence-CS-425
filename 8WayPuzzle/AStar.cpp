// AStar calculates the cost to get to each node with the cost to get to the goal state
// heuristics function h(n) = total manhattan distance
// i.e. summation(# of squares from desired location of each tile)
#include "DecisionTree.hpp"

int computeState(int a, int b)
{
    return a + b;
}

Node AStar(BoardTree board)
{
    // Creating a priority queue that orders Nodes by their cost --> heuristic + step cost
    std::priority_queue< Node, std::vector<Node>, std::greater<int> > frontier;
}