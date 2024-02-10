#include <stdio.h>

int  main() {

    int n;
    printf("Lutfen matris boyutunu giriniz.: ");
    scanf("%d", &n);

    int  pdizi[n][n];

    int  cikti = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            pdizi[i][j] = cikti;
            cikti++;
            printf("%d\t", pdizi[i][j]);
        }
        printf("\n");
    }

 
    char  yon;
    printf ("\nMatrisi hangi yone dondurmek istersiniz? Lütfen Sag icin 'a', Sol icin 'b' yaziniz.: ");
    scanf(" %c", &yon);

    int gecici[n][n];
    if  (yon == 'A' || yon == 'a') {  
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                gecici[j][n - 1 - i] = pdizi[i][j];
            }
        }
    } else if (yon == 'b' || yon == 'B') { 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                gecici[n - 1 - j][i] = pdizi[i][j];
            }
        }
    } else  {
        printf("Geçersiz bir secim yaptiniz.\n");

return 1;    }

    for  (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            pdizi[i][j] = gecici[i][j];
        }
    }


    printf("\nDondurulmus Matris:\n");
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            printf("%d\t", pdizi[i][j]);
        }
        printf("\n");
    }


    return 0;
    
}

