#include<stdio.h>
#include<stdlib.h>


void swap(int *a,int *b);
void display(int arr[],int n);
void heapify(int i,int arr[],int n){
	int largest = i;
	int left = 2*i;
	int right = 2*i+1;
	if(left<n && arr[largest] < arr[left]){
		largest = left;
	}
	if(right<n && arr[largest] < arr[right]){
		largest = right;
	}

	swap(&arr[largest],&arr[i]);
	if(largest!=i)heapify(largest,arr,n);
}

void swap(int *a , int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}



void heap_sort(int arr[],int n){

	int i;
	for(i=n/2;i>=0;i--){
		heapify(i,arr,n);
	}

	for(i=n-1;i>=0;i--){
		swap(&arr[0],&arr[i]);
		heapify(0,arr,i);
	}

	display(arr,n);
}


	


void display(int arr[],int n){

	int i;
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	return;
}

int main(){
	
	int n;
	printf("Enter the Number of elements\n");
	scanf("%d",&n);
	int arr[n];

	int i;
	printf("Enter the elements of the array\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	printf("After sorting output is \n");

	heap_sort(arr,n);


	return 0;
}
