#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

#define EMPTY 555
#define SUCCESS 0


/*
* Creates new list
*/
List create_list(char* path)
{
    // allocates memory for the list and it's components
    List l = malloc(sizeof(List));
    node head = malloc(sizeof(node));

    // initializes the components of the list
    head->c = 0;
    head->next = NULL;
    l->head = head;
    l->size = 0;
    l->tail = NULL;
    l->path = path;
    // success 
    return l;
}

/*
* Adds a new character to the list
*/
void add(List* L, char c)
{
    // if the list is not initialized
    if(L == NULL)
    {
        return;
    }
    // if the head is not filled yet
    if(l->head->c == 0)
    {
        l->head->c = c;
        l->tail = l->head->&next;
        l->size++;
        return;
    }
    node* element = malloc(sizeof(node));
    element->c = c;
    element->next = NULL;
    
    // puts the new element at the end of the list
    l->*(tail) = element;

    // updates the tail of the list
    l->tail = element->&next;


    

}
/*
* reads a specified file path and loads the the text file into the memory
*/
int load(List* list)
{
    // opens the file that will be loaded
    FILE* file = fopen(list->path, "r");
    if(file == NULL)
    {
        return EOF;    
    }

    // Avoids memory leaks caused by trying to load an unempty list
    if(list->size != 0)
    {
        return EMPTY;
    }
    char c;
    
    // loads all the bytes of the file into the list
    while(fread(&c, 1, sizeof(char), file) > 0)
    {
        add(list, c);
    }
    
    
    
}

/*
* frees all the elements of the list
*/
void destroy_nodes(node* N)
{
    // the end of the list
    if(N == NULL)
    {
        return;    
    }
    destroy_node(N->next);
    free(N);
    
}

/*
* Destroys the list
*/
int destroy_list(List* list)
{
    if(list == NULL)
    {
        return EMPTY;
    }
    
    // frees all the nodes and their elements
    destroy_nodes(list->head);
    free(list);
    return SUCCESS;

}
