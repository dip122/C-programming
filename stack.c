#include<stdio.h>
#include<stdlib.h>

struct Node {
	int val;
	struct Node *next;
};

struct stack{
	struct Node *head;
	struct Node *top;
	int count;
};

struct Node *newnode(int val){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}

void push(struct stack **q,int val){
	if((*q)->top == NULL){
		struct Node *s = newnode(val);
		(*q)->top = s;
		(*q)->head = s;
		(*q)->count = 1;
		return;
	}
	struct Node *node = newnode(val);
	(*q)->top->next = node;
	(*q)->top = (*q)->top->next;
	(*q)->count++;
	return;
}

int pop(struct stack **q){
	if((*q)->top == NULL){
		return -1;
	}else if((*q)->top == (*q)->head){
		int val = (*q)->top->val;
		(*q)->top = NULL;
		(*q)->head = NULL;
		(*q)->count = 0;
		return val;
	}
	int val = (*q)->top->val;
	struct Node *temp = (*q)->head;
	while(temp->next!=(*q)->top){
		temp = temp->next;
	}
	(*q)->top = temp;
	(*q)->top->next = NULL;
	(*q)->count--;
	return val;
}

int size(struct stack *q){
	int size = q->count;
	return size;
}

int top(struct stack *q){
	int top_element = q->top->val;
       	return top_element;
}

void display_stack(struct stack *q){
	struct Node *temp = q->head;
	while(temp!=NULL){
		printf("%d\t",temp->val);
		temp = temp->next;
	}
	printf("\n");
}

void createstack(struct stack **q){
	(*q)->head = NULL;
	(*q)->top = NULL;
}

int main(){

	struct stack *q;
	createstack(&q);

	while(1){
		int val;
		printf("1. Enter If you want to push the data to the stack\n");
		printf("2 . Enter if you want to pop the  element from the top of the stack\n");
		printf("3 . Enter to Get the top element\n");
		printf("4 . Enter to know the size of the stack\n");
		printf("5 . Enter to Display the stack\n");
		printf(" 6 . Exit\n");

		scanf("%d",&val);
		if(val == 1){
			int c;
			printf("Enter the number you want to push in the stack\n");
			scanf("%d",&c);
			push(&q,c);
		}else if(val == 2){
			int val = pop(&q);
			printf("Your Popped element from the top of the stack is %d\t",val);
		}else if(val == 3){
			int top_element = top(q);
			printf("top element of the stack is %d\t",top_element);
		}else if(val == 4){
			printf("size of the stack is %d\t",size(q));
		}else if(val == 5){
			printf("Stack is displayed below\n");
			display_stack(q);
		}
		else{
			break;
		}
	}
	return 0;

}
