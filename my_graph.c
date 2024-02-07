
#include <stdio.h>
#include "my_mat.h"

int main()
{
    int matrix[SIZE][SIZE];
    char letter;
    int x,y;

   // printf("please put a letter A/B/C or D to Exit: \n");
    scanf("%c", &letter);

    while (letter != 'D'&&letter != EOF){
    
        if (letter == 'A'){
            matrixVaribale(matrix, SIZE, SIZE);
        }

         if (letter == 'B'){
            
            scanf("%d %d", &x, &y);
            int result = isThereRoute(matrix,x,y);
            if (result == 0)
            {
                printf("False\n");
            }
            else{
                printf("True\n");
            }
            
        }

        if (letter == 'C') {
          scanf("%d %d", &x, &y);
        int res = printPath(matrix,x,y);
        printf("%d\n" , res);
           

    }
    scanf("%c", &letter);//for avoid to infinty loop

}
return 0;
}