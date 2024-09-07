#include "queue.h"
#include<stdio.h>
#include<stdlib.h>

struct queue *createqueue(){
	struct queue *q = (struct queue*)malloc(sizeof(struct queue));
	q->front = NULL;
	q->rear = NULL;
	q->count = 0;
	return q;
}

struct Node *newNode(struct TreeNode *val){
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	node->val = val;
	node->next = NULL;
}

void push(struct queue *q,struct TreeNode *val){
	if(q->front == NULL && q->front == NULL){
	//	printf("YES\n");
		struct Node *node = newNode(val);
		q->front = node;
		q->rear = node;
		q->count  = 1;
		return;
	}
	struct Node *node = newNode(val);
	q->rear->next = node;
	q->rear = q->rear->next;
	q->count++;
	return;
}

void pop(struct queue *q){
	if(q->front == NULL && q->rear == NULL){
		return;
	}else if(q->front == q->rear){
		q->front = NULL;
		q->rear = NULL;
		q->count = 0;
		return;
	}
	struct Node *temp = q->front;
	q->front = q->front->next;
	temp->next = NULL;
	q->count--;
	free(temp);
}

int size(struct queue *q){
	return q->count;
}

struct TreeNode *front(struct queue *q){
	if(q->front == NULL && q->rear == NULL){
		struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		node->val = -1;
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	return q->front->val;
}

int isEmpty(struct queue *q){
	if(q->count == 0)return 1;
	return 0;
}


