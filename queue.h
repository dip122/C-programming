#ifndef QUEUE_H
#define QUEUE_H

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct Node{
	struct TreeNode *val;
	struct Node *next;
};

struct queue{
	struct Node *front;
	struct Node *rear;
	int count;
};

struct queue *createqueue();

struct Node *newNode(struct TreeNode *val);
void push(struct queue *q,struct TreeNode *val);
void pop(struct queue *q);
struct TreeNode *front(struct queue *q);
int size(struct queue *q);
int isEmpty(struct queue *q);


#endif


