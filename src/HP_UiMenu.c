#include <HP_UiMenu.h>

HP_MenuItem HP_SettingsMenu[] = {
    { .itemStr = "Activate Pairing", .active = true, .selected = true},
    { .itemStr = "Reset Connection", .active = true, .selected = false},
    { .itemStr = "Set LED Brightness", .active = true, .selected = false},
    { .itemStr = "Autotune PID", .active = true, .selected = false}
};

HP_MenuItem HP_MainMenu[] = {
    { .itemStr = "Set Temperature", .active = true, .selected = true},
    { .itemStr = "Search SD Card", .active = true, .selected = false},
    { .itemStr = "Settings", .active = true, .selected = false}
};

void HP_Ui_ShowMenu(HP_MenuItem* itemList[])
{

}