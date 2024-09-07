#include<stdio.h>
#include<stdlib.h>

struct Node {
	int val;
	struct Node *next;
};

struct dequeue{
	struct Node *front;
	struct Node *rear;
	int count;
};

struct Node *newNode(int val){
	struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->val = val;
	newnode->next = NULL;
	return newnode;
}

void push_front(struct dequeue ** q , int val){
	if((*q)->front == NULL && (*q)->rear == NULL){
		struct Node *newnode = newNode(val);
		(*q)->front = newnode;
		(*q)->rear = newnode;
		(*q)->count = 1;
		return;
	}else{
		struct Node *newnode = newNode(val);
		newnode->next = (*q)->front;
		(*q)->front = newnode;
		(*q)->count++;
		return;
	}
}

void push_back(struct dequeue **q,int val){
	if((*q)->front == NULL && (*q)->rear == NULL){
		struct Node *newnode = newNode(val);
		(*q)->front = newnode;
		(*q)->rear = newnode;
		(*q)->count = 1;
		return;
	}else{
		struct Node *newnode = newNode(val);
		(*q)->rear->next = newnode;
		(*q)->rear = (*q)->rear->next;
		(*q)->count++;
		return;
	}
}

int pop_front(struct dequeue **q){
	if((*q)->front == NULL && (*q)->rear == NULL){
		printf("Noting to pop\n");
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

int pop_back(struct dequeue **q){
	if((*q)->front == NULL && (*q)->rear == NULL){
		printf("Noting to delete\n");
		return -1;
	}else if((*q)->front == (*q)->rear){
		int val = (*q)->front->val;
		(*q)->front = NULL;
		(*q)->rear = NULL;
		(*q)->count = 0;
		return val;
	}
	int val = (*q)->rear->val;
	struct Node *temp = (*q)->front;
	while(temp->next!=(*q)->rear){
		temp = temp->next;
	}
	(*q)->rear = temp;
	(*q)->rear->next = NULL;
	(*q)->count--;
	return val;
}

int size(struct dequeue *q){
	int size =q->count;
	return size;
}

int front(struct dequeue *q){
	if(q->front == NULL)return -1;
	int val = q->front->val;
	return val;
}

int back(struct dequeue *q ){
	if(q->rear == NULL)return -1;
	int val = q->rear->val;
	return val;
}

void display(struct dequeue *q){
	struct Node *temp = q->front;
	while(temp!=NULL){
		printf("%d\t",temp->val);
		temp = temp->next;
	}
	printf("\n");
}

void createdequeue(struct dequeue **q){
	(*q)->front = NULL;
	(*q)->rear = NULL;
}

int main(){
	struct dequeue *q;
	createdequeue(&q);

	while(1){
		printf("1. Enter If yout want to push data in the front of the dequeue\n");
		printf("2. Enter If you want to push the data in back of the dequeue\n");
		printf("3 . Pop_front\n");
		printf("4. pop_back\n");
		printf("5 . see front of the dequeue\n");
		printf("6 . see the back of the dequeue\n");
		printf("7. Display\n");
		printf("8. Exit\n");

		int val;
		scanf("%d",&val);
		if(val == 1){
			int c;
			printf("Enter the value you want to enter the front of the dequeue\n");
			scanf("%d",&c);
			push_front(&q,c);
		}else if(val == 2){
			int c;
			printf("Enter the value you want to enter in the back of the dequeue\n");
			scanf("%d",&c);
			push_back(&q,c);
		}else if(val == 3){
			int val = pop_front(&q);
			printf("Poped element from the front of the dequeue is %d\t",val);
			printf("\n");
		}else if(val == 4){
			int val = pop_back(&q);
			printf("Poped element from the back is %d\t",val);
			printf("\n");	
		}else if(val ==5){
			printf("Front of the dequeue is below\n");
			printf("%d\t",front(q));
		}else if(val == 6){
			printf("Back of the dequeue is below\n");
			printf("%d\t",back(q));
		}else if(val == 7){
			printf("Display the whole dequeue is\n");
			display(q);
		}else if(val == 8){
			printf("dequeue has stopped");
			break;
		}
	}
	return 0;
}
	
