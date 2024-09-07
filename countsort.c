#include<stdio.h>
#include<stdlib.h>


int max(int a,int b){
	if(a>b)return a;
	return b;
}


int *countsort(int arr[],int n){
	int maxi = -1e9;
	int i=0;
	for(i=0;i<n;i++){
		maxi = max(maxi,arr[i]);
	}

	int count[maxi+1];
	for(i=0;i<=maxi;i++)count[i] = 0;
	for(i=0;i<n;i++){
		count[arr[i]]++;
	}
	int *ans = (int*)malloc(n*sizeof(int));

	int j;
	j = 0;
	for(i=0;i<=maxi;i++){
		if(count[i]>0){
			while(count[i]>0){
				ans[j] = i;
				count[i]--;
				j++;
			}
		}
	}

	return ans;
}

int main(){
	int n;
	printf("Enter the Number of elements of the array\n");
	scanf("%d",&n);

	int arr[n],i;
	printf("Enter the elements of the array\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	printf("Element of the array is\n");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}

	int *ans = countsort(arr,n);
	printf("sorted elements are \n");
	for(i=0;i<n;i++){
		printf("%d\t",ans[i]);
	}
	return 0;
}

