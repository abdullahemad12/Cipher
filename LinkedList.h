#include <stdlib.h>

typedef struct node
{
    unsigned char c; // character that will be stored in the node
    struct node* next; // pointer to the next node
}node;

typedef struct List
{
    node* head; // head of the list
    node* tail; // the node of the last element in the list
    char* path; // path of the file
    int size; // size of the list 
}List;

// prototypes of functions

/*
* Creates new list
*/
List* create_list(char* path);

/*
* Adds a new character to the list
*/
void add(List* L, char c);



/*
* reads a specified file path and loads the the text file into the memory
*/
int load(List* list);

/*
* frees all the elements of the list
*/
void destroy_nodes(node* N);

/*
* Destroys the list
*/
int destroy_list(List* list);

/*
* Mainly for debugging purposes 
*/
void printl(List* L);

