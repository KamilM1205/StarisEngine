#ifndef COLOR_H_
#define COLOR_H_

namespace SEngine
{
    class Color {
        public:
            int r, g, b, a;

            Color();
            Color(int r, int g, int b, int a);
            Color(int r, int g, int b);
    };
} // namespace SEngine

#endif