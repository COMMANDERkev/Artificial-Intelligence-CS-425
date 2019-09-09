#include "PuzzleBoard.h"
#include <queue>

struct Node
{
    PuzzleBoard key;
    std::que
    Node *firstMove, *secondMove, *thirdMove, *fourthMove;
}; 
typedef Node* BoardTree;

