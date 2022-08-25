#include <sengine/state_machine.h>

namespace SEngine
{
    State::State() {}

    void State::setup(Logger *logger) {
        this->log = logger;
    }
    
    void State::update(float dt) {}

    void State::draw(Context *ctx) {}

    State* State::get_state() {
        return static_cast<State*>(this);
    }

    StateMachine::StateMachine(Logger *logger) {
        this->current_state = nullptr;
        this->log = logger;
    }

    StateMachine::StateMachine() {
        this->current_state = nullptr;
    }

    void StateMachine::set_state(State *state) {
        this->current_state = state;
        this->current_state->setup(this->log);
    }

    void StateMachine::update(float dt) {
        this->current_state->update(dt);
    }

    void StateMachine::draw(Context *ctx) {
        this->current_state->draw(ctx);
    }

    StateMachine::~StateMachine() {}
} // namespace SEngine
