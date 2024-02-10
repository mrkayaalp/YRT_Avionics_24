#include <stdio.h>
#include <stdlib.h>

//Matris Yazdırma Fonksiyonu
void matrisYazdirma(int row, int column, int **matris) 
{
    for (int i = 0; i < row; ++i) 
    {
        for (int j = 0; j < column; ++j)
        {
            printf("%d ", matris[i][j]);
        }
        printf("\n");
    }
}
//Konvulasyon Fonksiyonu

void konvolusyon(int **matris, int **filter, int **result, int row, int column, int size, int sum) 
{
    int toplam = 0;
    for (int i = 0; i <= row - size; ++i) 
    {
        for (int j = 0; j <= column - size; ++j) 
        {
            for (int x = 0; x < size; ++x) 
            {
                for (int y = 0; y < size; ++y)
                {
                    toplam += matris[i + x][j + y] * filter[x][y];
                }
            }
            result[i][j] = toplam / sum;
            toplam = 0;
        }
    }
}

//Kullanıcıdan Değer Alma 

int main() {
    int row, column, size;

    printf("Matrisin satir sayisini giriniz: ");
    scanf("%d", &row);

    printf("Matrisin sutun sayisini giriniz: ");
    scanf("%d", &column);

    printf("Filtre'nin boyutunu giriniz: ");
    scanf("%d", &size);

    int Row_result = row - size + 1 ;
    int Columnb_result = column - size + 1;

//2. Boyutlu  dinamik diziler için bellekten yer ayırıyoruz

    int **matris = malloc(sizeof(int *) * row);
    for (int i = 0; i < row; i++) 
    {
        matris[i] = malloc(sizeof(int) * column);
    }

    int **filter = malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) 
    {
        filter[i] = malloc(sizeof(int) * size);
    }

    int **result = malloc(sizeof(int *) * (Row_result));
    for (int i = 0; i < row - size + 1; i++) 
    {
        result[i] = malloc(sizeof(int) * (Columnb_result));
    }

    // Matris ve filter 2 boyutlu dizilerini alma
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < column; j++) 
        {
            printf("Matrisinizin %d. satirin %d. elemanini giriniz: ", i + 1, j + 1);
            scanf("%d", &matris[i][j]);
        }
    }

    int sum = 0; // filtre matrisinin toplamı
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            printf("Filtrenizin %d. satirin %d. elemanini giriniz: ", i + 1, j + 1);
            scanf("%d", &filter[i][j]);
            sum += filter[i][j];
        }
    }
    
    //Konvolüsyon fonksiyonunu çağırma
    konvolusyon(matris, filter, result, row, column, size, sum);

    //Sonuç matirisin yazdırma
    printf("Sonuc Matrisi:\n");
    matrisYazdirma(Row_result,Columnb_result, result);

    //Dinamik Belleği serbest bırakma
    for (int i = 0; i < row; i++) 
    {
        free(matris[i]);
    }
    free(matris);

    for (int i = 0; i < size; i++) 
    {
        free(filter[i]);
    }
    free(filter);

    for (int i = 0; i < row - size + 1; i++)
    {
        free(result[i]);
    }
    free(result);

    return 0;
}
