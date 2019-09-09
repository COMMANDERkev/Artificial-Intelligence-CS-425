#ifndef DecisionTree_hpp
#define DecisionTree_hpp

#include "PuzzleBoard.hpp"
#include <queue>


struct Node
{
    PuzzleBoard key;
    Node *firstMove, *secondMove, *thirdMove, *fourthMove;
    int stepCost;
}; 
typedef Node* BoardTree;

#endif