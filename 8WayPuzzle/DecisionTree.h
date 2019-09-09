#include "PuzzleBoard.h"

struct Node
{
    PuzzleBoard key;
    Node *firstMove, *secondMove, *thirdMove, *fourthMove;
}; 
typedef Node* BoardTree;

