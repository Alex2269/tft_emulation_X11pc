#ifndef bitmap_H
#define bitmap_H

/* Include Library */
#include "stdint.h"
#include "stdbool.h"

/* static inline uint32_t
convertRGBto888(uint8_t r, uint8_t g, uint8_t b)
{
  return (r << 16) | (g << 8) | b;
} */

void drawRGBBitmap(int16_t x, int16_t y, uint8_t *bitmap);

#endif // bitmap_H


