#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
	int data; //노드 데이터
	struct TreeNode *left, *right; //노드 포인터 왼쪽 자식 노드, 오른쪽 자식 노드
}TreeNode;

//원하는 값을 가진 노드에 대한 포인터 반환 없으면 null 반환
TreeNode* bstsearch(TreeNode *root, int key){
	
}

//트리에서 원하는 키 값을 가진 노드를 삽입
int bstinsert(TreeNode *root, int key){ 

}

//트리에서 원하는 키 값을 가진 노드 삭제
int bstdelete(TreeNode **root, int key){

}

//오름차순 정렬된 순서대로 출력
int bstdisplay(TreeNode *root){

}

int main(){
	TreeNode *t = NULL; //빈트리 생성
	TreeNode *snode; //원하는 키 값을 가진 노드에 대한 포인터(탐색연산결과 저장)
	int key; //데이터

	printf("트리 생성-첫 번째 입력값이 루트 노드의 키 값");
	while (1){
		printf("\n\n삽입할 키 값을 입력하시오 종료 -1");
		scanf("%d", &key, sizeof(key));
		if (key == -1) break;

		bstinsert(&t, key); //삽입 함수
		printf("\b%d 삽입 후 트리는 이것이다!!\n", key);
		bstdisplay(t); //출력함수
	}

	while (1){
		printf("\n 찾아서 삭제할 키 값(정수)을 입력하시오 종료 -1");
		scanf("%d", &key);
		if (key == -1) break;

		snode = bstsearch(t, key); //원하는 키 값을 가진 노드 탐색 후
		if (snode != NULL){ //해당 노드에 대한 포인터값 반환
			printf("%d: 찾았습니다!! \n", key); //그 값이 null 아니면 존재한다는 의미
		}
		else printf("%d: 못찾았습니다!! \n", key);

		printf("\n 찾아서 삭제할 키 값(정수)을 입력하시오: ");
		scanf("%d", &key);
		bstdelete(&t, key); //삭제
		printf("\n%d 삭제 후 트리는! \n", key);
		bstdisplay(t);
	}
	printf("\n\n");
}
