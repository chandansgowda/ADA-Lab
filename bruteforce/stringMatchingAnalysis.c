#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int match(int str[], int patt[], int stlen, int palen){
	int i, j, count =0;
	
	for (i = 0; i<stlen-palen; i++){
		j = 0;
		
		while (j<palen && patt[j] == str[i+j]){
			count ++;
			j++;
		}
			
		if (j == palen)
			return count;
	}
	return count;
}

void main(){
	FILE  *b, *w, *a;
	system("rm BEST_S.txt");
	system("rm AVERAGE_S.txt");
	system("rm WORST_S.txt");
	
	b = fopen("BEST_S.txt", "a");
	a = fopen("AVERAGE_S.txt", "a");
	w = fopen("WORST_S.txt", "a");
	
	int *str, pat[4], n;
	
	for(n = 100; n<=1000; n+=100){
		str = (int *)calloc(n, sizeof(int));
		str[n-1] = 1;
		pat[0] = pat[1] = pat[2] = 0;
		pat[3] = 1;
		fprintf(w, "%d  %d\n", n, match(str, pat, n, 4));  // Worst Case
		
		pat[3] = 0;
		fprintf(b, "%d  %d\n", n, match(str, pat, n , 4));  // Best Case
		
		str[n/2] = str[n/2 + 1] = 1;
		pat[2] = pat[3] = 1;
		fprintf(a, "%d  %d\n", n, match(str, pat,n , 4));  // Average Case
	}
	fclose(b);
	fclose(a);
	fclose(w);
}
