#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void Init(List *list){ 
	list->count = 0; 
	
	list->head = (Node*)malloc(sizeof(Node));
	list->tail = (Node*)malloc(sizeof(Node));

	list->head->prev = NULL;
	list->head->next = list->tail;

	list->tail->next = NULL;
	list->tail->prev = list->head;

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
		Node *neww = (Node *)malloc(sizeof(Node)); //추가할 노드 포인터
		neww->data = item;

		Node *temp = list->head; //삽입 위치 이전 노드를 가리키는 임시 포인터, list->head는 더미 노드의 head 포인터
		for (int i = 0; i < position - 1; i++){
			temp = temp->next; //첫 노드부터 따라가면서 삽입 위치 이전 노드를 찾음
		}
		neww->prev = temp; //새 노드의 이전 노드는 temp 포인터가 가리키는 노드
		neww->next = temp->next; //새 노드의 다음 노드는 temp->next 가 가리키는 노드 = 한 마디로 temp 다음 노드
		neww->next->prev = neww; //새 노드 다음 노드의 이전 노드는 새 노드
		neww->prev->next = neww; //새 노드 이전 노드의 다음 노드는 새노드

		list->count++;
	}
}

void Delete(List *list, int position){
	if (isEmpty(list)) printf("list empty");
	else if (position < 1 || position > list->count){
		printf("out of range\n");
	}
	else {
		Node *temp = list->head->next; //삭제할 노드를 가리키는 포인터
		for (int i = 0; i < position - 1; i++){
			temp = temp->next; //삭제할 노드 찾기
		}
		temp->prev->next = temp->next; //삭제할 노드 이전 노드의 다음 노드는 삭제할 노드의 다음 노드
		temp->next->prev = temp->prev; //삭제할 노드 다음 노드의 이전 노드는 삭제할 노드의 이전 노드

		free(temp); //삭제할 노드 메모리 놓아주기
	}
	list->count--;
}

void Retrieve(List *list, int position, element *result){
	if (isEmpty(list)) printf("list empty\n");
	else if (position < 1 || position > list->count){
		//넣을 때는 count보다 한칸 다음까지 넣을 수 있는데 삭제할 때는 딱 그 개수만큼만 가능하니까 +1을 하지 않는다 
		printf("out of range\n");
	}
	else {
		Node *temp = list->head->next;
		for (int i = 1; i < position ; i++){
			temp = temp->next;
		}
		*result = temp->data;
	}
}

void Display(List *list){
	if (isEmpty(list)) printf("list empty\n");
	else {
		Node *temp = list->head->next;
		for (int i = 0; i < list->count; i++){
			printf("List[%d] : %c\n", i+1, temp->data);
			temp = temp->next;
		}
	}
}

void Display_R(List *list){
	if (isEmpty(list)) printf("list empty\n");
	else {
		Node *temp = list->tail->prev;
		for (int i = list->count - 1; i >= 0; i--){
			printf("List[%d] : %c\n", i + 1, temp->data);
			temp = temp->prev;
		}
	}
}

void Delete_all(List *list){
	Node *temp = list->head->next; //삭제할 노드
	int ii = 1;
	for (int i = 1; i <= list->count; i++){
		printf("List[%d] : %C delete!!!!\n", ii, temp->data);
		temp = temp->next;
		Delete(list, i);
		i--;
		ii++;
	}
	if (ii == 0){
		printf("비어있습니드아");
	}
}

//void Delete_item(List *list, char item){
//	int index = 0;
//	Node *temp = list->head->next;
//	for (int i = 0; i < list->count; i++){
//		if (temp->data = item) {
//			index = i;
//			break;
//		}
//		else temp = temp->next;
//	}
//
//	if (isEmpty(list)) printf("list empty");
//	else {
//		Node *temp = list->head->next; //삭제할 노드를 가리키는 포인터
//		for (int i = 0; i < position - 1; i++){
//			temp = temp->next; //삭제할 노드 찾기
//		}
//		temp->prev->next = temp->next; //삭제할 노드 이전 노드의 다음 노드는 삭제할 노드의 다음 노드
//		temp->next->prev = temp->prev; //삭제할 노드 다음 노드의 이전 노드는 삭제할 노드의 이전 노드
//
//		free(temp); //삭제할 노드 메모리 놓아주기
//	}
//	list->count--;
//}