#include <wiringPiSPI.h>
#include <thread>

//SPI Channel is either 0 or 1
//Clock speed for MAX7219 is 10MHz

#define SPI_CHANNEL 0
#define CLOCK_SPEED 10000000

//Define Max7221 Registers

#define DIGIT_0      0x01
#define DIGIT_1      0x02
#define DIGIT_2      0x03
#define DIGIT_3      0x04
#define DIGIT_4      0x05
#define DIGIT_5      0x06
#define DIGIT_6      0x07
#define DIGIT_7      0x08
#define DECODE_MODE  0x09
#define INTENSITY    0x0a
#define SCAN_LIMIT   0x0b
#define SHUTDOWN     0x0c
#define DISPLAY_TEST 0x0f

class Max7219driver
{
public:
	Max7219driver();
	~Max7219driver();
	void setColour(int colour);
	void setIntensity(int  intensityLevel);
	void setAllLedsOn(bool isOn);
	void reset();

	enum colour
	{
		white = 0,
		red,
		green,
		blue,
		yellow,
		turqoise,
		purple,
		warm,
		cold
	};

private:

	unsigned char  addrRegBuffer[2];
	int bufferSize {8};

	void write(unsigned char* addrRegBuffer, size_t bufferSize)
	{
        unsigned char tempAddrBuffer[8];
        tempAddrBuffer[0] = addrRegBuffer[0];
        tempAddrBuffer[1] = addrRegBuffer[1];
        tempAddrBuffer[2] = addrRegBuffer[0];
        tempAddrBuffer[3] = addrRegBuffer[1];
        tempAddrBuffer[4] = addrRegBuffer[0];
        tempAddrBuffer[5] = addrRegBuffer[1];
        tempAddrBuffer[6] = addrRegBuffer[0];
        tempAddrBuffer[7] = addrRegBuffer[1];

        wiringPiSPIDataRW(SPI_CHANNEL, tempAddrBuffer, sizeof (tempAddrBuffer));

				// tempAddrBuffer[0] = 0x00;
				// tempAddrBuffer[1] = 0x00;
				// tempAddrBuffer[2] = 0x00;
				// tempAddrBuffer[3] = 0x00;
				// tempAddrBuffer[4] = addrRegBuffer[0];
				// tempAddrBuffer[5] = addrRegBuffer[1];
				// tempAddrBuffer[6] = 0x00;
				// tempAddrBuffer[7] = 0x00;
				//
        // wiringPiSPIDataRW(SPI_CHANNEL, tempAddrBuffer, sizeof (tempAddrBuffer));



//        pinMode (14, OUTPUT);


        //printf("%d\n", addrRegBuffer[0] );
        //printf("%d\n", addrRegBuffer[1] );

//        digitalWrite(10,LOW);

// //      Arduino Writing Method
// 					 int maxNr = 4;
// 					 int maxInUse = 4;
//         int c = 0;
// 				//NO-OPS
// 				for (maxNr = 4; maxNr>0; c--)
// 				{
//         	for (c = maxInUse; c> maxNr; c--)
//         	{
//             	wiringPiSPIDataRW(SPI_CHANNEL, tempAddrBuffer, sizeof (tempAddrBuffer));
// 					}
//
// 					wiringPiSPIDataRW(SPI_CHANNEL, addrRegBuffer, sizeof (addrRegBuffer));
// 					//NO OPS
// 					for (c = maxNr - 1; c>= 1; c--)
// 					{
// 						wiringPiSPIDataRW(SPI_CHANNEL, tempAddrBuffer, sizeof (tempAddrBuffer));
// 					}
//          }
//            unsigned char i = 8;
//            unsigned char mask;
//            while(i> 0)
//            {
//                mask = 0x01 << (i -1);
//                digitalWrite(14, LOW);
//                if (tempAddrBuffer[0] & mask) {
//                    digitalWrite(12, HIGH);
//                }else{
//                    digitalWrite(12, LOW);
//                }
//                digitalWrite(14, HIGH);
//                --i;
//            }
//
//            i = 8;
//            while(i> 0)
//            {
//                mask = 0x01 << (i -1);
//                digitalWrite(14, LOW);
//                if (tempAddrBuffer[1] & mask) {
//                    digitalWrite(12, HIGH);
//                }else{
//                    digitalWrite(12, LOW);
//                }
//                digitalWrite(14, HIGH);
//                --i;
//            }

        //REG AND DATA
//        unsigned char i = 8;
//        unsigned char mask;
//        while(i> 0)
//        {
//            mask = 0x01 << (i -1);
//            digitalWrite(14, LOW);
//            if (addrRegBuffer[0] & mask) {
//                digitalWrite(12, HIGH);
//            }else{
//                digitalWrite(12, LOW);
//            }
//            digitalWrite(14, HIGH);
//            --i;
//        }
//
//        i = 8;
//        while(i> 0)
//        {
//            mask = 0x01 << (i -1);
//            digitalWrite(14, LOW);
//            if (addrRegBuffer[1] & mask) {
//                digitalWrite(12, HIGH);
//            }else{
//                digitalWrite(12, LOW);
//            }
//            digitalWrite(14, HIGH);
//            --i;
//        }


//            unsigned char i = 8;
//            unsigned char mask;
//            while(i> 0)
//            {
//                mask = 0x01 << (i -1);
//                digitalWrite(14, LOW);
//                if (tempAddrBuffer[0] & mask) {
//                    digitalWrite(12, HIGH);
//                }else{
//                    digitalWrite(12, LOW);
//                }
//                digitalWrite(14, HIGH);
//                --i;
//            }
//
//            i = 8;
//            while(i> 0)
//            {
//                mask = 0x01 << (i -1);
//                digitalWrite(14, LOW);
//                if (tempAddrBuffer[1] & mask) {
//                    digitalWrite(12, HIGH);
//                }else{
//                    digitalWrite(12, LOW);
//                }
//                digitalWrite(14, HIGH);
//                --i;
//            }

//        digitalWrite(14,LOW);
//        digitalWrite(14,HIGH);


       // wiringPiSPIDataRW(SPI_CHANNEL, tempAddrBuffer, sizeof (tempAddrBuffer));
       // wiringPiSPIDataRW(SPI_CHANNEL, tempAddrBuffer, sizeof (tempAddrBuffer));
       // wiringPiSPIDataRW(SPI_CHANNEL, addrRegBuffer, sizeof (addrRegBuffer));
			 //
       // wiringPiSPIDataRW(SPI_CHANNEL, tempAddrBuffer, sizeof (tempAddrBuffer));
       // wiringPiSPIDataRW(SPI_CHANNEL, tempAddrBuffer, sizeof (tempAddrBuffer));
       // wiringPiSPIDataRW(SPI_CHANNEL, addrRegBuffer, sizeof (addrRegBuffer));
       // wiringPiSPIDataRW(SPI_CHANNEL, tempAddrBuffer, sizeof (tempAddrBuffer));
			 //
       // wiringPiSPIDataRW(SPI_CHANNEL, tempAddrBuffer, sizeof (tempAddrBuffer));
       // wiringPiSPIDataRW(SPI_CHANNEL, addrRegBuffer, sizeof (addrRegBuffer));
       // wiringPiSPIDataRW(SPI_CHANNEL, tempAddrBuffer, sizeof (tempAddrBuffer));
       // wiringPiSPIDataRW(SPI_CHANNEL, tempAddrBuffer, sizeof (tempAddrBuffer));
			 //
       // wiringPiSPIDataRW(SPI_CHANNEL, addrRegBuffer, sizeof (addrRegBuffer));
       // wiringPiSPIDataRW(SPI_CHANNEL, tempAddrBuffer, sizeof (tempAddrBuffer));
       // wiringPiSPIDataRW(SPI_CHANNEL, tempAddrBuffer, sizeof (tempAddrBuffer));
       // wiringPiSPIDataRW(SPI_CHANNEL, tempAddrBuffer, sizeof (tempAddrBuffer));
		 }
};
