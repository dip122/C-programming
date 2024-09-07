#include<stdio.h>
#include<stdlib.h>

struct Node {
	int val;
	struct Node *next;
};

struct Node *newnode(int val){
	struct Node *p = (struct Node*)malloc(sizeof(struct Node));
	p->val = val;
	p->next = NULL;
	return p;
}

void push(struct Node **head,int val){
	if((*head) == NULL){
		(*head) = newnode(val);
		return;
	}else{
		struct Node *temp = (*head);
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = newnode(val);
	}
}

struct Node *addTwoNumbers(struct Node *head1,struct Node *head2){
	
	struct Node *temp1 = head1;
	struct Node *temp2 = head2;
	int carry = 0;
	struct Node *dummy = newnode(-1);
	struct Node *p = dummy;
	while(temp1!=NULL && temp2!=NULL){
		int sum = temp1->val + temp2->val + carry;
		int digit = sum%10;
		carry = sum/10;
		dummy->next = newnode(digit);
		dummy = dummy->next;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	while(temp1!=NULL){
		int sum = temp1->val + carry;
		int digit = sum%10;
		carry = sum/10;
		dummy->next = newnode(digit);
		dummy = dummy->next;
		temp1 = temp1->next;
	}

	while(temp2!=NULL){
		int sum = temp2->val + carry;
		int digit = sum%10;
		carry = sum/10;
		dummy->next = newnode(digit);
		dummy = dummy->next;
		temp2 = temp2->next;
	}

	if(carry>0) dummy->next = newnode(carry);

	return p->next;
}

void display(struct Node *head){

	struct Node *temp = head;
	while(temp!=NULL){
		printf("%d",temp->val);
		temp = temp->next;
	}
	printf("\n");

}


struct Node *reverse(struct Node *head){
	struct Node *nextnode = head;
	struct Node *prevnode = NULL;
	struct Node *currnode = head;
	while(currnode!=NULL){
		nextnode = currnode->next;
		currnode->next = prevnode;
		prevnode = currnode;
		currnode = nextnode;
	}
	return prevnode;
}


int main(){

	int n,i;
	printf("Enter the length of the 1st number\n");
	scanf("%d",&n);

	getchar();

	struct Node *head1 = NULL;
	struct Node *head2 = NULL;
	struct Node *p , *q;
	printf("Enter the 1st number\n");

	for(i=0;i<n;i++){
		char c;
		scanf("%c",&c);
		if(head1 == NULL) { head1 = newnode(c - '0'); p = head1; }
		else{
			head1->next = newnode(c - '0');
			head1 = head1->next;
		}
	}

	printf("Enter the length of the 2nd number\n");
	int len;
	scanf("%d",&len);

	getchar();

	printf("Enter the second number\n");
	for(i=0;i<len;i++){
		char c;
		scanf("%c",&c);
		if(head2 == NULL) { head2 = newnode(c-'0');  q = head2; }
		else{
			head2->next = newnode(c - '0');
			head2 = head2->next;
		}
	}

	struct Node *t1 = reverse(p);
	struct Node *t2 = reverse(q);


	struct Node *Total = addTwoNumbers(t1,t2);

	struct Node *ans = reverse(Total);

	display(ans);

	return 0;
}
