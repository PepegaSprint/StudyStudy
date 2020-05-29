#include "LinkedList.h"
#include <cstddef>
#include <iostream>

using namespace std;
    LinkedList::LinkedList()
    {
        head = NULL;
    }
    void LinkedList::addNode(int d)
    {
        size++;
        Node* nd = new Node();
        nd->data = d;
        nd->next = NULL;
        if (head == NULL)
            head = nd;
        else
        {
            Node* current = head;
            while (current->next != NULL)
            current = current->next;
            current->next = nd;
        }
    };
    void LinkedList::printList()
    {
            Node* current = head;
            while (current)
            {
                cout << current->data << endl;
                current = current->next;
            }
    };

    void LinkedList::deleteNode(Node* nd)
    {
        Node* current = head;
        while (current->next != nd)
        {
            current = current->next;
        }
        current->next = current->next->next;
        size--;
    }

    void LinkedList::dupeClear()
    {
        cout << endl;
        int temp;
        Node* currentPrime = head;
        while (currentPrime != NULL && currentPrime->next != NULL)
        {
            Node* current = currentPrime;
            temp = current->data;
            while (current->next != NULL)
            {
                current = current->next;
                if (temp == current->data)
                    deleteNode(current);
            }
            currentPrime = currentPrime->next;
        }
    }

    int LinkedList::neededNode(int num)
    {
        Node* current = head;

        for (int i = 0; i < size-num; i++)
        {
            current = current->next;
        }
        return current->data;
    }