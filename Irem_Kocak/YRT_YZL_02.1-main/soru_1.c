#include <stdio.h>

// Matrisi ekrana basan fonksiyon
void printMatrix(int matris[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matris[i][j]);
        }
        printf("\n");
    }
}

// Sağa döndürme işlemi
void rotateRight(int matris[][10], int n) {
    int temp[10][10];

    // Sağa döndürme işlemi için geçici bir matris kullanılır
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = matris[n - 1 - j][i];
        }
    }

    // Geçici matrisin içeriği orijinal matrise kopyalanır
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matris[i][j] = temp[i][j];
        }
    }
}

// Sola döndürme işlemi
void rotateLeft(int matris[][10], int n) {
    int temp[10][10];

    // Sola döndürme işlemi için geçici bir matris kullanılır
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = matris[j][n - 1 - i];
        }
    }

    // Geçici matrisin içeriği orijinal matrise kopyalanır
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matris[i][j] = temp[i][j];
        }
    }
}

int main() {
    int n;

    printf("Matris boyutunu girin: ");
    scanf("%d", &n);

    int matris[10][10];

    printf("Matris elemanlarini girin:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matris[i][j]);
        }
    }

    printf("Dondurme yonunu secin:\n");
    printf("1. Saga\n2. Sola\n");

    int secim;
    scanf("%d", &secim);

    switch (secim) {
        case 1:
            rotateRight(matris, n);
            break;
        case 2:
            rotateLeft(matris, n);
            break;
        default:
            printf("Gecersiz secim!\n");
            return 1;
    }

    printf("Sonuc matrisi:\n");
    printMatrix(matris, n);

    return 0;
}
