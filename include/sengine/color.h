#ifndef COLOR_H_
#define COLOR_H_

#include <stdint.h>

namespace SEngine
{
    class Color
    {
    public:
        uint8_t r, g, b, a;

        Color();
        Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
        Color(uint8_t r, uint8_t g, uint8_t b);
    };
} // namespace SEngine

#endif