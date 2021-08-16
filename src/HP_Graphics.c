#include <stdint.h>
#include <pgmspace.h>

#include <HP_Graphics.h>

#pragma once

PROGMEM const uint8_t myHPLogo[]  = {
  0b00000000,0b00000000,0b00000000,0b00011100,0b00000000,0b00100000,0b00000000,0b00111000,0b00000000,0b00110000,0b00000000,0b01100000,0b00000001,0b10000000,0b00000000,0b00000000,
  0b00000000,0b00000000,0b00000000,0b00001110,0b00000000,0b01110000,0b00000000,0b00011100,0b00000000,0b00111000,0b00000000,0b01110000,0b00000001,0b10000000,0b00000000,0b00000000,
  0b00000000,0b00000000,0b00000000,0b00001111,0b10000000,0b00111000,0b00000000,0b00001110,0b00000000,0b00011100,0b00000000,0b00111000,0b00000001,0b11000000,0b00000000,0b00000000,
  0b00000000,0b00000000,0b00000000,0b00000111,0b10000000,0b00011000,0b00000000,0b00000110,0b00000000,0b00001100,0b00000000,0b00011100,0b00000000,0b11100000,0b00000000,0b00000000,
  0b00000000,0b00000000,0b00000000,0b00000001,0b11000000,0b00011100,0b00000000,0b00000111,0b00000000,0b00001110,0b00000000,0b00001100,0b00000000,0b01100000,0b00000000,0b00000000,
  0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b00001110,0b00000000,0b00000011,0b00000000,0b00000110,0b00000000,0b00001110,0b00000000,0b01110000,0b00000000,0b00000000,
  0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b00000110,0b00000000,0b00000011,0b00000000,0b00000111,0b00000000,0b00000110,0b00000000,0b00110000,0b00000000,0b00000000,
  0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b00000111,0b00000000,0b00000011,0b00000000,0b00000011,0b00000000,0b00000110,0b00000000,0b00110000,0b00000000,0b00000000,
  0b00000000,0b00000000,0b00000000,0b00000000,0b01110000,0b00000011,0b00000000,0b00000011,0b00000000,0b00000011,0b00000000,0b00000110,0b00000000,0b00110000,0b00000000,0b00000000,
  0b00000000,0b00000000,0b00000000,0b00000000,0b01110000,0b00000011,0b00000000,0b00000111,0b00000000,0b00000011,0b00000000,0b00000110,0b00000000,0b00110000,0b00000000,0b00000000,
  0b00000000,0b00000000,0b00000000,0b00000000,0b01110000,0b00000011,0b00000000,0b00000110,0b00000000,0b00000011,0b00000000,0b00000110,0b00000000,0b00110000,0b00000000,0b00000000,
  0b00000000,0b00000000,0b00000000,0b00000000,0b01110000,0b00000011,0b00000000,0b00000110,0b00000000,0b00000011,0b00000000,0b00000110,0b00000000,0b00110000,0b00000000,0b00000000,
  0b00000000,0b00000000,0b00000000,0b00000000,0b01100000,0b00000011,0b00000000,0b00001110,0b00000000,0b00000111,0b00000000,0b00001110,0b00000000,0b01110000,0b00000000,0b00000000,
  0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b00000011,0b00000000,0b00011100,0b00000000,0b00000110,0b00000000,0b00001100,0b00000000,0b01100000,0b00000000,0b00000000,
  0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b00000111,0b00000000,0b00111000,0b00000000,0b00000110,0b00000000,0b00001100,0b00000000,0b01100000,0b00000000,0b00000000,
  0b00000000,0b00000000,0b00000000,0b00000001,0b11000000,0b00001110,0b00000000,0b01110000,0b00000000,0b00001110,0b00000000,0b00001100,0b00000000,0b11100000,0b00000000,0b00000000,
  0b00000000,0b00000000,0b00000000,0b00000011,0b11000000,0b00001100,0b00000000,0b11100000,0b00000000,0b00001100,0b00000000,0b00011100,0b00000000,0b11000000,0b00000000,0b00000000,
  0b00001111,0b11111111,0b00000000,0b00000011,0b10000000,0b00011100,0b00000000,0b11000000,0b00000000,0b00011100,0b00000000,0b00111000,0b00000001,0b11000000,0b00000000,0b00000000,
  0b00111000,0b00000001,0b11000000,0b00000111,0b00000000,0b00111000,0b00000001,0b11000000,0b00000000,0b00111000,0b00000000,0b01110000,0b00000011,0b10000000,0b00000000,0b00000000,
  0b01100000,0b00000000,0b01100000,0b00001110,0b00000000,0b01110000,0b00000011,0b10000000,0b00000000,0b11110000,0b00000000,0b01100000,0b00000111,0b00000000,0b00000000,0b00000000,
  0b11000000,0b00000000,0b00110000,0b00011000,0b00000000,0b11100000,0b00000111,0b00000000,0b00000001,0b11100000,0b00000001,0b11100000,0b00001110,0b00000000,0b00000000,0b00000000,
  0b10000000,0b00000000,0b00010000,0b01111000,0b00000001,0b11000000,0b00000110,0b00000000,0b00000011,0b10000000,0b00000011,0b11000000,0b00011100,0b00000000,0b00000000,0b00000000,
  0b10000000,0b00000000,0b00010000,0b01110000,0b00000011,0b10000000,0b00001110,0b00000000,0b00000111,0b00000000,0b00000111,0b00000000,0b00011000,0b00000000,0b00000000,0b00000000,
  0b00000000,0b00000000,0b00000000,0b11100000,0b00000011,0b00000000,0b00011100,0b00000000,0b00001110,0b00000000,0b00000110,0b00000000,0b00111000,0b00000000,0b00000000,0b00000000,
  0b00000000,0b11110000,0b00000000,0b11100000,0b00000111,0b00000000,0b00011000,0b00000000,0b00011100,0b00000000,0b00001110,0b00000000,0b00110000,0b00000000,0b00000000,0b00000000,
  0b00001111,0b10011110,0b00000000,0b11100000,0b00000110,0b00000000,0b00111000,0b00000000,0b00011000,0b00000000,0b00001100,0b00000000,0b00110000,0b00000000,0b00000000,0b00000000,
  0b00011000,0b00000011,0b00000000,0b11100000,0b00000110,0b00000000,0b00110000,0b00000000,0b00011000,0b00000000,0b00001100,0b00000000,0b00110000,0b00000000,0b00000000,0b00000000,
  0b00110000,0b00000001,0b10000000,0b01100000,0b00000110,0b00000000,0b00111000,0b00000000,0b00011000,0b00000000,0b00001110,0b00000000,0b00111000,0b00000000,0b00000000,0b00000000,
  0b01100000,0b00000000,0b11000000,0b00110000,0b00000110,0b00000000,0b00011000,0b00000000,0b00011100,0b00000000,0b00000110,0b00000000,0b00011110,0b00000000,0b00000000,0b00000000,
  0b01000000,0b00000000,0b01000000,0b00111000,0b00000111,0b10000000,0b00011110,0b00000000,0b00001110,0b00000000,0b00000111,0b00000000,0b00001111,0b10000000,0b00000000,0b00000000,
  0b00000111,0b11111000,0b00000000,0b00011100,0b00000011,0b11000000,0b00001111,0b00000000,0b00000111,0b10000000,0b00000011,0b11000000,0b00000011,0b11000000,0b00000000,0b00000000,
  0b00001100,0b00001100,0b00000000,0b00001100,0b00000000,0b11100000,0b00000011,0b10000000,0b00000011,0b11110000,0b00000001,0b11100000,0b00000000,0b11100000,0b00000000,0b00000000,
  0b00011000,0b00000110,0b00000000,0b00000000,0b00000000,0b01100000,0b00000001,0b10000000,0b00000000,0b11111000,0b00000000,0b01110000,0b00000000,0b01110000,0b00000000,0b00000000,
  0b00010000,0b00000010,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,
  0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,
  0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,
  0b00001111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11100000,
  0b00011111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11110000,
  0b00111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111000,
  0b01111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111100,
  0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111110,
  0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,
  0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,
  0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,
  0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,
  0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,
  0b11111111,0b11111111,0b11111000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00011111,0b11111111,0b11111111,
  0b11111111,0b11111111,0b11100000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000111,0b11111111,0b11111111,
  0b11111111,0b11111111,0b11000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000011,0b11111111,0b11111111,
  0b11111111,0b11111111,0b10000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000001,0b11111111,0b11111111,
  0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,
  0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000111,0b00001110,0b11111110,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,
  0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000111,0b00001110,0b11000011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,
  0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000111,0b00001110,0b11000001,0b10000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,
  0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000111,0b00001110,0b11000001,0b10000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,
  0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000111,0b11111110,0b11000011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,
  0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000111,0b11111110,0b11111110,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,
  0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000111,0b00001110,0b11000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,
  0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000111,0b00001110,0b11000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,
  0b01111111,0b11111110,0b00000000,0b00000000,0b00000000,0b00000000,0b00000111,0b00001110,0b11000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b01111111,0b11111110,
  0b00111111,0b11111100,0b00000000,0b00000000,0b00000000,0b00000000,0b00000111,0b00001110,0b11000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00111111,0b11111100,
  0b00011111,0b11111000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000111,0b00001110,0b11000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00011111,0b11111000,
  0b00001111,0b11110000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00001111,0b11110000,
  0b00000111,0b11100000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000111,0b11100000
};
