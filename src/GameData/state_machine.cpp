#include <sengine/state_machine.h>

namespace SEngine
{
    State::State() {}
    
    void State::update(float dt) {}

    void State::draw(Context *ctx) {}

    State* State::get_state() {
        return static_cast<State*>(this);
    }

    StateMachine::StateMachine() {
        this->current_state = nullptr;
    }

    void StateMachine::set_state(State *state) {
        this->current_state = state;
    }

    void StateMachine::update(float dt) {
        this->current_state->update(dt);
    }

    void StateMachine::draw(Context *ctx) {
        this->current_state->draw(ctx);
    }

    StateMachine::~StateMachine() {}
} // namespace SEngine
