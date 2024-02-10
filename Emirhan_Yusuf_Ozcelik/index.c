#include <stdio.h>

// Enum değerleri
enum G_Range {
    G_RANGE_2G = 0b00000000,
    G_RANGE_4G = 0b00000001,
    G_RANGE_8G = 0b00000010,
    G_RANGE_16G = 0b00000011
};

enum Bandwidth {
    BW_7_81_HZ = 0b00000000,
    BW_15_63_HZ = 0b00000100,
    BW_31_25_HZ = 0b00001000,
    BW_62_5_HZ = 0b00001100,
    BW_125_HZ = 0b00010000,
    BW_250_HZ = 0b00010100,
    BW_500_HZ = 0b00011000,
    BW_1000_HZ = 0b00011100
};

enum Operation_Mode {
    NORMAL_MODE = 0b00000000,
    SUSPEND_MODE = 0b00100000,
    LOW_POWER_MODE1 = 0b01000000,
    STANDBY_MODE = 0b01100000,
    LOW_POWER_MODE2 = 0b10000000,
    DEEP_SUSPEND_MODE = 0b10100000,
    AUTO_CONTROLLED_FUSION_MODE = 0b11000000
};

// Konfigürasyon parametrelerini içeren struct
struct IMU_Config {
    enum G_Range g_range;
    enum Bandwidth bandwidth;
    enum Operation_Mode operation_mode;
    unsigned char acc_config_value; // 8 bit AccConfigValue
    const char *restrictions;
};

// Konfigürasyon yapmak için fonksiyon
void configureIMU(struct IMU_Config *config) {
    // AccConfigValue hesaplaması bitwise operatörlerle yapılır
    config->acc_config_value = (config->g_range | config->bandwidth | config->operation_mode);
}

// Değerleri yazdırmak için fonksiyon
void printValues(struct IMU_Config *config) {
    printf("G Range: %02X\n", config->g_range);
    printf("Bandwidth: %02X\n", config->bandwidth);
    printf("Operation Mode: %02X\n", config->operation_mode);
    printf("AccConfigValue (Decimal): %d\n", config->acc_config_value);
    printf("AccConfigValue (Hexadecimal): %02X\n", config->acc_config_value);
    printf("AccConfigValue (Binary): ");

    for (int i = 7; i >= 0; i--) {
        printf("%d", (config->acc_config_value >> i) & 1);
    }

    printf("\nRestrictions: %s\n", config->restrictions);
    printf("\n");
}

int main() {
    // Örnek bir konfigürasyon oluştur
    struct IMU_Config imuConfig1 = {G_RANGE_8G, BW_500_HZ, NORMAL_MODE, 0, "Auto controlled in fusion mode"};
    struct IMU_Config imuConfig2 = {G_RANGE_4G, BW_250_HZ, LOW_POWER_MODE1, 0, "Auto controlled in fusion mode"};

    // Konfigürasyon yap
    configureIMU(&imuConfig1);
    configureIMU(&imuConfig2);

    // Değerleri yazdır
    printValues(&imuConfig1);
    printValues(&imuConfig2);

    return 0;
}
