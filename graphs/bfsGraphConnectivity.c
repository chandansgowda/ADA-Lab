#include <stdio.h>
#include <stdlib.h>

int graph[10][10], visited[10], q[10], f=0, r=-1, n;

void createGraph(){ //to get input from user and store it in graph matrix
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


void bfs(int v) {
	int i;
	for (i=0;i<n;i++)
		if(graph[v][i] && !visited[i]){
			printf("%d--> %d\n",v,i);
	   		q[++r]=i; //putting unvisited vertex to queue
		}
	  		
	if(f<=r) {
		visited[q[f]]=1; //marking this vertex as visited
		bfs(q[f++]); //dequeuing and calling bfs on the vertex
	}
}


void main(){
	
	int i, count;
	
	createGraph();
	
	for(i=0;i<n;++i)
		visited[i] = 0; //initialize visited array to zero
		
	bfs(0); //calling bfs on vertex 0
	
	for(i=0;i<n;++i)
		if (visited[i])
			count++;    //count all ones i.e vertices visited when bfs was called
			
	(count==n) ? printf("Connected Graph\n") : printf("Graph not connected!\n");
	
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
