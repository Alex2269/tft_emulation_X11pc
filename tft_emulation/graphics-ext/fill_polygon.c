#include "color.h"
#include "fill_polygon.h"

// http:// lienryderflex.com/intersect/
static int
lineSegmentIntersection(float Ax, float Ay, float Bx, float By, float Cx, float Cy, float Dx, float Dy, float *X, float *Y)
{
  float distAB, theCos, theSin, newX, ABpos ;
  // Fail if either line segment is zero-length.
  if ((Ax==Bx && Ay==By) || (Cx==Dx && Cy==Dy))
  return 0;
  // Fail if the segments share an end-point.
  if ((Ax==Cx && Ay==Cy) || (Bx==Cx && By==Cy) ||
  (Ax==Dx && Ay==Dy) || (Bx==Dx && By==Dy))
  {
    return 0;
  }
  // (1) Translate the system so that point A is on the origin.
  Bx-=Ax; By-=Ay;
  Cx-=Ax; Cy-=Ay;
  Dx-=Ax; Dy-=Ay;
  // Discover the length of segment A-B.
  distAB=sqrt(Bx*Bx+By*By);
  // (2) Rotate the system so that point B is on the positive X axis.
  theCos=Bx/distAB;
  theSin=By/distAB;
  newX=Cx*theCos+Cy*theSin;
  Cy =Cy*theCos-Cx*theSin; Cx=newX;
  newX=Dx*theCos+Dy*theSin;
  Dy =Dy*theCos-Dx*theSin; Dx=newX;
  // Fail if segment C-D doesn't cross line A-B.
  if ((Cy<0. && Dy<0.) || (Cy>=0. && Dy>=0.))
  return 0;
  // (3) Discover the position of the intersection point along line A-B.
  ABpos=Dx+(Cx-Dx)*Dy/(Dy-Cy);
  // Fail if segment C-D crosses line A-B outside of segment A-B.
  if (ABpos<0. || ABpos>distAB)
  return 0;
  // (4) Apply the discovered position to line A-B in the original coordinate system.
  *X=Ax+ABpos*theCos;
  *Y=Ay+ABpos*theSin;
  // Success.
  return 1;
}

void fill_regular_polygon(int center_x, int center_y, int vertices, int radius)
{
  const double a = 2.0 * 3.14159265358979323846 / (double)vertices;
  int i = 1;
  int y, px, py, nx, ny;
  if (vertices < 3 || radius < 1)
  return;
  px = 0;
  py = -radius;
  nx = (int)(0.5 + radius * sin(a));
  ny = (int)(0.5 - radius * cos(a));
  y = -radius;
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
        // lineto(center_x + x, center_y + y);
        drawLine(getCursorX(), getCursorY(), center_x + x, center_y + y, GREEN);
      }
      else
      {
        // lineto(Display_Get_WIDTH() - 1, center_y + y);
        drawLine(getCursorX(), getCursorY(), Display_Get_WIDTH() - 1, center_y + y, GREEN);
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
