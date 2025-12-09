use std::cmp;
use std::fs;

fn area(p1: (i64, i64), p2: (i64, i64)) -> i64 {
    let x = (p1.0 - p2.0).abs() + 1;
    let y = (p1.1 - p2.1).abs() + 1;
    x * y
}

fn main() {
    // Parse input into a vector of points (tuples)
    let binding = fs::read_to_string("../input/example.txt").expect("There should be a file");
    let input: Vec<&str> = binding.lines().collect();
    let mut points: Vec<(i64, i64)> = vec![];
    let mut grid_x: i64 = 0;
    let mut grid_y: i64 = 0;
    for p in input {
        let tmp: Vec<&str> = p.split(',').collect();
        let pt: (i64, i64) = (
            tmp[0].parse().expect("Should be numeric"),
            tmp[1].parse().expect("Should be numeric"),
        );
        grid_x = cmp::max(grid_x, pt.0);
        grid_y = cmp::max(grid_y, pt.1);
        points.push(pt);
    }

    // Brute-force every possible combination and keeping track of the biggest
    let mut result = 0;
    for p1 in &points {
        for p2 in 1..points.len() {
			result = cmp::max(result, area(*p1, points[p2]));
        }
    }
    println!("The maximum rectangle has an area of {}", result);
}
