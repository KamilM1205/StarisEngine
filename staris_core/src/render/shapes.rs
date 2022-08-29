use super::context::Context;
use log::error;

impl Context {
    pub fn draw_point(&mut self, x: f32, y: f32) {
        let point = sdl2::rect::Point::new(x as i32, y as i32);
        self.canvas.draw_point(point).unwrap_or_else(|e| {
            error!("SDL draw point error: {e}");
        });
    }

    pub fn draw_line(&mut self, x1: f32, y1: f32, x2: f32, y2: f32) {
        let start = sdl2::rect::Point::new(x1 as i32, y1 as i32);
        let end = sdl2::rect::Point::new(x2 as i32, y2 as i32);

        self.canvas.draw_line(start, end).unwrap_or_else(|e| {
            error!("SDL draw line error: {e}");
        });
    }

    pub fn draw_rect(&mut self, x1: f32, y1: f32, x2: f32, y2: f32) {
        let rect = sdl2::rect::Rect::new(x1 as i32, y1 as i32, x2 as u32, y2 as u32);

        self.canvas.draw_rect(rect).unwrap_or_else(|e| {
            error!("SDL draw rect error: {e}");
        });
    }

    pub fn draw_filled_rect(&mut self, x1: f32, y1: f32, x2: f32, y2: f32) {
        let rect = sdl2::rect::Rect::new(x1 as i32, y1 as i32, x2 as u32, y2 as u32);

        self.canvas.fill_rect(rect).unwrap_or_else(|e| {
            error!("SDL draw rect error: {e}");
        });
    }

    pub fn draw_circle(&mut self, x: f32, y: f32, radius: f32) {
        let mut offsetx = 0.;
        let mut offsety = radius;
        let mut d = radius - 1.;

        while offsetx <= offsety {
            self.draw_point(x + offsetx, y + offsety);
            self.draw_point(x + offsety, y + offsetx);
            self.draw_point(x - offsetx, y + offsety);
            self.draw_point(x - offsety, y + offsetx);
            self.draw_point(x + offsetx, y - offsety);
            self.draw_point(x + offsety, y - offsetx);
            self.draw_point(x - offsetx, y - offsety);
            self.draw_point(x - offsety, y - offsetx);

            if d >= 2. * offsetx {
                d -= 2. * offsetx + 1.;
                offsetx += 1.;
            } else if d < 2. * (radius - offsety) {
                d += 2. * offsety - 1.;
                offsety -= 1.;
            } else {
                d += 2. * (offsety - offsetx - 1.);
                offsety -= 1.;
                offsetx += 1.;
            }
        }
    }

    pub fn draw_filled_circle(&mut self, x: f32, y: f32, radius: f32) {
        let mut offsetx = 0.;
        let mut offsety = radius;
        let mut d = radius - 1.;

        while offsetx <= offsety {
            self.draw_line(x - offsety, y + offsetx, x + offsety, y + offsetx);
            self.draw_line(x - offsetx, y + offsety, x + offsetx, y + offsety);
            self.draw_line(x - offsetx, y - offsety, x + offsetx, y - offsety);
            self.draw_line(x - offsety, y - offsetx, x + offsety, y - offsetx);

            if d >= 2. * offsetx {
                d -= 2. * offsetx + 1.;
                offsetx += 1.;
            } else if d < 2. * (radius - offsety) {
                d += 2. * offsety - 1.;
                offsety -= 1.;
            } else {
                d += 2. * (offsety - offsetx - 1.);
                offsety -= 1.;
                offsetx += 1.;
            }
        } 
    }
}
