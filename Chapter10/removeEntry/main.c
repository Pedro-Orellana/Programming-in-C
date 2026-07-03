// includes
#include <stdio.h>

// structs
struct entry
{
    int value;
    struct entry *next;
};

// prototypes
void printLinkedList(struct entry *head);
void removeEntry(struct entry *previousEntry);

int main()
{

    // create struct entry instances
    struct entry head, e1, e2, e3, e4, *listHandle;

    listHandle = &head;

    // assign values to entries and create the list
    head.next = &e1;

    e1.value = 100;
    e1.next = &e2;

    e2.value = 200;
    e2.next = &e3;

    e3.value = 300;
    e3.next = &e4;

    e4.value = 400;
    e4.next = 0;

    printLinkedList(listHandle->next);

    // remove e3
    removeEntry(&e2);

    printLinkedList(listHandle->next);

    return 0;
}

void printLinkedList(struct entry *head)
{
    while (head)
    {
        printf("The value of the current entry is: %i\n", head->value);
        head = head->next;
    }
}

void removeEntry(struct entry *previousEntry)
{
    struct entry *newNext = previousEntry->next->next;
    previousEntry->next = newNext;
}
