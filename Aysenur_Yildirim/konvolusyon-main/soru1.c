#include <stdio.h>

void printMatrix(float matrix[][100], int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%.2f ", matrix[i][j]);
        }
          printf("\n");
    }
}

void applyConvolution(int G[][100], float F[][3], float R[][100], int M, int N, int k) {
    float filterSum = 0.0;;


    for(int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            filterSum += F[i][j];
        }
    }

    for  (int i = 0; i <= M - k; i++) {
        for  (int j = 0; j <= N - k; j++) {
            float   sum = 0.0;
            for(int x = 0; x < k; x++) {
                for (int y = 0; y < k; y++) {
                    sum += G[i + x][j + y] * F[x][y];
                }
            }
            R[i][j] = sum / filterSum;
        }
    }
}

int main() {
    int  M,  N, k;


    printf  ("Goruntu matrisinin boyutlarini girin (M N): ");
    scanf ("%d %d", &M, &N);

    printf ("Konvolusyon filtresinin boyutunu girin (k): ");
    scanf ("%d", &k);

    int G[100][100];
    float  F[3][3];
    float  R[100][100];


    printf("Goruntu matrisini girin:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    printf("Konvolusyon filtresini girin:\n");
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            scanf("%f", &F[i][j]);
        }
    }

    applyConvolution(G, F, R, M, N, k);

    printf("Sonuc Matrisi:\n");
    printMatrix(R, M - k + 1, N - k + 1);

    return 0;
}
