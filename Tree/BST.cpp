/*
20~100사이 난수 뽑음(나이)
들어온 난수 순서대로 나이를 기준(key)으로 성명, 성별을 갖는 이진탐색트리
이진탐색트리에서 특정 나이를 갖는 재난지원금 신청자 찾기

예) 20세 입력하면 20세 나이를 갖는 재난지원금 신청자의 정보 이진탐색트리에서 찾아서 보여줌
해당 신청자를 찾는데 몇 번 순회하는지 출력
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct node {
	int key; //나이
	char name, sex; //이름, 성별(f,m)
	struct node* left, * right;
}NODE;

NODE* newNode(int age, char name, char sex) {
	NODE* node = (NODE*)malloc(sizeof(NODE));

	node->key = age;
	node->sex = sex;
	node->name = name;

	node->left = NULL;
	node->right = NULL;
	return(node);
}

int cnt = 0;
NODE* search(NODE* root, int key) {
	cnt++;
	if (root == NULL || root->key == key) return root; //root가 NULL, key가 자기 자신인 경우 리턴
	if (root->key < key) return search(root->right, key); //현재키<찾으려는 키면 오른쪽 트리로(큰수로)
	return search(root->left, key); //아니면 왼쪽 트리로
}

NODE* insert(NODE* node, int key, char name, char sex)
{
	if (node == NULL) return newNode(key, name, sex); //트리가 비었다면 새로 노드를 만듦

	if (key < node->key) node->left = insert(node->left, key, name, sex); //찾는키<노드키면 왼쪽
	else if (key > node->key) node->right = insert(node->right, key, name, sex); //반대면 오르쪽

	return node; //노드 포인터 반환
}

void inorder(NODE* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d세 이름: %c, ", root->key, root->name);
		if (root->sex == 'f') printf("여자\n");
		else printf("남자\n");
		inorder(root->right);
	}
}

int main() {
	srand((unsigned)time(NULL));
	char nameSet = 'A'; //이름 세트
	char sex;
	int totalNum = 80; //총 80명

	NODE* root = NULL;
	for (int i = 0; i < totalNum; i++) {
		int age = rand() % 81 + 20; //사람 한 명 들어옴 0~80
		int setSex = rand() % 2; //성별 결정 0-female, 1-male
		if (setSex == 0) sex = 'f';
		else sex = 'm';

		root = insert(root, age, nameSet + i, sex);
		insert(root, age, nameSet + i, sex);
	}

	printf("전체 목록\n");
	inorder(root);

	int findAge;
	printf("\n찾고 싶은 사람의 나이는? ");
	scanf("%d", &findAge);

	NODE* res = search(root, findAge);
	if (res == NULL) printf("그런 나이의 사람은 없습니다");
	else {
		printf("%d세 이름: %c, ", res->key, res->name);
		if (res->sex == 'f') printf("여자\n");
		else printf("남자\n");
		printf("\n총 %d번만에 찾았습니다\n", cnt);
	}
}
