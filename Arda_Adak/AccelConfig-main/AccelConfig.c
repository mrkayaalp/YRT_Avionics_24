#include <stdio.h>
#include "AccelConfigLib.c"


// Fonksiyonun prototipi
void decimalToBinary8Bit(int num);

int main() {
    
    //Değerleri ödevden istenildiği gibi yanyana alabilmek için "OR" bitwise operatörünü kullandım
    int AccConfigValue = G_RANGE_8G | BANDWIDTH_500_HZ | OPERATION_MODE_NORMAL;

    printf("AccConfigValue(Decimal): %d\n", AccConfigValue); //Decimal çıktı alma
    printf("AccConfigValue(Hexadecimal): %#X\n", AccConfigValue); //"%x" belirteci ile hexadecimal çıktı alma.
    printf("AccConfigValue(Binary): "); //Binary çıktı alma
    
    // Fonksiyon çağrısı
    decimalToBinary8Bit(AccConfigValue);

    return 0;
}

// Fonksiyon tanımı

void decimalToBinary8Bit(int num) {
    int binaryNum[8]; // 8 bit binary representation
    int i = 0;

    while (num > 0) {
        binaryNum[i++] = num % 2;
        num /= 2;
    }

    // Padding zeros to make it 8 digits
    while (i < 8) {
        binaryNum[i++] = 0;
    }

    // Printing array in reverse order.
    printf("0b");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}
