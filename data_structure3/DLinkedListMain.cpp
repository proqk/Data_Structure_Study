#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

int main(){
	List list1; //����Ʈ�� ����
	element result; //�˻��� ����� ����Ǵ� ����

	Init(&list1); //�׸�� 0���� �ʱ�ȭ

	Insert(&list1, 1, 'A'); //ù��° ��ġ�� 'A'����
	Insert(&list1, 2, 'D'); //�ι�° ��ġ�� 'D'����
	Insert(&list1, 3, 'E'); //����° ��ġ�� 'E'����
	Insert(&list1, 2, 'B'); //�ι�° ��ġ�� 'B'����
	Insert(&list1, 5, 'D'); //�׹�° ��ġ�� 'D'����
	Insert(&list1, 1, 'D'); //ù��° ��ġ�� 'D'����
	printf("After insert\n");
	Display(&list1);

	Delete(&list1, 3); //����° ��ġ�� ������ ����
	printf("\nAfter delete\n");
	Display(&list1);

	printf("\nRetrieve_all data\n");
	Retrieve(&list1, 2, &result); //�ι�° ��ġ�� ������ �˻�
	printf("%d��° �׸� : %c\n", 2, result);

	printf("\n���������� ���\n");
	Display_R(&list1);

	//Delete_item(&list1, 'D');
	//printf("\nAfter delete item 'D'\n");
	//Display(&list1);

	printf("\nDelete All\n");
	Delete_all(&list1);
	printf("\nAfter Delete All\n");
	Display(&list1);

	printf("\n\n");
	return 0;
}