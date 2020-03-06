#pragma once
using namespace std;

class LinkedList {
public:
    int value;
    LinkedList* next = nullptr;

    //          *** Problem 1A ***      O(N)
    LinkedList* reverseLinkedList(LinkedList* root)
    {
        LinkedList* previous = nullptr;
        LinkedList* current = root;
        LinkedList* next = current->next;

        while (current != nullptr)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        root = previous;
    }

    //          *** Problem 1B ***
    LinkedList* mergedSortedLinkedLists(LinkedList* first, LinkedList* second)
    {
        
    }
};

/* 1A.Write a function that reverses the order of the linked list.
LinkedList * reverseLinkedList(LinkedList * root)

1B.Write a function that merges two sorted linked lists.
LinkedList * mergedSortedLinkedLists(LinkedList * first, LinkedList * second)
*/

