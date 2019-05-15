/**
* Fuctions that encrypts and decrypts the list
**/

#define _XOPEN_SOURCE
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "cipher.h"

/*
* Generates random number between 0 and 255 
*/
BYTE random()
{
	srand48((long int)time(NULL));
	return (BYTE)(LIMIT * drand48());
}


/*
* if the List is encrypted removes the signature and returns the key other wise returns zero
*/
BYTE EncKey(List* L, BYTE* factor)
{

	if(L == NULL)
	{
		printf("Error while ciphering.\n details: NULL LinkedList was passed to EncKey. Program was terminated to protect your files\n");
		exit(ERROR);		
	}
    node* signature = NULL; // The second node before the last node
    node* current = L->head; // The first node in the list 
    
    // iterates over the list looking for the signature
    for(int i = 0, n = L->size; i < n; i++)
    {   
        // avoids going through all the conditions unnessecarily
        if(n - i <= 5)
        {
            // last three elements 
            if(n - i == 5)
            {   
                signature = current;
            }
            if(n - i == 4)
            {
                // not possible signature
                if(current->c != 'M')
                {
                    return 0;
                }
            }
            else if(n - i == 3)
            {
                // not a possible signature
                if(current->c != 'A')
                {
                    return 0;
                }
            }
			// factor
			else if (n - i == 2)
			{
				// protects against errors
				if(factor != NULL)
				{
					*factor = current->c;
				}
			}
            // key
            else if(n - i == 1)
            {
                BYTE key = current->c;
                L->tail = signature; // set the new tail of the list to the forth element from the end
                L->size -= 4; // updates the new size
                node* temp = signature->next; 
                signature->next = NULL;
                destroy_nodes(temp); // destroys the last 4 nodes
                return key;
            }
        }
        current = current->next;
    }
    return 0;
}

/*
*   Encrypts the file and returns true, if Success, and false otherwise
*   It will fail if the List is already encrypted 
*/
bool encrypt(List* L)
{
    // A key was found: the file was already encyrpted
    if(EncKey(L, NULL) != 0)
    {
        return false;        
    }

	// cipher key
	BYTE key = random();
	BYTE factor = random();
	long int acc = 0;

	node* cursor = L->head;
	for(int i = 0, n = L->size; i < n; i++)
	{	
		// resets the acc
		if(acc >= MAX)
		{
			acc = 0;
		}
		acc += (long int)(pow(factor, 2) * key); 
		// using a long int to prevent overflow error
		int c =(int) cursor->c;
		c = (c + acc) % 255;
		cursor->c = (BYTE)c;
		cursor = cursor->next;
	}
	// adds the signature and the Keys to the list
	add(L, 'M');
	add(L, 'A');
	add(L, factor);
	add(L, key);

    return true;    
}

/*
* Decrypts the List and returns true, only if the list was already encrypted
*/
bool decrypt(List* L)
{
	BYTE key;
	BYTE factor; 
	// checks if the list was already encrypted
	if((key = EncKey(L, &factor)) == 0)
	{
		return false;
	}
	long int acc = 0;
	node* cursor = L->head;
	for(int i = 0, n = L->size; i < n; i++)
	{
		// resets the acc
		if(acc >= MAX)
		{
			acc = 0;
		}
		acc += (long int)(pow(factor, 2) * key); 
		// using a long int to prevent overflow error
		int c; // decrypted byte
		int E =(int) cursor->c; // Encrypted Byte
		c = 255 - ((acc-E) % LIMIT);
		cursor->c = (BYTE) c;
		cursor = cursor->next;
	}
	return true;
}










