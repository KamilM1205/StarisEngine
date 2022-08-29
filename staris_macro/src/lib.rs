use proc_macro::TokenStream;
use quote::quote;
use syn::{parse_macro_input, ItemStruct, parse::{self, Parser}, Generics};

// https://users.rust-lang.org/t/solved-derive-and-proc-macro-add-field-to-an-existing-struct/52307/4
#[proc_macro_attribute]
pub fn state(args: TokenStream, input: TokenStream) -> TokenStream {
    let mut item_struct = parse_macro_input!(input as ItemStruct);
    let _ = parse_macro_input!(args as parse::Nothing);
    

    let state_name = item_struct.ident.clone();

    if let syn::Fields::Named(ref mut fields) = item_struct.fields {
        fields.named.push(
            syn::Field::parse_named
                .parse2(quote! { pub commands: staris_engine::data::Command< #state_name > })
                .unwrap()   
        )
    }

    println!("Dump: {}", quote! { #item_struct }.to_string());

    let impl_trait = quote! {
        use staris_engine::sdl2::event::Event;
        impl staris_engine::data::CommandHandler for #state_name {
            fn handle(&mut self, event: staris_engine::sdl2::event::Event) {
                use staris_engine::data::CommandType;
                match event {
                    Event::KeyDown { keycode, keymod, repeat, .. } => {
                        if self.commands.binds.contains_key(&CommandType::KeyEvent(keycode.unwrap(), keymod, repeat)) {
                            (self.commands.binds.get(&CommandType::KeyEvent(keycode.unwrap(), keymod, repeat)).unwrap())(self);
                        }
                    },
                    _ => (),
                }
            }
        }
    };

    println!("Dump: {}", quote! { #impl_trait }.to_string());

    let ret_tokens = quote! {
        #item_struct
        
        #impl_trait
    };

    println!("Dump: {}", quote! { #ret_tokens }.to_string());

    return ret_tokens.into();
}