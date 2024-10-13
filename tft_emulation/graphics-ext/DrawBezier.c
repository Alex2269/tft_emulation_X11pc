#include "vga_adafruit.h"
#include "DrawBezier.h"

// stackoverflow.com/questions/12430016/bezier-drawing-routine-to-fixed-point-how-to-rewrite

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

void DrawBezierFX(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy, uint8_t solid, uint32_t color)
{
  for(unsigned i=0; i<=1024; i+=1)
  {
    unsigned t = i<<5;
    unsigned u = (1024-i)<<5;
    unsigned a = ((((u*u)>>15)*u)>>15);
    unsigned b = ((((t*u)>>15)*u)>>15)*3;
    unsigned c = ((((t*t)>>15)*u)>>15)*3;
    unsigned d = ((((t*t)>>15)*t)>>15);
    int x = ax*a + bx*b + cx*c + dx*d;
    int y = ay*a + by*b + cy*c + dy*d;
    fillRect(x>>15 ,y>>15, solid,solid, color);
  }
}

