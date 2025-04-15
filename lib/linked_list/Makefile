##
## EPITECH PROJECT, 2024
## makefile
## File description:
## root makefile
##

SRC =	add_linked_list.c 			\
		del_linked_list.c			\
		disp_linked_list.c			\
		list_to_linked_list.c		\
		linked_list_len.c			\
		linked_list_to_list.c		\
		delete_linked_list.c		\

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra

CPPFLAGS = -iquote ../../include

NAME = liblinked_list.a

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all	clean fclean re
