#!/bin/bash

# pipex_tests.sh - Automated tests for pipex project

# Test file setup
echo -e "Hello world.\nThis is a test.\nHello again." > input.txt

echo -e "input.txt:\nHello world.\nThis is a test.\nHello again."

separator="========================================="

# Helper function to display output if file exists
print_output() {
    local file=$1
    if [[ -f "$file" ]]; then
        cat "$file"
    else
        echo "(No output: $file not found)"
    fi
}

# -------------------------
# Test 1: Simple grep and wc
# -------------------------
printf "\n$separator\n[Test 1] grep 'hello' | wc -l\n"
./pipex input.txt "grep hello" "wc -l" output1.txt
print_output output1.txt

# -------------------------
# Test 2: Lowercase and sort
# -------------------------
printf "\n$separator\n[Test 3] lowercase and sort\n"
./pipex input.txt "tr A-Z a-z" "sort" output2.txt
print_output output2.txt

# -------------------------
# Test 3: Invalid command
# -------------------------
printf "\n$separator\n[Test 4] Invalid command should trigger error\n"
./pipex input.txt "badcmd" "wc -l" output3.txt
print_output output3.txt

# -------------------------
# Test 4: Missing input file
# -------------------------
printf "\n$separator\n[Test 4] Missing input file\n"
./pipex notfound.txt "cat" "wc -l" output4.txt
print_output output4.txt

# -------------------------
# Done
# -------------------------
printf "\n$separator\nDone. Outputs: output1.txt to output4.txt\n"
