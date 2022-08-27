use staris_engine::render::context::Context;

struct Game {

}

impl staris_engine::data::state_machine::State for Game {
    fn update(&mut self, dt: f32) {
        
    }

    fn draw(&self, ctx: &mut Context) {
        
    }
}

fn main() {
    let mut se = staris_engine::sengine::SEngine::new();

    se.run(Game {});
}
