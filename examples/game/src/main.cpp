#include <sengine/sengine.h>
#include <sengine/state_machine.h>

#include <iostream>

class Game: public SEngine::State {
    public:
        void update(float dt);
        void draw();
};

void Game::update(float dt) {
    std::cout << "Test" << std::endl;
}

void Game::draw() {}

int main() {
    SEngine::SEngine se("test");

    Game game = Game();

    se.run(game.get_state());

    return 0;
}