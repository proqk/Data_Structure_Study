#include <stdio.h>
#include "ArrayList.h"

int main(){
	List list1; //리스트형 변수
	element result; //검색한 결과가 저장되는 변수

	Init(&list1); //항목수 0으로 초기화

	Insert(&list1, 1, 'A'); //첫번째 위치에 'A'삽입
	Insert(&list1, 2, 'C'); //두번째 위치에 'C'삽입
	Insert(&list1, 3, 'E'); //세번째 위치에 'E'삽입
	Insert(&list1, 2, 'B'); //두번째 위치에 'B'삽입
	Insert(&list1, 4, 'D'); //네번째 위치에 'D'삽입
	printf("After insert\n");
	Display(&list1);

	Delete(&list1, 3); //세번째 위치의 데이터 삭제
	printf("\nAfter delete\n");
	Display(&list1);

	printf("\nRetrieve_all data\n");
	for (int i = 1; i <= Length(&list1); i++){
		Retrieve(&list1, i, &result);
		printf("%d번째 항목 : %c\n", i, result);
	}

	printf("\n\n");
	return 0;
}