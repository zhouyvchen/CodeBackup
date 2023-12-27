use std::io;

fn main() {
    println!("猜一个数字");
    println!("请输入你猜测的数字");

    let mut guess = String::new();
    io::stdin()
        .read_line(&mut guess)
        .expect("Failed to read line");

    println!("你猜的数字是：{}", guess);
}
