#include <stdio.h>

// Sabit tanýmlamalar
#define MAX_SATIR 100
#define MAX_SUTUN 100

// kullanýlacak Fonksiyonlar
void matrisYazdir(int matris[MAX_SATIR][MAX_SUTUN], int satir, int sutun) //Bu Fonksiyon, bir tamsayý matrisini ekrana yazdýrmak için kullanýlacak.Fonksiyon, üç parametre alýr : yazdýrýlacak matris, matrisin satir sayýsý ve matrisin sütun sayýsý.
{
    for (int i = 0; i < satir; ++i) //Bu Döngü, matrisin her satýrýný temsil eder ve i deðiþkeni her döngü adýmýnda bir artar.
    {
        for (int j = 0; j < sutun; ++j) //Bu Döngü, matrisin her sütununu temsil eder ve i deðiþkeni her döngü adýmýnda bir artar.
        {
            printf("%d ", matris[i][j]);//i. satýrýn elemanlarý yazdýrýlýr.
        }
        printf("\n");//bir alt satýra geçilir
    }

}
//Bu fonksiyon, konvolusyon fonksiyonunu tanýmlar. Fonksiyon, iki matrisin (Görüntü ve Filtre) konvolüsyonunu hesaplar ve sonuç matrisine yazar. Parametreler arasýnda M ve N matris boyutlarýný, k filtre boyutunu ve T ise filtre matrisinin elemanlarý toplamýný belirtir.
void konvolusyon(int Goruntu[MAX_SATIR][MAX_SUTUN], int Filtre[MAX_SATIR][MAX_SUTUN], int sonuc[MAX_SATIR][MAX_SUTUN], int M, int N, int k, int T)
{
    for (int i = 0; i <= M - k; ++i) //Bu satýr, dýþtaki döngüyü baþlatýr.M satýrlý görüntü ve k satýrlý filtre matrisinin konvolüsyonu sonucunda m-k+1 satýrlý sonuc matrisi oluþur. bu yüzden i <= M-k ile döngü sýnýrlandýrýlýr.
    {
        for (int j = 0; j <= N - k; ++j) //Bu satýr, içteki döngüyü baþlatýr. N sütunlu görüntü ve k sütunlu filtre matrisinin konvolüsyonu sonucunda N-k+1 satýrlý sonuc matrisi oluþur. bu yüzden i <= N-k ile döngü sýnýrlandýrýlýr.
        {
            int toplam = 0;//Bu satýrdan sonra sonuç matrisinin farklý bir elemaný hesaplanýr bu yüzden her seferinde toplam sýfýrlanýr.
            
            for (int x = 0; x < k; ++x) // Bu satýr, iç içe üçüncü döngüyü baþlatýr. Bu döngü, filtre matrisinin her bir elemanýný temsil eder ve x deðiþkeni her döngü adýmýnda bir artar.
            {
                for (int y = 0; y < k; ++y) // Bu döngü, filtre matrisinin her bir elemanýný temsil eder ve y deðiþkeni her döngü adýmýnda bir artar.
                {
                    toplam += Goruntu[i + x][j + y] * Filtre[x][y]; //sonuc matrisinin elemanýný bulmak üzere görüntü ile filtre elemanlarýnýn çarpýmýnýn toplamý toplam deðiþkenine atanýr.
                }
            }
            sonuc[i][j] = toplam / T; // Toplam deðiþkeni filtre matrisinin elemanlarý toplamýný tutan T deðiþkenine bölünür ve sonuç matrisinin bir elemaný bulunmuþ olur.
        }
    }
}

int main() {
    // Kullanýcýdan alýnan deðerleri tutacak deðiþkenler
    int M, N, k;

    // Kullanýcýdan matris boyutlarý ve filtre boyutu alýnýr.
    printf("Goruntu matrisinin satir sayisini girin: ");
    scanf_s("%d", &M);

    printf("Goruntu matrisinin sutun sayisini girin: ");
    scanf_s("%d", &N);

    printf("Filtre matrisinin boyutunu girin: ");
    scanf_s("%d", &k);

    // Matrisler ve sonuç matrisinin boyutlarý belirtilir.
    int Goruntu[MAX_SATIR][MAX_SUTUN];
    int Filtre[MAX_SATIR][MAX_SUTUN];
    int sonuc[MAX_SATIR][MAX_SUTUN];

    // Görüntü matrisini kullanýcýdan alma
    printf("Goruntu matrisini girin:\n");
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            scanf_s("%d", &Goruntu[i][j]);
        }
    }
      

    // Filtre matrisini kullanýcýdan alma
    printf("Filtre matrisini girin:\n");
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k; ++j) 
        {

            scanf_s("%d", &Filtre[i][j]);
        }
    }
        

    //Filtre matrisinin her elemaný bu döngüyle toplanýr ve T deðiþkenine atanýr.
    int T = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            T += Filtre[i][j];
        }
    }

    // Konvolüsyon iþlemi fonksiyon yardýmýyla gerçekleþtirilir
    konvolusyon(Goruntu, Filtre, sonuc, M, N, k, T);

    // Görüntü Matrisi yazdýrýlýr
    printf("Goruntu Matrisi:\n");
    matrisYazdir(Goruntu, M, N);

    // Filtre Matrisi yazdýrýlýr
    printf("\nFiltre Matrisi:\n");
    matrisYazdir(Filtre, k, k);

    // Sonuç Matrisi yazdýrýlýr
    printf("\nSonuc Matrisi:\n");
    matrisYazdir(sonuc, M - k + 1, N - k + 1);

    return 0;
}

