#include <stdio.h>
#include <stdlib.h>

int graph[10][10], visited[10], stack[10], stop=-1, n;

void createGraph(){
	printf("Enter no. of vertices: ");
	scanf("%d",&n);
	printf("Enter adjacency matrix:\n");
	for(int i=0;i<n;i++){
		for(int j=0; j<n;j++)
			scanf("%d",&graph[i][j]);
	}
}



void dfs(int x){
	visited[x] = 1;
	
	for(int i=0;i<n;i++)
		if(graph[x][i] && !visited[i])
			dfs(i);
			
	stack[++stop] = x;
}



void main(){
	int i;
	createGraph();
	
	for(i=0;i<n;i++) 
		visited[i]=0;
	
	for(i=0;i<n;i++){
		if (visited[i]==0)
			dfs(i);
	}
	
	printf("Topologically sorted order\n");
	for(i=n-1;i>=0;i--) 
		printf("%d --> ",stack[i]);
	
}
