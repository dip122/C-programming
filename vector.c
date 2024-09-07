#include<stdio.h>
#include<stdlib.h>

struct Node {
	int val;
	struct Node *next;
};

struct Node *newnode(int val){
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	node->val = val;
	node->next = NULL;
}

struct vector{
	struct Node *front ;
	struct Node *rear;
	int count;
};

void createvector(struct vector **q){
	(*q)->front = NULL;
	(*q)->rear = NULL;
}

void push_back(struct vector **q , int val){
	if((*q)->front == (*q)->rear && (*q)->front == NULL){
		struct Node *newNode = newnode(val);
		(*q)->front = newNode;
		(*q)->rear = newNode;
		(*q)->count = 1;
		return;
	}
	struct Node *newNode = newnode(val);
	(*q)->rear->next = newNode;
	(*q)->rear = (*q)->rear->next;
	(*q)->count++;
	return;
}

void pop_back(struct vector **q){
	if((*q)->front == NULL && (*q)->front == NULL){
		printf("Nothing to pop\n");
		return;
	}else if((*q)->front == (*q)->rear){
		struct Node *temp = (*q)->front;
		(*q)->front = NULL;
		(*q)->rear = NULL;
		(*q)->count = 0;
		free(temp);
		return;
	}else{
		struct Node *temp = (*q)->front;
		while(temp->next != (*q)->rear){
			temp = temp->next;
		}
		struct Node *t = temp->next;
		(*q)->rear = temp;
		(*q)->rear->next = NULL;
		free(t);
		(*q)->count--;
		return;
	}
}

int size(struct vector *q){
	int size = q->count;
	return size ;
}

int isEmpty(struct vector *q){
	if(q->count == 0)return 1;
	return 0;
}
int back(struct vector *v){
	if(v->rear == NULL)return -1;
	int val = v->rear->val;
	return val;
}


void display(struct vector *v){
	struct Node *temp = v->front;
	while(temp!=NULL){
		printf("%d\t",temp->val);
		temp = temp->next;
	}
	printf("\n");
}
	

int main(){

	struct vector *v;
	createvector(&v);

	while(1){
		printf("1. Enter If Your want to push back some value\n");
		printf("2 . Enter Tf You want to pop back the data\n");
		printf("3. Enter to know the size of the vector\n");
		printf(" 4. Enter to know if the vector is Empty or not\n");
		printf("5 . Enter if you want to know the back of the vector\n");
		//printf("6 . Enter If you want to know the size of the vector\n");
		printf("6 . Display vector\n");
		printf("7 . Exit\n");

		int val;
		scanf("%d",&val);
		if(val == 1){
			int c;
			printf("Enter the value you want to push\n");
			scanf("%d",&c);
			push_back(&v,c);
		}else if(val == 2){
			pop_back(&v);
		}else if(val == 3){
			printf("size of the vector is %d\t",size(v));
		}else if(val == 4){
			if(isEmpty(v) == 1){
				printf("vector is Empty\n");
			}else {
				printf("vector is not empty\n");
			}
		}else if(val == 5){
			printf("back of the vector is %d\t",back(v));
		}else if(val == 6){
			display(v);
		}
		else break;
	}

	return 0;
}
