all: bubble insertion select quick shell

bubble: 0-bubble_sort.c 0-main.c print_array.c
	gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 0-bubble_sort.c 0-main.c print_array.c -o bubble -g

insertion: 1-main.c 1-insertion_sort_list.c print_list.c
	gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 1-main.c 1-insertion_sort_list.c print_list.c -o insertion -g

select: 2-main.c 2-selection_sort.c print_array.c
	gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 2-main.c 2-selection_sort.c print_array.c -o select -g 

quick: 3-main.c 3-quick_sort.c print_array.c
	gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 3-main.c 3-quick_sort.c print_array.c -o quick -g

shell: 100-main.c 100-shell_sort.c print_array.c
	gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 100-main.c 100-shell_sort.c print_array.c -o shell
