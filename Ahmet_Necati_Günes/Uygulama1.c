#include <stdio.h>
int dizi[10000][10000];
void sola_dondur(int boyut, int dizi[10000][10000]) {
    for (int i = boyut - 1; i >= 0; i--) {
        for (int k = 0; k < boyut; k++) {
            if (dizi[i][k] != 0)
                printf("%d\t", dizi[k][i]);
        }
        printf("\n");
    }
}
void saga_dondur(int boyut, int dizi[10000][10000]) {
    for (int i = 0; i <= boyut - 1; i++) {
        for (int k = boyut - 1; k >= 0; k--) {
            printf("%d\t", dizi[k][i]);
        }
        printf("\n");
    }
}
int main() {
    int boyut, yon, a, b;
    printf("diziniz n*n lik olmali n nedir: ");
    scanf("%d", &boyut);
    for (a = 0; a < boyut; a++) {
        for (b = 0; b < boyut; b++) {
            printf(" (%d)(%d) elemani girin : ", a, b);
            scanf("%d", &dizi[a][b]);
        }
    }
    printf("saga donme icin 1 sola donme icin 0 tuslayin: ");
    scanf("%d", &yon);
    switch (yon) {
    case 0:
        sola_dondur(boyut, dizi);
        break;
    case 1:
        saga_dondur(boyut, dizi);
        break;
    }
      return 0;
}