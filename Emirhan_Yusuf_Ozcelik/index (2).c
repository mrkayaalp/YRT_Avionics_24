#include <stdio.h>

#define MAX 10

void matrisi_dondur(int matris[MAX][MAX], int n, char yon) {
    int temp[MAX][MAX];
    int i, j;

    if (yon == 'd') {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                temp[j][n - i - 1] = matris[i][j];
            }
        }
    } else if (yon == 's') {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                temp[n - j - 1][i] = matris[i][j];
            }
        }
    }

    // Döndürülen matrisi orijinal matris olarak kopyala
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matris[i][j] = temp[i][j];
        }
    }
}

void matrisi_yazdir(int matris[MAX][MAX], int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matris[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matris[MAX][MAX];
    int n, i, j;
    char yon;

    printf("Matris boyutunu girin (N): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Hatali giris. Gecerli bir matris boyutu giriniz (1-%d).\n", MAX);
        return 1;  // Programı hata koduyla sonlandır
    }

    printf("Matris elemanlarini girin:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matris[i][j]);
        }
    }

    printf("Matrisi hangi yonde dondurmek istediginizi belirtin (s: sola, d: saga): ");
    scanf(" %c", &yon);

    if (yon == 's' || yon == 'd') {
        
        printf("\nOrijinal Matris:\n");
        matrisi_yazdir(matris, n);

        matrisi_dondur(matris, n, yon);

        if (yon == 's') {
            printf("\nSola Dondurulmus Matris:\n");
        } else {
            printf("\nSaga Dondurulmus Matris:\n");
        }
        matrisi_yazdir(matris, n);
    } else {
        printf("Gecersiz yon. 's' veya 'd' giriniz.\n");
    }

    return 0;
}
