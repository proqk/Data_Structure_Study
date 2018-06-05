#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

//데이터=item, 왼쪽자식노드에 대한 주소(leftnode), 오른쪽자식노드에 대한 주소(rightnode)를 이용하여 노드를 만들고 노드 포인터 반환
TreeNode* MakeTreeNode(t_element item, TreeNode *leftNode, TreeNode *rightNode){
	TreeNode *t = (TreeNode*)malloc(sizeof(TreeNode));
	t->data = item;
	t->left = leftNode;
	t->right = rightNode;
	return t;
}

//방문한 노드=t 의 데이터를 출력해 주는 함수
void Visit(TreeNode *t){
	switch (t->data){
		case '+':	case '-':	case '*':	case '/':	printf("%c ", t->data); break; //연산자는 문자로 출력
		default: printf("%d ", t->data); //숫자는 그냥 출력
	}
}

//전위순휘 root->left->right, t는 트리의 root node에 대한 포인터, 방문한 노드 데이터 출력
void PreOrder(TreeNode *t){
	if (t != NULL){
		Visit(t);
		PreOrder(t->left);
		PreOrder(t->right);
	}
}

//중위순위 left->root->right, t는 트리의 root node에 대한 포인터, 방문한 노드 데이터 출력
void InOrder(TreeNode *t){
	if (t != NULL){
		InOrder(t->left);
		Visit(t);
		InOrder(t->right);
	}
}

//후위순위 left->right->root, t는 트리의 root node에 대한 포인터, 방문한 노드 데이터 출력
void PostOrder(TreeNode *t){
	if (t != NULL){
		PostOrder(t->left);
		PostOrder(t->right);
		Visit(t);
	}
}

//루트 노드에 대한 포인터t, t를 루트노드로 하는 트리의 노드를 모두 삭제하는 함수, 삭제하기 전 해당 노드 데이터 출력
void DeleteTree(TreeNode *t){
	if (t != NULL){
		DeleteTree(t->left); //왼쪽
		DeleteTree(t->right); //오른쪽
		Visit(t); //출력
		free(t);
	}
}

int main(){
	TreeNode *n7 = MakeTreeNode(6, NULL, NULL); //단말노드부터
	TreeNode *n6 = MakeTreeNode(5, NULL, NULL); //5번 노드의 하위 노드 두 개는 null
	TreeNode *n5 = MakeTreeNode(2, NULL, NULL);
	TreeNode *n4 = MakeTreeNode(3, NULL, NULL);
	TreeNode *n3 = MakeTreeNode('-', n6, n7);
	TreeNode *n2 = MakeTreeNode('*', n4, n5);
	TreeNode *n1 = MakeTreeNode('+', n2, n3); //root

	printf("pre order\n"); PreOrder(n1);
	printf("\nin order\n"); InOrder(n1);
	printf("\npost order\n"); PostOrder(n1);
//	printf("\nlevel order\n"); LevelOrder(n1);
	printf("\ndelete tree\n"); DeleteTree(n1);
}
