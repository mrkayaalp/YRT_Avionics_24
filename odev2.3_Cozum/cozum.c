#include <stdio.h>
#include <stdint.h>

typedef enum
{ // g range'in enum tanımlaması
    ASF_2G ,
    ASF_4G,
    ASG_8G,
    ASF_16G
} GRange;

typedef enum
{ // banwidth'in enum tanımlaması
    Hz_7,
    Hz_15,
    Hz_31,
    Hz_62,
    Hz_125,
    Hz_250,
    Hz_500,
    Hz_1000 
} Bandwidth;

typedef enum
{ // operation Mode' un enum tanımlaması
    normal,
    suspend,
    lowPower_1,
    standby,
    lowPower_2,
    deepSuspend
} OperationMode;

typedef struct
{
    uint8_t  gRange;
    uint8_t  bandwidth;
    uint8_t  operationMode;
    uint8_t  accConfigValue;
} AccValue;

int main()
{
    AccValue accValue = {ASF_2G, Hz_125, normal, 0x00};
    accValue.accConfigValue = (accValue.gRange) | (accValue.bandwidth << 2) | (accValue.operationMode << 5);
    printf("%d\n", accValue.bandwidth);
    return 0;
}
