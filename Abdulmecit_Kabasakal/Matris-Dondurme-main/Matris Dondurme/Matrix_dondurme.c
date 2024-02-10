#include <stdio.h>

void solaDondurme(int n,int matris [n][n]){ // sola dondurme fonksiyonunun tanımı
    int gecici_matris[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            gecici_matris[n-1-j][i]=matris[i][j];
        }
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0;j<n;j++)
        {
            matris[i][j]=gecici_matris[i][j];
        } 
    }
}
void sagaDondurme(int n,int matris[n][n]){ //saga dondurme fonksiyonun tanımı
    int gecici_matris[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            gecici_matris[j][n-1-i]=matris[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matris[i][j]=gecici_matris[i][j];
        }
    }
}
void matris_Yazdirma(int n,int matris[n][n]){ //matris yazdırma fonksiyonunun tanımı
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",matris[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int n;
    printf("Matrisin boyutunu giriniz: ");//matris boyutunun alınması
    scanf("%d",&n); 
    int matris[n][n]; //matrisin tanımlanması ve elemanlarının girilmesi
    printf("Matrisin elemanlarini giriniz :");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matris[i][j]);
        }
    }
    printf("Girilen matris :\n");
    matris_Yazdirma(n,matris); //matrisin ekrana yazdırılması
    int secim;
    printf("Saga dondurmek icin 1'i , sola dondurmek icin 2'yi tuslayiniz :"); //secimin yapılması
    scanf("%d",&secim);
    if(secim==1){ //secime gore olusan if else if blogu
        sagaDondurme(n,matris);  
        printf("\nSaga Dondurulmus Matris\n");
        matris_Yazdirma(n,matris);
    }
    else if(secim==2){
        solaDondurme(n,matris);
        printf("\nSola Dondurulmus Matris\n");
        matris_Yazdirma(n,matris);
    }
    else{
        printf("!!! Hatali Tuslama Yaptiniz !!!");
    }
    return 0;
}

