#include <Arduino.h>
#include <HP_SysMon.hpp>
#include <HP_Types.h>
#include <HP_StatusDisplay.h>
#include <HP_Settings.h>


HP_SysMon::HP_SysMon(uint32_t _execMillis)
{
    execMillis = _execMillis;
}

HP_SysMon::~HP_SysMon()
{
    /* Delete all tasks */
    stopMon();
}

void HP_SysMon::assignMod(  const char* name, 
                            HP_ModStatus (*getStatPtr)(), 
                            bool (*faultHdlPtr)(),
                            void (*reportFPtr)(), 
                            int dispInd)
{
    HP_MonMod mod;
    mod.getStatFunPtr = getStatPtr;
    mod.faultHandlePtr = faultHdlPtr;
    mod.reportFunPtr = reportFPtr;
    mod.statusDispIndex = dispInd;

    moduleVec.push_back(mod);
    /* Copy the name */
    memcpy(moduleVec.back().name, name, strlen(name)+1);
}

bool HP_SysMon::removeMod(const char* name)
{
    for (int i = 0; i < (moduleVec.size()/sizeof(HP_MonMod))-1; i++)
    {
        if (moduleVec.at(i).name == name)
        {
            moduleVec.erase(moduleVec.begin() + i);
            return true;
        }
    }
    return false;
}

void HP_SysMon::setExecutionTime(uint32_t _execMillis)
{
    execMillis = _execMillis;
}

uint32_t HP_SysMon::getExecutionTime()
{
    return execMillis;
}

void HP_SysMon::startMon()
{
    Serial.println("Started SysMon");

    xTaskCreate(
        monSystem,
        "SysMon-Task",
        10000,
        this,
        20,
        &sysMonHandle
    );
}

void HP_SysMon::stopMon()
{
    vTaskDelete(sysMonHandle);
}

std::vector<HP_MonMod>* HP_SysMon::getModVec()
{
    return &moduleVec;
}


void monSystem(void* MonObj)
{
    HP_SysMon* monSysPtr = (HP_SysMon*) MonObj;
    std::vector<HP_MonMod>* modVecPtr = monSysPtr->getModVec();
    HP_ModStatus stat;
    while(1)
    {
        Serial.println("SM: r");
        for (int i = 0; i < (modVecPtr->size() / sizeof(HP_MonMod)); i++)
        {
            if (modVecPtr->at(i).getStatFunPtr)
            {
                stat = modVecPtr->at(i).getStatFunPtr();
                switch(stat)
                {
                    case MOD_HW_NOT_DETECTED: break;
                    case MOD_FAULT: break;
                    case MOD_NOT_INITIALIZED: break;
                    case MOD_INIT_RUNNING: break;
                    case MOD_FUNCTIONAL: break;
                }
            }
        }
        vTaskDelay(monSysPtr->getExecutionTime());
    }
}

