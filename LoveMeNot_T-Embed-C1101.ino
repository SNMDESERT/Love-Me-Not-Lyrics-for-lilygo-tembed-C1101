/*
 * Love Me Not OLED Lyrics animation adapted for LILYGO T-Embed-CC1101
 * Display: built-in ST7789 320x170 TFT
 * Board: ESP32-S3
 *
 * Library required: TFT_eSPI by Bodmer
 * Uses the T-Embed-CC1101 display pins from the official board configuration.
 */
#define USER_SETUP_LOADED
#define ST7789_DRIVER
#define TFT_WIDTH 170
#define TFT_HEIGHT 320
#define TFT_MISO 10
#define TFT_MOSI 9
#define TFT_SCLK 11
#define TFT_CS   41
#define TFT_DC   16
#define TFT_RST  40
#define TFT_BL   21
#define TFT_INVERSION_ON
#define USE_HSPI_PORT
#define SPI_FREQUENCY 80000000

#include <TFT_eSPI.h>
#include "animation_frames.h"

TFT_eSPI tft = TFT_eSPI();

const int TOTAL_FRAMES = 102;
const uint16_t IMG_W = 128;
const uint16_t IMG_H = 64;
const int ANIMATION_DELAY_MS = 64;
uint16_t frame565[IMG_W * IMG_H];

void setup() {
  pinMode(15, OUTPUT);      // T-Embed power enable
  digitalWrite(15, HIGH);
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  tft.init();
  tft.setRotation(3);       // landscape: 320x170
  tft.fillScreen(TFT_BLACK);
}

void loop() {
  for (int i = 0; i < TOTAL_FRAMES; i++) {
    const unsigned char* frame = epd_bitmap_allArray[i];

    // Convert Adafruit 1-bit bitmap (MSB-first) to RGB565 for TFT_eSPI.
    for (uint16_t y = 0; y < IMG_H; y++) {
      for (uint16_t x = 0; x < IMG_W; x++) {
        uint8_t b = pgm_read_byte(&frame[y * (IMG_W / 8) + (x / 8)]);
        bool on = (b & (0x80 >> (x & 7))) != 0;
        frame565[y * IMG_W + x] = on ? TFT_WHITE : TFT_BLACK;
      }
    }

    // Center the original 128x64 animation on the 320x170 display.
    tft.pushImage((320 - IMG_W) / 2, (170 - IMG_H) / 2,
                  IMG_W, IMG_H, frame565);
    delay(ANIMATION_DELAY_MS);
  }
}
