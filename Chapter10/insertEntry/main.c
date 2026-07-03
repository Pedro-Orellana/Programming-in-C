// includes
#include <stdio.h>

struct entry
{
    int value;
    struct entry *next;
};

// prototypes
void insertEntry(struct entry *new_entry, struct entry *previous_entry);
void printList(struct entry *list_handle);

int main()
{

    // create the linked list and some items in it
    struct entry head, e1, e2, e3, e4, *list_handle;

    // point the handle to the first entry
    list_handle = &head;

    // assigning values to the entries
    head.next = &e1;

    e1.value = 10;
    e1.next = &e2;

    e2.value = 20;
    e2.next = &e3;

    e3.value = 30;
    e3.next = &e4;

    e4.value = 40;
    e4.next = 0;

    printList(list_handle->next);

    // creating new entry
    struct entry e5;
    e5.value = 50;
    e5.next = 0;

    // adding e5 to the beginning of the list
    insertEntry(&e5, &head);

    // printing the new list
    printList(list_handle->next);

    return 0;
}

void printList(struct entry *handle)
{
    while (handle)
    {
        printf("The value of this entry is %i\n", handle->value);
        handle = handle->next;
    }
}

void insertEntry(struct entry *new_entry, struct entry *previous_entry)
{
    // getting an instance of the struct entry pointed at by previous_entry pointer
    // struct entry temp_previous = *previous_entry;

    // conversely, I could get just the pointer of next, like this
    struct entry *previous_next = previous_entry->next;

    // changing previous_entry to point to new_entry
    previous_entry->next = new_entry;

    // making new_entry point to the correct next element in the list
    // new_entry->next = temp_previous.next;
    new_entry->next = previous_next;
}
