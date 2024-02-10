#include <stdio.h>

void matris_Yazdirma(int n,int m,int matris[m][n]){ //matrisi ekrana yazdırma
    for (int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",matris[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int m,n,k; // matris boyutları

    printf("Lutfen goruntu matrisinin boyutlarini sirasiyla giriniz");
    scanf("%d%d",&m,&n); //kullanıcıdan matris boyutlarının alınması
    int goruntu_matrisi[m][n]; //goruntu matrisinin tanımlanması
    printf("Lutfen goruntu matrisinin elemanlarini giriniz");
    for(int i=0;i<m;i++){ //goruntu matrisinin elemanlarinin girilmesi
        for(int j=0;j<n;j++){
            scanf("%d",&goruntu_matrisi[i][j]);
        }
    }
    printf("Goruntu Matrisi :\n"); //girilen goruntu matrisinin ekrana yazılması
    matris_Yazdirma(n,m,goruntu_matrisi);

    printf("Lutfen Filtre Matrisinin Boyutunu Giriniz :");
    scanf("%d",&k); //filtre matrisinin boyutunun alinmasi
    int filtre_matrisi[k][k]; //filtre matrisinin tanımlanması
    printf("Lutfen filtre matrisinin elamanlarini giriniz :");
    for(int i=0;i<k;i++){ //filtre matrisinin elemanlarinin girilmesi
        for(int j=0;j<k;j++){
            scanf("%d",&filtre_matrisi[i][j]);
        }
    }
    printf("Filtre matrisi :\n");
    matris_Yazdirma(k,k,filtre_matrisi); //filtre matrisinin ekrana yazılması

    int toplam= 0; //filtre matrisinin elemanlarının toplamının hesaplanması
    for (int i=0;i<k;i++){ //sonuc matrisini hesaplarken toplam degere ihtiyacimiz olucak
        for(int j=0;j<k;j++){
            toplam+=filtre_matrisi[i][j];
        }
    }

    int sonuc_matris[m-k+1][n-k+1]; //sonuc matrisinin tanımlanması
    //goruntu üzerinde filtreleme işleminin yapılıp sonuc matrise yazılması
    for(int i=0;i<m-k+1;i++){
        for(int j=0;j<m-k+1;j++){
            int sum=0;
            for (int x=0;x<k;x++){
                for (int y=0;y<k;y++){
                    sum+=goruntu_matrisi[i+x][j+y] * filtre_matrisi[x][y];
                }
            }
            sonuc_matris[i][j] = sum / toplam;  // yukarıdan gelen sum degeri ile bulunan toplam değerinin
                                                // bolumu sonucu sonuc_matrisin bir elemanı 
        }
    }
    printf("Sonuc Matrisi : \n");
    matris_Yazdirma(m-k+1, n-k+1 ,sonuc_matris); //sonuc matrisin yazdırılması
    return 0;
}