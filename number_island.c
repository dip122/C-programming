#include<stdio.h>
#include<stdlib.h>



struct Node {
	int row;
	int col;
	struct Node *next;
};

struct Node *newnode(int row,int col){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->row= row;
	newNode->col = col;
	newNode->next = NULL;
	return newNode;
}

struct queue {
	struct Node *front;
	struct Node *rear;
	int count;
};

struct pair{
	int x,y;
};

struct queue *createqueue(){
	struct queue *q = (struct queue*)malloc(sizeof(struct queue));
	q->front = NULL;
	q->rear = NULL;
	return q;
}

void push(struct queue *q,int row,int col){
	if(q->front == NULL && q->rear == NULL){
		struct Node *node = newnode(row,col);
		q->front = node;
		q->rear = node;
		q->count = 1;
		return;
	}
	q->rear->next = newnode(row,col);
	q->rear = q->rear->next;
	q->count++;
	return;
}

void pop(struct queue *q){
	if(q->front == NULL && q->rear == NULL){
		printf("queue is already empty\n");
		return;
	}else if(q->front == q->rear){
		struct Node *temp = q->front;
		q->front = NULL;
		q->rear = NULL;
		free(temp);
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

int isEmpty(struct queue *q){
	if(q->count == 0)return 1;
	return 0;
}

struct pair front(struct queue *q){
	struct pair p;
	p.x = q->front->row;
	p.y = q->front->col;
	return p;
}

void bfs(int row,int col,int **grid,int n,int m,int **vis){

	int i;
	int delrow[4] = {0,-1,0,+1};
	int delcol[4] = {+1,0,-1,0};
	struct queue *q = createqueue();
	vis[row][col] = 1;
	push(q,row,col);
	while(isEmpty(q) == 0){
		struct pair p = front(q);
		int row = p.x;
		int col = p.y;
		pop(q);
		for(i=0;i<4;i++){
			int nrow = row + delrow[i];
			int ncol = col + delcol[i];
			if(nrow>=0 && ncol>=0 && nrow<n && ncol<m 
					 && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0){

				vis[nrow][ncol] = 1;
				push(q,nrow,ncol);
			}
		}
	}
		
}

void display(int **grid,int n,int m){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d\t",grid[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	int **grid = (int**)malloc(n*sizeof(int* ));
	int i,j;
	for(i=0;i<n;i++){
		grid[i] = (int*)malloc(m*sizeof(int));
	}

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&grid[i][j]);
		}
	}

	display(grid,n,m);

	int **vis = (int**)malloc(n*sizeof(int *));
	for(i=0;i<n;i++){
		vis[i] = (int*)malloc(m*sizeof(int));
		for(j=0;j<m;j++){
			vis[i][j] = 0;
		}
	}

	int count = 0;

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(grid[i][j] == 1 && vis[i][j] == 0){
				bfs(i,j,grid,n,m,vis);
				count++;
			}
		}
	}

	printf("Number of island is %d\t",count);
	return 0;

}

