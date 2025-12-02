use day02::is_invalid_id_pt1 as is_invalid;

fn main() {
    let input: &'static str = include_str!("../../../input/input.txt");

    let mut tup_ranges: Vec<(u64, u64)> = Vec::new();
    for range in input.split(',') {
        if range.contains('-') {
            let tmp: Vec<&str> = range.split('-').collect();
            tup_ranges.push((tmp[0].trim_matches('\n').parse().unwrap(), tmp[1].trim_matches('\n').parse().unwrap()));
        }
    }

    let mut result: u64 = 0;
    let mut idx: u64;
    for range in tup_ranges.iter_mut() {
        idx = 0;
        while range.0 + idx <= range.1 {
            result += is_invalid(range.0 + idx);
            idx += 1;
        }
    }
    println!("Your puzzle answer was: {result}");
}
