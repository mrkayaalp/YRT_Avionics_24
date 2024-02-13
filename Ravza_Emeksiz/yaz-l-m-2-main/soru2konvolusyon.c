#include <stdio.h>


void convolution(int M,int N,int k,int G[M][N], int F[k][k], int R[M - k + 1][N - k + 1]) {
    // M: G matrisinin satır sayısı
    // N: G matrisinin sütun sayısı
    // k: F filtrenin boyutu
    // G: MxN boyutunda giriş matrisi
    // F: kxk boyutunda filtre matrisi
    // R: (M-k+1)x(N-k+1) boyutunda çıkış matrisi
    
    for (int i = 0; i < M - k + 1; i++) {
        for (int j = 0; j < N - k + 1; j++) {
            int sum = 0;
  // G matrisinin (i,j) konumunda kxk boyutunda bir pencere oluşturulur
            for (int row_index = 0; row_index < k; row_index++) {
                for (int column_index = 0; column_index < k; column_index++) {
 // Filtre matrisiyle pencere üzerinde nokta çarpımı yapılır ve sonuç toplama eklenir
                    sum += G[i + column_index][j + column_index] * F[row_index][column_index];
                }
            }
// Elde edilen toplam, R matrisinin ilgili konumuna atanır
            R[i][j] = sum;
        }
    }
}

int main()
{
    int M,N;

    printf("Görüntü matrisi G'nin satır sayısını girin: ");
    scanf("%d", &M);
    printf("Görüntü matrisi G'nin sütun sayısını girin: ");
    scanf("%d", &N);
     
    
    
     int G[M][N];

    printf("oluşturmak istediğiniz görüntü matrisinin elemanlarını giriniz:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &G[i][j]);
        }
    }
    

    printf("oluşturduğunuz matris:\n");           
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
    //görüntü matrisi G'yi kullanıcıdan aldık
    
    int k;
    
    printf("filtre matrisi F'nin boyutunu giriniz: ");     
    scanf("%d", &k);
    
    int F[k][k];

    printf("oluşturmak istediğiniz matrisin elemanlarını giriniz:\n");
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &F[i][j]);
        }
    }

    printf("oluşturduğunuz matris:\n");           
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            printf("%d ", F[i][j]);
        }
        printf("\n");
    }
    //filtre matrisi F'yi kullanıcıdan aldık
     
    int R[M - k + 1][N - k + 1];                   //sonuç matrisini tanımlıyoruz
    
    convolution(M, N, k, G, F, R);                 // convolution fonksiyonu çağrılır ve sonuç matrisi R'e aktarılır.
    
    printf("Konvolüsyon işlemi sonucu oluşan matris R:\n");
    for (int i = 0; i < M - k + 1; i++) {
        for (int j = 0; j < N - k + 1; j++) {
            // Oluşan sonuç matrisi R, ekrana yazdırılır
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }

    
    return 0;
}




