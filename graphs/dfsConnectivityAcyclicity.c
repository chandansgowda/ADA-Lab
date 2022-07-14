#include <stdio.h>
#include <stdlib.h>

int graph[10][10], visited[10], acyclic=1, n;

void createGraph(){  //to get input from user and store it in graph matrix
	int i,j;
	printf("Enter no. of vertices: ");
	scanf("%d",&n);
	printf("Enter Adjacency Matrix: \n");
	for(i=0;i<n;++i){
		for(j=0;j<n;j++){
			scanf("%d",&graph[i][j]);
		}
	}
}

void dfs(int x){

	visited[x] = 1;  //marking this vertex as visited
	
	for(int i=0;i<n;i++){
	
		if (graph[x][i] && visited[i]){
			acyclic=0;
			printf("%d<-->%d\n",i,i); //cycle
		}
		
		if (graph[x][i] && !visited[i]) {
			printf("%d--> %d\n",x,i);  //connected component
			dfs(i);
		}
	}
	
}


void main(){
	
	int i, count;
	
	createGraph();
	
	for(i=0;i<n;++i)
		visited[i] = 0;
		
	dfs(0); //calling dfs on vertex 0
	
	for(i=0;i<n;++i)
		if (visited[i])
			count++;    //count all ones i.e vertices visited when dfs was called
			
	(count==n) ? printf("Connected Graph\n") : printf("Graph not connected!\n");
	(acyclic) ? printf("Acyclic Graph\n") : printf("Graph not acyclic!\n");
	
}



/* USE IF REQUIRED

void displayGraph(){
	int i,j;
	printf("Adjacency Matrix: \n");
	for(i=0;i<n;++i){
		for(j=0;j<n;j++){
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
}

*/
