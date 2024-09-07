#include<stdio.h>
#include<stdlib.h>


void merge(int arr[],int low,int mid,int high,int n){

	int len1 = (mid-low+1);
	int len2 = (high-mid);
	int left[len1] , right[len2];
	int i,j,k;
	for(i=0;i<len1;i++){
		left[i] = arr[low + i];
	}
	for(i=0;i<len2;i++){
		right[i] = arr[mid+1+i];
	}

	i=0,j=0,k=low;
	while(i<len1 && j<len2){
		if(left[i] < right[j]){
			arr[k] = left[i];
			i++;
			k++;
		}else if(left[i] >= right[j]){
			arr[k] = right[j];
			j++;
			k++;
		}
	}

	while(i<len1){
		arr[k] = left[i];
		i++;
		k++;
	}
	while(j<len2){
		arr[k] = right[j];
		j++;
		k++;
	}

}



void mergesort(int arr[],int low,int high,int n){

	if(low >= high) return;

	int mid = low + (high-low)/2;
	mergesort(arr,low,mid,n);
	mergesort(arr,mid+1,high,n);
	merge(arr,low,mid,high,n);
}


int main(){
	int n;
	printf("Enter the Number of Elements of the array\n");
	scanf("%d",&n);
	int arr[n];
	int i;
	printf("Enter the elements of the array\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	mergesort(arr,0,n-1,n);
	printf("sorted arrays is \n");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	return 0;
}
		
