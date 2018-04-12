#include <stdio.h>
#include "ArrayList.h"

void Init(List *list){ list->count = 0; } //리스트를 가져왔고 리스트니까 포인터로 count 변수에 접근한다
int Length(List *list) { return list->count; }
int isEmpty(List *list) {
	if (list->count == 0) return true;
	else return false;
}
int isFull(List *list) {
	if (list->count == MAX) return true;
	else return false;
}

void Insert(List *list, int position, element item){
	if (isFull(list)) printf("list full");
	else if (position < 1 || position > list->count + 1){
		printf("out of range\n");
	}
	else {
		for (int i = list->count - 1; i >= position - 1; i--){
			list->data[i + 1] = list->data[i];
		}

		list->data[position - 1] = item;
		list->count++;
	}
}

void Delete(List *list, int position){
	if (isEmpty(list)) printf("list empty");
	else if (position < 1 || position > list->count + 1){
		printf("out of range\n");
	}
	else {
		//		printf("ee%d\n", list->count);
		for (int i = position; i <= list->count - 1; i++){
			list->data[i - 1] = list->data[i];
		}

		list->count--;
	}
}

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
			printf("List[%d] : %s\n", i + 1, list->data[i]);
		}
		for (i; i < MAX; i++){
			printf("List[%d] : empty\n", i + 1);
		}
	}
}