#include <stdio.h>
#include <limits.h>
#include "my_mat.h"
#define INF INT_MAX

//if the letter is 'A' run "matrixVaribale" function to absorb the values of the matrix
void matrixVaribale(int matrix[][SIZE], int rows, int cols){ // A
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

//if the letter is 'B' get two positions from the user and run "isThereRoute" function to check if there is a route between them
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

/*if the letter is 'C' get two positions from the user and run "printPath" 
function that calculate a "shortest path" matrix by Floyd-Warshall algorithm and return the weight of the path
**/
int printPath(int matrixDist[SIZE][SIZE], int x, int y){
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
        return -1;
    }
    // Print the shortest path from x to y
     return dist[x][y];
   // printf("Shortest path from %d to %d: %d\n", x, y, dist[x][y]);
}

