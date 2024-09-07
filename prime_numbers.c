#include<stdio.h>

int isprime[200005];
void sieve(){
	isprime[0] = isprime[1] = 0;
	int i,j;
	for(i = 2;i<=200004;i++){
		if(isprime[i] == 1){
			for(j=2*i;j<=200004;j+=i){
				isprime[j] = 0;
			}
		}
	}	
}


int main(){
	for(int i=0;i<=200004;i++){
		isprime[i] = 1;
	}

	sieve();

	printf("All prime numbers below 1000 is \n");
	for(int i=1;i<=1000;i++){
		if(isprime[i] == 1){
			printf("%d\t",i);
		}
	}

	return 0;
}
