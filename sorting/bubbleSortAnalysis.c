#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INITIAL 10
#define FINAL 1000
#define INCRE 10

int count;

void bubbleSort(int *arr, int n){
	int i,j, temp, flag=0;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if (arr[j]<arr[j+1]){
			count++;
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag = 1;
			}
		}
		if (flag==0) return;
	}
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
		bubbleSort(arr,n);
		fp1 = fopen("best.txt","a");
		fprintf(fp1,"%d\t%d\n",n,count);
		count=0;
		
		//Worst Case
		for(i=0;i<n;i++){
			arr[i]= (i==0) ? rand()%100 : arr[i-1]+rand()%10+1;
		}
		bubbleSort(arr,n);
		fp2 = fopen("worst.txt","a");
		fprintf(fp2,"%d\t%d\n",n,count);
		count=0;
		
		//Average Case
		for(i=n/2;i<n;i++){
			arr[i]=rand()%10;
		}
		bubbleSort(arr,n);
		fp3 = fopen("avg.txt","a");
		fprintf(fp3,"%d\t%d\n",n,count);
		count=0;
	}
	
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	
	//system("ls; gnuplot -p -c plot.txt");
}
