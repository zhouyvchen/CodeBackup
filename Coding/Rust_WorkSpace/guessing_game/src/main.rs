//use core::num;
use rand::Rng;
use std::cmp::Ordering;
use std::io;

fn main() {
    println!("猜一个数字");
    let secret_number = rand::thread_rng().gen_range(1..101);
    //    println!("秘密数字是 {}", secret_number);
    loop {
        println!("请输入你猜测的数字");

        let mut guess = String::new();
        io::stdin()
            .read_line(&mut guess)
            .expect("Failed to read line");

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        println!("你猜的数字是：{}", guess);

        match guess.cmp(&secret_number) {
            Ordering::Less => println!("太小"),
            Ordering::Greater => println!("太大"),
            Ordering::Equal => {
                println!("恭喜你");
                break;
            }
        }
    }
}
