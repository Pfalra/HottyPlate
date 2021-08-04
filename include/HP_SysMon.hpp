#ifndef HP_SYSMONITOR_H
#define HP_SYSMONITOR_H

#include <stdint.h>
#include <Arduino.h>
#include <HP_Types.h>

typedef struct 
{
    char name[24];
    HP_ModStatus (*getStatFunPtr)();
    bool (*faultHandlePtr)();
    void (*reportFunPtr)();
    int statusDispIndex; // TODO: Find a way to make SysMon independent of the LEDs. Negative indexes are not displayed
} HP_MonMod;

/* The param will be the object that started the monitoring */
void showStatus(void* MonObj);
void monSystem(void* MonObj);

class HP_SysMon
{
    private:
    /* Variables */ 
    std::vector<HP_MonMod> moduleVec;

    TaskHandle_t sysStatusShowHandle;
    TaskHandle_t sysMonHandle;

    uint32_t execMillis;
    
    public:
    /* Constructors */
    HP_SysMon(uint32_t _execMillis);

    /* Desctructor */
    ~HP_SysMon();

    /* Functions */
    void assignMod( const char* name, 
                    HP_ModStatus (*getStatPtr)(), 
                    bool (*faultHdlPtr)(),
                    void (*reportFPtr)(), 
                    int dispInd = -1);

    bool removeMod(const char* name);

    void startMon();
    void stopMon();

    void setExecutionTime(uint32_t _execMillis);
    uint32_t getExecutionTime();

    std::vector<HP_MonMod>* getModVec();
};


#endif