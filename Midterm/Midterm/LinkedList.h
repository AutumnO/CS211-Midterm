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

    //          *** Problem 1B ***      O(N)
    LinkedList* mergedSortedLinkedLists(LinkedList* first, LinkedList* second)
    {
        LinkedList* result;
        if (first == nullptr)
        {
            return second;
        }
        else if (second == nullptr)
        {
            return first;
        }

        if (first->value > second->value)
        {
            result = first;
            result->next = mergedSortedLinkedLists(first->next, second);
        }
        else
        {
            result = second;
            result->next = mergedSortedLinkedLists(first, second->next);
        }
        return result;
    }
};

/* 1A.Write a function that reverses the order of the linked list.
LinkedList * reverseLinkedList(LinkedList * root)

1B.Write a function that merges two sorted linked lists.
LinkedList * mergedSortedLinkedLists(LinkedList * first, LinkedList * second)
*/

