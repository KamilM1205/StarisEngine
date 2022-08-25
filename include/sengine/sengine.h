#ifndef SENGINE_H
#define SENGINE_H

#include <SDL2/SDL.h>

#include <sengine/state_machine.h>
#include <sengine/export.h>
#include <sengine/logger.h>

#include <thread>

namespace SEngine
{
    enum WindowMode {
        Windowed,
        FullScreen,
    };

    class EXPORT SEngine
    { 
        private:
            int x, y;
            int WIDTH, HEIGHT;
            WindowMode wm;
            const char* title;

            SDL_Window *win;
            SDL_Renderer *ren;
            Context ctx;

            StateMachine sm;

            Logger logger;

            std::thread game_thread;
            bool isRunning;

            void state_worker();
            void init_sdl();

        public:
            
            SEngine(const char* title);
            ~SEngine();

            //setters
            void set_title(const char* title);
            void set_window_mode(WindowMode wm);
            void run(State *main_state);
    };

} // namespace SEngine

#endif