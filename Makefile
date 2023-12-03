##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## Makefile
##

NAME	=	mysh

CC	=	gcc

WCC	=	gcc -g3

CFLAGS	= 	-I ./include/ -W -Wall -Wextra

LFLAGS 	= 	-L ./lib/ -lmy

RM	= 	rm -f

SRC	=	src/main.c		\
		src/signal.c		\
		src/check_cmd.c		\
		src/cmd.c		\
		src/setenv.c		\
		src/tools_setenv.c	\
		src/unsetenv.c		\
		src/cd.c		\
		src/tools_cd.c		\
		src/exec_cmd.c		\
		src/error.c		\
		src/set_reset_free.c	\

all: $(NAME)

$(NAME): build_lib build_src

w : build_lib_w build_src_w

build_lib :
	make -C ./lib/

build_lib_w :
	make -C ./lib/

build_src :
	$(CC) $(SRC) $(CFLAGS) $(LFLAGS) -o $(NAME)

build_src_w :
	$(WCC) $(SRC) $(CFLAGS) $(LFLAGS) -o $(NAME)

clean:
	$(RM) *~ \#*\#*

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./lib/

re: fclean all

git:
	git add .
	git commit -m "$m"
	git push -u origin main

.PHONY: all w build_lib build_lib_w build_src clean fclean re git
