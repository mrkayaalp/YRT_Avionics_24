#include <stdio.h>

int main() {
    int matris[10][10]; // Maksimum boyutu 10x10 olan bir tamsay� tipinde 2D matris tan�mlan�r.
    int n;//matrisin boyutunu tutmas� i�in bir n de�i�keni olu�turulur

    printf("Matris boyutunu girin (en fazla 10): ");
    scanf("%d", &n); // Kullan�c�dan matris boyutunu al�n�r.

    // Girilen matris boyutunu kontrol eder, e�er hatal� giri� yap�ld�ya ekrana hata ��kt�s� verir.
    if (n <= 0 || n > 10) {
        printf("Hatal� matris boyutu. Program sonland�r�l�yor.\n");
        return 1;
    }

    printf("Matris elemanlarini girin:\n");
    // Kullan�c�n�n girdi�i matris elemanlar�n� for d�ng�s� kullanarak matrise yerle�tirir.
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &matris[i][j]);

    int secim;//kullan�c�n�n sa�a ve sola d�nd�rme iste�ini anlamak i�in secim de�ikeni olu�turulur
    printf("Matrisi saga d�nd�rmek icin (1), sola d�nd�rmek icin (2) e bas�n: ");//kullan�c�ya ne yapmak istedi�i sorulur
    scanf("%d", &secim); // Kullan�c�dan matrisi sa�a veya sola d�nd�rme se�ene�ini al�r.

    if (secim == 1) {
        // Matrisi sa�a d�nd�rme i�lemi
        int temp[10][10];//yeni ge�i�i kullan�lacak bir dizi olu�turulur 
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                temp[j][n - 1 - i] = matris[i][j];//matrisin her bir eleman� sa�a d�nd�r�ld���nde olaca�� konuma g�re temp dizisine tan�mlan�r

        // D�nd�r�len matrisi orijinal matrise kopyalar.
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                matris[i][j] = temp[i][j];//matrisin d�nd�r�lm�� hali tekrar matris[i][j] dizisine atan�r
    }
    else if (secim == 2) {
        // Matrisi sola d�nd�rme i�lemi
        int temp[10][10];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                temp[n - 1 - j][i] = matris[i][j]; // matrisin her bir eleman� sola d�nd�r�ld���nde olaca�� konuma g�re temp dizisine tan�mlan�r

        // D�nd�r�len matrisi orijinal matrise kopyalar.
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                matris[i][j] = temp[i][j];//matrisin d�nd�r�lm�� hali tekrar matris[i][j] dizisine atan�r
    }
    else {
        printf("Hatal� secim. Program sonland�r�l�yor.\n");
        return 1;
    }

    // D�nd�r�lm�� matrisi ekrana yazd�r�r.
    printf("Dondurulmus Matris:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", matris[i][j]);//for d�ng�s� ile ayn� sat�rdaki elemanlar yazd�r�l�r
        }
        printf("\n");//ayn� sat�rdaki elemanlar yazd�r�ld�ktan sonra bir alt sat�ra ge�mek i�in \n yaz�l�r
    }
    //sonu� olarak kullan�c�n�n iste�ine g�re sa�a veya sola d�nd�r�lm�� matris kullan�c�ya verilir.
    return 0;
}
