# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slangero <slangero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/05 11:00:32 by slangero          #+#    #+#              #
#    Updated: 2024/08/21 17:12:08 by slangero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



##################################DIRECTORIES
SRCS = main.c \
		ft_printf/ft_printf.c \
		ft_printf/print_charstr.c \
		ft_printf/print_nbr.c \
		ft_printf/print_pointer.c \

###################################VARIABLES

NAME = pipex


OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) 

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re