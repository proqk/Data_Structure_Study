#pragma once
#define MAX 30 //�迭 ũ��

typedef char element;

typedef struct _ArrayStack {
	int top; //���� �� ���� �ε���
	element data[MAX]; //���� ������ ����
}ArrayStack;

typedef ArrayStack Stack; //�迭�� ������ ����

void Init(Stack *s); //���� �ʱ�ȭ top ���� -1��
int isEmpty(Stack *s); //������ �����?
int isFull(Stack *s); //������ �� á��?

void Push(Stack *s, element item); //������ �� ���� ������ ����
element Pop(Stack *s); //���� �ֻ���� ������ ����, �����Ǵ� ������ ��ȯ
element Peek(Stack *s); //���� �ֻ���� ������ �˻�, ã�� ������ ��ȯ
void Display(Stack *s); //���� ������ ǥ��