#ifndef HP_TYPES_H
#define HP_TYPES_H

#include <stdint.h>

#define MAX_NUM_MODULES 10
#define MAX_MODNAME_LEN 24


typedef enum HP_ModStatus_e
{
    MOD_HW_NOT_DETECTED,
    MOD_FAULT,
    MOD_NOT_INITIALIZED,
    MOD_INIT_RUNNING,
    MOD_FUNCTIONAL
} HP_ModStatus;



#endif