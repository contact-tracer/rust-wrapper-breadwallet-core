#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));



#[cfg(test)]
mod tests {
    use super::*;
    use std::mem;

    #[test]
    fn first_test() {
        unsafe {
            let mut c_buf = 25;
            println!("{}",BRBIP38KeyIsValid(&mut c_buf));
            //asset_eq!(0,BRBIP38KeyIsValid("2gdgdjgmhf"));
        }
    }
}
