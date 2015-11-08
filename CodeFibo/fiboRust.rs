use std::env::args;
use std::thread;

fn fibo(n : u64) -> u64 {
    let v1:u64;
    let mut v2:u64 = 0;
    if n < 2 {
        v1 = 1
    }
    else {
        let arg1 = n - 1;
        let handle = thread::spawn(move || { fibo(arg1)});
        let arg2 = n - 2;
        v2 = fibo(arg2);
        v1 = handle.join().unwrap()
    }
    v1 + v2
}


fn main() {
    let a =  args();
    let n:u64 = a.last().expect("no args at all")
             .trim().parse().ok().expect("an integer as last argument");
    println!("{}", fibo(n));
}
