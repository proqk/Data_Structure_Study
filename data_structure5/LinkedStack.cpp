#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

void Init(Stack *s) {
	s->top = NULL; //top �ʱⰪ�� -1
	s->count = 0;
}

int isEmpty(Stack *s){ //top�� NULL�� �� ������ �������
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
		Node *delnode; // ������ ��带 ����Ű�� ������ 
		delnode = s->top; //������ ���� ���� ���� �� ��
		d = delnode->data; //�����ʹ� ������ ������� ����
		s->count--;
		s->top = delnode->p; //top�� ���� ������ ��� ���� ����� ��������
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
