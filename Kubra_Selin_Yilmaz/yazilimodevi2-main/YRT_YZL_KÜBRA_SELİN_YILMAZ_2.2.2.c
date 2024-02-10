#include <stdio.h>
#include <stdlib.h>

int main() {
    int M, N, k, i, j;
    
    // Input dimensions
    printf("Enter the number of rows (M) for the image matrix: ");
    scanf("%d", &M);
    printf("Enter the number of columns (N) for the image matrix: ");
    scanf("%d", &N);
    
    // Input filter size
    printf("Enter the filter size (k): ");
    scanf("%d", &k);

    int imageMatrix[M][N];
    int filterMatrix[k][k];
    int outputMatrix[M - k + 1][N - k + 1];

    // Initialize output matrix to 0
    for (i = 0; i < M - k + 1; i++) {
        for (j = 0; j < N - k + 1; j++) {
            outputMatrix[i][j] = 0;
        }
    }

    // Input values for the image matrix
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("Enter value for image matrix at [%d][%d]: ", i, j);
            scanf("%d", &imageMatrix[i][j]);
        }
    }

    // Input values for the filter matrix
    for (i = 0; i < k; i++) {
        for (j = 0; j < k; j++) {
            printf("Enter value for filter matrix at [%d][%d]: ", i, j);
            scanf("%d", &filterMatrix[i][j]);
        }
    }

    // Calculate filter sum
    int filterSum = 0;
    for (i = 0; i < k; i++) {
        for (j = 0; j < k; j++) {
            filterSum += filterMatrix[i][j];
        }
    }

    if (filterSum == 0) {
        printf("Error: Filter sum cannot be zero. Exiting.\n");
        return 1;
    }

    // Convolution process
    for (i = 0; i < M - k + 1; i++) {
        for (j = 0; j < N - k + 1; j++) {
            for (int m = 0; m < k; m++) {
                for (int n = 0; n < k; n++) {
                    outputMatrix[i][j] += filterMatrix[m][n] * imageMatrix[i + m][j + n];
                }
            }
            outputMatrix[i][j] /= filterSum;
        }
    }

    // Print the output matrix
    printf("Output Matrix:\n");
    for (i = 0; i < M - k + 1; i++) {
        for (j = 0; j < N - k + 1; j++) {
            printf("[%d][%d] = %d\n", i, j, outputMatrix[i][j]);
        }
    }

    return 0;
}
