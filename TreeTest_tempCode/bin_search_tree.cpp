#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
	int data; //노드 데이터
	struct TreeNode *left, *right; //노드 포인터 왼쪽 자식 노드, 오른쪽 자식 노드
}TreeNode;

//원하는 값을 가진 노드에 대한 포인터 반환 없으면 null 반환
TreeNode* bstsearch(TreeNode *root, int key){
	if (root == NULL) return NULL; //루트가 비어있다면 비어있음
	if (root->data == key) return root; //데이터를 찾으면 노드 주소 반환
	else if (root->data < key) bstsearch(root->right, key);
	else bstsearch(root->left, key);
}

TreeNode* createnode(int key){
	TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
	newnode->right = NULL;
	newnode->left = NULL;
	newnode->data = key;

	return newnode;
	//삽입할 값을 가진 새로운 노드를 만든다
}

//트리에서 원하는 키 값을 가진 노드를 삽입
TreeNode* bstinsert(TreeNode *root, TreeNode* newnode){
	if (root == NULL) {
		root = newnode;
	}
	if (newnode->data > root->data){ //삽입할 값이 노드 값보다 크면 오른쪽으로 가야함
		if (root->right != NULL) bstinsert(root->right, newnode); //비어있지 않다면 다시 내려가야 하니까 재귀를 돌린다
		else root->right = newnode; //오른쪽 자식 노드가 비어있으면 새로운 노드를 넣는다 
	}
	else if(newnode->data < root->data) {
		if (root->left != NULL) bstinsert(root->left, newnode); 
		else root->left = newnode; //왼쪽도 똑같다
	}
	return root;
}

TreeNode* bstsearch2(TreeNode *root){ //삭제할 노드를 찾을껀데 왼쪽 노드에서 가장 큰 수(=가장 오른쪽 노드)를 찾을 것
	if (root == NULL) return NULL; //없으면 반환
	if (root->right != NULL) return bstsearch2(root->right); //있으면 오른쪽으로 내려감
	else return root;
}

//트리에서 원하는 키 값을 가진 노드 삭제
TreeNode* bstdelete(TreeNode *root, int key){
	TreeNode* temp = NULL;

	if (root == NULL) printf("삭제할 노드가 없음"); //삭제하려는게 없을 수도 있으니까 조건으로 빼줌
	else if (root->data < key){ //일단 노드를 찾아가야 함. 위에랑 같음
		root->right = bstdelete(root->right, key); //찾는 값이 노드보다 크면 오른쪽
	}
	else if (root->data > key) { //아니면 왼쪽ㅎ
		root->left = bstdelete(root->left, key);
	}
	else {
		if (root->left != NULL && root->right != NULL){
			//2. 자식이 둘 다 있으면.. 둘 다 날려버릴 수는 없으니까 그 자리에 다른 값으르 넣어서 땜빵쳐야 한다
			//그 땜빵값을 뭐로 하느냐가 문젠데 삭제할 수랑 가장 가까운 수를 넣어서 트리 자체는 안 깨지게 하면 된다
			//삭제할 수를 기준으로 본다면 삭제할 수의 왼쪽 노드들에서는 가장 큰 수가, 오른쪽에서는 가장 작은 수가 제일 가까운 수가 되는데
			//뭐로 골라 넣을지는 내 맘이다. 왼쪽이 맘에 안들어서 왼쪽 애를 끌어오겠습니다
			printf("3\n");
			temp = bstsearch2(root->left); //가장 값이 큰 노드는 왼쪽에서 가장 오른쪽에 있는 노드
			root->data = temp->data; //현재 노드를 바꿔치기 한다
			root->left = bstdelete(root->left, temp->data); //바꿔치기 한 노드(왼쪽에서 가장 오른쪽에 있느느 노드)를 삭제한다
		}
	//else if (root->data == key){ //삭제할 노드를 찾았다면 단말인지/자식이1개/자식이2개 케이스를 나눔
	//	 //임시 노드
		//else if (root->left == NULL && root->right == NULL){ //1. 자식이 아무 것도 없다면 찾아서 없애버림
		//	printf("1\n");
		//	free(temp);
		//}
		//else if (root->left == NULL || root->right==NULL){ //2. 왼쪽 자식이나 오른쪽 자식이 하나만 비어있는거라면
		//	printf("2\n");
		//	if (root->left == NULL){ //왼쪽 자식이 없다면 오른쪽에 있다는 의미니까 오른쪽 자식을 현재 노드에 이어줘야 함
		//		root = root->right; //도킹
		//	}
		//	else{ //오른쪽 자식이 없다면 왼쪽 자식이 있다는 의미니까 왼쪽 자식을 현재 노드에 도킹
		//		root = root->left;
		//	}
		//	free(temp);
		//}
		//else { 
		//}
		else{
			temp = root;
			if (root->left == NULL){ //왼쪽 자식이 없다면 오른쪽에 있다는 의미니까 오른쪽 자식을 현재 노드에 이어줘야 함
				root = root->right; //도킹
			}
			else if(root->right == NULL){ //오른쪽 자식이 없다면 왼쪽 자식이 있다는 의미니까 왼쪽 자식을 현재 노드에 도킹
				root = root->left;
			}
			free(temp);
		}
	}
	return root;
}

//오름차순 정렬된 순서대로 출력
void bstdisplay(TreeNode *root){
	if (root == NULL) return; //출력할 것이 없으면 빠져나옴
	bstdisplay(root->left); //왼쪽 맨 아래부터 출력해야 하니까 재귀로 계속 돌림
	printf("%d ", root->data);
	bstdisplay(root->right); //오른쪽 출력
}

int main(){
	TreeNode *t = NULL; //빈트리 생성
	TreeNode *snode; //원하는 키 값을 가진 노드에 대한 포인터(탐색연산결과 저장)
	int key; //데이터

	printf("트리 생성-첫 번째 입력값이 루트 노드의 키 값");
	printf("\n\n삽입할 root 키 값을 입력 : ");
	scanf("%d", &key);
	t=bstinsert(t, createnode(key));
	bstdisplay(t); //출력함수
	while (1){
		printf("\n\n삽입할 키 값을 입력 종료 -1: ");
		scanf("%d", &key);
		if (key == -1) break;

		bstinsert(t, createnode(key)); //삽입 함수
		printf("\b%d 삽입 후 트리\n", key);
		bstdisplay(t); //출력함수
	} 

	while (1){
		printf("\n찾을 키를 입력 종료 -1: ");
		scanf("%d", &key);
		if (key == -1) break;

		snode = bstsearch(t, key); //원하는 키 값을 가진 노드 탐색 후
		if (snode != NULL){ //해당 노드에 대한 포인터값 반환
			printf("%d: 찾았어 \n", key); //그 값이 null 아니면 존재한다는 의미
		}
		else printf("%d: 못찾았어 \n", key);
 
		printf("\n 찾아서 삭제할 키 값(정수)을 입력: ");
		scanf("%d", &key);
		bstdelete(t, key); //삭제
		printf("\n%d 삭제 후 트리 \n", key);
		bstdisplay(t);
	}
	printf("\n\n");
}
