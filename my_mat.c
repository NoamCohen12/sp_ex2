#include <stdio.h>
#include <limits.h>
#include "my_mat.h"
#define INF INT_MAX

void matrixVaribale(int matrix[][SIZE], int rows, int cols){ // A
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int isThereRoute(int matrixDist[SIZE][SIZE], int x, int y){
    int dist[SIZE][SIZE];
    int i, j, k;

    // Initialize distances array
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
            else if (matrixDist[i][j] == 0)
            {
                dist[i][j] = INF;
            }
            else
            {
                dist[i][j] = matrixDist[i][j];
            }
        }
    }

    // Floyd-Warshall algorithm
    for (k = 0; k < SIZE; k++)
    {
        for (i = 0; i < SIZE; i++)
        {
            for (j = 0; j < SIZE; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Check if there is a route from x to y
    if (dist[x][y] == INF||dist[x][y] == 0)
    {
        return 0;
    }
    else{
        return 1;
    }

}




void printPath(int matrixDist[SIZE][SIZE], int x, int y){
    int dist[SIZE][SIZE];
    int i, j, k;

    // Initialize distances array
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
            else if (matrixDist[i][j] == 0)
            {
                dist[i][j] = INF;
            }
            else
            {
                dist[i][j] = matrixDist[i][j];
            }
        }
    }

    // Floyd-Warshall algorithm
    for (k = 0; k < SIZE; k++)
    {
        for (i = 0; i < SIZE; i++)
        {
            for (j = 0; j < SIZE; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Check if there is a route from x to y
    if (dist[x][y] == INF||dist[x][y] == 0)
    {
        printf("-1\n");
        return;
    }

    // Print the shortest path from x to y
     printf( "%d\n", dist[x][y]);

   // printf("Shortest path from %d to %d: %d\n", x, y, dist[x][y]);
}
/////////////////////////////////////////////////////////////////////

