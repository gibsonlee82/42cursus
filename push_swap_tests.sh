#!/bin/bash

make re CFLAGS="-g -Wall -Wextra -Werror"

run_test() {
    echo "Test: $1"
    shift
    valgrind --leak-check=full --show-leak-kinds=all ./push_swap "$@"
    echo
}

run_test "Already sorted" 1 2 3
run_test "Reverse sorted" 3 2 1
run_test "Random small" 2 1 3
run_test "Five numbers" 5 2 4 1 3
run_test "Duplicate numbers" 1 2 2
run_test "Negative numbers" -3 -1 -2 0 1
run_test "Single number" 42
run_test "No arguments"

