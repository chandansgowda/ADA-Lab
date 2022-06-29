#include <stdio.h>
#include <stdlib.h>

void main() {
    
    int* arr;
    int n,i,j,cur;
    
    printf("Array Size>> ");
    scanf("%d", &n);
    arr = (int*)malloc(n*sizeof(int));
    
    printf("Input Array>> \n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    //Insertion Sort
    for(i=1;i<n;i++){
        cur = arr[i];
        j = i-1;
        while(j>=0 && cur<arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=cur;
    }
    
    printf("Sorted Array Is>>  ");
    for(i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    
}
