use std::collections::HashMap;
use sdl2::event::Event;

pub trait CommandHandler {
    fn handle(&mut self, event: Event);
}

#[derive(Hash, PartialEq, Eq)]
pub enum CommandType {
    // KeyCode, KeyMode, repeat
    KeyEvent(sdl2::keyboard::Keycode, sdl2::keyboard::Mod, bool),
}

#[derive(Default)]

pub struct Command<T> {
    pub binds: HashMap<CommandType, fn(&mut T)>,
}

impl<T> Command<T> {
    pub fn bind(&mut self, key: CommandType, callback: fn(&mut T)) {
        self.binds.insert(key, callback);
    }
}