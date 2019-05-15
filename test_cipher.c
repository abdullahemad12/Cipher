#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include "cipher.h"


int main(void)
{
	List* l = create_list("test.txt");
    load(l);
 	if(!encrypt(l))
	{
		printf("Couldn't Encrypt\n");
		return 1;
	}
	printl(l);
	if(!decrypt(l))
	{
		printf("Couldn't Decrypt\n");
		return 2;
	}
	printl(l);
    destroy_list(l);
	
}
