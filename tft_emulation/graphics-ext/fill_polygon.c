#include "color.h"
#include "fill_polygon.h"

void fill_regular_polygon(int center_x, int center_y, int vertices, int radius, uint32_t color)
{
  if (vertices < 3 || radius < 1) return;

  const double a = 6.28318530718 / (double)vertices;
  int i = 1;
  int y, px, py, nx, ny;

  nx = +(int)(0.5 + radius * sin(a * (double)i));
  ny = -(int)(0.5 + radius * cos(a * (double)i));

  px = 0;
  py = y = -radius;
  while (y <= ny || ny > py)
  {
    const int x = px + (nx - px) * (y - py) / (ny - py);
    setCursorX(center_x - x);
    setCursorY(center_y + y);
    drawLine(getCursorX(), getCursorY(), center_x + x, center_y + y, color);
    y++;
    while (y > ny)
    {
      if (nx < 0) return;
      i++;
      px = nx;
      py = ny;
      nx = +(int)(0.5 + radius * sin(a * (double)i));
      ny = -(int)(0.5 + radius * cos(a * (double)i));
    }
  }
}

/**
void fill_regular_polygon(int center_x, int center_y, int vertices, int radius, uint32_t color)
{
  if (vertices < 3 || radius < 1)
  return;

  const double a = 2.0 * 3.14159265358979323846 / (double)vertices;
  int i = 1;
  int y, px, py, nx, ny;

  nx = (int)(0.5 + radius * sin(a));
  ny = (int)(0.5 - radius * cos(a));
  px = 0;
  py = y = -radius;
  while (y <= ny || ny > py)
  {
    const int x = px + (nx - px) * (y - py) / (ny - py);
    if (center_y + y >= 0 && center_y + y < Display_Get_HEIGHT())
    {
      if (center_x - x >= 0)
      {
        setCursorX(center_x - x);
        setCursorY(center_y + y);
      }
      else
      {
        setCursorX(0);
        setCursorY(center_y + y);
      }
      if (center_x + x < Display_Get_WIDTH())
      {
        drawLine(getCursorX(), getCursorY(), center_x + x, center_y + y, color);
      }
      else
      {
        drawLine(getCursorX(), getCursorY(), Display_Get_WIDTH() - 1, center_y + y, color);
      }
    }
    y++;
    while (y > ny)
    {
      if (nx < 0)
      return;
      i++;
      px = nx;
      py = ny;
      nx = (int)(0.5 + radius * sin(a * (double)i));
      ny = (int)(0.5 - radius * cos(a * (double)i));
    }
  }
}
**/
