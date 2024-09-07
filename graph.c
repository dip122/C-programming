#include<stdio.h>
#include<stdlib.h>


struct Node {
	int val;
	struct Node *next;
};

struct AdjList{
	struct Node *Listhead;
};

struct Graph {
	int v;
	struct AdjList *adj;
};

struct Node *newnode(int val){
	struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->val = val;
	newnode->next = NULL;
	return newnode;
}

struct Graph *creategraph(int v){
	
	struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->v = v;//v is the number of vertices

	graph->adj = (struct AdjList*)malloc(v*sizeof(struct AdjList));//graph->array is the adjList of size v --same as vector<int> adj[v]---each one adjList is a linkedlist

	int i;
	for(i=0;i<v;i++){
		graph->adj[i].Listhead = NULL;//graph->adj[i] is not a pointer , it is an AdjList type struct...not a pointer ... so I have used '.' to access Listhead 
	}

	return graph;
}

void addEdge(struct Graph *g,int u,int v){

	struct Node *newNode = newnode(v);
	newNode->next = g->adj[u].Listhead;
	g->adj[u].Listhead = newNode;

	struct Node *newnode2 = newnode(u);
	newnode2->next = g->adj[v].Listhead;
	g->adj[v].Listhead = newnode2;
	
}

void dfs(int node,struct Graph *g,int vis[],int n){
	int i;
	vis[node] = 1;

	struct Node *adjList = g->adj[node].Listhead;
	while(adjList!=NULL){
		if(vis[adjList->val] == 0){
			dfs(adjList->val,g,vis,n);
		}
		adjList = adjList->next;
	}
}


int main(){

	int v;
	printf("Enter the number of vertices\n");
	scanf("%d",&v);

	printf("Enter the number of Edges\n");
	int n;
	scanf("%d",&n);
	struct Graph *g = creategraph(v);
	int i, ans = 0;
	printf("Enter the edges\n");
	for(i=0;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		addEdge(g,x,y);
	}

	int vis[v];
	for(i=0;i<v;i++){
		vis[i] = 0;
	}

	for(i=0;i<v;i++){
		if(vis[i] == 0){
			dfs(i,g,vis,v);
			//printf("%d\t",i);
			printf("\n");
			ans++;
		}
	}

	printf("Number of connected component is %d\t",ans);
	return 0;

}
