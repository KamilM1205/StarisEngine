#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#include <sengine/export.h>
#include <sengine/context.h>

namespace SEngine
{
    class EXPORT State
    {
    public:
        State();
        virtual void update(float dt);
        virtual void draw(Context *ctx);
        State* get_state();
    };

    class EXPORT StateMachine
    {
        private:
            State *current_state;
        public:
            void set_state(State *state);
            void update(float dt);
            void draw(Context *ctx);
            StateMachine();
            ~StateMachine();
    };
} // namespace SEngine

#endif