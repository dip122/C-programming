#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

struct TreeNode *newTreeNode(int val){
	struct TreeNode *treeNode = (struct TreeNode*)malloc(sizeof(struct TreeNode*));
	treeNode->val =val;
	treeNode->left = NULL;
	treeNode->right = NULL;
}

void levelorderTraversal(struct TreeNode *root){
	if(root == NULL)return;
	int i;
	struct queue *q = createqueue();
	push(q,root);
	while(isEmpty(q) == 0){
		int n = size(q);
		for(i=0;i<n;i++){
			struct TreeNode *currnode = front(q);
			pop(q);
			printf("%d\t",currnode->val);
			if(currnode->left != NULL)push(q,currnode->left);
			if(currnode->right!=NULL)push(q,currnode->right);
		}
		printf("\n");
	}
}


int main(){

	struct TreeNode *root = newTreeNode(1);
	root->left = newTreeNode(2);
	root->right = newTreeNode(3);
	root->left->left = newTreeNode(4);
	root->left->right = newTreeNode(5);
	root->right->left = newTreeNode(6);
	root->right->right = newTreeNode(7);

	levelorderTraversal(root);

	return 0;
}
