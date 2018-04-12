#pragma once

//#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#define MAX 10
typedef char* element; //char�� element�� ����

typedef struct _ArrayList{
	int count; //����Ʈ�� ������ ����
	element data[MAX]; //element�� ������ �迭
}ArrayList ;

typedef ArrayList List; 

void Insert(List *list, int position, element item); //����Ʈ�� ���ϴ� ��ġ�� ������ ����
void Delete(List *list, int position); //����Ʈ�� ���ϴ� ��ġ�� ������ ����
void Retrieve(List *list, int position, element *result); //����Ʈ�� ���ϴ� ��ġ�� �� Ž��
void Display(List *list); //����Ʈ ���� ���, �迭�̶�� �� ������ ǥ��
void Init(List *list); //����Ʈ �ʱ�ȭ
int Length(List *list); //����Ʈ �׸� �� ��ȯ
int isEmpty(List *list); //����Ʈ�� ����ִ��� Ȯ��
int isFull(List *list); //�迭 ����Ʈ���� �ʿ�

//#endif