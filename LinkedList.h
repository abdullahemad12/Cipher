#include <stdlib.h>

typedef struct node
{
    char c; // character that will be stored in the node
    struct node* next; // pointer to the next node
}node;

typedef struct List
{
    node* head; // head of the list
    node** tail; // the address of the node of the last element in the list
    char* path; // path of the file
    int size; // size of the list 
}List;
