use std::thread;

fn main() {

    let han: Vec<_> = (0..10).into_iter()
        .map( |t| { thread::spawn(move || { println!("Hello world from {}", t);
                                            thread::sleep_ms(5000)}) })
        .collect();

    for h in han {
        h.join().unwrap();
    }
    
}
