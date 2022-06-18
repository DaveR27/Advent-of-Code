use std::fs::File;
use std::io::{BufRead, BufReader};

fn to_u32(slice: &[i32]) -> u32 {
    slice.iter().fold((0,1),|(acc,mul),&bit|(acc+(mul*(1&bit as u32)),mul.wrapping_add(mul))).0
}

fn main() {
    let mut zeros: [i32; 12] = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
    let mut ones: [i32; 12] = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];

    let mut max: [i32; 12] = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
    let mut min: [i32; 12] = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];


    let filename = "puzzleInput.txt";
    // Open the file in read-only mode (ignoring errors).
    let file = File::open(filename).unwrap();
    let reader = BufReader::new(file);

    // Read the file line by line using the lines() iterator from std::io::BufRead.
    for (index, line) in reader.lines().enumerate() {
        let line = line.unwrap(); // Ignore errors.
        println!("{}", line);
        // let loopnum = line.chars().map(|c| c.to_digit(10).unwrap()).sum::<u32>();
        
        // println!("{}", loopnum);
        // println!("here");

        // for i in 0..12 {
        //     if loopnum == 0 {
        //         zeros[i] = zeros[i] + 1;
        //     } else {
        //         ones[i] = ones[i] + 1;
        //     }
        // }
    }

    for i in 0..5 {
        if zeros[i] < ones[i] {
            max[i] = 1;
        } else {
            min[i] = 1;
        }
    }

    let gamma = to_u32(&max);
    let epsilon = to_u32(&min);
    
    // println!("{}", gamma);
    // println!("{}", epsilon);
    // println!("{}", (gamma * epsilon).to_string());
}