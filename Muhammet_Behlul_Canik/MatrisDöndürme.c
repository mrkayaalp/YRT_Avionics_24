#include <stdio.h>

int main() {
    int matris[10][10]; // Maksimum boyutu 10x10 olan bir tamsayý tipinde 2D matris tanýmlanýr.
    int n;//matrisin boyutunu tutmasý için bir n deðiþkeni oluþturulur

    printf("Matris boyutunu girin (en fazla 10): ");
    scanf_s("%d", &n); // Kullanýcýdan matris boyutunu alýnýr.

    // Girilen matris boyutunu kontrol eder, eðer hatalý giriþ yapýldýya ekrana hata çýktýsý verir.
    if (n <= 0 || n > 10) {
        printf("Hatalý matris boyutu. Program sonlandýrýlýyor.\n");
        return 1;
    }

    printf("Matris elemanlarini girin:\n");
    // Kullanýcýnýn girdiði matris elemanlarýný for döngüsü kullanarak matrise yerleþtirir.
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf_s("%d", &matris[i][j]);

    int secim;//kullanýcýnýn saða ve sola döndürme isteðini anlamak için secim deðikeni oluþturulur
    printf("Matrisi saga döndürmek icin (1), sola döndürmek icin (2) e basýn: ");//kullanýcýya ne yapmak istediði sorulur
    scanf_s("%d", &secim); // Kullanýcýdan matrisi saða veya sola döndürme seçeneðini alýr.

    if (secim == 1) {
        // Matrisi saða döndürme iþlemi
        int temp[10][10];//yeni geçiçi kullanýlacak bir dizi oluþturulur 
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                temp[j][n - 1 - i] = matris[i][j];//matrisin her bir elemaný saða döndürüldüðünde olacaðý konuma göre temp dizisine tanýmlanýr

        // Döndürülen matrisi orijinal matrise kopyalar.
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                matris[i][j] = temp[i][j];//matrisin döndürülmüþ hali tekrar matris[i][j] dizisine atanýr
    }
    else if (secim == 2) {
        // Matrisi sola döndürme iþlemi
        int temp[10][10];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                temp[n - 1 - j][i] = matris[i][j]; // matrisin her bir elemaný sola döndürüldüðünde olacaðý konuma göre temp dizisine tanýmlanýr

        // Döndürülen matrisi orijinal matrise kopyalar.
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                matris[i][j] = temp[i][j];//matrisin döndürülmüþ hali tekrar matris[i][j] dizisine atanýr
    }
    else {
        printf("Hatalý secim. Program sonlandýrýlýyor.\n");
        return 1;
    }

    // Döndürülmüþ matrisi ekrana yazdýrýr.
    printf("Dondurulmus Matris:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", matris[i][j]);//for döngüsü ile ayný satýrdaki elemanlar yazdýrýlýr
        }
        printf("\n");//ayný satýrdaki elemanlar yazdýrýldýktan sonra bir alt satýra geçmek için \n yazýlýr
    }
    //sonuç olarak kullanýcýnýn isteðine göre saða veya sola döndürülmüþ matris kullanýcýya verilir.
    return 0;
}
