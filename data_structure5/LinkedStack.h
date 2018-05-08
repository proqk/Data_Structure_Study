#pragma once

typedef int element;

typedef struct _Node{
	element data; //���� ������
	struct _Node *p; //���� ����� �����͸� ����Ű�� ���� ������
} Node;

typedef struct _LinkedStack{
	int count; //������ �׸��
	Node *top; //���� ���۳��(�ֻ�� ���)�� ����Ű�� ������
} LinkedStack;

typedef LinkedStack Stack; //���Ḯ��Ʈ�� ������ ����

void Init(Stack *s); //���� �ʱ�ȭ top ���� NULL��
int isEmpty(Stack *s); //������ �����?
 
void Push(Stack *s, element item); //������ �� ���� ������ ����
element Pop(Stack *s); //���� �ֻ���� ������ ����, �����Ǵ� ������ ��ȯ
element Peek(Stack *s); //���� �ֻ���� ������ �˻�, ã�� ������ ��ȯ
void Display(Stack *s); //���� ������ ǥ��
