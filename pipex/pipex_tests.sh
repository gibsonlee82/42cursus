#!/bin/bash

# Test file setup
echo -e "hello world\nthis is a test\nhello again" > input.txt

# Test 1: Simple grep and wc
./pipex input.txt "grep hello" "wc -l" output1.txt
echo "\n[Test 1] grep 'hello' | wc -l"
cat output1.txt

# Test 2: Cut and sort
./pipex input.txt "cut -d' ' -f1" "sort" output2.txt
echo "\n[Test 2] cut first word | sort"
cat output2.txt

# Test 3: Multiple spaces and casing
./pipex input.txt "tr A-Z a-z" "sort" output3.txt
echo "\n[Test 3] lowercase and sort"
cat output3.txt

# Test 4: Error handling (invalid command)
./pipex input.txt "badcmd" "wc -l" output4.txt
echo "\n[Test 4] Invalid command should trigger error"
cat output4.txt

# Test 5: Missing input file
./pipex notfound.txt "cat" "wc -l" output5.txt
echo "\n[Test 5] Missing input file"
cat output5.txt

# Cleanup
echo "\nDone. Outputs: output1.txt to output5.txt"
