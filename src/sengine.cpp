
#include <sengine/sengine.h>

#include <iostream>

namespace SEngine
{
    SEngine::SEngine(const char* title) {
        this->title = title;
        this->WIDTH = 640;
        this->HEIGHT = 480;
        this->sm = StateMachine();
    }

    void SEngine::set_title(const char* title) {
        this->title = title;
    }

    void SEngine::set_window_mode(WindowMode wm) {
        
    }

    void SEngine::event_handler(SDL_Event *event) {
        
    }

    void SEngine::run(State *main_state) {
        if (SDL_Init(SDL_INIT_EVERYTHING))
        {
            std::cout << "SDL_Init ERROR: " << SDL_GetError() << std::endl;
            exit(1);
        }
        
        SDL_DisplayMode displayMode;
        int request = SDL_GetDesktopDisplayMode(0, &displayMode);

        this->win = SDL_CreateWindow(this->title, 0, 0, this->WIDTH, this->HEIGHT, SDL_WINDOW_SHOWN || SDL_WINDOWPOS_CENTERED);
        if (win == nullptr) {
            std::cout << "SDL_CreateWindow ERROR: " << SDL_GetError() << std::endl;
            exit(1);
        }

        this->ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED || SDL_RENDERER_PRESENTVSYNC);
        if (ren == nullptr)
        {
            std::cout << "SDL_CreateRenderer ERROR: " << SDL_GetError() << std::endl;
            exit(1);
        }

        this->sm.set_state(main_state);

        bool quit = false;

        while (!quit) {
            SDL_Event event;

            SDL_PollEvent(&event);

            if (event.type == SDL_QUIT) {
                quit = true;
            }

            this->event_handler(&event);
            this->sm.update(0.0);
        }
    }

    SEngine::~SEngine() {
        SDL_DestroyRenderer(this->ren);
        SDL_DestroyWindow(this->win);

        SDL_Quit();
    }
} // namespace SEngine
