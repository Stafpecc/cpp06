#!/bin/bash

make

tests=(
    "a"
    "z"
    "0"
    "7"
    "42"
    "127"
    "128"
    "-1"
    "3.14"
    "3.14f"
    "0.0"
    "-42"
    "999999999999999999999999"
    "12abc"
    "'a'"
    "'\\x07'"
    "-inf"
    "+inf"
    "nan"
    "-inff"
    "+inff"
    "nanf"
)

for test in "${tests[@]}"; do
    echo "=== Testing: $test ==="
    ./exec/Scalarconverter "$test"
    echo
done