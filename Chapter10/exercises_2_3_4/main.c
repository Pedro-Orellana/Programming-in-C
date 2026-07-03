// includes
#include <stdio.h>

struct entry
{
    int value;
    struct entry *next;
};

// prototypes
void insertEntry(struct entry *newEntry, struct entry *previousEntry);
void printLinkedList(struct entry *head);
void removeEntry(struct entry *previousEntry);

void main()
{
    struct entry head, e1, e2, e3, e4, e5;

    head = (struct entry){.value = 0, .next = &e1};
    e1 = (struct entry){.value = 1, .next = &e2};
    e2 = (struct entry){.value = 2, .next = &e3};
    e3 = (struct entry){.value = 3, .next = &e4};
    e4 = (struct entry){.value = 4, .next = &e5};
    e5 = (struct entry){.value = 5, .next = nullptr};

    // print the current linked list
    printf("Printing list BEFORE inserting new item:\n");
    printLinkedList(&head);
    printf("\n");
    printf("Printing list AFTER inserting new Item:\n");

    struct entry e6 = {.value = 6, .next = nullptr};
    insertEntry(&e6, &head);
    printLinkedList(&head);

    printf("\n");
    printf("Printing list AFTER removing LAST item from list\n");
    removeEntry(&e4);
    printLinkedList(&head);
    printf("\n");

    printf("Printing list AFTER removing FIRST item from list\n");
    removeEntry(&head);
    printLinkedList(&head);
    printf("\n");
}

void printLinkedList(struct entry *head)
{
    while (head != nullptr)
    {
        if (head->value == 0)
        {
            // original head. Do not print anything
            head = head->next;
            continue;
        }

        printf("entry value: %d\n", head->value);
        head = head->next;
    }
}

// mutation functions for linked-list

void insertEntry(struct entry *newEntry, struct entry *previousEntry)
{
    struct entry *temp = previousEntry->next;
    previousEntry->next = newEntry;
    newEntry->next = temp;
}

void removeEntry(struct entry *previousEntry)
{
    struct entry *entryToDelete = previousEntry->next;
    previousEntry->next = entryToDelete->next;
}
