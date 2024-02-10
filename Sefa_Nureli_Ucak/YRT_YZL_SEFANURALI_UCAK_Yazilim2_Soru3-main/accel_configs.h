// accel_configs.h

#ifndef ACCEL_CONFIGS_H
#define ACCEL_CONFIGS_H

// AccelRange, AccelBandwidth, ve AccelOperationMode için enum'lar
enum AccelRange {
    ACCEL_RANGE_2G, // 0b00
    ACCEL_RANGE_4G, // 0b01
    ACCEL_RANGE_8G, // 0b10
    ACCEL_RANGE_16G // 0b11
};

enum AccelBandwidth {
    ACCEL_BW_7_81HZ, // 0b00 
    ACCEL_BW_15_63HZ, // 0b01
    ACCEL_BW_31_25HZ, // 0b10
    ACCEL_BW_62_5HZ, // 0b11
    ACCEL_BW_125HZ, // 0b100
    ACCEL_BW_250HZ, // 0b101
    ACCEL_BW_500HZ, // 0b110
    ACCEL_BW_1000HZ // 0b111
};

enum AccelOperationMode {
    ACCEL_MODE_NORMAL, // 0b00
    ACCEL_MODE_SUSPEND, // 0b01
    ACCEL_MODE_LOW_POWER_1, // 0b10
    ACCEL_MODE_STANDBY, // 0b11
    ACCEL_MODE_LOW_POWER_2, // 0b100
    ACCEL_MODE_DEEP_STANDBY // 0b101
};

// AccelParams struct'ı
struct AccelParams {
    enum AccelRange range;
    enum AccelBandwidth bandwidth;
    enum AccelOperationMode mode;
};

struct AccelConfigs {
    struct AccelParams params;
};

#endif // ACCEL_CONFIGS_H

