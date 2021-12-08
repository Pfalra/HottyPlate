#ifndef HP_UIMENU_H
#define HP_UIMENU_H

#include <stdbool.h>
#include <stdint.h>

#define MAX_MENUSTR_LEN 24
#define MAX_MENUITEM_LEN 10

/* TODO: Make max number of menuitems dependent on the textsize */



typedef struct HP_MenuItem_e
{
    char itemStr[MAX_MENUSTR_LEN];
    bool active;
    bool selected;
    void (*clickAction)();
    uint8_t textSize;
} HP_MenuItem;

void HP_Ui_ShowMainMenu();
void HP_Ui_ShowSettingsMenu();

#endif
