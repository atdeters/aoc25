#!/usr/bin/env bash

cd src
cargo build --release --bin p2 --quiet
cargo run --bin p2 --quiet
cargo clean --quiet
