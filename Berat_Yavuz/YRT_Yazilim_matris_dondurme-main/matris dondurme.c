#include <stdio.h>

/*Ekrana matrisi yazdıracak bir fonksiyon oluşturduk 
bunu main kodun altında veri aldıktan sonra kullanacağız*/
void matrisiYazdir(int matris[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", matris[i][j]);
        }
        printf("\n");
    }
}

/*Matrisi saat yönünde döndüren bir fonksiyon tanımladık 
kullanıcıdan aldığımız veriye göre döndüreceğiz*/
void sagaDonder(int matris[][10], int n) {
    int geciciMatris[10][10];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            geciciMatris[j][n - i - 1] = matris[i][j];
        }
    }

/*Döndürülmüş matrisi asıl matris üzerine kopyalıyoruz 
    eğer bu aşamayı yapmazsak fonksiyon döndürülür ancak ekrana yansımaz*/
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matris[i][j] = geciciMatris[i][j];
        }
    }
}

/*Matrisi saat yönünün tersine döndüren bir fonksiyon tanımladık 
kullanıcıdan aldığımız veriye göre döndüreceğiz*/
void solaDonder(int matris[][10], int n) {
    int geciciMatris[10][10];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            geciciMatris[n - j - 1][i] = matris[i][j];
        }
    }

/*Döndürülmüş matrisi asıl matris üzerine kopyalıyoruz 
    eğer bu aşamayı yapmazsak fonksiyon döndürülür ancak ekrana yansımaz*/
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matris[i][j] = geciciMatris[i][j];
        }
    }
}

int main() {
    int N;

//Kullanıcıdan matrisin boyutu için veri istiyoruz
    printf("Matris boyutunu girin (en fazla 10): ");
    scanf("%d", &N);

//İkili dizi olan matrisin elamnlarını alıyoruz
    int matris[10][10];     
    printf("Matris elemanlarini girin:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("matris[%d][%d]: ", i, j);
            scanf("%d", &matris[i][j]);
        }
    }

//Matrisi ekrana yazdırıyoruz
    printf("Orijinal Matris:\n");
    matrisiYazdir(matris, N);

// Kullanıcıdan döndürme yönü hakkında veri alıyoruz
    int tercih;
    printf("Dondurme yonunu secin (1: Saga, 2: Sola): ");
    scanf("%d", &tercih);

/* Matrisi kullanıcının tercihine göre başta tanımladığımız 
döndürme fonksiyonları ile döndürüyoruz*/
    if (tercih == 1) {
        sagaDonder(matris, N);
    } else if (tercih == 2) {
        solaDonder(matris, N);
    } else {
        printf("Geçersiz tercih!");
        return 1;
    }

// Döndürülmüş matrisi ekrana yazdırıyoruz
    printf("Dondurulmus Matris:\n");
    matrisiYazdir(matris, N);

    return 0;
}
