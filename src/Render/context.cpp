#include <sengine/context.h>

namespace SEngine
{
    Context::Context(SDL_Renderer *ren)
    {
        this->ren = ren;
    }

    void Context::set_color(Color color)
    {
        this->draw_color = color;
        SDL_SetRenderDrawColor(this->ren, color.r, color.g, color.b, color.a);
    }

    void Context::set_clear_color(Color color)
    {
        this->clear_color = color;
    }

    void Context::clear()
    {
        SDL_SetRenderDrawColor(this->ren, this->clear_color.r, this->clear_color.g, this->clear_color.b, this->clear_color.a);
        SDL_RenderClear(this->ren);
        SDL_SetRenderDrawColor(this->ren, this->draw_color.r, this->draw_color.g, this->draw_color.b, this->draw_color.a);
    }

    void Context::display() {
        SDL_RenderPresent(this->ren);
    }

    void Context::draw_line(int x1, int y1, int x2, int y2) {
        SDL_RenderDrawLine(this->ren, x1, y1, x2, y2);
    }

    void Context::draw_rect(int x, int y, int w, int h) {
        SDL_Rect rect;
        rect.x = x;
        rect.y = y;
        rect.w = w;
        rect.h = h;

        SDL_RenderDrawRect(this->ren, &rect);
    }

    void Context::draw_filled_rect(int x, int y, int w, int h) {
        SDL_Rect rect;
        rect.x = x;
        rect.y = y;
        rect.w = w;
        rect.h = h;

        SDL_RenderFillRect(this->ren, &rect);
    }

    Context::~Context() {}
} // namespace SEngine
