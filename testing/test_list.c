#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


int main(void)
{
    List* l = create_list("test.txt");
    load(l);
    node* current = l->head;
    while(current != NULL)
    {
        printf("%c", current->c);
        current = current->next;
    }
    destroy_list(l);
}
