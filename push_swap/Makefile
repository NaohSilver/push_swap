# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/08 01:33:55 by niludwig          #+#    #+#              #
#    Updated: 2017/07/10 17:27:04 by niludwig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = PUSH_SWAP
CC = gcc
CFLAG = -Wall -Werror -Wextra

PUSH = main.c

OBJ_PUSH = $(PUSH:.c=.o)

LIBFT_PATH = ./libft/libft/
LIBFT_NAME = libft.a
PRINT_PATH = ./libft/
PRINT = libftprintf.a

RM = rm -f

all: $(PUSH)

$(PUSH_SWAP): $(OBJ_PUSH)
	@echo "Creating exec"
	@$(MAKE) -C $(LIBFT_PATH) > /dev/null
	@$(CC) -o $(PUSH_SWAP) $(OBJ_PUSH) -L. $(LIBFT_PATH)$(LIBFT_NAME) $(PRINT_PATH)$(PRINT)

%.o: %.c
	@$(CC) $(CFLAG) -o $@ -c $<

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJ_PUSH)

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(PUSH_SWAP)

re: fclean all
