ARG=$(seq -500 500 | shuf | head -n 500 | tr '\n' ' ')

valgrind ./push_swap $ARG | wc -l
