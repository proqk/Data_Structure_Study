#pragma once

typedef int element;

typedef struct _Node{
	element data; //나의 데이터
	struct _Node *p; //다음 노드의 데이터를 가리키는 나의 포인터
} Node;

typedef struct _LinkedStack{
	int count; //스택의 항목수
	Node *top; //스택 시작노드(최상단 노드)를 가리키는 포인터
} LinkedStack;

typedef LinkedStack Stack; //연결리스트로 구현한 스택

void Init(Stack *s); //스택 초기화 top 값을 NULL로
int isEmpty(Stack *s); //스택이 비었나?
 
void Push(Stack *s, element item); //스택의 맨 위에 데이터 삽입
element Pop(Stack *s); //스택 최상단의 데이터 삭제, 삭제되는 데이터 반환
element Peek(Stack *s); //스택 최상단의 데이터 검색, 찾은 데이터 반환
void Display(Stack *s); //스택 데이터 표시
