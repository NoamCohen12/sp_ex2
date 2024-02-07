#include <stdio.h>
#include <limits.h>
#include "my_mat.h"
#define INF INT_MAX

void matrixVaribale(int matrix[][SIZE], int rows, int cols)
{ // A
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
                printf("done\n");

}
int isThereRoute(int matrix[][SIZE],int x, int y, int isVisited[10])
{

    if (matrix[x][y] > 0)
    {
        return 1;
    }
    else
    {
        // DFS algorithm:
        //  we check the matrix in [x][y] if we dont reach to y it will be "1"- so there is no route to y
        isVisited[x] = 1;
        // we check if there is route from x to neighbore if there
        //  is we check from the neighbore to his neighbore etc
        for (int i = 0; i < 10; i++)
        {
            if (matrix[x][i] > 0 && isVisited[i] == 0 && isThereRoute(matrix, i, y, isVisited) == 1)
            {
                return 1;
            }
        }
    }
    return 0;
}
void printPath(int matrixDist[SIZE][SIZE], int x, int y) {
    int dist[SIZE][SIZE];
    int i, j, k;

    // Initialize distances array
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
        if(i==j){dist[0][j] = 0;}
        
            dist[i][j] = matrixDist[i][j];

    // Floyd-Warshall algorithm
    for (k = 0; k < SIZE; k++) {
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest path from x to y
    printf("Shortest path from %d to %d: %d\n", x, y, dist[x][y]);
}

