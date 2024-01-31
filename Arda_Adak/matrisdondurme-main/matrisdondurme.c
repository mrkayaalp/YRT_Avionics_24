#include <stdio.h>

int main() {
    
    int N , i , j , secim; //Matrisin elemanlarını 1 den başlayarak tam sayılar kullandığım için int kullandım.
    printf("Oluşturmak istediğiniz NxNlik matrisin boyutunu belirleyiniz.\n"); //Kaça kaçlık matris olduğunu kullanıcıdan alıyorum
    scanf("%d", &N);
    
    int matris[N][N]; 
    int matrissayilari = 1; //Matrisin elemanlarını 1 den başlatmak için değer atadım.
    for(i = 0 ; i < N ; i++){
        for(j = 0 ; j < N ; j++){
            matris[i][j] = matrissayilari++; // Matrisin bütün elemanları 1 den başlayıp artarak ilerlemesini sağladım.
        }
    }
    printf("Oluşturmak istediğiniz %dx%d matris oluşturuldu:\n", N , N);
    for(i = 0 ; i < N ; i++){
        for(j = 0 ; j < N ; j++){
            printf("%3d", matris[i][j]);// Matrisi yazdırım , matris elemanları içinde 2 basamaklı sayılar girdiği zaman satırlar kayaradk kötü görüntü oluşturduğu için %3d ile boşluk bıraktım.
        }
        printf("\n");
    }
    printf("Matirse uygulamak istediğiniz işlemi seçin.\n1.90 Derece sola döndür.\n2.90 Derece sağa döndür.\n");
    scanf("%d", &secim);
    
    switch(secim){ //switch ile matrisin nereye döndülürmek istediğini kullanıcıdan aldım.
        case 1:
        printf("Yeni matrisiniz :\n"); //For ile döndürmeyi nasıl sağladığımı anlatmak için repoya bir .png dosyası koyacağım oradan anlatmak istediğimi açıkladım.
        for(i = (N - 1) ; i >= 0 ; i--){
            for(j = 0 ; j < N ; j++){
                printf("%3d", matris[j][i]);
            }
            printf("\n");
        }
        break;
        
        case 2:
        printf("Yeni matrisiniz :\n"); //Sola döndürmediki kullandığım mantık ile yola çıkarak aynısını sağa döndürme için kullandım
        for(i = 0 ; i < N ; i++){
            for(j = (N - 1) ; j >=0 ; j--){
                printf("%3d", matris[j][i]);
            }
            printf("\n");
        }
        break;
        
        default: //Eğer kullanıcı 1 veya 2 den farklı bir değer girerse işlemin geçersiz olduğunu kullanıcıya yazdırdım.
            
            printf("Geçersiz seçim!\n");
            break;
        
    }

    return 0;
}
