#include <stdio.h>

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

void main() {
    int mat[10][10];
    int i,j,k;
    
    createGraph();  //get input to form matrix for the graph
    
    printf("Cloning graph...\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            mat[i][j] = graph[i][j];  //copying input matrix to temporary matrix mat
        }
    }
    
    //Floyd-Warshall Algorithm
    printf("Applying Floys Warshall Algo...\n");
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<0;j++){
                if (mat[i][k] + mat[k][j] < mat[i][j])  //checking if distance from i->j is lesser via k
                    mat[i][j] = mat[i][k] + mat[k][j];  //updating the value
            }
        }
    }
    
    printf("Shortest path matrix\n");
    for(i=0;i<n;i++){
		for(j=0; j<n;j++){
			printf("%d ",mat[i][j]); //printing the matrix mat after updating all elements with correcponding sortest distances
		}
		printf("\n");	
	}
    
}
