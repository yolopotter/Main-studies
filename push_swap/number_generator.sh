ARG=$(seq -800 70000 | shuf -n 500 | paste -sd ' ' -); ./push_swap $ARG | wc -l
