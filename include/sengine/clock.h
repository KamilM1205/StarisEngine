#ifndef CLOCK_H_
#define CLOCK_H_

#include <inttypes.h>

namespace SEngine
{
    class Clock {
        private:
            uint64_t last_tick_time = 0;
            uint64_t delta = 0;
            uint64_t fps = 0;
        public:
            Clock();
            void count();
            ~Clock();
    };
} // namespace SEngine


#endif CLOCK_H_