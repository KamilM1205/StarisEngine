use super::context::Context;
use log::error;

impl Context {
    pub fn draw_line(&mut self, x1: i32, y1: i32, x2: i32, y2: i32) {
        let start = sdl2::rect::Point::new(x1, y1);
        let end = sdl2::rect::Point::new(x2, y2);

        self.canvas.draw_line(start, end).unwrap_or_else(|e| {
            error!("SDL draw line error: {e}");
        });
    }
    
    pub fn draw_rect(&mut self, x1: i32, y1: i32, x2: u32, y2: u32) {
        let rect = sdl2::rect::Rect::new(x1, y1, x2, y2);
        
        self.canvas.draw_rect(rect).unwrap_or_else(|e| {
            error!("SDL draw rect error: {e}");
        });
    }

    pub fn draw_filled_rect(&mut self, x1: i32, y1: i32, x2: u32, y2: u32) {
        let rect = sdl2::rect::Rect::new(x1, y1, x2, y2);
        
        self.canvas.fill_rect(rect).unwrap_or_else(|e| {
            error!("SDL draw rect error: {e}");
        });
    }
}
