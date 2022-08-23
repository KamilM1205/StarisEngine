#ifndef SENGINE_H
#define SENGINE_H

#include <SDL2/SDL.h>

#include <sengine/state_machine.h>
#include <sengine/export.h>
#include <sengine/logger.h>

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

            StateMachine sm;

            Logger logger;

            void event_handler(SDL_Event *event);

        public:
            
            SEngine(const char* title);
            ~SEngine();
            //setters
            void set_title(const char* title);
            void set_window_mode(WindowMode);
            void run(State *main_state);
    };

} // namespace SEngine

#endif