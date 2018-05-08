#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

int main(){
	Stack s1;
	Init(&s1);
	for (int i = 1; i <= 5; i++){
		printf("Push(%d)\n", i);
		Push(&s1, i);
		Display(&s1);
	}

	printf("Pop() : %d\n", Pop(&s1));
	Display(&s1);

	printf("Pop() : %d\n", Pop(&s1));
	Display(&s1);

	printf("Peek() : %d\n", Peek(&s1));
	Display(&s1);

	printf("\n\n");
	return 0;
}