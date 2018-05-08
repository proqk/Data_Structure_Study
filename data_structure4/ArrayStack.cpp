#include <stdio.h>
#include "ArrayStack.h"

void Init(Stack *s) {
	s->top = -1; //top 초기값은 -1
}

int isEmpty(Stack *s){ //top이 -1일 때 스택은 비어있음
	return s->top == -1;
}

int isFull(Stack *s){
	return s->top == MAX - 1;
}

void Push(Stack *s, element item){
	if (isFull(s)) printf("stack empty die");
	else{
		s->top++;
		s->data[s->top] = item;
	}
}

element Peek(Stack *s){
	element d;
	if (isEmpty(s)) {
		printf("stack full dis"); 
		return -1;
	}
	else{
		d = s->data[s->top];
		return d;
	}
}

element Pop(Stack *s){
	int t = Peek(s);
	s->top--;
	return t;
}

void Display(Stack *s){
	if (isEmpty(s)) printf("stack empty die");
	else{
		printf("bottom [ ");
		for (int i = 0; i <= s->top; i++){
			printf("%d ", s->data[i]);
		}
		printf(" ] top \n\n");
	}
}
