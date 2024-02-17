all: bubble insertion select

bubble: 0-bubble_sort.c 0-main.c print_array.c
	gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 0-bubble_sort.c 0-main.c print_array.c -o bubble -g

insertion: 1-main.c 1-insertion_sort_list.c print_list.c
	gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 1-main.c 1-insertion_sort_list.c print_list.c -o insertion -g

select: 2-main.c 2-selection_sort.c print_array.c
	gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 2-main.c 2-selection_sort.c print_array.c -o select

