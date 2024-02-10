#include <stdio.h>

// Matrisi ekrana yazdıran fonksiyon
void matrisiYazdir(int matris[][10], int boyut) {
    for (int i = 0; i < boyut; i++) {
        for (int j = 0; j < boyut; j++) {
            printf("%3d ", matris[i][j]);
        }
        printf("\n");
    }
}

// Matrisi sağa döndüren fonksiyon
void sagaDonder(int matris[][10], int boyut, int adet) {
    for (int k = 0; k < adet; k++) {
        int temp[10][10];

        for (int i = 0; i < boyut; i++) {
            for (int j = 0; j < boyut; j++) {
                temp[j][boyut - 1 - i] = matris[i][j];
            }
        }

        for (int i = 0; i < boyut; i++) {
            for (int j = 0; j < boyut; j++) {
                matris[i][j] = temp[i][j];
            }
        }
    }
}

// Matrisi sola döndüren fonksiyon
void solaDonder(int matris[][10], int boyut, int adet) {
    for (int k = 0; k < adet; k++) {
        int temp[10][10];

        for (int i = 0; i < boyut; i++) {
            for (int j = 0; j < boyut; j++) {
                temp[i][j] = matris[j][boyut - 1 - i];
            }
        }

        for (int i = 0; i < boyut; i++) {
            for (int j = 0; j < boyut; j++) {
                matris[i][j] = temp[i][j];
            }
        }
    }
}

int main() {
    int boyut;

    // Matris boyutunu kullanıcıdan al
    do {
        printf("Kare matrisin boyutunu giriniz (minumum 1): ");
        scanf("%d", &boyut);

        if (boyut <= 0) {
            printf("Hatali giris! Matris boyutu minumum 1 olmalidir. Lutfen tekrar giriniz.\n");
        }

    } while (boyut <= 0);

    int matris[10][10];

    // Matris elemanlarını kullanıcıdan al
    for (int i = 0; i < boyut; i++) {
        for (int j = 0; j < boyut; j++) {
            printf("%d. satir %d. sutun elemanini giriniz: ", i + 1, j + 1);
            scanf("%d", &matris[i][j]);
        }
    }

    // Matrisi ekrana yazdır
    printf("\nGirilen Matris:\n");
    matrisiYazdir(matris, boyut);

    int secim;
    int adet;

    // Kullanıcıya döndürme yöntemi ve adetini sorma
    do {
        printf("\nMatrisi hangi yöne dondurmek istersiniz?\n");
        printf("1 - Saga\n");
        printf("2 - Sola\n");
        printf("Secim: ");
        scanf("%d", &secim);

        if (secim != 1 && secim != 2) {
            printf("Hatali giris! Lutfen 1 veya 2 giriniz.\n");
        }

    } while (secim != 1 && secim != 2);

    printf("Matrisi kac kere dondurmek istersiniz: ");
    scanf("%d", &adet);

    // Döndürme işlemini gerçekleştirme
    if (secim == 1) {
        sagaDonder(matris, boyut, adet);
    } else {
        solaDonder(matris, boyut, adet);
    }

    // Sonuç matrisini ekrana yazdır
    printf("\nDondurulmus Matris:\n");
    matrisiYazdir(matris, boyut);

    return 0;
}
