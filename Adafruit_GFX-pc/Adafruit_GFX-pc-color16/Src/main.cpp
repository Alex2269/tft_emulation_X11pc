#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <limits.h>

#include "gfx.h"
#include "Adafruit_GFX.hpp"
#include "color.h"
#include "wiring_time.h"

#include "graphicstest.h"

#define delay(a) usleep(a*1000)

/**
*
* ┌───────────────────┬───────────────┬─────────┐
* │ Interface         │ Attribute     │  Value  │
* ├───────────────────┼───────────────┼─────────┤
* │ usleep()          │ Thread safety │ MT-Safe │
* └───────────────────┴───────────────┴─────────┘
*
**/

Adafruit_GFX tft = Adafruit_GFX(640, 480);

int main(void)
{
  gfx_open(tft.width(),tft.height(),"tft emulation");
  sinus_fill();

  while(1)
  {
    tft.fillScreen(BLACK);
    for(int16_t i=16;i<tft.width()-16;i++) {
      if( !(i % 32) ) draw_dynamic_grid(i-33);
    }
    sinusoide_draw(); gfx_flush(); sleep(1);
    testText(); gfx_flush(); sleep(1);
    testLines(CYAN); gfx_flush(); sleep(1);
    testFilledCircles(10, MAGENTA); gfx_flush(); sleep(1);
    testCircles(10, WHITE); gfx_flush(); sleep(1);
    testTriangles(); gfx_flush(); sleep(1);
    testFilledTriangles();
    draw_dot_grid(); gfx_flush(); sleep(1);
    testRoundRects(); gfx_flush(); sleep(1);
    testFilledRoundRects();
    draw_dot_grid(); gfx_flush(); sleep(1);
  }

  gfx_flush(); // update the graphics
  usleep(4e5);
}

