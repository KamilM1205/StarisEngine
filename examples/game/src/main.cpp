#include <sengine/sengine.h>
#include <sengine/state_machine.h>
#include <sengine/color.h>
#include <sengine/context.h>

#include <iostream>

class Game: public SEngine::State {
    public:
        void update(float dt);
        void draw(SEngine::Context *ctx);
};

void Game::update(float dt) {
    
}

void Game::draw(SEngine::Context *ctx) {
    ctx->set_clear_color(SEngine::Color(255, 0, 0));

    ctx->set_color(SEngine::Color(0, 255, 0));
    ctx->draw_rect(10, 10, 80, 80);
    ctx->set_color(SEngine::Color(0, 0, 255));
    ctx->draw_filled_rect(110, 110, 40, 40);
}

int main() {
    SEngine::SEngine se("test");

    Game game = Game();

    se.run(game.get_state());

    return 0;
}