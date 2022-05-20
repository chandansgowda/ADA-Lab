#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count, n=10;

void linearSearch(int k, int *a){
	count = 0;
	int i;
	for(i=0;i<n;i++){
		count++;
		if (a[i]==k){
			printf("Key Found at Location %d\n", i+1);
			return;
		}	
	}
}


void main(){
	FILE *fp1,*fp2,*fp3;
	int *a;
	system("rm l_best.txt l_avg.txt l_worst.txt");
	fp1 = fopen("l_best.txt","a");
	fp2 = fopen("l_worst.txt","a");
	fp3 = fopen("l_avg.txt","a");
	srand(time(0));
	int key, i;
	for (n=10;n<100;n = n+10){
		a = (int*)malloc(n*sizeof(int));
		i = 0;
		while(i!=n){
			a[i] = rand()%100;
			printf("%d  ", a[i]);
			i++;		
		}	

		key = a[0];
		linearSearch(key,a);
		fprintf(fp1,"%d\t%d\n", n, count);

		key = 7777;
		linearSearch(key,a);
		fprintf(fp2,"%d\t%d\n", n, count);

		key = a[n/2];
		linearSearch(key,a);
		fprintf(fp3,"%d\t%d\n", n, count);
	}

	fclose(fp1); fclose(fp2); fclose(fp3);
	
}
