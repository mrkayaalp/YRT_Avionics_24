#include <stdio.h>

void convolution(int G[4][4], int F[3][3]) {
    int sonuc[2][2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int toplam = 0;

            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    if (i + k < 4 && j + l < 4) {
                        toplam += G[i + k][j + l] * F[k][l];
                    }
                }
            }

            int Ftoplam = 0;
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    Ftoplam += F[k][l];
                }
            }

            sonuc[i][j] = toplam / Ftoplam;
        }
    }

    printf("Islem Sonucu:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d\t", sonuc[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int F[3][3] = { {0,1,0},{2,3,1},{0,1,2} };
    int G[4][4] = { {0,1,2,0},{3,4,5,2},{6,7,1,1},{1,2,3,4} };
    convolution(G, F);

    return 0;
}