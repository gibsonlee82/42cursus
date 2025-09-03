#!/bin/bash

EXEC="./so_long"

# List of map folders to test
MAP_DIRS=("./maps/invalid" "./maps/valid")

for dir in "${MAP_DIRS[@]}"; do
    echo "======================================"
    echo " Running tests in: $dir"
    echo "======================================"

    for file in "$dir"/*.ber; do
        if [ -f "$file" ]; then
            echo ">>> Testing: $file"
            valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes "$EXEC" "$file"
            echo -e "\n"
        fi
    done
done
