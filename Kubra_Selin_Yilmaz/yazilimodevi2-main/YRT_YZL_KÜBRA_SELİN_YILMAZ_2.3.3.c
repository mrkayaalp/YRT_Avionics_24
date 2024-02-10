#include <stdio.h>

// Enum değerleri
enum GRange {
    G_RANGE_2G = 0,
    G_RANGE_4G,
    G_RANGE_8G,
    G_RANGE_16G
};

enum Bandwidth {
    BW_7_81_HZ = 0,
    BW_15_63_HZ,
    BW_31_25_HZ,
    BW_62_5_HZ,
    BW_125_HZ,
    BW_250_HZ,
    BW_500_HZ
};

enum OperationMode {
    NORMAL_MODE = 0,
    SUSPEND_MODE,
    LOW_POWER_MODE,
    FAST_MODE
};

// Struct yapısı
typedef struct {
    int gRange;             // İvmeölçer G Range değeri
    int bandwidth;          // İvmeölçer Bandwidth değeri
    int operationMode;      // İvmeölçer Operation Mode değeri
    int accConfigValue;     // Register'a gönderilecek AccConfigValue değeri
} IMUConfig;

// İvmeölçer konfigürasyon fonksiyonu
void configureAccelerometer(IMUConfig *config) {
    // İvmeölçer konfigürasyonu
    config->gRange = G_RANGE_8G;
    config->bandwidth = BW_125_HZ;
    config->operationMode = NORMAL_MODE;

    // AccConfigValue değerini hesapla
    config->accConfigValue = (config->gRange << 6) | (config->bandwidth << 3) | config->operationMode;
}

int main() {
    IMUConfig imuConfig;

    // İvmeölçer konfigürasyonunu yap
    configureAccelerometer(&imuConfig);

    // Sonuçları yazdır
    printf("AccConfigValue (Decimal): %d\n", imuConfig.accConfigValue);
    printf("AccConfigValue (Hexadecimal): 0x%X\n", imuConfig.accConfigValue);
    printf("AccConfigValue (Binary): ");
    
    // AccConfigValue'yi binary olarak yazdır
    for (int i = 11; i >= 0; --i) {
        printf("%d", (imuConfig.accConfigValue >> i) & 1);
    }
    printf("\n");

    return 0;
}
