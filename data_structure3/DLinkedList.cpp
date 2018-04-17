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

} //����Ʈ�� �����԰� ����Ʈ�ϱ� �����ͷ� count ������ �����Ѵ�

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
		Node *neww = (Node *)malloc(sizeof(Node)); //�߰��� ��� ������
		neww->data = item;

		Node *temp = list->head; //���� ��ġ ���� ��带 ����Ű�� �ӽ� ������, list->head�� ���� ����� head ������
		for (int i = 0; i < position - 1; i++){
			temp = temp->next; //ù ������ ���󰡸鼭 ���� ��ġ ���� ��带 ã��
		}
		neww->prev = temp; //�� ����� ���� ���� temp �����Ͱ� ����Ű�� ���
		neww->next = temp->next; //�� ����� ���� ���� temp->next �� ����Ű�� ��� = �� ����� temp ���� ���
		neww->next->prev = neww; //�� ��� ���� ����� ���� ���� �� ���
		neww->prev->next = neww; //�� ��� ���� ����� ���� ���� �����

		list->count++;
	}
}

void Delete(List *list, int position){
	if (isEmpty(list)) printf("list empty");
	else if (position < 1 || position > list->count){
		printf("out of range\n");
	}
	else {
		Node *temp = list->head->next; //������ ��带 ����Ű�� ������
		for (int i = 0; i < position - 1; i++){
			temp = temp->next; //������ ��� ã��
		}
		temp->prev->next = temp->next; //������ ��� ���� ����� ���� ���� ������ ����� ���� ���
		temp->next->prev = temp->prev; //������ ��� ���� ����� ���� ���� ������ ����� ���� ���

		free(temp); //������ ��� �޸� �����ֱ�
	}
	list->count--;
}

void Retrieve(List *list, int position, element *result){
	if (isEmpty(list)) printf("list empty\n");
	else if (position < 1 || position > list->count){
		//���� ���� count���� ��ĭ �������� ���� �� �ִµ� ������ ���� �� �� ������ŭ�� �����ϴϱ� +1�� ���� �ʴ´� 
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
	Node *temp = list->head->next; //������ ���
	int ii = 1;
	for (int i = 1; i <= list->count; i++){
		printf("List[%d] : %C delete!!!!\n", ii, temp->data);
		temp = temp->next;
		Delete(list, i);
		i--;
		ii++;
	}
	if (ii == 0){
		printf("����ֽ��ϵ��");
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
//		Node *temp = list->head->next; //������ ��带 ����Ű�� ������
//		for (int i = 0; i < position - 1; i++){
//			temp = temp->next; //������ ��� ã��
//		}
//		temp->prev->next = temp->next; //������ ��� ���� ����� ���� ���� ������ ����� ���� ���
//		temp->next->prev = temp->prev; //������ ��� ���� ����� ���� ���� ������ ����� ���� ���
//
//		free(temp); //������ ��� �޸� �����ֱ�
//	}
//	list->count--;
//}