#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(){
	List list1; //리스트형 변수
	element result; //검색한 결과가 저장되는 변수

	Init(&list1); //항목수 0으로 초기화

	Insert(&list1, 1, 'A'); //첫번째 위치에 'A'삽입
	Insert(&list1, 2, 'C'); //두번째 위치에 'C'삽입
	Insert(&list1, 3, 'E'); //세번째 위치에 'E'삽입
	Insert(&list1, 2, 'B'); //두번째 위치에 'B'삽입
	Insert(&list1, 4, 'D'); //네번째 위치에 'D'삽입
	Insert(&list1, 1, 'D'); //첫번째 위치에 'D'삽입
	printf("After insert\n");
	Display(&list1);

	Delete(&list1, 3); //세번째 위치의 데이터 삭제
	printf("\nAfter delete\n");
	Display(&list1);

	printf("\nRetrieve_all data\n");
	Retrieve(&list1, 2, &result); //두번째 위치의 데이터 검색
	printf("%d번째 항목 : %c\n", 2, result);

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
