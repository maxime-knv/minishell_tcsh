##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## zz
##

SRC     =	mini_printf.c			\
		my_compute_power_rec.c		\
		my_compute_square_root.c	\
		my_find_prime_sup.c		\
		my_getnbr.c			\
		my_is_prime.c			\
		my_putchar.c			\
		my_put_nbr.c			\
		my_putstr.c			\
		my_revstr.c			\
		my_showmem.c			\
		my_showstr.c			\
		my_sort_int_array.c		\
		my_strcapitalize.c		\
		my_strcat.c			\
		my_strcmp.c			\
		my_strcpy.c			\
		my_strdup.c			\
		my_str_isalpha.c		\
		my_str_islower.c		\
		my_str_islower.c		\
		my_str_isnum.c			\
		my_str_isprintable.c		\
		my_str_isupper.c		\
		my_strlen.c			\
		my_strlowcase.c			\
		my_strncat.c			\
		my_strncmp.c			\
		my_strcpy.c			\
		my_strncpy.c			\
		my_strstr.c			\
		my_strupcase.c			\
		my_swap.c			\
		my_str_to_word_array.c		\
		my_arrlen.c					\
		my_cut_last_char.c			\
		my_is_in.c					\
		my_getenv.c					\
		free_all.c					\
		my_strndup.c				\
		parse_arr.c

OBJ     =       $(SRC:.c=.o)

NAME    =	libmy.a			\

CPPFLAGS	=	-iquote ../../include -g3

all:    $(NAME)

$(NAME):	$(OBJ)
	$(AR) rc $(NAME) $(OBJ)
	cp $(NAME) ../../
	mkdir -p ../../include
	cp my.h ../../include
clean:
	$(RM) $(OBJ)
	$(RM) *.o
	$(RM) *#
	$(RM) *~

fclean: clean
	$(RM) $(NAME)
	$(RM) ../libmy.a

re:	fclean all

.PHONY: all clean fclean re
