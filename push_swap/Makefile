PUSH_SWAP = push_swap
CHECKER = checker
INCLUDES = -I./ -I my_checker/get_next_line.h
OBJ_PS =	main.o\
		check_error.o\
		utile.o\
		utile2.o\
		insert_stack.o\
		instraction1.o\
		instraction2.o\
		list_function2.o\
		sorting.o\
		ft_sort_tow.o\
		ft_sort_three.o\
		sort_for.o\
		sort_five.o\
		ft_sort_stack.o\
		ft_sort_a.o\
		ft_pivot.o\
		ft_put.o\
		quick_sort.o\
		sort_three.o\
		add_oper.o\
		clear_memory.o\
		optimiser.o\
		optimiser1.o\
		optimiser2.o

OBJ_CH = check_error.o\
			clear_memory.o\
			insert_stack.o\
			instraction1.o\
			instraction2.o\
			utile.o\
			utile2.o\
			my_checker/checker.o\
			my_checker/get_next_line.o\
			my_checker/get_next_line_utils.o

all: $(OBJ_CH) $(OBJ_PS)
	@ $(CC) -Wall -Wextra -Werror $(OBJ_PS) -o $(PUSH_SWAP)
	@ $(CC) -Wall -Wextra -Werror $(OBJ_CH) -o $(CHECKER)
	@ echo "\x1b[32m Project is successfully compiled \x1b[0m"

%.o : ./%.c
	@ $(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)
	@ echo "\x1b[32m Compiling object files \x1b[0m"

clean:
	@ rm -f $(OBJ_PS)
	@ rm -f $(OBJ_CH)

fclean: clean
	@ rm -f push_swap
	@ rm -f checker
	@ echo "\x1b[31m You deleted all object files in this project \x1b[0m"

re: fclean all