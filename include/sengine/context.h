#ifndef CONTEXT_H_
#define CONTEXT_H_

#include <sengine/export.h>
#include <sengine/color.h>

#include <SDL2/SDL.h>

namespace SEngine
{
    class Context
    {
    private:
        SDL_Renderer *ren;

        Color clear_color;
        Color draw_color;
    public:
        Context(SDL_Renderer *ren);

        void set_color(Color color);
        void set_clear_color(Color color);
        void clear();
        void display();

        void draw_line(int x1, int y1, int x2, int y2);
        void draw_rect(int x, int y, int w, int h);
        void draw_filled_rect(int x, int y, int w, int h);
        void draw_triangle();

        ~Context();
    };
    
} // namespace SEngine

#endif