pub fn is_invalid_id_pt1( id: u64 ) -> u64 {
    if !id.to_string().chars().count().is_multiple_of(2) {
        0
    }
    else {
        let tmp_str: String = id.to_string();
        let len = tmp_str.chars().count();
        let mut idx: usize = 0;
        while idx + len / 2 < len {
            if tmp_str.chars().nth(idx) != tmp_str.chars().nth(idx + len / 2) {
                return 0;
            }
            idx += 1;
        }
        id
    }
}

pub fn is_invalid_id_pt2( id: u64 ) -> u64 {

    let tmp_str: &str = &id.to_string();
    let len = tmp_str.chars().count();
    let mut chunk_size: usize = 1;

    while chunk_size <= len / 2 {
        if len.is_multiple_of(chunk_size) {
            let owner = tmp_str.chars().collect::<Vec<char>>();
            let mut iter = owner.chunks_exact(chunk_size);
            let mut last = iter.next();
            let mut flag = true;
            for it in iter {
                if last != Some(it) {
                    flag = false;
                    continue;
                }
                last = Some(it);
            }
            if flag {
                return id;
            }
        }
        chunk_size += 1;
    }
    0
}
