// includes
#include "LinkedList.h"

// constants
#define LIMIT 225
#define ERROR -12
#define MAX 8589934592


typedef unsigned char BYTE; 

// prototypes

/*
* Decrypts the List and returns true, only if the list was already encrypted
*/
bool decrypt(List* L);


/*
*   Encrypts the file and returns true, if Success, and false otherwise
*   It will fail if the List is already encrypted 
*/
bool encrypt(List* L);
