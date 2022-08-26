use super::color::Color;

pub struct Context {
    canvas: sdl2::render::Canvas<sdl2::video::Window>,
    clear_color: Color,
    draw_color: Color,
}

impl Context {
    pub fn new(canvas: sdl2::render::Canvas<sdl2::video::Window>) -> Self {
        Self { canvas, clear_color: Color(0, 0, 0, 255), draw_color: Color(255, 255, 255, 255) }
    }

    pub fn set_clear_color(&mut self, color: Color) {
        self.clear_color = color;
    }

    pub fn clear(&mut self) {
        self.canvas.set_draw_color(sdl2::pixels::Color::RGBA(self.clear_color.0, self.clear_color.1, self.clear_color.2, self.clear_color.3));
        self.canvas.clear();
        self.canvas.set_draw_color(sdl2::pixels::Color::RGBA(self.draw_color.0, self.draw_color.1, self.draw_color.2, self.draw_color.3));
    }

    pub fn display(&mut self) {
        self.canvas.present();
    }
}