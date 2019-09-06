#include "PuzzleBoard.h"

struct Node
{
    PuzzleBoard key;
    Node *first, *second, *third, *fourth;
}; 
typedef Node* BoardTree;