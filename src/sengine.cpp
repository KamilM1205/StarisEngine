
#include <sengine/sengine.h>

#include <iostream>

namespace SEngine
{
    SEngine::SEngine(const char* title) {
        this->title = title;
        this->WIDTH = 640;
        this->HEIGHT = 480;
        this->wm = WindowMode::Windowed;
        this->sm = StateMachine();
        //this->logger = Logger();
        logger.debug("SEngine constructor called!");
    }

    void SEngine::set_title(const char* title) {
        this->title = title;
    }

    void SEngine::set_window_mode(WindowMode wm) {
        this->wm = wm;
    }

    void SEngine::event_handler(SDL_Event *event) {
        
    }

    void SEngine::run(State *main_state) {
        if (SDL_Init(SDL_INIT_EVERYTHING))
        {
            std::cout << "SDL_Init ERROR: " << SDL_GetError() << std::endl;
            exit(1);
        }
        
        logger.info("Hello! im a little fly!! just wanna fly around smwr!");
        logger.warning("A warning");
        logger.error("An error occured");
        logger.debug("Yeeeaa i got the point");

        SDL_DisplayMode displayMode;
        int request = SDL_GetDesktopDisplayMode(0, &displayMode);

        if (this->wm == WindowMode::FullScreen) {
            this->win = SDL_CreateWindow(this->title, 0, 0, displayMode.w, displayMode.h, SDL_WINDOW_SHOWN);
        } else {
            this->win = SDL_CreateWindow(this->title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->WIDTH, this->HEIGHT, SDL_WINDOW_SHOWN);
        }
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

        Context ctx = Context(this->ren);

        while (!quit) {
            SDL_Event event;

            SDL_PollEvent(&event);

            if (event.type == SDL_QUIT) {
                quit = true;
            }

            this->event_handler(&event);
            this->sm.update(0.0);

            ctx.clear();
            this->sm.draw(&ctx);
            ctx.display();
        }
    }

    SEngine::~SEngine() {
        SDL_DestroyRenderer(this->ren);
        SDL_DestroyWindow(this->win);

        SDL_Quit();
    }
} // namespace SEngine
