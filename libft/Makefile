# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/09 17:00:46 by gcadel            #+#    #+#              #
#    Updated: 2015/10/09 17:01:17 by gcadel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_putchar.c \
		ft_putstr.c \
		ft_memset.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_bzero.c \
		ft_strcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strncpy.c \
		ft_putnbr.c \
		ft_putendl.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_strlcat.c \
		ft_itoa.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_swapint.c \
		ft_swapstr.c \
		ft_intlen.c \
		ft_quicksort.c \
		get_next_line.c \
		ft_arrcpy.c \
		ft_arrlen.c \
		ft_arrfree.c \
		ft_joinarray.c \
		ft_epur_tab.c

OBJ = $(SRC:.c=.o)

CC = gcc -I./includes

CFLAGS = -Wall -Wextra -Werror -g

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo ""
	@echo "libft compiled !"

%.o: %.c
	@echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@echo "Objects deleted !"
	@/bin/rm -rf $(OBJ)

fclean: clean 
	@echo "libft.a deleted !"
	@/bin/rm -rf $(NAME) a.out

re: fclean all

.PHONY: all re fclean clean
