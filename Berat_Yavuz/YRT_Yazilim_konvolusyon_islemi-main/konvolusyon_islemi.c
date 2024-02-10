#include <stdio.h>

#define MAX_M 100   //dizi elemanlarını tanımladık
#define MAX_N 100
#define MAX_K 10

/* Görüntü matrisini ekrana yazdıran bir fonksiyon tanımladık
burda for döngüsü ile dizinin bütün elemanlarını kapsadık*/
void matrisiYazdir(int matris[MAX_M][MAX_N], int M, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", matris[i][j]);
        }
        printf("\n");
    }
}

/* Konvolüsyon işlemi uygulayan bir fonksiyon tanımladık
filtre matrisini görüntü matrisi üzerinde gezdirerek filtredeki sayılarla pikselleri çarptık ve toplayıp 
filtrenin toplamına böldük ve sonucu orta noktaya yazdırdık*/
void konvolusyonUygula(int G[MAX_M][MAX_N], int F[MAX_K][MAX_K], int R[MAX_M][MAX_N], int M, int N, int k) {
    int kenar = k / 2;
//Görüntü matrisinin her pikseli için konvolüsyon uygulattık
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            R[i][j] = 0;
//Filtre matrisinin içinde konvolüsyon işlemini döndürdük 
            for (int x = 0; x < k; x++) {
                for (int y = 0; y < k; y++) {
// Görüntü matrisi içinde konvolüsyon penceresinin konumunu hesapladık
                    int gX = i - kenar + x;
                    int gY = j - kenar + y;

// Görüntü sınırlarını kontrol ettik
                    if (gX >= 0 && gX < M && gY >= 0 && gY < N) {
                        R[i][j] += G[gX][gY] * F[x][y]; // Konvolüsyon işlemi: Görüntü pikseli ile filtre pikselini çarp ve topla
                    }
                }
            }

// Filtre toplamına böldük
            R[i][j] /= k * k;
        }
    }
}

int main() {
    int M, N, k;

// Kullanıcıdan görüntü boyutunu ve filtre boyutunu aldık
    printf("Goruntu boyutunu girin (M N): ");
    scanf("%d %d", &M, &N);

    printf("Filtre boyutunu girin (k): ");
    scanf("%d", &k);

// Kullanıcıdan görüntü matrisini ve filtre matrisini aldık
    int G[MAX_M][MAX_N], F[MAX_K][MAX_K];

    printf("Goruntu matrisini girin:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    printf("Filtre matrisini girin:\n");
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &F[i][j]);
        }
    }

    // Konvolüsyon işlemi uyguladık ve sonucu ekrana yazdırdık
    int R[MAX_M][MAX_N];
    konvolusyonUygula(G, F, R, M, N, k);

    printf("Konvolusyon sonucu:\n");
    matrisiYazdir(R, M, N);

    return 0;
}
