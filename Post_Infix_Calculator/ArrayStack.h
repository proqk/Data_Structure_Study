#pragma once
#define MAX 30 //배열 크기

typedef char element;

typedef struct _ArrayStack {
	int top; //스택 맨 위의 인덱스
	element data[MAX]; //스택 데이터 공간
}ArrayStack;

typedef ArrayStack Stack; //배열로 구현한 스택

void Init(Stack *s); //스택 초기화 top 값을 -1로
int isEmpty(Stack *s); //스택이 비었나?
int isFull(Stack *s); //스택이 꽉 찼나?

void Push(Stack *s, element item); //스택의 맨 위에 데이터 삽입
element Pop(Stack *s); //스택 최상단의 데이터 삭제, 삭제되는 데이터 반환
element Peek(Stack *s); //스택 최상단의 데이터 검색, 찾은 데이터 반환
void Display(Stack *s); //스택 데이터 표시