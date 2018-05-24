#include <stdio.h>
#include "Stack.h"

void Init(Stack *s)
{
	s->top = -1;
}

int isEmpty(Stack *s)
{
	return s->top == -1;
}

int isFull(Stack *s)
{
	return s->top == MAX - 1;
}

void Push(Stack *s, element item)
{
	if (isFull(s))
		printf("Stack Full, Overflow!!!\n");
	else {
		s->top++;
		s->data[s->top] = item;
	}
}

element Pop(Stack *s)
{
	element d;

	if (isEmpty(s)) {
		printf("Stack Empty, Underflow!!!\n");
		return -1;
	}
	else {
		d = s->data[s->top];
		s->top--;
		return d;
	}
}

element Peek(Stack *s)
{
	if (isEmpty(s)) {
		printf("Stack Empty\n");
		return -1;
	}
	else
		return s->data[s->top];
}

void Display(Stack *s)
{
	if (isEmpty(s)) {
		printf("Stack Empty\n");
	}

	else {
		printf("bottom [ ");
		for (int i = 0; i <= s->top; i++)
			printf("%c ", s->data[i]);
		printf("] top \n\n");
	}
}
