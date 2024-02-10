#include <stdio.h>

#define MAX 10

void konvolusyon(int G[MAX][MAX], int F[MAX][MAX], int M, int N, int k, int R[MAX][MAX]) {
    int i, j, m, n, sum;

    for (i = 0; i <= M - k; i++) {
        for (j = 0; j <= N - k; j++) {
            sum = 0;
            for (m = 0; m < k; m++) {
                for (n = 0; n < k; n++) {
                    sum += G[i + m][j + n] * F[m][n];
                }
            }
            R[i][j] = sum / 10; // Toplamı filtre boyutuna böler
        }
    }
}

void matrisi_yazdir(int matris[MAX][MAX], int M, int N) {
    int i, j;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", matris[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int G[MAX][MAX], F[MAX][MAX], R[MAX][MAX];
    int M, N, k;

    printf("Goruntu matrisinin satir ve sutun sayisini girin (M N): ");
    scanf("%d %d", &M, &N);

    printf("Goruntu matrisini girin:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    printf("Filtre matrisinin boyutunu girin (k): ");
    scanf("%d", &k);

    if (k <= 0 || k > MAX) {
        printf("Hatali giris. Gecerli bir filtre boyutu giriniz (1-%d).\n", MAX);
        return 1;  // Programı hata koduyla sonlandır
    }

    printf("Filtre matrisini girin:\n");
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &F[i][j]);
        }
    }

    konvolusyon(G, F, M, N, k, R);

    printf("\nGoruntu Matrisi:\n");
    matrisi_yazdir(G, M, N);

    printf("\nFiltre Matrisi:\n");
    matrisi_yazdir(F, k, k);

    printf("\nSonuc Matrisi:\n");
    matrisi_yazdir(R, M - k + 1, N - k + 1);

    return 0;
}
