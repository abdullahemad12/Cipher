/**
* Fuctions that encrypts and decrypts the list
**/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#include "LinkedList.h"

/*
* if the List is encrypted removes the signature and returns the key other wise returns zero
*/
int EncKey(List* L)
{
    node* signature = NULL; // The second node before the last node
    node* current L->head; // The first node in the list 
    
    // iterates over the list looking for the signature
    for(int i = 0, n = L->size; i < n; i++)
    {   
        if(n - i < 4)
        {
            // last three elements 
            if(n - i == 4)
            {   
                signature = current;
            }
            if(n - i == 3)
            {
                // not possible signature
                if(current->c != 'M')
                {
                    return 0;
                }
            }
            else if(n - i == 2)
            {
                // not a possible signature
                if(current->c != 'A')
                {
                    return 0;
                }
            }
            //encrypted list
            else if(n - i == 1)
            {
                int key =(int) current->c;
                L->tail = &signature; // set the new tail of the list to the forth element from the end
                L->size -= 3; // updates the new size
                node* temp = signature->next; 
                signature->next = NULL;
                destroy_nodes(temp); // destroys the last three nodes
                return key;
                
            }
        }
    }
    return 0;
}
int encrypt(List L)
{
    
}
