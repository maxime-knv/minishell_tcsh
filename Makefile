##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

CC 	?=	gcc

SRC	=	src/mysh.c						\
		src/get_user_input.c			\
		src/separators/is_semilicon.c	\
		src/separators/is_pipe.c     	\
		src/separators/is_one_left.c	\
		src/separators/is_two_left.c	\
		src/separators/is_one_right.c	\
		src/separators/is_two_right.c	\
		src/tree/create_tree_node.c		\
		src/tree/create_tree.c     		\
		src/tree/print_tree.c 			\
		src/separators/get_sep.c		\
		src/utils/get_priority_index.c	\
		src/utils/cut_array.c         	\
		src/utils/get_new_str_from_arr.c\
		src/execute_command.c			\
		src/path_of_command.c			\
		src/buid_in/is_cd.c				\
		src/buid_in/is_setenv.c			\
		src/buid_in/is_unsetenv.c		\
		src/buid_in/get_build.c 		\
		src/utils/parse_array.c			\
		src/change_directory.c			\
		src/envirement/create_node.c	\
		src/envirement/create_val.c		\
		src/envirement/print_list.c		\
		src/envirement/len_linked_list.c\
		src/envirement/list_to_arr.c	\
		src/envirement/add_env_to_list.c\
		src/envirement/setenv_error.c	\
		src/my_mulcat.c					\
		src/my_char_not_in.c			\
		src/envirement/change_env.c		\
		src/envirement/setenv.c			\
		src/buid_in/exec_buid_in.c		\
		src/tree/exec_tree.c			\
		src/utils/search_in_dir.c		\
		src/tree/exec_func_tree.c		\
		src/tree/pipe_func.c			\
		src/tree/rec_exec_tree.c		\
		src/sep_func/one_left_func.c	\
		src/sep_func/two_left_func.c	\
		src/sep_func/semilicon_func.c   \
		src/tree/free_tree.c			\
		src/buid_in/is_env.c			\
		src/sep_func/one_right_func.c	\
		src/sep_func/two_right_func.c	\
		src/buid_in/is_exit.c

OBJ     =   $(SRC:.c=.o)

NAME    =	mysh

LIB	=	make -C lib/my/

CPPFLAGS += -iquote./include -lcrypt

CFLAGS += -Wall -Wextra

CPPFLAGS += -iquote include/

VALGRIND = -g3

all:	$(OBJ)
	$(LIB)
	$(CC)  -o $(NAME) $(SRC) -L lib/my/ -lmy $(CPPFLAGS) -g3
	# clear

val:	$(OBJ)
	$(LIB)
	$(CC) -o $(NAME) $(VALGRIND) $(CFLAGS) $(SRC) -L lib/my/ -lmy $(CPPFLAGS)
clean:
	make clean -C lib/my/
	$(RM) $(OBJ)
	$(RM) coding-style*
	$(RM) *~
	$(RM) *#
	$(RM) *.o
	$(RM) src/setenv/*.o
	$(RM) src/*.o
	$(RM) src/*~
	$(RM) src/#*
	$(RM) include/*#
	$(RM) include/*~

fclean: clean
	make fclean -C lib/my/
	$(RM) $(NAME)
	$(RM) ./lib/my/libmy.a
	$(RM) libmy.a
	clear

re:	fclean all

t:
	make
	rm tester_2/mysh
	cp mysh tester_2

.PHONY: all clean fclean re
