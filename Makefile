#tests
test: test_cipher.c LinkedList.c LinkedList.h cipher.h cipher.c Makefile
	clang -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror test_cipher.c LinkedList.c cipher.c -o test -lm

