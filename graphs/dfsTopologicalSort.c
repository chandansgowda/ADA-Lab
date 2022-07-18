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
			
	stack[++stop] = x; //pushing x to stack and this willl maintain the topological order
}



void main(){
	int i;
	createGraph(); //getting input matrix from user and storing it in graph[][]
	
	for(i=0;i<n;i++) 
		visited[i]=0; //initializing visited array to 0 (false)
	
	for(i=0;i<n;i++){
		if (visited[i]==0)
			dfs(i);  //calling dfs on all unvisited vertices
	}
	
	printf("Topologically sorted order\n");
	for(i=n-1;i>=0;i--) 
		printf("%d --> ",stack[i]); //printing stack (taken as array for simplicity) in reverse order
	
}
