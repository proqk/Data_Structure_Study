#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

void Init(Stack *s) {
	s->top = NULL; //top 초기값은 -1
	s->count = 0;
}

int isEmpty(Stack *s){ //top이 NULL일 때 스택은 비어있음
	return s->top == NULL;
//	return s->count == 0;
}

void Push(Stack *s, element item){
		Node *neww = (Node *)malloc(sizeof(Node));
		neww->data = item; 
		neww->p = s->top;
		s->top = neww;
		s->count++;
}

element Pop(Stack *s){
	element d;
	if (isEmpty(s)) {
		printf("stack full die"); 
		return -1;
	}
	else{
		Node *delnode; // 삭제할 노드를 가리키는 포인터 
		delnode = s->top; //삭제할 노드는 지금 스택 맨 위
		d = delnode->data; //데이터는 삭제할 노드한테 있음
		s->count--;
		s->top = delnode->p; //top은 이제 삭제된 노드 다음 노드의 포인터임
		free(delnode);
		return d;
	}
}

element Peek(Stack *s){
	if (isEmpty(s)){
		printf("stack full die");
		return -1;
	}
	else{
		return s->top->data;
	}
}

void Display(Stack *s){
	if (isEmpty(s)) printf("stack empty die");
	else{
		Node *temp = s->top;
		printf("top [ ");
		for (int i = 0; i < s->count; i++){
			printf("%d ", temp->data);
			temp = temp->p;
		}
		printf(" ] bottom \n\n");
	}
}
