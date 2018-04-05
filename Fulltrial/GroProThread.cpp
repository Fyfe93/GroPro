#include "GroProThread.h"

typedef struct
{
    int    globalLightIntensity;
    int    globalOperationId;
    int    globalRealTimeToggle;
} GLOBDATA;

GLOBDATA globalData;


void GroProThread::run() {
    PID pid = PID(0.4, 500, 0, 0.01, 0.01, 0.008);
    Max7219driver driver;
    Opt3001 sensor;
    sensor.Write(0x45);
    driver.setColour(Max7219driver::colour::white);

    while (1)
    {
        switch (globalData.globalOperationId) {
                float lux;
                float PIDout;
            case 1:
                driver.setIntensity(globalData.globalLightIntensity);
                break;
            case 2:
                //printf("slider2");
                break;
            case 3:
                //printf("slider3");
                break;
            case 4:
                driver.setColour(Max7219driver::colour::warm);
                break;
            case 5:
                driver.setColour(Max7219driver::colour::cold);
                break;
            case 6:
                driver.setColour(Max7219driver::colour::white);
                break;
            case 7:
                lux = sensor.Read();
                PIDout = pid.calculate(3000, lux);
                PIDout = ((PIDout / 33.3));
                PIDout = (int)PIDout;
                driver.setIntensity(PIDout);
                break;
            case 8:
                lux = sensor.Read();
                PIDout = pid.calculate(3000, lux);
                PIDout = ((PIDout / 33.3));
                PIDout = (int)PIDout;
                driver.setIntensity(PIDout);
                break;
            default:
                lux = sensor.Read();
                printf ("Lux %f\n\n", lux);
                PIDout = pid.calculate(3000, lux);
                printf ("Pid Pre-Scale %f\n\n", PIDout);
                PIDout = ((PIDout / 33.3));
                PIDout = (int)PIDout;
                printf ("Pid Post-Scale %f\n\n", PIDout);
                driver.setIntensity(PIDout);
                break;
        }
        
        

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        


        
    }
}


void GroProThread::listen() {
    char* messageArray;
    messageArray = new char[50];
    GroProServer server(5002, messageArray);
    server.clear(messageArray);
    printf("Server Open");
    
    while (1)
    {
        int msg;
        ssize_t issue =  server.run(messageArray);
        sscanf(messageArray, "%d", &msg);
        
        globalData.globalOperationId = (msg % 10);
        globalData.globalLightIntensity = (int)((msg/10)/6.67);
//        printf("msg: %d\n",msg/10);
//        printf("id: %d\n",globalData.globalOperationId);
        if (globalData.globalOperationId == 7) {
            printf("Connected");
        }
        if (issue <= 0)
        {
            printf("Disconnected");
            server.clear(messageArray);
            server.reactivateServer();
            //break;
        }
        server.clear(messageArray);
        
    }
    
    delete[] messageArray;
}
