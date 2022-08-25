#ifndef EVENT_H_
#define EVENT_H_

#include <SDL2/SDL.h>

namespace SEngine {
    class EventHandler {
        public:
            EventHandler();
            void HandleEvent(SDL_Event *event);
            ~EventHandler();
    };
} // namespace SEngine

#endif