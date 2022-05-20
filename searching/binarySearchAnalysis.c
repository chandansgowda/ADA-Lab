#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count, n=10;

void binarySearch(int k, int*a){
	count = 0;
	int f=0, l =n-1, m;
	while(f<=l){
		m = (f+l)/2;
		count++;
		if (a[m]==k){
			printf("Found at Position %d\n", m+1);
			return;
		}	
		else if (a[m]<k) f=m+1;
		else l = m-1;
	}
	if (f>l) printf("\nElement not found\n");
}

void main(){
	FILE *fp1,*fp2,*fp3;
	
	FILE * gnuplotPipe = popen ("gnuplot -p", "w");
	
	
	int *a;
	system("rm b_best.txt b_avg.txt b_worst.txt");
	fp1 = fopen("b_best.txt","a");
	fp2 = fopen("b_worst.txt","a");
	fp3 = fopen("b_avg.txt","a");
	srand(time(0));
	int key, i;
	for (n=10;n<100;n+=10){
		a = (int*)malloc(n*sizeof(int));
		i = 0;
		while(i!=n){
			a[i] = i==0 ? rand()%100: a[i-1]+rand()%10;
			printf("%d  ", a[i]);
			i++;		
		}	

		key = a[(n-1)/2];
		binarySearch(key,a);
		fprintf(fp1,"%d\t%d\n", n, count);

		key = a[0];
		binarySearch(key,a);
		fprintf(fp2,"%d\t%d\n", n, count);

		key = a[((n-1)/2)/2];
		binarySearch(key,a);
		fprintf(fp3,"%d\t%d\n", n, count);
	}

	
	fprintf(gnuplotPipe, "load 'plot_bi.txt'");
	
	fclose(fp1); fclose(fp2); fclose(fp3); pclose(gnuplotPipe);
	scanf("%d",&key);

	
	
}
