#include <stdio.h>
#define SIZE 5
#define CAPACITY 20
#define MAX_LEN 21


int knapSack(int weights[SIZE], int values[SIZE], int selected_bool[SIZE]);
int max(int x, int y);
int main()
{
    printf("start");
    char product[SIZE][MAX_LEN];
    int values[SIZE];
    int weights[SIZE];
    int result[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%s", product[i]);
        scanf("%d", &values[i]);
        scanf("%d", &weights[i]);
    }
    int maxVul = knapSack(weights, values, result);
   // printf("%d", maxVul);
    return 0;
}

int knapSack(int weights[SIZE], int values[SIZE], int selected_bool[SIZE]) {
    int matrix[SIZE+1][CAPACITY+1];//0-15

    for (int i = 0; i < CAPACITY+1; i++) {
        matrix[0][i] = 0;
    }
    for (int i = 0; i < SIZE+1; i++) {
        matrix[i][0] = 0;
    }

    for (int i = 1; i < SIZE+1; i++) {  // Starting from 1
        for (int B = 1; B < CAPACITY+1; B++) {  // Starting from 1
            if (weights[i-1] > B) {
                matrix[i][B] = matrix[i - 1][B];
            } else {
                matrix[i][B] = max(matrix[i - 1][B], values[i-1] + matrix[i - 1][B - weights[i-1]]);
            }
        }

    }
// Print the matrix
    printf("Matrix:\n");
    for (int i = 0; i < SIZE+1; i++) {
        for (int j = 0; j < CAPACITY+1; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    // Return the maximum value in the last cell of the matrix
    return matrix[SIZE][CAPACITY];
}
int max(int x, int y){
    if(x > y){
        return x;
    }else{
        return y;
    }
}