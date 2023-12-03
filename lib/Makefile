##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME	=	libmy.a

CC	=	gcc

RM	=	rm -rf

CFLAGS	=	-I ./include/ -Wextra -Wall

OBJ	=	$(SRC:.c=.o)

ARRC 	= 	ar rc

COPYH	= 	cp include/*.h ../include/

SRC	=	my_putchar.c		\
		my_putstr.c		\
		my_strlen.c		\
		my_lenarray.c		\
		my_ischar.c		\
		my_isnum.c		\
		my_put_nbr.c		\
		my_perror.c		\
		my_parray.c		\
		my_strlen.c		\
		my_lenarray.c		\
		my_strcmp.c		\
		my_strncmp.c		\
		my_strcpy.c		\
		my_strcat.c		\
		my_strdup.c		\
		my_printf.c		\
		my_str_to_array.c	\
		my_free_array.c		\

all :	$(NAME)

$(NAME):	$(OBJ)
	$(ARRC) $(NAME) $(OBJ)
	ranlib $(NAME)
	$(COPYH)

fclean :	clean
	$(RM) $(NAME) *.o *~ \#*\#*

re :	fclean all

.PHONY:	all clean fclean re
