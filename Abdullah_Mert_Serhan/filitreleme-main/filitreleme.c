#include <stdio.h>

// Maksimum matris boyutları
#define MAX_ROWS 20
#define MAX_COLS 20

// Fonksiyon tanımları
void convolution(int G[MAX_ROWS][MAX_COLS], int F[MAX_ROWS][MAX_COLS], float R[MAX_ROWS][MAX_COLS], int rows_G, int cols_G, int k);

int main() {
    // Görüntü matrisi
    int G[MAX_ROWS][MAX_COLS];
    int rows_G, cols_G;

    // Filtre matrisi
    int F[MAX_ROWS][MAX_COLS];
    int k;

    // Sonuç matrisi
    float R[MAX_ROWS][MAX_COLS];

    // Görüntü matrisi satır sayısını kullanıcıdan al
    printf("Goruntu matrisinin satir sayisini giriniz: ");
    scanf("%d", &rows_G);

    // Görüntü matrisi sütun sayısını kullanıcıdan al
    printf("Goruntu matrisinin sutun sayisini giriniz: ");
    scanf("%d", &cols_G);

    // Görüntü matrisi elemanlarını tek tek kullanıcıdan al
    printf("Goruntu matrisini giriniz:\n");
    for (int i = 0; i < rows_G; i++) {
        for (int j = 0; j < cols_G; j++) {
            printf("Satir %d, Sutun %d degerini giriniz: ", i + 1, j + 1);
            scanf("%d", &G[i][j]);
        }
    }

    // Filtre matrisinin boyutunu kullanıcıdan al
    printf("Filtre matrisinin boyutunu giriniz (tek bir sayi): ");
    scanf("%d", &k);

    // Filtre matrisi elemanlarını tek tek kullanıcıdan al
    printf("Filtre matrisini giriniz:\n");
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            printf("Satir %d, Sutun %d degerini giriniz: ", i + 1, j + 1);
            scanf("%d", &F[i][j]);
        }
    }

    // Konvolüsyon işlemini uygula
    convolution(G, F, R, rows_G, cols_G, k);

    // Sonuç matrisini yazdır
    printf("\nSonuc matrisi:\n");
    for (int i = 0; i < rows_G - k + 1; i++) {
        for (int j = 0; j < cols_G - k + 1; j++) {
            printf("%.2f ", R[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Konvolüsyon işlemini uygula
void convolution(int G[MAX_ROWS][MAX_COLS], int F[MAX_ROWS][MAX_COLS], float R[MAX_ROWS][MAX_COLS], int rows_G, int cols_G, int k) {
    for (int i = 0; i < rows_G - k + 1; i++) {
        for (int j = 0; j < cols_G - k + 1; j++) {
            float sum = 0;
            float filterSum = 0;

            for (int x = 0; x < k; x++) {
                for (int y = 0; y < k; y++) {
                    sum += G[i + x][j + y] * F[x][y];
                    filterSum += F[x][y];
                }
            }

            R[i][j] = sum / filterSum;
        }
    }
}
