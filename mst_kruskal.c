#include<stdio.h>
#include<stdio.h>


struct Pair{
	int x,y,z;
};

typedef struct Pair pair;

int compare(pair a, pair b){
	if(a.z >= b.z)return 1;
	return 0;
}

pair make_pair(int a,int b,int c){
	pair p;
	p.x = a;
	p.y = b;
	p.z = c;
	return p;
}

void swap(pair *a, pair *b){
	pair temp = *a;
	*a = *b;
	*b = temp;
}

void sort(pair arr[],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(compare(arr[i],arr[j])){
				swap(&arr[i],&arr[j]);
			}
		}
	}
}


int findUpar(int node,int parent[],int n){

	if(parent[node] == node)return node;
	return parent[node] = findUpar(parent[node],parent,n);
}

void make_union(int u,int v,int size[],int parent[],int n){
	int uu = findUpar(u,parent,n);
	int uv = findUpar(v,parent,n);
	if(size[uu] < size[uv]){
		parent[uu] = uv;
		size[uv]+=size[uu];
	}else {
		parent[uv] = uu;
		size[uu]+=size[uv];
	}
}

int getsize(int node,int size[],int parent[],int n){
	int uu = findUpar(node,parent,n);
	return size[uu];
}


int main(){


	int V,i,j;
	printf("Enter the Number of Edges\n");
	scanf("%d",&V);
	int n;
	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	printf("Enter node1 , node 2 and weight\n");
	pair arr[V];
	for(i=0;i<V;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		arr[i] = make_pair(x,y,z);
	}

	sort(arr,V);

	int sum_mst = 0;
	int parent[n+1],size[n+1];
	for(i=0;i<=n;i++){
		parent[i] = i;
	}
	for(i=0;i<=n;i++){
		size[i] = 1;
	}

	for(i=0;i<V;i++){
		pair p = arr[i];
		int node1 = p.x;
		int node2 = p.y;
		if(findUpar(node1,parent,n+1)!=findUpar(node2,parent,n+1)){
			make_union(node1,node2,size,parent,n+1);
			sum_mst+=p.z;
		}
	}

	printf("MST SUM is %d\t",sum_mst);
	return 0;


}
