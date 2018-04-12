#pragma once

//#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#define MAX 10
typedef char* element; //char을 element형 지정

typedef struct _ArrayList{
	int count; //리스트의 데이터 개수
	element data[MAX]; //element형 데이터 배열
}ArrayList ;

typedef ArrayList List; 

void Insert(List *list, int position, element item); //리스트의 원하는 위치에 데이터 삽입
void Delete(List *list, int position); //리스트의 원하는 위치의 데이터 삭제
void Retrieve(List *list, int position, element *result); //리스트의 원하는 위치의 값 탐색
void Display(List *list); //리스트 내용 출력, 배열이라면 빈 공간도 표시
void Init(List *list); //리스트 초기화
int Length(List *list); //리스트 항목 수 반환
int isEmpty(List *list); //리스트가 비어있는지 확인
int isFull(List *list); //배열 리스트에만 필요

//#endif