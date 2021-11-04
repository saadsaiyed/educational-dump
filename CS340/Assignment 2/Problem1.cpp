#include <stdio.h>

using namespace std;

// N is number of nodes
const int N = 20;

struct Node
{
    int value = NULL;
    Node* leftChild = nullptr;
    Node* rightChild = nullptr;
};

void traverse(Node root){
    Node* queue[N];                         // <--- line 16
    queue[0] = root.leftChild;
    queue[1] = root.rightChild;             // <--- line 18

    while (queue[0] != nullptr)
    {
        visit(queue[0]->value);
        queue.push(queue[0]->leftChild);
        queue.push(queue[0]->rightChild);
        queue.pop();
    }
}

void visit(int value){
    cout << "Node" << value << " visited\n";
}


