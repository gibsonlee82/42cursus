echo "================Sort Test 1 (list: 6 elements)====================="
echo "./push_swap 2 1 3 6 5 8"
./push_swap 2 1 3 6 5 8

echo "=================Sort Test 2 (ARG input: 5 elements)==================="
echo "ARG='4 67 3 87 23'; ./push_swap $ARG | wc -l"
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

echo "================Sort Test 3 (checker_linux)====================="
echo "ARG='4 67 3 87 23'; ./push_swap $ARG | ./checker_linux $ARG"
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG

echo "=================Sort Test 4 (list: 4 elements)==================="
echo "ARG='4 67 3 87'; ./push_swap $ARG"
ARG="4 67 3 87"; ./push_swap $ARG

echo "=================Sort Test 5 (3 elements)==================="
echo "ARG='4 67 3'; ./push_swap $ARG | wc -l"
ARG="4 67 3"; ./push_swap $ARG

echo "=================Sort Test 6 (2 elements)==================="
echo "ARG='67 3'; ./push_swap $ARG | wc -l"
ARG="67 3"; ./push_swap $ARG

echo "=================Sort Test 7 (1 elements)==================="
echo "ARG='4'; ./push_swap $ARG | wc -l"
ARG="4"; ./push_swap $ARG

echo "=================Sort Test 8 (0 element)==================="
echo "./push_swap"
./push_swap

echo "=================Error Input (two)==================="
echo "./push_swap 1 two 4 3"
./push_swap 1 two 4 3

echo "=================Error Input (duplicate)==================="
echo "./push_swap 1 3 4 3"
./push_swap 1 3 4 3

echo "=================Error Input (INT_MAX)==================="
echo "./push_swap 2147483647"
./push_swap 2147483647

echo "=================Error Input (INT_MIN)==================="
echo "./push_swap -2147483648"
./push_swap -2147483648

echo "===============Leak Check (letters)=========================="
echo "valgrind ./push_swap --leak-check=full --show-leak-kinds=all 1 two 4 3"
valgrind ./push_swap --leak-check=full --show-leak-kinds=all 1 two 4 3

echo "===============Leak Check (ordered list)=========================="
echo "valgrind ./push_swap --leak-check=full --show-leak-kinds=all 1 2 3 4"
valgrind ./push_swap --leak-check=full --show-leak-kinds=all 1 2 3 4

echo "===============Leak Check (unordered list)=========================="
echo "valgrind ./push_swap --leak-check=full --show-leak-kinds=all 2 1 3 4"
valgrind ./push_swap --leak-check=full --show-leak-kinds=all 2 1 3 4

echo "===============Leak Check (duplicate numbers)=========================="
echo "valgrind ./push_swap --leak-check=full --show-leak-kinds=all 2 1 2 4"
valgrind ./push_swap --leak-check=full --show-leak-kinds=all 2 1 2 4

echo "===============Leak Check (>INT_MAX)=========================="
echo "valgrind ./push_swap --leak-check=full --show-leak-kinds=all 111111111111111111111111111111"
valgrind ./push_swap --leak-check=full --show-leak-kinds=all 111111111111111111111111111111