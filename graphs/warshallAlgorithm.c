#include <stdio.h>
#include <stdlib.h>

int graph[10][10], visited[10]={0}, indegree[10]={0}, n;

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
	createGraph();
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			P[i][j] = graph[i][j];
		}
	}
	
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				P[j][k] = (P[j][k] || (P[j][i] && P[i][k]));
			}
		}
	}
	
	printf("Transitive Closure matrix:\n");
	for(int i=0;i<n;i++){
		for(int j=0; j<n;j++){
			printf("%d ",P[i][j]);
		}
		printf("\n");	
	}
}
