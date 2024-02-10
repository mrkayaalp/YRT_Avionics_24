enum GRange {
    
    G_RANGE_2G = 0, //xxxxxx00b     //Girdilerin binary hallerinin decimal karşılıklarıyla eşleştir
    G_RANGE_4G = 1, //xxxxxx01b
    G_RANGE_8G = 2, //xxxxxx10b
    G_RANGE_16G =3, //xxxxxx11b
};
enum Bandwidth {
    
    BANDWIDTH_7_81_HZ = 0,   //xxx000xxb
    BANDWIDTH_15_63_HZ = 4,  //xxx001xxb
    BANDWIDTH_31_25_HZ = 8,  //xxx010xxb
    BANDWIDTH_62_5_HZ = 12,  //xxx011xxb
    BANDWIDTH_125_HZ = 16,   //xxx100xxb
    BANDWIDTH_250_HZ = 20,   //xxx101xxb
    BANDWIDTH_500_HZ = 24,   //xxx110xxb
    BANDWIDTH_1000_HZ = 28,  //xxx111xxb
};
enum OperationMode {
    
    OPERATION_MODE_NORMAL = 0,          //000xxxxxb
    OPERATION_MODE_SUSPEND = 32,        //001xxxxxb
    OPERATION_MODE_LOW_POWER_1 = 64,    //010xxxxxb
    OPERATION_MODE_STANDBY = 96,        //011xxxxxb
    OPERATION_MODE_LOW_POWER_2 = 128,   //100xxxxxb
    OPERATION_MODE_DEEP_SUSPEND = 160,  //101xxxxxb
}; 

//Soruda istenildiği gibi enum değerleri struct yapısında tuttum
struct SensorConfig {
    enum GRange gRange;
    enum Bandwidth bandwidth;
    enum OperationMode operationMode;
    int accConfigValue; 
};