use crate::render::context::Context;

pub trait State {
    fn update(&mut self, dt: f32);
    fn draw(&self, ctx: &mut Context);
}

pub struct StateMachine<S>
where
    S: State,
{
    state: Option<S>,
}

impl<S> Default for StateMachine<S>
where
    S: State,
{
    fn default() -> Self {
        Self { state: None }
    }
}

impl<S> StateMachine<S>
where
    S: State,
{
    pub fn set_state(&mut self, state: S) {
        self.state = Some(state);
    }

    pub fn update(&mut self, dt: f32) {
        self.state.as_mut().unwrap().update(dt);
    }

    pub fn draw(&mut self, ctx: &mut Context) {
        self.state.as_mut().unwrap().draw(ctx);
    }
}
