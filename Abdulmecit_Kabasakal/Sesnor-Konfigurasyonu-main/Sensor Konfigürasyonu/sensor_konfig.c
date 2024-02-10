#include <stdio.h>

enum gRange{  //g range'in enum tanımlaması
    ASF_2G,
    ASF_4G,
    ASG_8G,  
    ASF_16G,
};
enum bandwidth{  //banwidth'in enum tanımlaması
    Hz_7,
    Hz_15,
    Hz_31,
    Hz_62,
    Hz_125, 
    Hz_250,
    Hz_500,
    Hz_1000,
};
enum operationMode{  //operation Mode' un enum tanımlaması
    normal,
    suspend,
    lowPower_1,
    standby,   
    lowPower_2,
    deepSuspend,
};
struct IMUConfig{ // IMU konfigürasyonu içeren struct yapısı
    enum gRange gRange;
    enum bandwidth bandwidth;
    enum operationMode operationMode;
    unsigned char accConfigValue;
};
//IMU konfigürasyon değerini hesaplayan fonksiyon
unsigned char Hesapla(enum gRange range, enum bandwidth bw, enum operationMode opMode){
    return ((range<<5)|(bw<<2)|opMode);
}
int main(){
    struct IMUConfig configuration = {ASF_4G, Hz_31, lowPower_2, 0}; //istenilen seçenekleri giriniz

    configuration.accConfigValue = Hesapla(configuration.gRange, configuration.bandwidth, configuration.operationMode);

    printf("AccConfigValue (Decimal): %d\n",configuration.accConfigValue);
    printf("AccConfigValue (Hexadecimal): 0x%02x\n",configuration.accConfigValue);
    printf("AccConfigValue (Binary) : ");
    //binary formatı ekrana yazdırma
    for (int i=7;i>=0;i--){
        printf("%d",(configuration.accConfigValue>>i)&1);
    }
    printf("\n");
    return 0;
}