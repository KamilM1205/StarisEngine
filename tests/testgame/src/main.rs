use staris_engine::render::context::Context;

#[derive(Default)]
struct Game {
    x: f32,
    y: f32,
}

impl staris_engine::data::state_machine::State for Game {
    fn update(&mut self, dt: f32) {
        self.x += 0.01;
    }

    fn draw(&self, ctx: &mut Context) {
       ctx.draw_filled_circle(self.x, self.y, 30.); 
    }
}

fn main() {
    let mut se = staris_engine::sengine::SEngine::new();

    se.run(Game {x: 100., y: 100.});
}
