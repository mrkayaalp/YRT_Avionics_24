#include <stdio.h>

int main() {
    int M, N, i, j, k;
    int toplam = 0;

    printf("Oluşturmak istediğiniz görüntü matrisinin boyutlarını belirleyiniz: (MxN) \n"); //Görüntü matrisinin büyüklüğünü kullanıcıdan al
    scanf("%d%d", &M , &N);

    int matris[M][N];

    printf("Matrisin elemanlarını giriniz:\n");

    // Görüntü matrisin elemanlarını kullanıcıdan al
    for(i = 0; i < M; i++){
        for(j = 0; j < N; j++){
            printf("Eleman[%d][%d]: ", i , j);
            scanf("%d", &matris[i][j]);
        }
    }

    printf("Görüntü matrisiniz:\n");

    // Görüntü matrisi yazdır
    for(i = 0; i < M; i++){
        for(j = 0; j < N; j++){
            printf("%3d", matris[i][j]);
        }
        printf("\n");
    }

    do {
        printf("Oluşturmak istediğiniz filtre matrisinin boyutlarını belirleyiniz (kxk): \n"); //Filtre matrisinin büyüklüğünü kullanıcıdan al
        scanf("%d", &k);

        if (M < k || N < k) {
            printf("Filtre matrisi görüntü matrisinden büyük olamaz!\n");
        }
    }
    while (M < k || N < k); //Filtre matrisini görüntü matrisinden büyük olmasını engelle

    int matris2[k][k];

    printf("Filtre matrisinin elemanlarını girin:\n"); //Filtre matrisinin elemanlarını kullanıcıdan al
    for(i = 0; i < k; i++){
        for(j = 0; j < k; j++){
            printf("Eleman[%d][%d]: ", i , j);
            scanf("%d", &matris2[i][j]);
            toplam += matris2[i][j]; //Filtre matrisi elemanları toplamını bul (Konvolusyon işlemi sonrası çıkıcak matrisi bölmek için kullanılıcak) //
        }
    }

    printf("Filtre matrisiniz:\n"); // Filtre matrisini yazdır
    for(i = 0; i < k; i++){
        for(j = 0; j < k; j++){
            printf("%3d", matris2[i][j]);
        }
        printf("\n");
    }

    // Konvolusyon
    int sonuc[M - k + 1][N - k + 1];

    for(i = 0; i < M - k + 1; i++){
        for(j = 0; j < N - k + 1; j++){
            sonuc[i][j] = 0;

            for(int x = 0; x < k; x++){  
                for(int y = 0; y < k; y++){
                    sonuc[i][j] += (matris[i + x][j + y] * matris2[x][y]) ;
                    
                }
            }
            
        }
    }

    // Konvolusyon sonucunu yazdır
    printf("Konvolüsyon işlemi sonucu oluşan matris:\n");
    for(i = 0; i < M - k + 1; i++){
        for(j = 0; j < N - k + 1; j++){
            printf("%3d ", sonuc[i][j] / toplam);
        }
        printf("\n");
    }

    return 0;
}