#include <stdio.h>

int main()
{
     int N;
    
    printf("oluşturmak istediğiniz matrisin boyutunu giriniz: ");     // Kullanıcıdan matris boyutunu alıyoruz
    scanf("%d", &N);

    
    int matris[N][N];

    printf("oluşturmak istediğiniz matrisin elemanlarını giriniz:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matris[i][j]);
        }
    }

    printf("oluşturduğunuz matris:\n");           // Alınan matrisi ekrana yazdırıyoruz
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d", matris[i][j]);
        }
        printf("\n");
    }
    
    int donmeYonu;
    printf("matrisi hangi yönde döndürmek istiyorsunuz (1:Sağa, 2:Sola): ");   //Kullanıcıdan dönme yönünü alıyoruz
    scanf("%d", &donmeYonu);
    
    
    if(donmeYonu==1){                          //Sağa döndürmek istiyor demektir
        for (int i=0; i<N; i++){               //Dıştaki döngü, 0'dan N'e kadar olan indeksleri dolaşır
             for(int j=N-1 ;j>=0 ;j--){        //İçteki döngü, N-1'den 0'a kadar olan indeksleri tersten dolaşır.
                 printf("%d ",matris[j][i]);   //sağa döndürülmüş matrisi yazdırmış oluyoruz
             }
             printf("\n");                     //Alt satıra geçmesi, tablo şeklinde matris görüntüsü oluşması için ilk for'un altına \n koyuyoruz
        }
    }else if(donmeYonu==2) {                   //sola döndürmek istiyor demektir
        for (int i=N-1;i>=0;i--){              //Dıştaki döngü, N-1'den 0'a kadar olan indeksleri tersten dolaşır.
             for(int j=0 ;j<N ;j++){           // İçteki döngü, 0'dan N'e kadar olan indeksleri dolaşır.
                 printf("%d ",matris[j][i]);
             } 
             printf("\n");
        }
        
    }else{
        printf("Geçersiz yön girdiniz.Lütfen tekrar deneyin\n");
        return 1;                   /* Programın normal bir şekilde sonlanmadığını ve bir hata durumu olduğunu 
                                     belirtmek için genellikle farklı değerler de kullanılabilir, ancak sıklıkla 
                                     return 1 kullanılmaktadır.*/
    }
    
     return 0;
}


