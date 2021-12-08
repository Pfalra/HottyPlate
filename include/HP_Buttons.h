#ifndef HP_BUTTONS_H
#define HP_BUTTONS_H

#include <stdint.h>

typedef enum HP_ButtonAction_e
{
    NONE,
    GO_UP,
    GO_DOWN,
    GO_LEFT,
    GO_RIGHT,
    CONFIRM
} HP_ButtonAction;

typedef struct HP_Button_s
{
    const uint8_t pinNumber;
    bool pressed;
    bool served;
    HP_ButtonAction action;
} HP_Button;


void HP_Buttons_init();

#endif 
