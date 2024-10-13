#ifndef __DrawBezier_H
#define __DrawBezier_H

/* Include Library */
#include "stdint.h"
#include "stdbool.h"

void DrawBezier(float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy, uint8_t solid, uint32_t color);
void DrawBezierFX(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy, uint8_t solid, uint32_t color);

#endif // __DrawBezier_H

