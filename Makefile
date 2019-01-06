##
## EPITECH PROJECT, 2018
## philosophers
## File description:
## Makefile
##


NAME	= philo

SRC	= src/main.c \
	src/table_of_phil.c \
	src/join_thread.c \
	src/eat.c \
	src/think_rest.c

OBJ	= $(SRC:.c=.o)

CC	= gcc

ifeq ($(DEBUG),1)
CFLAGS	+= -g3 -ggdb
endif

CFLAGS	+= -W -Wall -Wextra -L./lib -I./include -lriceferee -lpthread

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) -g

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
