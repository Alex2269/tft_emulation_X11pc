#include "vga_adafruit.h"
#include "DrawBezier.h"

void DrawBezier(float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy, uint8_t solid, uint32_t color)
{
  float step = 1.0/1000.0;
  for(float t=0; t<=1; t+=step)
  {
    float u = 1.0-t;
    float a = u*u*u;
    float b = 3.0*u*u*t;
    float c = 3.0*u*t*t;
    float d = t*t*t;
    float x = ax*a + bx*b + cx*c + dx*d;
    float y = ay*a + by*b + cy*c + dy*d;
    fillRect(x,y, solid,solid, color);
  }
}

