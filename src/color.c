#include "color.h"

bool isColorCustom(color c)
{
    uint8_t *ptr = &c;
    return ptr[3];
}

color color_create(uint8_t red, uint8_t green, uint8_t blue)
{
    color c;
    uint8_t *ptr = &c;
    ptr[3] = 1;
    ptr[0] = red;
    ptr[1] = green;
    ptr[2] = blue;
    return c;
}
void color_setRed(color *c, uint8_t red)
{
    uint8_t *ptr = c;
    ptr[0] = red;
}
void color_setGreen(color *c, uint8_t green)
{
    uint8_t *ptr = c;
    ptr[1] = green;
}
void color_setBlue(color *c, uint8_t blue)
{
    uint8_t *ptr = c;
    ptr[2] = blue;
}
uint8_t color_getRed(color c)
{
    uint8_t *ptr = &c;
    return ptr[0];
}
uint8_t color_getGreen(color c)
{
    uint8_t *ptr = &c;
    return ptr[1];
}
uint8_t color_getBlue(color c)
{
    uint8_t *ptr = &c;
    return ptr[2];
}