#include <stdio.h>

int main() {
    int r, c, a[100][100], b[100][100], mul[100][100], i, j, k;
    printf("enter the number of rows: ");
    scanf("%d", &r);
    printf("enter the number of columns: ");
    scanf("%d", &c);
    printf("\nenter elements of 1st matrix: \n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nenter elements of 2nd matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("enter element b%d%d: ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            mul[i][j] = 0;
            for(k = 0; k < c; k++) {
                mul[i][j] += a[i][k] * b[k][j];    
            }
        }
    }
    printf("\nmultiplication of the two given matrices: \n");
    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++) {
            printf("  %d   ", mul[i][j]);
            if (j == r - 1) {
                printf("\n\n");
            }
        }
    }
    return 0;
}
