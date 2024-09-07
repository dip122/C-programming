#include<stdio.h>
#include<stdlib.h>

struct Node{
	int val;
	struct Node *next;
};

struct queue{
	struct Node *front;
	struct Node *rear;
	int count;
};

struct Node *newnode(int val){
	struct Node *newnode_create = (struct Node*)malloc(sizeof(struct Node));
	newnode_create->val = val;
	newnode_create->next = NULL;
}	

void push(struct queue **q,int val){

	struct Node *newNode = newnode(val);
	if((*q)->front == NULL && (*q)->rear == NULL){
		(*q)->front = newNode;
		(*q)->rear = newNode;
		(*q)->count = 1;
		return;
	}
	else{
		//*q->rear is not NULL right now
		(*q)->rear->next = newNode;
		(*q)->rear = (*q)->rear->next;
		(*q)->count++;
		return;
	}
}
int pop(struct queue **q){
	if((*q)->front == NULL && (*q)->rear == NULL){
		printf("Noting to pop/n");
		return -1;
	}else if((*q)->front == (*q)->rear){
		int val = (*q)->front->val;
		(*q)->front = NULL;
		(*q)->rear = NULL;
		(*q)->count = 0;
		return val;
	}
	int val = (*q)->front->val;
	(*q)->front = (*q)->front->next;
	(*q)->count--;
	return val;
}

int front(struct queue *q){
	if((q)->front == NULL)return -1;
	int val = q->front->val;
	return val;
}

int back(struct queue *q){
	if(q->rear == NULL)return -1;
	int val = q->rear->val;
	return val;
}

int isEmpty(struct queue *q){
	if(q->front == NULL && q->rear == NULL)return 1;
	else return 0;
}

int size(struct queue *q){
	int count = q->count;
	return count;
}

void display(struct queue *q){
	struct Node *temp = q->front;
	while(temp!=NULL){
		printf("%d\t",temp->val);
		temp = temp->next;
	}
	printf("\n");
	return;
}

void createqueue(struct queue **q){
	(*q)->front = NULL;
	(*q)->rear = NULL;
}

int main(){

	struct queue *q;
	createqueue(&q);

	push(&q,1);
	push(&q,2);
	display(q);
	pop(&q);
	display(q);	
	return 0;
}	
