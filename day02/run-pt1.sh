#!/usr/bin/env bash

cd src
cargo build --release --bin p1 --quiet
cargo run --bin p1 --quiet
cargo clean --quiet
