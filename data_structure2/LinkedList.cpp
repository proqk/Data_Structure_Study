#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void Init(List *list){ 
	list->count = 0; 
	list->head = NULL;
} //����Ʈ�� �����԰� ����Ʈ�ϱ� �����ͷ� count ������ �����Ѵ�

int Length(List *list) { return list->count; }
int isEmpty(List *list) { 
	if (list->count == 0) return true;
	else return false;

	//return (list->count == 0);
}

void Insert(List *list, int position, int item){
	if (position < 1 || position > list->count + 1){
		printf("out of range\n");
	}
	else {
		Node *neww = (Node *)malloc(sizeof(Node));
		neww->data = item;

		if (position == 1){ //ó�� ��忡 ���� ���� head�� �ϴµ� �� �������ʹ� ��峢�� �ϴϱ� ��츦 ����
			neww->next = list->head;
			list->head = neww;
		}
		else{
			Node *temp = list->head;
			for (int i = 1; i < position - 1; i++){
				temp = temp->next;
			}
			neww->next = temp->next;
			temp->next = neww;
		}
		list->count++;
	}
}

//void Delete(List *list, int position){
//	if (isEmpty(list)) printf("list empty");
//	else if (position < 1 || position > list->count + 1){
//		printf("out of range\n");
//	}
//	else {
////		printf("ee%d\n", list->count);
//		for (int i = position; i <= list->count - 1; i++){
//			list->data[i - 1] = list->data[i];
//		}
//
//		list->count--;
//	}
//}

void Retrieve(List *list, int position, element *result){
	if (isEmpty(list)) printf("list empty\n");
	else if (position < 1 || position > list->count + 1){
		printf("out of range\n");
	}
	else {
		*result = list->data[position - 1];
	}
}

void Display(List *list){
	if (isEmpty(list)) printf("list empty\n");
	else {
		int i;
		for (i = 0; i < list->count; i++){
			printf("List[%d] : %c\n", i + 1, list->data[i]);
		}
		for (i; i < MAX; i++){
			printf("List[%d] : empty\n", i + 1);
		}
	}
}
