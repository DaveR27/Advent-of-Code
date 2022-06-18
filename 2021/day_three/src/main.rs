use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

// The output is wrapped in a Result to allow matching on errors
// Returns an Iterator to the Reader of the lines of the file.
fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}

fn to_u32(slice: &[i32]) -> u32 {
    slice.iter().fold((0,1),|(acc,mul),&bit|(acc+(mul*(1&bit as u32)),mul.wrapping_add(mul))).0
}

fn main() {
    let mut zeros: [i32; 5] = [0, 0, 0, 0, 0];
    let mut ones: [i32; 5] = [0, 0, 0, 0, 0];

    let mut max: [i32; 5] = [0, 0, 0, 0, 0];
    let mut min: [i32; 5] = [0, 0, 0, 0, 0];

    if let Ok(lines) = read_lines("puzzleInput.txt") {
            for line in lines {
                if let Ok(ip) = line {
                    // Find if 1 or 0 occurs more at each bit position, knowing each number is only 5 bits
                    for i in 0..5 {
                        if ip.chars().map(|c| c.to_digit(10).unwrap()).sum::<u32>() == 0 {
                            zeros[i] = zeros[i] + 1;
                        } else {
                            ones[i] = ones[i] + 1;
                        }
                    } 
                }
            }
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
    
    println!("{}", gamma);
    println!("{}", epsilon);
    println!("{}", (gamma * epsilon).to_string());
}