#include <stdio.h>

// Fonksiyon prototipi
void rotateMatrix(int matris[100][100], int n, int direction);

// Matrisi ekrana yazdıran fonksiyon
void printMatrix(int matris[100][100], int n);

int main() {
    int n;

    // Kullanıcıdan matris boyutunu al
    printf("Matris boyutunu girin (NxN): ");
    scanf("%d", &n);

    // Matris elemanlarını kullanıcıdan al
    int matris[100][100];
    printf("Matris elemanlarini tam sayi olacak sekilde girin:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("matris[%d][%d]: ", i, j);
            scanf("%d", &matris[i][j]);
        }
    }

    // Matrisi ekrana yazdır
    printf("\nGirilen Matris:\n");
    printMatrix(matris, n);

    // Hangi yönde çevrileceğini kullanıcıya sor
    int secim;
    printf("\nMatrisi hangi yonde cevirmek istersiniz? (1: Saga, 2: Sola): ");
    scanf("%d", &secim);

    // Matrisi çevir ve ekrana yazdır
    printf("\nSonuc:\n");
    rotateMatrix(matris, n, secim);

    return 0;
}

// Matrisi çeviren fonksiyon
void rotateMatrix(int matris[100][100], int n, int direction) {
    int temp[100][100];

    if (direction == 1) {
        // Sağa çevir
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[j][n - 1 - i] = matris[i][j];
            }
        }
    } else if (direction == 2) {
        // Sola çevir
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[n - 1 - j][i] = matris[i][j];
            }
        }
    } else {
        printf("Gecersiz secim!\n");
        return;
    }

    // Yeni matrisi ekrana yazdır
    printMatrix(temp, n);
}

// Matrisi ekrana yazdıran fonksiyon
void printMatrix(int matris[100][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matris[i][j]);
        }
        printf("\n");
    }
}
