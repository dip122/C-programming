#include<stdio.h>


void display(int arr[],int n);
void swap(int *a,int *b);
void sort(int arr[],int n){


	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(arr[i] > arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	display(arr,n);
}


void selection_sort(int arr[],int n){
	int i,j;
	for(i=0;i<n;i++){
		int mini = arr[i];
		int ind = -1;
		for(j=i+1;j<n;j++){
			if(arr[j] < mini){
				mini = arr[j];
				ind  = j;
			}
		}
		if(ind!=-1)swap(&arr[i],&arr[ind]);
	}

	display(arr,n);
}

void display(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}

}

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int n;
	printf("Enter the Number of elements\n");
	scanf("%d",&n);

	int arr[n];

	int i;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	selection_sort(arr,n);
}


