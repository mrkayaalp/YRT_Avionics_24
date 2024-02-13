#include <stdio.h>

// IVMEolcer konfigürasyon parametreleri için enum değerleri
enum GRange {
    G_2,
    G_4,
    G_8,
    G_16
};

enum Bandwidth {
    BW_7_81Hz,
    BW_15_63Hz,
    BW_31_25Hz,
    BW_62_5Hz,
    BW_125Hz,
    BW_250Hz,
    BW_500Hz,
    BW_1000Hz
};

enum OperationMode {
    NORMAL,
    SUSPEND,
    LOW_POWER1,
    STANDBY,
    LOW_POWER2,
    DEEP_SUSPEND
};

// IVMEolcer konfigürasyonunu tutacak struct yapısı
struct IVMEolcerConfig {
    enum GRange gRange;
    enum Bandwidth bandwidth;
    enum OperationMode operationMode;
    int accConfigValue; // Register'a gönderilecek değer
};

// IVMEolcer konfigürasyon değerlerini hesaplayan fonksiyon
int hesaplaAccConfigValue(struct IVMEolcerConfig config) {
    return (config.gRange << 6) | (config.bandwidth << 4) | (config.operationMode << 2);
}

int main() {
    // IVMEolcerConfig yapısı 
    struct IVMEolcerConfig config = {
        .gRange = G_4,
        .bandwidth = BW_125Hz,
        .operationMode = LOW_POWER1
    };

    // AccConfigValue değerini hesapla
    config.accConfigValue = hesaplaAccConfigValue(config);

    // Sonuçları ekrana yazdır
    printf("G Range: %d\n", config.gRange);
    printf("Bandwidth: %d\n", config.bandwidth);
    printf("Operation Mode: %d\n", config.operationMode);
    printf("AccConfigValue (Decimal): %d\n", config.accConfigValue);
    printf("AccConfigValue (Hexadecimal): 0x%X\n", config.accConfigValue);
    printf("AccConfigValue (Binary): 0b");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (config.accConfigValue >> i) & 1);
    }
    printf("\n");

    return 0;
}
