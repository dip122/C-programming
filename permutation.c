#include<stdio.h>
#include<stdlib.h>

//length of perm = length of array

void generatePermutations(int ind,int *arr, int *perm, int *visited, int n) {
    if (ind == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", perm[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;//visit ithe index of array

            perm[ind] = arr[i];//store the permutation...in the current index we will store the arr[i] element

            generatePermutations(ind+1,arr, perm, visited, n);// from 0 to ind cal is done , go to ind+1....0 to ind string is ready in perm array

            // Backtracking to previous state
            visited[i] = 0;
        }
    }
}

int main(){
	
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    int perm[n];
    int visited[n];

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Permutations of the first %d numbers:\n", n);
    generatePermutations(0,arr, perm, visited, n);

    return 0;
}	
