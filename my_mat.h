#define SIZE 10
/**
 * Function that gets the matrix values from the user:
*/
void matrixVaribale (int matrix[][SIZE], int rows, int cols);

int isThereRoute(int matrixDist[SIZE][SIZE], int x, int y);

/**
 * Fuction that uses the Floyd-Warshall algorithm to find the shortest path between two position.
*/
void printPath(int matrix[SIZE][SIZE],int x, int y);


