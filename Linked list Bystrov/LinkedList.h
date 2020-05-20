#include <cstddef>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

class LinkedList
{

private:
    Node* head;
public:
    int size = 0;
    LinkedList();
    void addNode(int d);
    void printList();
    void deleteNode(Node* nd);
    void dupeClear();
    int neededNode(int num);
};

