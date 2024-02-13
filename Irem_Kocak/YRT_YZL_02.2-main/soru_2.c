#include <stdio.h>

// Fonksiyon prototipi
void konvolusyon(int G[100][100], int F[3][3], int M, int N, int k, int R[100][100]);

int main() {
    int M, N, k;

    // Görüntü matrisi boyutlarını ve filtre boyutunu kullanıcıdan alın
    printf("Goruntu matrisi boyutlarini (M ve N) girin: ");
    scanf("%d %d", &M, &N);

    printf("Konvolusyon filtre matrisinin boyutunu (k) girin: ");
    scanf("%d", &k);

    int G[100][100];  // Gri seviyeli görüntü matrisi
    int F[3][3];       // Konvolusyon filtre matrisi
    int R[100][100];   // Sonuç matrisi

    // Görüntü matrisini kullanıcıdan alın
    printf("Goruntu matrisini girin:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    // Konvolusyon filtre matrisini kullanıcıdan alın
    printf("Konvolusyon filtre matrisini girin:\n");
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &F[i][j]);
        }
    }

    // Konvolusyon işlemini uygula
    konvolusyon(G, F, M, N, k, R);

    // Sonuç matrisini yazdır
    printf("Konvolusyon sonucu matris (R):\n");
    for (int i = 0; i < M - k + 1; i++) {
        for (int j = 0; j < N - k + 1; j++) {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Konvolusyon işlemini gerçekleştiren fonksiyon
void konvolusyon(int G[100][100], int F[3][3], int M, int N, int k, int R[100][100]) {
    for (int i = 0; i < M - k + 1; i++) {
        for (int j = 0; j < N - k + 1; j++) {
            int toplam = 0;

            // Filtre matrisi ile pikselleri çarp ve topla
            for (int x = 0; x < k; x++) {
                for (int y = 0; y < k; y++) {
                    toplam += G[i + x][j + y] * F[x][y];
                }
            }

            // Toplamı orta noktaya yaz
            R[i][j] = toplam;
        }
    }
}
