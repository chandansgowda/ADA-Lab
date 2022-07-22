//This is the boilerplate code to analyse any algorithms whose best, average and worst cases depend upon input

#include <stdio.h>
#include <stdlib.h> 
#include <time.h> //to generate random number based on time

#define START 10 //array size
#define END 1000
#define INCREMENT 10 //increment array size after every iteration

int count; //declaring global variable

void algorithmToBeAnalyzed(/*parameters*/){
	
	//Write Your algorithm here
	
	count++; //use this statement inside basic operation
}

void main(){

	int *arr,n,i; //declaring required variables
	
	FILE *fp1, *fp2, *fp3; //declaring file pointers
	
	system("rm best.txt avg.txt worst.txt"); //using shell command to remove old files with same name
	
	srand(time(0)); //to generate random numbers based on time
	
	for(n=START;n<=END;n+=INCRE){ //n is the array size and it increases in every iteration
	
		arr = (int*)malloc(n*sizeof(int)); //dynamically allocating memory
		
		
		//Best Case
		count=0; //resetting count to prevent usage of previous value
		for(i=0;i<n;i++){
			arr[i] = rand()%100; //replace this with required input for best case
		}	
		algorithmToBeAnalyzed(/*parameters*/); //calling required function
		fp1 = fopen("best.txt","a"); //assigning best.txt pointer to fp1 in append mode 
		fprintf(fp1,"%d\t%d\n", n,count); //appending [n count] to the best.txt file
				
		
		//Average Case
		count=0;  //resetting count to prevent usage of previous value
		for(i=0;i<n;i++){
			arr[i] = rand()%100; //replace this with required input for average case
		}
		algorithmToBeAnalyzed(/*parameters*/); //calling required function
		fp2 = fopen("avg.txt","a"); //assigning avg.txt pointer to fp2 in append mode 
		fprintf(fp2,"%d\t%d\n", n,count); //appending [n count] to the avg.txt file
		
		
		//Worst Case
		count=0;  //resetting count to prevent usage of previous value
		for(i=0;i<n;i++){
			arr[i] = rand()%100; //replace this with required input for worst case
		}
		algorithmToBeAnalyzed(/*parameters*/); //calling required function
		fp3 = fopen("worst.txt","a"); //assigning worst.txt pointer to fp3 in append mode 
		fprintf(fp3,"%d\t%d\n", n,count); //appending [n count] to the worst.txt file
	}
	
	fclose(fp1); fclose(fp2); fclose(fp3); //Closing files to prevent memory leaks
}
