#include <stdio.h>
#include <stdlib.h>

typedef struct node //구조체 정의
{
    int data;
    struct node *left;
    struct node *right;
}NODE;
  
/* newNode(): 노드에 메모리 할당하고 초기화*/
NODE* newNode(int data)
{
  //노드에 메모리 할당 
  NODE* node = (NODE*)malloc(sizeof(NODE));
  
  //데이터 넣음
  node->data = data;
  
  // 왼쪽, 오른쪽 노드를 NULL로 초기화
  node->left = NULL;
  node->right = NULL;
  return(node);
}

/* 이진트리에서 전위 순회 과정 출력 */
void printPreorder(NODE* node)
{
     if (node == NULL)
          return;
    
     /* 출력 */
     printf("%d ", node->data);  
  
     /* 왼쪽 서브 트리로 */
     printPreorder(node->left);  
  
     /* 오른쪽 서브 트리로 */
     printPreorder(node->right);
}  

/* 이진트리에서 중위 순회 과정 출력 */
void printInorder(NODE* node)
{
     if (node == NULL)
          return;
  
     /* 왼쪽 서브 트리로 */
     printInorder(node->left);
  
     /* 출력 */
     printf("%d ", node->data);  
  
     /* 오른쪽 서브 트리로 */
     printInorder(node->right);
}

/* 이진트리에서 후위 순회 과정 출력 */
void printPostorder(NODE* node)
{
	 // NULL이면 반환
     if (node == NULL)
        return;
  
     // 왼쪽 서브 트리로
     printPostorder(node->left);
  
     // 오른쪽 서브 트리로
     printPostorder(node->right);
  
     // 출력
     printf("%d ", node->data);
}
  
int main()
{
  /*루트 노드를 만든다*/
  NODE *root = newNode(1);  
  /* 루트 노드를 만든 상태
  
        1
      /   \
     NULL  NULL  
  */
    
  
  root->left        = newNode(2);
  root->right       = newNode(3);
  /* 루트 노드1에 왼쪽, 오른쪽에 각각 2, 3이라는 자식 노드 추가한 상태
           1
         /   \
        2      3
     /    \    /  \
    NULL NULL NULL NULL
  */
  
  
  root->left->left  = newNode(4);
  /* 2의 왼쪽 자식으로 4를 추가한 상태
           1
       /       \
      2          3
    /   \       /  \
   4    NULL  NULL  NULL
  /  \
NULL NULL
*/
  
  printf("\n전위 순회: ");
  printPreorder(root);
  printf("\n중위 순회: ");
  printInorder(root);
  printf("\n후위 순회: ");
  printPostorder(root);
  
  getchar();
  return 0;
}
