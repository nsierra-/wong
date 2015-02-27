# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 19:54:32 by nsierra-          #+#    #+#              #
#    Updated: 2015/01/04 16:41:19 by nsierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

TESTNAME = testa

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	  ft_isprint.c ft_memcpy.c ft_memset.c ft_strcat.c ft_strchr.c ft_strcmp.c \
	  ft_strcpy.c ft_strdup.c ft_strlen.c ft_strncat.c ft_strncmp.c \
	  ft_strncpy.c ft_strrchr.c ft_strstr.c ft_tolower.c ft_toupper.c \
	  ft_putchar.c ft_putstr.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_putendl_fd.c \
	  ft_sisascii.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	  ft_lstmap.c ft_lstpush.c


TSRC =  ft_strlcat.c \
	  ft_strnstr.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
	  ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	  ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
	  ft_strsplit.c ft_itoa.c ft_putnbr.c ft_putnbr_fd.c ft_set_new_str.c


OBJ = $(SRC:.c=.o) $(TSRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I . -c $(SRC) $(TSRC)
	ar rc  $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(TESTNAME)

test: fclean all
	$(CC) -o $(TESTNAME) $(SRC) $(TSRC) main.c -L./ -lft
	./$(TESTNAME)

testd: fclean
	$(CC) -g -o $(TESTNAME) $(SRC) $(TSRC) main.c
	gdb testlib

re: fclean all

ret: fclean test
	./$(TESTNAME)
