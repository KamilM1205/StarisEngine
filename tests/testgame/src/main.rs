use staris_engine::{
    render::context::Context,
    data::{ Command, CommandType },
};

#[macro_use] extern crate staris_engine;

#[state]
#[derive(Default)]
struct Game {
    x: f32,
    y: f32,
}

impl Game {
    pub fn ttt(game: &mut Game) {
        println!("AAAAAA");
    }
}

impl staris_engine::data::state_machine::State for Game {
    fn init(&mut self) {
        self.x = 100.;
        self.y = 100.;

        self.commands.bind(CommandType::KeyEvent(staris_engine::sdl2::keyboard::Keycode::A, staris_engine::sdl2::keyboard::Mod::NOMOD, true), Game::ttt);
    }

    fn update(&mut self, dt: f32) {
        self.x += 0.01;
    }

    fn draw(&self, ctx: &mut Context) {
       ctx.draw_filled_circle(self.x, self.y, 30.); 
    }
}

fn main() {
    let mut se = staris_engine::sengine::SEngine::new();

    se.run(Game::default());
}
