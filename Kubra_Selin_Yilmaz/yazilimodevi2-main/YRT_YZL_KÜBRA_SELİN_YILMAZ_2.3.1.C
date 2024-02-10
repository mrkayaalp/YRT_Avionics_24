#include <stdio.h>

int main() {
    int a[10][10], n, i, j, x;

    // Get the size of the matrix from the user
    printf("Enter the number of rows and columns of the matrix (up to 10): ");
    scanf("%d", &n);

    // Get matrix elements from the user
    printf("\nEnter the elements of the matrix:\n");
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }

    // Display the matrix
    printf("\nMatrix: \n");
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    // Get the rotation direction from the user
    printf("\nEnter 1 to rotate the matrix to the right, 2 to rotate to the left: ");
    scanf("%d", &x);

    // Rotate the matrix and display the result
    if (x == 1) {
        printf("\nMatrix rotated 90 degrees to the right: \n");
        for (i = 0; i < n; i++) {
            for (j = n - 1; j >= 0; j--) {
                printf("%5d", a[j][i]);
            }
            printf("\n");
        }
    } else if (x == 2) {
        printf("\nMatrix rotated 90 degrees to the left: \n");
        for (i = n - 1; i >= 0; i--) {
            for (j = 0; j <= n - 1; j++) {
                printf("%5d", a[j][i]);
            }
            printf("\n");
        }
    } else {
        printf("\nInvalid choice!\n");
    }

    return 0;
}
