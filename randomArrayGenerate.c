#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void main(){

	int *arr,n,i;
	
	srand(time(0)); //to generate random numbers based on time
	
	for(n=10;n<100;n+=10){ //n is the array size and it increases in every iteration
	
		printf("\n\n[n=%d]\n",n);
		arr = (int*)malloc(n*sizeof(int)); //dynamically allocating memory
		
		for(i=0;i<n;i++){
			arr[i] = rand()%100; //random number generation
			printf("%d  ",arr[i]);
		}	
		
	}
}
