#include <stdio.h>

enum AccelerometerConfigurations{
    G_RANGE_2G=0b00,
    G_RANGE_4G=0b01,
    G_RANGE_8G=0b10,
    G_RANGE_16G=0b11,
    BANDWIDTH_7_81_HZ=0b000,
    BANDWIDTH_15_63_HZ=0b001,
    BANDWIDTH_31_25_HZ=0b010,
    BANDWIDTH_62_5_HZ=0b011,
    BANDWIDTH_125_HZ=0b100,
    BANDWIDTH_250_HZ=0b101,
    BANDWIDTH_500_HZ=0b110,
    BANDWIDTH_1000_HZ=0b111,
    OPERATION_MODE_NORMAL=0b000,
    OPERATION_MODE_SUSPEND=0b001,
    OPERATION_MODE_LOW_POWER_1=0b010,
    OPERATION_MODE_STANDBY=0b011,
    OPERATION_MODE_LOW_POWER_2=0b100,
    OPERATION_MODE_DEEP_SUSPEND=0b101,
};


struct IMUConfiguration {
    enum AccelerometerConfigurations gRange;
    enum AccelerometerConfigurations bandwidth;
    enum AccelerometerConfigurations operationMode;
    int accConfigValue;                              // Bitwise toplamı AccConfigValue'ya atanacak
};


void ConfigurationValues(struct IMUConfiguration config) {  //decimal, hexadecimal ve binary formatlarda ekrana YAZDIRACAĞIMIZ için void kullanıyoruz.
    printf("G Range: %d\n", config.gRange);
    printf("Bandwidth: %d\n", config.bandwidth);
    printf("Operation Mode: %d\n", config.operationMode);
    printf("AccConfigValue (Decimal): %d\n", config.accConfigValue);
    printf("AccConfigValue (Hexadecimal): 0x%X\n", config.accConfigValue);
    printf("AccConfigValue (Binary): ");
    for (int i = sizeof(config.accConfigValue) * 8 - 1; i >= 0; i--) {        /*Bu kısım, config.accConfigValue değişkeninin binary (ikili) gösterimini ekrana yazdırmak için bir döngü içinde kullanılır.
                                                                               sizeof(config.accConfigValue) ifadesi, config.accConfigValue değişkeninin bellekte kaç byte tuttuğunu verir.sizeof(config.accConfigValue) * 8 ifadesi, 
                                                                               config.accConfigValue değişkeninin kaç bit olduğunu verir.Bu işlem, config.accConfigValue değişkeninin binary gösterimindeki her bir biti başlangıçta 
                                                                               en yüksek sıradan en düşük sıraya kadar (soldan sağa doğru) ekrana yazdırır. */
        printf("%d", (config.accConfigValue >> i) & 1);                        /*Her iterasyonda, (config.accConfigValue >> i) ifadesi, config.accConfigValue değişkenini i kadar sağa kaydırarak, yani en yüksek bitin (en soldaki bitin) 
                                                                                i konumdan itibaren başlayarak incelenmesini sağlar. Daha sonra & 1 ifadesi, bu kaydırılmış değerin en düşük bitini (yani en sağdaki biti) alır.*/
    }
    printf("\n");
}


int main()
{
    // Örnek bir konfigürasyon yapısı oluşturulur
    struct IMUConfiguration config;
    config.gRange = G_RANGE_8G;
    config.bandwidth = BANDWIDTH_500_HZ;
    config.operationMode = OPERATION_MODE_NORMAL;

    // AccConfigValue hesaplanır
    config.accConfigValue = (config.gRange << 6) | (config.bandwidth << 4) | config.operationMode;

    // Konfigürasyon değerleri ekrana yazdırılır
    ConfigurationValues(config);


    return 0;
}

/*OUTPUT:
G Range: 2
Bandwidth: 6
Operation Mode: 0
AccConfigValue (Decimal): 224
AccConfigValue (Hexadecimal): 0xE0
AccConfigValue (Binary): 00000000000000000000000011100000    */
