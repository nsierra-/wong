# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/02 08:22:33 by nsierra-          #+#    #+#              #
#    Updated: 2015/02/27 22:10:01 by nsierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	game_2048

INC_FILES	=
SRC_FILES	=	main.c \
				ncurses_handling.c \
				util.c \
				parse_options.c

SRC			=	$(addprefix src/, $(SRC_FILES))
INC			=	$(addprefix inc/, $(INC_FILES))
OBJ			=	$(SRC:.c=.o)

CC			=	gcc
MAKE		=	make

CFLAGS		=	-g3 -Wall -Wextra -Werror
IFLAGS		=	-I./inc/ -I./libft/
LDFLAGS		=	-L./libft/ -lft -lncurses

$(NAME):		$(INC) $(OBJ)
				$(MAKE) -C libft/
				$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $@

all:			$(NAME)

%.o:			%.c
				$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
				$(MAKE) -C libft/ clean
				rm -rf $(OBJ)

fclean:			clean
				$(MAKE) -C libft/ fclean
				rm -f $(NAME)

re:				fclean all

.PHONY:
