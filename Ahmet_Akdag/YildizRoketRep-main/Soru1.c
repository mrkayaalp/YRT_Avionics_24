#include <stdio.h>
#include <stdlib.h>



    int main (void)
    {
     int k ;
	 int row; // Matrisin satır veya sütün sayısı
     printf("Matrisin satir veya sutun sayisini giriniz:");
     scanf("%d",&row); //Burda değişkeni alıyoruz.

	//Malloc ile matrisimiz için yer ayırıyoruz

	 int** matris;
	 matris = malloc(sizeof(int*) * row);
	 for(k=0 ; k < row ; k++)
	 {
		matris[k] = malloc(sizeof(int) * row);
	 }


     int i,j; //Döngülerde kullanıcağımız değişkenler

	    matris[row][row]; //2 boyutlu matrisi tanımlıyoruz

    	for(i=0;i<row;i++) //iç içe for döngüsü ile matrisi alıyoruz
    	{
     		for(j=0;j<row;j++)
     		{
      			printf("%d. satirin %d. elemaini giriniz",i+1,j+1);//i+1 ve j+1 dememim sebebi
      			scanf("%d",&matris[i][j]);						   //bu değişkenlerin 0 dan başlaması
     		}
    	}
		printf("Girdiğiniz Matris\n");
    	for(i=0;i<row;i++)	//Matrisi kontrol amacıyla yazdırıyoruz.
    	{
     		for(j=0;j<row;j++)
     		{
      		printf("%d ",matris[i][j]);
     		}
     	printf("\n"); //Matrisi satırlara ayırmak için sütun sayısı tamamlanınca satırı bitiriyoruz.
    	}

		//Kullanıcının tercihini alıyoruz
    	printf("Saga dondurmek icin 1'e , sola dondurmek icin 2'ye basin"); 
    	int key;
    	scanf("%d",&key);

		//Sağa döndürme komutları
    	if(key==1)
    	{
        	for(i=0;i<row;i++)
      		{
             for(j=row-1;j>=0;j--)
             {
               printf("%d ",matris[j][i]);
             }
        	printf("\n");
      		}
    	}
		//Sola döndürme komutları
    	else if(key==2)
    	{
      		for(i=row-1;i>=0;i--)
      		{
             for(j=0;j<row;j++)
             {
               printf("%d ",matris[j][i]);
             }
        	printf("\n");
	      	}
    	}
		// 1 veya 2 den farklı bir değişken girerse gecersiz işlem yazdırıyoruz
    	else
    	{
      	printf("Gecersiz islem !!!!");
    	}


	 //Malloc ile ayırdığımız rami boşalttık.
	 //Hem tanımlarken hemde boşaltırken for kullandık çünkü arraylerimiz 2 boyutlu
	 for(k=0 ; k < row ; k++)
	 {
		free(matris[k]);
	 }
		 free(matris);

    }                      
