#include <vector>
#include <wiringPi.h> // Include WiringPi library!
#include <softPwm.h>

//sudo g++ pwmTest.cpp -o pwmTest -lwiringPi -lpthread to compile.


class PwmClass
{
public:
    PwmClass();
    ~PwmClass();
    void setupAllPins();
    
    //Level is from 0-100
    void setLevelAllPins(int level);
    void setLevelIrPins(int level);
    void setLevelUvPins(int level);
    
    
private:
    std::vector<int> m_assignedPinsVec{3,4,28,29,0,1,24,27};
    int m_numberOfPins{8};
    
 
};


