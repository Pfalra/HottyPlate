#include <Arduino.h>
#include <stdint.h>
#include <HP_Buttons.h>

HP_Button upButton = {26, false, true, GO_UP};
HP_Button confButton = {25, false, true, CONFIRM};
HP_Button downButton = {33, false, true, GO_DOWN};

HP_Button* HP_InterfaceButtons[] = {&upButton, &confButton, &downButton, NULL};

void genericButtonIsr(HP_Button* isrButton)
{
    isrButton->pressed = true;
    isrButton->served = false;
}

void IRAM_ATTR upButtonIsr()
{
    genericButtonIsr(&upButton);
}

void IRAM_ATTR downButtonIsr()
{
    genericButtonIsr(&downButton);
}

void IRAM_ATTR confButtonIsr()
{
    genericButtonIsr(&confButton);
}

void HP_Buttons_init()
{
    pinMode(upButton.pinNumber, INPUT_PULLUP);
    pinMode(confButton.pinNumber, INPUT_PULLUP);
    pinMode(downButton.pinNumber, INPUT_PULLUP);

    attachInterrupt(upButton.pinNumber, upButtonIsr, FALLING);
    attachInterrupt(confButton.pinNumber, upButtonIsr, FALLING);
    attachInterrupt(downButton.pinNumber, downButtonIsr, FALLING);
}