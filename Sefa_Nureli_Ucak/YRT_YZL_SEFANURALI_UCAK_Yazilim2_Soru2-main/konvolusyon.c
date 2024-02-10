
#include <stdio.h>

#define MAX_SIZE 10

// Fonksiyon prototipleri
void convolve(int M, int N, int K, int matrix_goruntu[MAX_SIZE][MAX_SIZE], int filter[MAX_SIZE][MAX_SIZE]);
void printMatrix(int M, int N, int matrix[MAX_SIZE][MAX_SIZE]);
void getUserMatrix(int *M, int *N, int matrix[MAX_SIZE][MAX_SIZE]);
void getUserFilter(int *K, int filter[MAX_SIZE][MAX_SIZE]);

int main() {
    int M, N, K;

    int matrix_goruntu[MAX_SIZE][MAX_SIZE];
    int filter[MAX_SIZE][MAX_SIZE];

    // Kullanıcıdan goruntu matrix boyutu ve elemanları al
    getUserMatrix(&M, &N, matrix_goruntu);

    // Goruntu matrisini ekrana yazdır
    printf("Goruntu Matrisi:\n");
    printMatrix(M, N, matrix_goruntu);

    // Kullanıcıdan filtre matrix boyutu ve elemanları al
    getUserFilter(&K, filter);

 // Filtre matrisini ekrana yazdır
    printf("Filtre Matrisi:\n");
    printMatrix(K, K, filter);


    // Konvolüsyon işlemini gerçekleştir
    convolve(M, N, K, matrix_goruntu, filter);

    return 0;
}

// Matrisi ekrana yazdıran fonksiyon
void printMatrix(int M, int N, int matrix[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Kullanıcıdan goruntu matrix boyutu ve elemanları alan fonksiyon
void getUserMatrix(int *M, int *N, int matrix[MAX_SIZE][MAX_SIZE]) {
    printf("Goruntu matris boyutunu girin (MxN):\n");
    printf("M:");
    scanf("%d", M);
    printf("N:");
    scanf("%d", N);

    printf("Goruntu matris elemanlarini girin:\n");
    for (int i = 0; i < *M; i++) {
        for (int j = 0; j < *N; j++) {
            printf("matrix_goruntu[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Kullanıcıdan filtre matrix boyutu ve elemanları alan fonksiyon
void getUserFilter(int *K, int filter[MAX_SIZE][MAX_SIZE]) {
    printf("Filtre matris boyutunu girin (K K):\n");
    scanf("%d", K);

// Üçül koşul operatörü kullanılarak M ve N'den küçük olan değer ile K'yı karşılaştırma
   int minMN = (M < N) ? M : N;
    if (K > minMN) {
        printf("Hata: Filtre boyutu, goruntu matrisinin boyutundan buyuk olamaz. Program sonlandiriliyor.\n");
        return 1; // Programı hata koduyla sonlandır
    }

    printf("Filtre matris elemanlarini girin:\n");
    for (int i = 0; i < *K; i++) {
        for (int j = 0; j < *K; j++) {
            printf("filter[%d][%d]: ", i, j);
            scanf("%d", &filter[i][j]);
        }
    }
}

// Konvolüsyon işlemini gerçekleştiren fonksiyon
void convolve(int M, int N, int K, int matrix_goruntu[MAX_SIZE][MAX_SIZE], int filter[MAX_SIZE][MAX_SIZE]) {
    int result[MAX_SIZE][MAX_SIZE];

    // Konvolüsyon işlemi
    for (int i = 0; i <= M - K; i++) {
        for (int j = 0; j <= N - K; j++) {
            int sum = 0;
            for (int m = 0; m < K; m++) {
                for (int n = 0; n < K; n++) {
                    sum += matrix_goruntu[i + m][j + n] * filter[m][n];
                }
            }
            result[i][j] = sum / filter_sum(filter, K);
        }
    }

    // Konvolüsyon sonucunu ekrana yazdır
    printf("Konvolusyon Sonucu:\n");
    printMatrix(M - K + 1, N - K + 1, result);
}

// Filtre matrixinin elemanlarının toplamını hesaplayan fonksiyon
int filter_sum(int filter[MAX_SIZE][MAX_SIZE], int K) {
    int sum = 0;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            sum += filter[i][j];
        }
    }
    return sum;
}

