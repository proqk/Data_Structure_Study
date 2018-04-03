#include <stdio.h>
#include "ArrayList.h"

int main(){
	List list1; //����Ʈ�� ����
	element result; //�˻��� ����� ����Ǵ� ����

	Init(&list1); //�׸�� 0���� �ʱ�ȭ

	Insert(&list1, 1, 'A'); //ù��° ��ġ�� 'A'����
	Insert(&list1, 2, 'C'); //�ι�° ��ġ�� 'C'����
	Insert(&list1, 3, 'E'); //����° ��ġ�� 'E'����
	Insert(&list1, 2, 'B'); //�ι�° ��ġ�� 'B'����
	Insert(&list1, 4, 'D'); //�׹�° ��ġ�� 'D'����
	printf("After insert\n");
	Display(&list1);

	Delete(&list1, 3); //����° ��ġ�� ������ ����
	printf("\nAfter delete\n");
	Display(&list1);

	printf("\nRetrieve_all data\n");
	for (int i = 1; i <= Length(&list1); i++){
		Retrieve(&list1, i, &result);
		printf("%d��° �׸� : %c\n", i, result);
	}

	printf("\n\n");
	return 0;
}