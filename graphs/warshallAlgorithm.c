#include <stdio.h>
#include <stdlib.h>

int graph[10][10], n;

void createGraph(){
	printf("Enter no. of vertices: ");
	scanf("%d",&n);
	printf("Enter adjacency matrix:\n");
	for(int i=0;i<n;i++){
		for(int j=0; j<n;j++)
			scanf("%d",&graph[i][j]);
	}
}


void main(){
	int i,j,k, P[10][10];
	createGraph(); //get input to form matrix for the graph
	
	printf("Cloning graph...\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			P[i][j] = graph[i][j]; //copying input matrix to temporary matrix P
		}
	}
	
	printf("Applying Warshall's Algorithm\n");
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				P[i][j] = (P[i][j] || (P[i][k] && P[k][j])); //updating positions with transitive closures
			}
		}
	}
	
	printf("Transitive Closure matrix:\n");
	for(i=0;i<n;i++){
		for(j=0; j<n;j++){
			printf("%d ",P[i][j]);
		}
		printf("\n");	
	}
}
