
#include <sengine/sengine.h>

namespace SEngine
{
    SEngine::SEngine(const char* title) {
        this->title = title;
        this->WIDTH = 640;
        this->HEIGHT = 480;
        this->wm = WindowMode::Windowed;
        this->sm = StateMachine(&this->logger);
        this->isRunning = true;
    }

    void SEngine::set_title(const char* title) {
        this->title = title;
    }

    void SEngine::set_window_mode(WindowMode wm) {
        this->wm = wm;
    }

    void SEngine::state_worker() {
        while (this->isRunning) {
            this->sm.update(0.0);
        }
    }

    void SEngine::init_sdl() {
        if (SDL_Init(SDL_INIT_EVERYTHING))
        {
            logger.error("SDL_Init ERROR: " + std::string(SDL_GetError()));
            exit(1);
        }
        
        SDL_DisplayMode displayMode;
        int request = SDL_GetDesktopDisplayMode(0, &displayMode);

        if (this->wm == WindowMode::FullScreen) {
            this->win = SDL_CreateWindow(this->title, 0, 0, displayMode.w, displayMode.h, SDL_WINDOW_SHOWN);
        } else {
            this->win = SDL_CreateWindow(this->title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->WIDTH, this->HEIGHT, SDL_WINDOW_SHOWN);
        }
        if (win == nullptr) {
            logger.error("SDL_CreateWindow ERROR: " + std::string(SDL_GetError()));
            exit(1);
        }

        this->ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED || SDL_RENDERER_PRESENTVSYNC);
        if (ren == nullptr)
        {
            logger.error("SDL_CreateRenderer ERROR: " + std::string(SDL_GetError()));
            exit(1);
        }
    }

    void SEngine::run(State *main_state) {
        this->sm.set_state(main_state);

        this->ctx = Context(this->ren);

        this->game_thread = std::thread(&SEngine::state_worker, this);

        while (this->isRunning) {
            SDL_Event event;

            SDL_PollEvent(&event);

            if (event.type == SDL_QUIT) {
                this->isRunning = false;
            }

            this->ctx.clear();
            this->sm.draw(&this->ctx);
            this->ctx.display();
        }

        this->game_thread.join();
    }

    SEngine::~SEngine() {
        SDL_DestroyRenderer(this->ren);
        SDL_DestroyWindow(this->win);

        SDL_Quit();
    }
} // namespace SEngine
