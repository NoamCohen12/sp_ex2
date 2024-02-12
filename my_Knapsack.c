#include <stdio.h>
#define SIZE 5
#define CAPACITY 20
#define MAX_LEN 21

int knapSack(int weights[SIZE], int values[SIZE], int selected_bool[SIZE]);
int max(int x, int y);
int main()
{
    // printf("start");
    // Declare arrays to store product names, values, weights, and result
    char product[SIZE][MAX_LEN];
    int values[SIZE];
    int weights[SIZE];
    int result[SIZE];

    // Input product names, values, and weights
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%s", product[i]);
        scanf("%d", &values[i]);
        scanf("%d", &weights[i]);
    }

    // Call knapSack function to calculate maximum profit and select items
    int maxVul = knapSack(weights, values, result);
    // printf("%d", maxVul);

    // Print maximum profit
    printf("Maximum profit: %d\n", maxVul);

    // Print the selected items
    printf("Selected items:");
    for (int i = 0; i < SIZE; i++)
    {
        if (result[i] == 1)
        {
            printf(" %s", product[i]);
        }
    }

    return 0;
}

// Function to solve the knapsack problem
int knapSack(int weights[SIZE], int values[SIZE], int selected_bool[SIZE])
{
    // 2D array to store intermediate results
    int matrix[SIZE + 1][CAPACITY + 1]; // 0-15

    // Initialize the matrix with zeros
    for (int i = 0; i < CAPACITY + 1; i++)
    {
        matrix[0][i] = 0;
    }
    for (int i = 0; i < SIZE + 1; i++)
    {
        matrix[i][0] = 0;
    }

    // Fill the matrix using dynamic programming approach
    for (int i = 1; i < SIZE + 1; i++)
    { // Starting from 1
        for (int B = 1; B < CAPACITY + 1; B++)
        { // Starting from 1
            if (weights[i - 1] > B)
            {
                matrix[i][B] = matrix[i - 1][B];
            }
            else
            {
                matrix[i][B] = max(matrix[i - 1][B], values[i - 1] + matrix[i - 1][B - weights[i - 1]]);
            }
        }
    }
// /   // Print the matrix
//     printf("Matrix:\n");
//     for (int i = 0; i < SIZE + 1; i++)
//     {
//         for (int j = 0; j < CAPACITY + 1; j++)
//         {
//             printf("%d\t", matrix[i][j]);
//         }
//         printf("\n");
//     }

// Trace back to find selected items
    int i = SIZE;
    int j = CAPACITY;
    while (i>0 && j>0)
    {
        if (matrix[i][j] > matrix[i-1][j])
        {
            selected_bool[i-1] = 1;

            j = j -weights[i-1];
        }
        else
        {
            selected_bool[i-1] = 0;
        }
        i=i-1;
    }


    // Return the maximum value
    return matrix[SIZE][CAPACITY];
}
// Function to return the maximum value between x and y
int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}