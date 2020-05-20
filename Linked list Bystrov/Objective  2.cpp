#include "LinkedList.h"
#include <cstddef>
#include <iostream>

using namespace std;

int main()
{
    LinkedList ls;
    ls.addNode(20);
    ls.addNode(2387);
    ls.addNode(20);
    ls.addNode(74);
    ls.addNode(20);
    ls.addNode(0);
    ls.addNode(74);
    ls.addNode(74);
    ls.addNode(74);
    cout << "Original node"<<endl;
    ls.printList();
    ls.dupeClear();
    cout << "Clean node"<<endl;
    ls.printList();
    cout << endl << "4-th node" << endl << ls.neededNode(4);
    return 0;
}