##
## EPITECH PROJECT, 2025
## makefile
## File description:
## root makefile
##

CC ?= gcc

PATH_UNI = ./tests/unitest/test_42sh.c

INCLUDE_DIR = include

MAIN = src/main.c

SRC = 	$(addprefix src/, 					\
		mysh.c								\
		\
		built-in/cd/do_cd.c					\
		built-in/exit/do_exit.c				\
		built-in/env/do_env.c				\
		built-in/env/do_setenv.c			\
		built-in/env/do_unsetenv.c			\
		built-in/env/get_env_var.c			\
		built-in/env/is_env_var.c			\
		\
		parsing/wich_path.c					\
		parsing/make_tree.c					\
		parsing/get_input.c					\
		parsing/check_tree.c				\
		parsing/format_cmd.c				\
		parsing/wave.c 	                    \
		\
		operators/exec_rr_r.c				\
		operators/error_branch.c			\
		operators/exec_pipe.c				\
		operators/exec_r.c					\
		operators/exec_rr.c					\
		operators/exec_l.c					\
		operators/exec_ll.c					\
		\
		execution/do_existing_command.c		\
		execution/exec_proper_function.c	\
		execution/exec_command_no_fork.c	\
		execution/exec_command.c			\
		execution/exec_operator.c			)

OBJ = $(SRC:.c=.o) $(MAIN:.c=.o)

TESTS = tests_run

CFLAGS = -Wall -Wextra

CPPFLAGS = -iquote include

LDFLAGS = -L lib/linked_list/ -L lib/my

LDLIBS = -llinked_list -lmy

NAME = mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	make -C lib/linked_list/
	$(CC) -o $(NAME) $(OBJ) $(LDLIBS) $(LDFLAGS)

debug: CFLAGS += -g3
debug: fclean $(OBJ)
	make -C lib/my/ CFLAGS+=-g3
	make -C lib/linked_list/ CFLAGS+=-g3
	$(CC) -o $(NAME) $(OBJ) $(LDLIBS) $(LDFLAGS)

$(TESTS): LDFLAGS += --coverage -lcriterion
$(TESTS):
	$(CC) -o $(TESTS) $(SRC) $(PATH_UNI) \
		$(LDLIBS) $(CPPFLAGS) $(LDFLAGS)
	./$(TESTS)

uni_clean:
	$(RM) $(TESTS)*

clean:
	make -C lib/my/ clean
	make -C lib/linked_list/ clean
	$(RM) $(OBJ)

fclean:	clean uni_clean
	make -C lib/my/ fclean
	make -C lib/linked_list/ fclean
	$(RM) $(NAME)

re: fclean all

tests:
	./tests/cmp.sh

tester: re
	./tests/test.sh

.PHONY: all debug clean fclean re tests tester uni_clean
