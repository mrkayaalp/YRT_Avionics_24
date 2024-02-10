// accel_configs.c

#include <stdio.h>
#include "accel_configs.h"

int main() {
    // Belirli bir Range, Bandwidth ve Operation Mode'u seçilir
    struct AccelConfigs configs = {
        .params = {ACCEL_RANGE_4G, ACCEL_BW_250HZ, ACCEL_MODE_DEEP_STANDBY}
    };

    unsigned char combinedValue = 0;
    combinedValue |= (configs.params.mode) << 5;       // Mode'u sola kaydır ve 3 bit al
    combinedValue |= (configs.params.bandwidth) << 2;  // Bandwidth'i sola kaydır ve 3 bit al
    combinedValue |= (configs.params.range);            // Range'i direkt al

    
  // Sonuçları yazdır
    printf("Combined Value (Decimal): %u\n", combinedValue);
    printf("Combined Value (Hexadecimal): 0x%02X\n", combinedValue);
    printf("Combined Value (Binary): 0b");
    
    // Binary olarak yazdırma
    for (int i = 7; i >= 0; i--) {
        printf("%d", (combinedValue >> i) & 1);
    }
    printf("\n");

    return 0;
}
