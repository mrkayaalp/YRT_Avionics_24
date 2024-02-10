#include <stdio.h>
#include <stdlib.h>

// Struct tanımı
struct accelerometer
{
    enum grange {
        g2 = 0,
        g4 = 1,
        g8 = 2,
        g16 = 3
    };

    enum band_width {
        hz781 = 0,
        hz1563 = 1,
        hz3125 = 2,
        hz625 = 3,
        hz125 = 4,
        hz250 = 5,
        hz500 = 6,
        hz1000 = 7
    };

    enum operation_mode {
        normal = 0,
        suspend = 1,
        low_power1 = 2,
        standby = 3,
        low_power2 = 4,
        deep_suspend = 5
    };

    enum grange gr;
    enum band_width bw;
    enum operation_mode mode;
};

// Fonksiyon tanımı
char* intToBinaryString(int value, int numBits);

int main()
{
    struct accelerometer sensor;

    // Kullanıcıdan giriş alınması
    printf("Lutfen sensorunuzun grange degerini seciniz:\n");
    printf("2G icin 0\n");
    printf("4G icin 1\n");
    printf("8G icin 2\n");
    printf("16G icin 3\nBir deger giriniz: ");
    scanf("%d", (int*)&sensor.gr);

    printf("\nLutfen sensorunuzun Band Width degerini seciniz:\n");
    printf("7.81Hz icin 0\n");
    printf("15.63Hz icin 1\n");
    printf("31.25Hz icin 2\n");
    printf("62.5Hz icin 3\n");
    printf("125Hz icin 4\n");
    printf("250Hz icin 5\n");
    printf("500Hz icin 6\n");
    printf("1000Hz icin 7\nBir deger giriniz: ");
    scanf("%d", (int*)&sensor.bw);

    printf("\nLutfen sensorunuzun Operation Mode degerini seciniz:\n");
    printf("normal icin 0\n");
    printf("suspend icin 1\n");
    printf("low_power1 icin 2\n");
    printf("standby icin 3\n");
    printf("low_power2 icin 4\n");
    printf("deep_suspend icin 5\nBir deger giriniz: ");
    scanf("%d", (int*)&sensor.mode);

    // Enum değerlerini birleştirip binary olarak yazdırma
    int combinedValue = (sensor.mode << 5) | (sensor.bw << 2) | sensor.gr;

    // Tüm değerleri yazdırma
    printf("\nSecilen Degerler:\n");
    printf("Grange: %d\n", sensor.gr);
    printf("Band Width: %d\n", sensor.bw);
    printf("Operation Mode: %d\n", sensor.mode);
    
    // Binary değeri string olarak al ve yazdır
    char* binaryString = intToBinaryString(combinedValue, 8);
    printf("Combined Binary: 0b%s\n", binaryString);

    printf("Decimal: %d\n", combinedValue);
    printf("Hexadecimal: 0x%x\n", combinedValue);

    // Belleği serbest bırak
    free(binaryString);

    return 0;
}

// Fonksiyon tanımı
char* intToBinaryString(int value, int numBits)
{
    // Ayrılacak bellek miktarını hesapla ve bellek bloğunu ayır
    char* binaryString = (char*)malloc(numBits + 1);

    // Her bir bit için dön
    for (int i = numBits - 1; i >= 0; --i)
    {
        // İlgili biti al ve karaktere dönüştür, ardından ikili dizeye ekle
        binaryString[numBits - i - 1] = ((value >> i) & 1) + '0';
    }

    // Dizeyi sonlandır
    binaryString[numBits] = '\0';

    // Dönüştürülmüş ikili dizeyi geri döndür
    return binaryString;
}
