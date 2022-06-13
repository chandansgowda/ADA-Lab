#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INITIAL 10
#define FINAL 1000
#define INCRE 10

int count;


void merge(int arr[], int p, int q, int r) {

  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    count++;
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
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
		mergeSort(arr,0,n-1);
		fp1 = fopen("best.txt","a");
		fprintf(fp1,"%d\t%d\n",n,count);
		count=0;
		
		//Worst Case
		for(i=0;i<n;i++){
			arr[i]= (i<n/2) ? rand()%10*2 : rand()%10+1;
		}
		mergeSort(arr,0,n-1);
		fp2 = fopen("worst.txt","a");
		fprintf(fp2,"%d\t%d\n",n,count);
		count=0;
		
		//Average Case
		for(i=n/2;i<n;i++){
			arr[i]=rand()%10;
		}
		mergeSort(arr,0,n-1);
		fp3 = fopen("avg.txt","a");
		fprintf(fp3,"%d\t%d\n",n,count);
		count=0;
	}
	
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	
	system("ls; gnuplot -p -c plot.txt");
}
