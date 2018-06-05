#pragma once

typedef int t_element;

typedef struct _TreeNode {
	t_element data;
	struct _TreeNode *left, *right;

}TreeNode;

TreeNode* MakeTreeNode(t_element item, TreeNode *leftNode, TreeNode *rightNode);

void DeleteTree(TreeNode *t); 
void Visit(TreeNode *t);
void PreOrder(TreeNode *t);
void Inorder(TreeNode *t);
void PostOrdr(TreeNode *t);
void LevelOrder(TreeNode *t);

