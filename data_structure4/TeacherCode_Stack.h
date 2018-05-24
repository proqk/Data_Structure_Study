#pragma once

#define MAX 30

typedef int element;

typedef struct _ArrayStack
{
	int top;						// 스택의 최상단(마지막 입력된) 데이터 위치 인덱스
	element data[MAX];				// 스택을 구성하는 데이터 배열
}ArrayStack;

typedef ArrayStack Stack;

void Init(Stack *s);				// 스택 초기화, top 값을 -1로
int isEmpty(Stack *s);				// 스택이 비어있는지 확인(비어있다면 1, 아니면 0반환)
int isFull(Stack *s);				// 스택이 차 있는지 확인(차 있다면 1, 아니면 0반환)

void Push(Stack *s, element item);	// 스택(s)에 데이터(item) 삽입
element Pop(Stack *s);				// 스택(s) 최상단(마지막 입력된) 데이터 삭제, 그 값은 반환
element Peek(Stack *s);				// 스택(s) 최상단(마지막 입력된) 데이터 보기, 그 값을 반환
void Display(Stack *s);				// 스택(s)에 있는 데이터 모두 보기
