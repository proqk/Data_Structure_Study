#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void Init(List *list){ 
	list->count = 0; 
	list->head = NULL;
} //리스트를 가져왔고 리스트니까 포인터로 count 변수에 접근한다

int Length(List *list) { return list->count; }
int isEmpty(List *list) { 
	if (list->count == 0) return true;
	else return false;

	//return (list->count == 0);
}

void Insert(List *list, int position, element item){
	if (position < 1 || position > list->count + 1){
		printf("out of range\n");
	}
	else {
		Node *neww = (Node *)malloc(sizeof(Node));
		neww->data = item;

		if (position == 1){ //처음 노드에 넣을 때는 head로 하는데 그 다음부터는 노드끼리 하니까 경우를 나눔
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

void Delete(List *list, int position){
	if (isEmpty(list)) printf("list empty");
	else if (position < 1 || position > list->count){
		printf("out of range\n");
	}
	else {
		Node *d;
		if (position == 1){
			d = list->head;
			list->head = d->next;
		}
		else{
			Node *temp = list->head;
			for (int i = 1; i < position - 1; i++){
				temp = temp->next;
			}

			d = temp->next;
			temp->next = d->next;
		}

		free(d);
		list->count--;
	}
}

void Delete_all(List *list){
	Node *temp = list->head; //삭제할 노드
	int ii = 1;
	for (int i = 1; i <= list->count; i++){
		printf("List[%d] : %C delete\n", ii, temp->data);
		temp = temp->next;
		Delete(list, i);
		i--;
		ii++;

	}
}

void Retrieve(List *list, int position, element *result){
	if (isEmpty(list)) printf("list empty\n");
	else if (position < 1 || position > list->count){
		//넣을 때는 count보다 한칸 다음까지 넣을 수 있는데 삭제할 때는 딱 그 개수만큼만 가능하니까 +1을 하지 않는다 
		printf("out of range\n");
	}
	else {
		Node *temp = list->head;
		for (int i = 1; i < position ; i++){
			temp = temp->next;
		}
		*result = temp->data;
	}
}

void Display(List *list){
	if (isEmpty(list)) printf("list empty\n");
	else {
		Node *temp = list->head;
		for (int i = 0; i < list->count; i++){
			printf("List[%d] : %c\n", i+1, temp->data);
			temp = temp->next;
		}
	}
}

//void Delete_item(List *list, char item){
//
//	for (int i = 1; i < list->count; i++){
//		if ()
//	}
//
//
//	Node *d;
//	if (position == 1){
//		d = list->head;
//		list->head = d->next;
//	}
//	else{
//		Node *temp = list->head;
//		for (int i = 1; i < position - 1; i++){
//			temp = temp->next;
//		}
//
//		d = temp->next;
//		temp->next = d->next;
//	}
//
//	free(d);
//	list->count--;
//
//}

