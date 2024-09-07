#include<stdio.h>
#include<stdlib.h>

struct pair {
	int x,y;
};
struct Node{
	struct pair val;
	struct Node *next;
};

struct queue{
	struct Node *front;
	struct Node *rear;
	int count;
};

struct Node *newnode(struct pair val){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}

void push(struct queue *q , struct pair val){
	if(q->front == NULL && q->rear ==NULL){
		struct Node *newNode  = newnode(val);
		q->front = newNode;
		q->rear = newNode;
		q->count = 1;
		return;
	}
	struct Node *newNode = newnode(val);
	q->rear->next = newNode;
	q->rear = q->rear->next;
	q->count++;
	return;
}

void pop(struct queue *q){
	if(q->front == NULL && q->rear == NULL){
		printf("queue is already empty\n");
		return;
	}else if(q->front == q->rear ){
		struct Node *temp = q->front;
		q->front = NULL;
		q->rear = NULL;
		q->count = 0;
		free(temp);
		return;
	}

	struct Node *temp = q->front;
	q->front = q->front->next;
	temp->next = NULL;
	free(temp);
	q->count--;
	return;
}

int size(struct queue *q){
	return q->count;
}

int isEmpty(struct queue *q){
	if(q->count == 0)return 1;
	return 0;
}

struct pair front(struct queue *q){
	if(q->front != NULL)return q->front->val;
	struct pair p;
	p.x = 0;
	p.y = 0;
	return p;
}

struct queue *createqueue(){
	struct queue *q = (struct queue*)malloc(sizeof(struct queue));
	q->front = NULL;
	q->rear = NULL;
	return q;
}

void bfs(int row,int col,int **grid,int **vis,int n,int m,int delrow[],int delcol[]){

	struct queue *q = createqueue();
	int i;
	struct pair p;
	p.x = row;
	p.y = col;
	push(q,p);
	vis[row][col] = 1;
	while(isEmpty(q) == 0){
		struct pair p = front(q);
		pop(q);
		int row =p.x;
		int col = p.y;
		for(i=0;i<4;i++){
			int nrow = row + delrow[i];
			int ncol = col + delcol[i];
			if(nrow>=0 && ncol>=0 && nrow<n && ncol<m 
				&& !vis[nrow][ncol] && grid[nrow][ncol] == 1){
				vis[nrow][ncol] = 1;
				struct pair pa ;
				pa.x = nrow;
				pa.y = ncol;
				push(q,pa);
			}
		}
	}
}



int main(){

	int n,m,i,j;
	printf("Enter the row and column\n");
	scanf("%d%d",&n,&m);

	int **grid = (int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++){
		grid[i] = (int*)malloc(m*sizeof(int));
	}

	int ans = 0;
	printf("Enter the gridproperly\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&grid[i][j]);
		}
	}

	int **vis = (int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++){
		vis[i] = (int*)malloc(m*sizeof(int));
	}

	int delrow[4] = {0,-1,0,+1};
	int delcol[4] = {+1,0,-1,0};


	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if( i == 0 || i == n-1 || j == 0 || j == m-1){
				if(vis[i][j] == 0 && grid[i][j] == 1){
					bfs(i,j,grid,vis,n,m,delrow,delcol);
				}
			}
		}
	}


	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(!vis[i][j] && grid[i][j] == 1){
				bfs(i,j,grid,vis,n,m,delrow,delcol);
				ans++;
			}
		}
	}

	printf("Number of closed island is %d \n",ans);
	return 0;
}




