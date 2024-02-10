#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>


void decimaltobinary(int sayi) {
	int i=8;
	printf("AccConfigValue= 0b");
	for (i; i >= 0; i--) {
		printf("%d", (sayi >> i) & 1);
	}
}


enum AccelRange {
	AFS_2G,
	AFS_4G,
	AFS_8G,
	AFS_16G
};

enum AccelBandwith {
	AFS_781,
	AFS_1563,
	AFS_3125,
	AFS_625,
	AFS_125,
	AFS_250,
	AFS_500,
	AFS_1000
};

enum AccelMode {
	AFS_NORMAL,
	AFS_SUSPEND,
	AFS_LOW1,
	AFS_STDBY,
	AFS_LOW2,
	AFS_DEEPSUSP

};

int main() {
	struct AccelConfig {
		uint8_t Range;
		uint8_t Bandwith;
		uint8_t Mode;
		uint8_t AccConfigValue;
	};
	struct AccelConfig config; 
	config.Range = AFS_8G ;
	config.Bandwith = AFS_500<<2;
	config.Mode = AFS_NORMAL<<5;
	config.AccConfigValue = config.Range + config.Bandwith + config.Mode;
	printf("AccConfigValue(Decimal)= %d\nAccConfigValue(Hexadecimal)= 0x%lx\n", config.AccConfigValue, config.AccConfigValue);
	decimaltobinary(config.AccConfigValue);
	return 0;
}

