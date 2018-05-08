#pragma once
#define MAX 5

typedef int element;

typedef struct ArrayCQueue{
	int front, back; //back = rear
	element data[MAX];
}; ArrayCQueue;

typedef ArrayCQueue Queue; //배열 구현 큐

void Init(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);

void Enqueue(Queue *q, element item); //큐 마지막 데이터 뒤에 새로운 데이터 삽입
element Dequeue(Queue *q); //큐 첫 데이터 삭제하고 반환
element Peek(Queue *q); //큐의 첫 데이터
void Display(Queue *q);
