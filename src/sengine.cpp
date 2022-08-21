
#ifndef SENGINE_H
#define EXPORT // Exporting (Compiling) Shared Library
#include <sengine/sengine.h>
#endif

#include <SDL2/SDL.h>
#include <iostream>

namespace SEngine
{
    SEngine::SEngine(char* title) {
        this->title = title;
        this->WIDTH = 640;
        this->HEIGHT = 480;
    }

    void SEngine::set_title(char* title) {
        this->title = title;
    }

    void SEngine::set_window_mode(WindowMode wm) {
        
    }

    void SEngine::run() {
        init_engine();
    }

    void SEngine::init_engine() {
        if (SDL_Init(SDL_INIT_EVERYTHING))
        {
            std::cout << "SDL_Init ERROR: " << SDL_GetError() << std::endl;
            exit(1);
        }
        
        SDL_DisplayMode displayMode;
        int request = SDL_GetDesktopDisplayMode(0, &displayMode);

        SDL_Window *win = SDL_CreateWindow(this->title, 0, 0, this->WIDTH, this->HEIGHT, SDL_WINDOW_SHOWN || SDL_WINDOWPOS_CENTERED);
        if (win == nullptr) {
            std::cout << "SDL_CreateWindow ERROR: " << SDL_GetError() << std::endl;
            exit(1);
        }

        SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED || SDL_RENDERER_PRESENTVSYNC);
        if (ren == nullptr)
        {
            std::cout << "SDL_CreateRenderer ERROR: " << SDL_GetError() << std::endl;
            exit(1);
        }
    }

    SEngine::~SEngine() {
        //SDL_DestroyWindow(this->win);
    }
} // namespace SEngine
