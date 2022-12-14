use log::error;
use sdl2::event::Event;

use crate::{
    data::{state_machine::{State, StateMachine}, CommandHandler},
    logger::setup_logging,
    render::context::Context,
};

pub struct SEngine {
    title: String,
    width: u32,
    height: u32,
}

impl SEngine {
    pub fn new() -> Self {
        setup_logging("log/log.txt", log::LevelFilter::Debug);
        Self {
            title: "SEngine".to_owned(),
            width: 640,
            height: 480,
        }
    }

    pub fn set_title(&mut self, title: impl Into<String>) {
        self.title = title.into();
    }

    pub fn set_size(&mut self, w: u32, h: u32) {
        self.width = w;
        self.height = h;
    }

    pub fn run(&mut self, state: impl State + CommandHandler) {
        let sdl_contex = match sdl2::init() {
            Ok(s) => s,
            Err(e) => {
                error!("SDL init error: {e}");
                return;
            }
        };

        let video_subsystem = match sdl_contex.video() {
            Ok(v) => v,
            Err(e) => {
                error!("SDL init video subsystem error: {e}");
                return;
            }
        };

        let window = match video_subsystem
            .window(&self.title, self.width, self.height)
            .position_centered()
            .opengl()
            .build()
            .map_err(|e| e.to_string())
        {
            Ok(w) => w,
            Err(e) => {
                error!("SDL init window error: {e}");
                return;
            }
        };

        let canvas = match window.into_canvas().build().map_err(|e| e.to_string()) {
            Ok(c) => c,
            Err(e) => {
                error!("SDL init canvas error: {e}");
                return;
            }
        };

        let mut ctx = Context::new(canvas);

        let mut sm = StateMachine::default();
        sm.set_state(state);

        'engine_loop: loop {
            for event in sdl_contex.event_pump().unwrap().poll_iter() {
                match event {
                    Event::Quit { .. } => break 'engine_loop,
                    _ => {}
                }

                sm.state.as_mut().unwrap().handle(event);
            }

            ctx.clear();
            sm.update(0.0);
            sm.draw(&mut ctx);
            ctx.display();
        }
    }
}
