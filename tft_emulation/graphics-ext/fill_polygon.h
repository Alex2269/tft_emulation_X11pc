#ifndef __fill_polygon_H_H
#define __fill_polygon_H_H

/* Include Library */
#include "stdint.h"
#include "stdbool.h"


// http:// lienryderflex.com/intersect/
static int
lineSegmentIntersection(float Ax, float Ay, float Bx, float By, float Cx, float Cy, float Dx, float Dy, float *X, float *Y);
void fill_regular_polygon(int center_x, int center_y, int vertices, int radius);


#endif // __fill_polygon_H_H




