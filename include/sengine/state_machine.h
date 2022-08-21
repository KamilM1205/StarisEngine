#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#include <sengine/export.h>

namespace SEngine
{
    class EXPORT State
    {
    public:
        State();
        virtual void update(float dt);
        virtual void draw();
        State* get_state();
    };

    class EXPORT StateMachine
    {
        private:
            State *current_state;
        public:
            void set_state(State *state);
            void update(float dt);
            void draw();
            StateMachine();
            ~StateMachine();
    };
} // namespace SEngine

#endif