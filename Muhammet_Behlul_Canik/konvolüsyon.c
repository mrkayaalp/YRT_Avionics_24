#include <stdio.h>

// Sabit tan�mlamalar
#define MAX_SATIR 100
#define MAX_SUTUN 100

// kullan�lacak Fonksiyonlar
void matrisYazdir(int matris[MAX_SATIR][MAX_SUTUN], int satir, int sutun) //Bu Fonksiyon, bir tamsay� matrisini ekrana yazd�rmak i�in kullan�lacak.Fonksiyon, �� parametre al�r : yazd�r�lacak matris, matrisin satir say�s� ve matrisin s�tun say�s�.
{
    for (int i = 0; i < satir; ++i) //Bu D�ng�, matrisin her sat�r�n� temsil eder ve i de�i�keni her d�ng� ad�m�nda bir artar.
    {
        for (int j = 0; j < sutun; ++j) //Bu D�ng�, matrisin her s�tununu temsil eder ve i de�i�keni her d�ng� ad�m�nda bir artar.
        {
            printf("%d ", matris[i][j]);//i. sat�r�n elemanlar� yazd�r�l�r.
        }
        printf("\n");//bir alt sat�ra ge�ilir
    }

}
//Bu fonksiyon, konvolusyon fonksiyonunu tan�mlar. Fonksiyon, iki matrisin (G�r�nt� ve Filtre) konvol�syonunu hesaplar ve sonu� matrisine yazar. Parametreler aras�nda M ve N matris boyutlar�n�, k filtre boyutunu ve T ise filtre matrisinin elemanlar� toplam�n� belirtir.
void konvolusyon(int Goruntu[MAX_SATIR][MAX_SUTUN], int Filtre[MAX_SATIR][MAX_SUTUN], int sonuc[MAX_SATIR][MAX_SUTUN], int M, int N, int k, int T)
{
    for (int i = 0; i <= M - k; ++i) //Bu sat�r, d��taki d�ng�y� ba�lat�r.M sat�rl� g�r�nt� ve k sat�rl� filtre matrisinin konvol�syonu sonucunda m-k+1 sat�rl� sonuc matrisi olu�ur. bu y�zden i <= M-k ile d�ng� s�n�rland�r�l�r.
    {
        for (int j = 0; j <= N - k; ++j) //Bu sat�r, i�teki d�ng�y� ba�lat�r. N s�tunlu g�r�nt� ve k s�tunlu filtre matrisinin konvol�syonu sonucunda N-k+1 sat�rl� sonuc matrisi olu�ur. bu y�zden i <= N-k ile d�ng� s�n�rland�r�l�r.
        {
            int toplam = 0;//Bu sat�rdan sonra sonu� matrisinin farkl� bir eleman� hesaplan�r bu y�zden her seferinde toplam s�f�rlan�r.
            
            for (int x = 0; x < k; ++x) // Bu sat�r, i� i�e ���nc� d�ng�y� ba�lat�r. Bu d�ng�, filtre matrisinin her bir eleman�n� temsil eder ve x de�i�keni her d�ng� ad�m�nda bir artar.
            {
                for (int y = 0; y < k; ++y) // Bu d�ng�, filtre matrisinin her bir eleman�n� temsil eder ve y de�i�keni her d�ng� ad�m�nda bir artar.
                {
                    toplam += Goruntu[i + x][j + y] * Filtre[x][y]; //sonuc matrisinin eleman�n� bulmak �zere g�r�nt� ile filtre elemanlar�n�n �arp�m�n�n toplam� toplam de�i�kenine atan�r.
                }
            }
            sonuc[i][j] = toplam / T; // Toplam de�i�keni filtre matrisinin elemanlar� toplam�n� tutan T de�i�kenine b�l�n�r ve sonu� matrisinin bir eleman� bulunmu� olur.
        }
    }
}

int main() {
    // Kullan�c�dan al�nan de�erleri tutacak de�i�kenler
    int M, N, k;

    // Kullan�c�dan matris boyutlar� ve filtre boyutu al�n�r.
    printf("Goruntu matrisinin satir sayisini girin: ");
    scanf("%d", &M);

    printf("Goruntu matrisinin sutun sayisini girin: ");
    scanf("%d", &N);

    printf("Filtre matrisinin boyutunu girin: ");
    scanf("%d", &k);

    // Matrisler ve sonu� matrisinin boyutlar� belirtilir.
    int Goruntu[MAX_SATIR][MAX_SUTUN];
    int Filtre[MAX_SATIR][MAX_SUTUN];
    int sonuc[MAX_SATIR][MAX_SUTUN];

    // G�r�nt� matrisini kullan�c�dan alma
    printf("Goruntu matrisini girin:\n");
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            scanf("%d", &Goruntu[i][j]);
        }
    }
      

    // Filtre matrisini kullan�c�dan alma
    printf("Filtre matrisini girin:\n");
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k; ++j) 
        {

            scanf("%d", &Filtre[i][j]);
        }
    }
        

    //Filtre matrisinin her eleman� bu d�ng�yle toplan�r ve T de�i�kenine atan�r.
    int T = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            T += Filtre[i][j];
        }
    }

    // Konvol�syon i�lemi fonksiyon yard�m�yla ger�ekle�tirilir
    konvolusyon(Goruntu, Filtre, sonuc, M, N, k, T);

    // G�r�nt� Matrisi yazd�r�l�r
    printf("Goruntu Matrisi:\n");
    matrisYazdir(Goruntu, M, N);

    // Filtre Matrisi yazd�r�l�r
    printf("\nFiltre Matrisi:\n");
    matrisYazdir(Filtre, k, k);

    // Sonu� Matrisi yazd�r�l�r
    printf("\nSonuc Matrisi:\n");
    matrisYazdir(sonuc, M - k + 1, N - k + 1);

    return 0;
}

