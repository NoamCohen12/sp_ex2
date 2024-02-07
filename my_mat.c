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
}
int isThereRoute(int matrix[][SIZE], int x, int y, int isVisited[10])
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




//-------------------------------------------------------------------------------------------------

// void printPath(int matrixDist[SIZE][SIZE], int x, int y)
// {
//     int dist[SIZE][SIZE];
//     int i, j, k;

//     // Initialize distances array
//     for (i = 0; i < SIZE; i++)
//     {
//         for (j = 0; j < SIZE; j++)
//         {
//             if (i == j)
//             {
//                 dist[i][j] = 0;
//             }
//             else if (matrixDist[i][j] == 0)
//             {
//                 dist[i][j] = INF; // Setting a large value instead of INF
//             }
//             else
//             {
//                 dist[i][j] = matrixDist[i][j];
//             }
//         }
//     }

//     // Floyd-Warshall algorithm
//     for (k = 0; k < SIZE; k++)
//     {
//         for (i = 0; i < SIZE; i++)
//         {
//             for (j = 0; j < SIZE; j++)
//             {
            
//                 if (dist[i][k] + dist[k][j] < dist[i][j])
//                 {
//                      if (dist[i][j] == 0)
//                 {
//                     continue;
//                 }
//                     dist[i][j] = dist[i][k] + dist[k][j];
//                 }
//             }
//         }
//     }

//     // Print the shortest path from x to y
//     printf("Shortest path from %d to %d: %d\n", x, y, dist[x][y]);
// }


void printPath(int matrixDist[SIZE][SIZE], int x, int y)
{
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
                dist[i][j] = INF; // Setting a large value instead of INF
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
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest path from x to y
    printf("Shortest path from %d to %d: %d\n", x, y, dist[x][y]);
}


// void printPath(int matrixDist[SIZE][SIZE], int x, int y)
// {
//     int dist[SIZE][SIZE];
//     int i, j, k;

//     // Initialize distances array
//     for (i = 0; i < SIZE; i++)
//     {
//         for (j = 0; j < SIZE; j++)
//         {

//              if (matrixDist[i][j] == 0)
//             {

//                 dist[i][j] = -1; // No path between vertices
//             }
//             else
//             {
//                 dist[i][j] = matrixDist[i][j];
//             }
//         }
//     }

//     for (size_t i = 0; i < SIZE; i++)
//     {
//         for (size_t j = 0; j < SIZE; j++)
//         {
//             printf("%d ", matrixDist[i][j]);
//         }
//         printf("\n");
//     }

//     // Floyd-Warshall algorithm
//     for (k = 0; k < SIZE; k++)
//     {
//         for (i = 0; i < SIZE; i++)
//         {
//             for (j = 0; j < SIZE; j++)
//             {
//                 if (dist[i][k] != -1 && dist[k][j] != -1 &&
//                     (dist[i][j] == -1 || dist[i][k] + dist[k][j] < dist[i][j]))
//                 {
//                     dist[i][j] = dist[i][k] + dist[k][j];
//                 }
//             }
//         }
//     }

//     // Print the shortest path from x to y
//     printf("Shortest path from %d to %d: %d\n", x, y, dist[x][y]);
// }




