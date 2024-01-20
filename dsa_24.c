#include <stdio.h>

int main() {
    int rows, columns;
    printf("enter the number of rows and columns in the matrix: ");
    scanf("%d %d", &rows, &columns);
    int matrix[rows][columns];
    printf("enter the elements of the matrix: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("enter element: ");
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("the original matrix: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("the transposed matrix: \n");
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }
    return 0;
}
