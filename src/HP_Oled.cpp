#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <HP_Settings.h>
#include <HP_Oled.h>

Adafruit_SSD1306 oled(OLED_WIDTH_PX, OLED_HEIGHT_PX);

void HP_Oled_init()
{
    Serial.println("Starting OLED");
    if(!oled.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
        Serial.println(F("SSD1306 allocation failed"));
    }

    /* Show Logo */    
    oled.clearDisplay();
    oled.setTextColor(WHITE);
    oled.setTextSize(3);
    oled.setCursor(1,0);
    oled.println("Hotty \r\nPlate");
    oled.setTextSize(1);
    oled.println("V0.1");
    oled.display();
}