#include <stdio.h>
#include <stdlib.h>

// Matrisi ekrana yazdýran fonksiyon
void print_matrix(int **matrix, int n) {
	int i,j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Matrisi saða 90 derece döndüren fonksiyon
void rotate_right(int **matrix, int n) {
	int i,j;
    // bellekte fazla yer kaplayacaðý için yeni matrisi dinamik olarak oluþturuyorum
    int **new_matrix = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        new_matrix[i] = (int *)malloc(n * sizeof(int));
    }

    // Matrisin elemanlarýný yerini deðiþtirerek yeni matrise aktarýyorum
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            new_matrix[j][n - i - 1] = matrix[i][j];
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j]=new_matrix[i][j];
        }
    }

    printf("Matrisin saga 90 derece dondurulmus hali:\n");
    print_matrix(new_matrix, n);

    // dinamik bellekte oluþturduðum matrisi iþi bitince kaldýrýyorum
    for (i = 0; i < n; i++) {
        free(new_matrix[i]);
    }
    free(new_matrix);
}

// Matrisi sola 90 derece döndüren fonksiyon
void rotate_left(int **matrix, int n) {
	int i,j;
    // bellekte fazla yer kaplayacaðý için yeni matrisi dinamik olarak oluþturuyorum
    int **new_matrix = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        new_matrix[i] = (int *)malloc(n * sizeof(int));
    }

    // Matrisin elemanlarýný yerini deðiþtirerek yeni matrise aktarýyorum
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            new_matrix[n - j - 1][i] = matrix[i][j];
        }
    }

	for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j]=new_matrix[i][j];
        }
    }
    
    printf("Matrisin sola 90 derece dondurulmus hali:\n");
    print_matrix(new_matrix, n);

    // dinamik bellekte oluþturduðum matrisi iþi bitince kaldýrýyorum
    for (i = 0; i < n; i++) {
        free(new_matrix[i]);
    }
    free(new_matrix);
}

int main() {
    int n,i,j,secim;
    int exit=1;
    printf("Matrisin boyutunu giriniz: ");
    scanf("%d", &n);

    // bellekte fazla yer kaplayacaðý için yeni matrisi dinamik olarak oluþturuyorum
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Matrisin elemanlarini giriniz:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
	
    printf("orijinal matris:\n");
    print_matrix(matrix, n);
	do{//do while ile istenen kadar döndürmeyi sağlıyorum
		printf("lutfen saga dondurmek icin 1, sola dondurmek icin 2 giriniz. cikmak istiyorsaniz 3 giriniz:");
		scanf("%d",&secim);
		switch(secim){
			case 1:
            	rotate_right(matrix, n);
				break;
		
			case 2:
				rotate_left(matrix, n);
				break;
			
			case 3:
				printf("cikis yapildi.");
				exit=0;
				break;
			default:
				printf("gecersiz harf girisi yapildi, tekrar deneyin.");
				break;
		}
	}while(exit==1);
	

    // dinamik bellekte oluþturduðum ana matrisi iþi bitince kaldýrýyorum
    for (i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

