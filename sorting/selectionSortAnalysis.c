#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define INITIAL 10
#define FINAL 1000
#define INCRE 10

int count;

void sort(int arr[], int size){
	int index, i, j;
	for (i = 0; i<size-2; i++){
		int index = i;
		for (j = i+1; j<size-1; j++){
			count++;
			if (arr[index] > arr[j])
				index = j;
		}
		
		if (index != i){
			int temp = arr[index];
			arr[index] = arr[i];
			arr[i] = temp;
		}
	}
	return;
}

void main(){
	int *arr, n, i;
	FILE *fp1, *fp2, *fp3;
	system("rm best.txt worst.txt avg.txt");
	srand(time(0));
	for(n=INITIAL;n<FINAL;n+=INCRE){
		arr=(int*)malloc(sizeof(int)*n);
		
		//Best Case
		for(i=0;i<n;i++){
			arr[i]=2*n-i;
		}
		sort(arr,n);
		fp1 = fopen("best.txt","a");
		fprintf(fp1,"%d\t%d\n",n,count);
		count=0;
		
		//Worst Case
		for(i=0;i<n;i++){
			arr[i]= (i==0) ? rand()%100 : arr[i-1]+rand()%10+1;
		}
		sort(arr,n);
		fp2 = fopen("worst.txt","a");
		fprintf(fp2,"%d\t%d\n",n,count);
		count=0;
		
		//Average Case
		for(i=n/2;i<n;i++){
			arr[i]=rand()%10;
		}
		sort(arr,n);
		fp3 = fopen("avg.txt","a");
		fprintf(fp3,"%d\t%d\n",n,count);
		count=0;
	}
	
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	
	//system("ls; gnuplot -p -c plot.txt");
}
