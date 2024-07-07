#include "vga_adafruit.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <limits.h>

#include "color.h"
#include "fonts_all_includes.h"
#include "c_images_all_includes.h"
#include "lissajous.h"
#include "fill_polygon.h"
#include "DrawBezier.h"

#define WIDTH 800
#define HEIGHT 480

#define delay(a) usleep(a*1000)


void draw_window(void)
{
  // osMutexWait(Display_MutexHandle, osWaitForever); // mutex on

  // draw petals/leaf`s left top - for fun
  for(float a = 0; a <6.28318530718; a += 0.01)
  {
   for(float r1 = 2; r1 <18; r1 ++)
   {
    float r = r1 * (1 + sin(a)) * (1 + 0.9 * cos(8 * a)) * (1 + 0.1 * cos(24 * a));
    fillRect(180-(uint16_t)(100 + r * cos(a)), 190 - (uint16_t)(100 + r * sin(a)),3,3, GREEN);
   }
  }
  for(float a = 0; a <6.28318530718; a += 0.01)
  {
    float r = 18 * (1 + sin(a)) * (1 + 0.9 * cos(8 * a)) * (1 + 0.1 * cos(24 * a));
    fillRect(180-(uint16_t)(100 + r * cos(a)), 190 - (uint16_t)(100 + r * sin(a)),3,3, OLIVE);
  }

  fillRoundRect(8, Display_Get_HEIGHT()-42, Display_Get_WIDTH()-15, 36, 6, DARKBLUE);

  setTextSize(1);
  setCursor(60, Display_Get_HEIGHT()-40);
  setTextColor(CYAN);
  setTextBgColor(DARKBLUE);
  UG_FONT_set(&font_ClearSans_36X38);
  UG_PutString("STATUS BAR TEST");
  UG_FONT_set(&font_BebasNeue_41X59);

  drawRoundRect(6, Display_Get_HEIGHT()-43, Display_Get_WIDTH()-11, 38, 6, RED);

  drawRoundRect(1, 5, Display_Get_WIDTH()-2, Display_Get_HEIGHT()-6,  10, BLUE);
  drawRoundRect(2, 6, Display_Get_WIDTH()-4, Display_Get_HEIGHT()-8,  10, YELLOW);
  drawRoundRect(3, 7, Display_Get_WIDTH()-6, Display_Get_HEIGHT()-10, 10, CYAN);
  drawRoundRect(4, 8, Display_Get_WIDTH()-8, Display_Get_HEIGHT()-12, 10, MAGENTA);

  // drawRoundRect(97,  9, 76, 92, 8, RED);
  // drawRoundRect(98, 10, 74, 90, 8, GREEN);
  // drawRoundRect(99, 11, 72, 88, 8, CYAN);

  #define left 302
  #define win_width 162
  fillRoundRect(left+3, 11, win_width+2, 88, 8, DARKSLATEGRAY);
  drawRoundRect(left+1,  9, win_width+6, 92, 8, RED);
  drawRoundRect(left+2, 10, win_width+4, 90, 8, GREEN);
  drawRoundRect(left+3, 11, win_width+2, 88, 8, CYAN);


  #define y_set 112
  drawRoundRect(5, y_set+1, Display_Get_WIDTH()-10,  y_set+8, 8, RED);
  drawRoundRect(6, y_set+2, Display_Get_WIDTH()-12,  y_set+6, 8, GREEN);
  drawRoundRect(7, y_set+3, Display_Get_WIDTH()-14,  y_set+4, 8, CYAN);
  fillRoundRect(8, y_set+4, Display_Get_WIDTH()-15,  y_set+2, 8, SADDLEBROWN);
  // osMutexRelease(Display_MutexHandle); // mutex off
}

void dial_arc(void)
{
  #include "angle.h"
  Point point;
  point.x1 = 350;
  point.y1 = 420;
  point.ro = 175;
  uint16_t old_angle;

  draw_arch(point.x1, point.y1, 0, 180, 50, 2, OLIVE);
  draw_arch(point.x1, point.y1, 0, 180, 80, 2, OLIVE);

  /* Infinite loop */
  for(;;)
  {
    for(uint16_t i =0;i<=180; i++)
    {
      // osMutexWait(Display_MutexHandle, portMAX_DELAY); // mutex on

      point.angle = old_angle;
      draw_arrow(&point, 96, 2, GRAY50); // directional arrow clar
      draw_arch(point.x1, point.y1, point.angle -5, point.angle +5, 50, 2, OLIVE);
      draw_arch(point.x1, point.y1, point.angle -3, point.angle +3, 80, 2, OLIVE);

      point.angle = i;
      draw_arrow(&point, 96, 2, ORANGE); // directional arrow draw
      draw_arrow(&point, 96, 2, ORANGE); // directional arrow draw
      draw_arrow(&point, 96, 2, ORANGE); // directional arrow draw
      draw_arrow(&point, 96, 2, ORANGE); // directional arrow draw
      draw_arch(point.x1, point.y1, point.angle -5, point.angle +5, 50, 2, OLIVE);
      draw_arch(point.x1, point.y1, point.angle -3, point.angle +3, 80, 2, OLIVE);
      delay(5);

      old_angle = point.angle;

      // osMutexRelease(Display_MutexHandle); // mutex off

      for(uint16_t i=0;i<=180;i+=30)
      {
        // osMutexWait(Display_MutexHandle, portMAX_DELAY); // mutex on
        point.angle = i;
        get_angle_pos(&point);
        // write_graph_dot_line(point.x1,point.y1, point.x2,point.y2, 1, GREEN);
        for(uint16_t i=100;i<=110;i++) draw_angle(&point, i, 2, RED); // yellow tags
        for(uint16_t i=110;i<=116;i++) draw_angle(&point, i, 2, GREEN); // yellow tags
        // osMutexRelease(Display_MutexHandle); // mutex off
        delay(10);
      }

      delay(50);
    }

    delay(50);
  }

}

void draw_dot_grid(void)
{
  // osMutexWait(Display_MutexHandle, portMAX_DELAY); // mutex on
  for(uint16_t y = 106;y<Display_Get_HEIGHT()-270;y+= 8)
    for(uint16_t x = 16; x<Display_Get_WIDTH()-15; x+=32) fillRect(x, y, 2,2, CYAN);
  for(uint16_t y = 106;y<Display_Get_HEIGHT()-270;y+=32)
    for(uint16_t x = 16; x<Display_Get_WIDTH()-15; x+=8 ) fillRect(x, y, 2,2, CYAN);
  // osMutexRelease(Display_MutexHandle); // mutex off
}

void draw_dynamic_grid(int16_t shiftx)
{
  if(shiftx < 12) return;
  #define y_pos  124
  #define ceil_x  33
    // osMutexAcquire(Display_MutexHandle, portMAX_DELAY);
  // osMutexWait(Display_MutexHandle, portMAX_DELAY); // mutex on
  for(uint16_t y = y_pos;y<y_pos+97;y+= 8)
    for(uint16_t x = shiftx; x<ceil_x+shiftx; x+=32) fillRect(x, y, 2,2, CYAN);
  for(uint16_t y = y_pos;y<y_pos+97;y+=32)
    for(uint16_t x = shiftx; x<ceil_x+shiftx; x+=8 ) fillRect(x, y, 2,2, CYAN);
  // osMutexRelease(Display_MutexHandle); // mutex off
}

uint16_t i = 0;
int main(void){
    i++;
    gfx_open(WIDTH,HEIGHT,"tft emulation");
    Display_Set_WIDTH(WIDTH);
    Display_Set_HEIGHT(HEIGHT);

    fillRect(0, 0, Display_Get_WIDTH(),Display_Get_HEIGHT(), GRAY50);

    drawRGBBitmap(10, 235, tiger);
    // drawRGBBitmap(10, 235, RGBY);
    // drawRGBBitmap(10, 235, lion);

    draw_window();

    gfx_color(128,127,255);

    // draw_line(20,20,20+100,20+10, 0x00ff00);
    // drawCircle(100, 100, 50, 0x0000ff);
    // draw_dot_grid();

    for(int16_t i=8;i<Display_Get_WIDTH()-8;i++)
    {
        if( !(i % 32) ) draw_dynamic_grid(i-33);
    }
    if(i>Display_Get_WIDTH()) i=0;

    gauge(640, 270, YELLOW, 270+20); // value == degrees

    // dial_arc();

    float ax, ay, bx, by, cx, cy, dx, dy;
    ax=290; bx=260; cx=340; dx=310;
    ay=430; by=300; cy=300; dy=430;
    DrawBezierFX(ax, ay, bx, by, cx, cy, dx, dy, 1, YELLOW);

    fill_regular_polygon(360, 310, 5, 45, BLUE);

    lissajous(385,52, 0.125, 0.250, CYAN , DARKSLATEGRAY);

    gfx_flush(); //Update the graphics

    usleep(4e6);
}


