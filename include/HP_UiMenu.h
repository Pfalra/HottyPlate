#ifndef HP_UIMENU_H
#define HP_UIMENU_H

#include <stdbool.h>

typedef struct HP_MenuItem_e
{
    char itemStr[24];
    bool active;
    bool selected;
    void* clickAction;
} HP_MenuItem;


#endif
