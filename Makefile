# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slangero <slangero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/05 11:00:32 by slangero          #+#    #+#              #
#    Updated: 2024/09/05 13:38:27 by slangero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



##################################DIRECTORIES
aSRCS = ft_printf/ft_printf.c \
		ft_printf/print_charstr.c \
		ft_printf/print_nbr.c \
		ft_printf/print_pointer.c \

###################################VARIABLES

SRCS = main.c \
		process.c \
		execute_command.c \

NAME = pipex

LIB = ft
LIB_DIR = /Users/slangero/0_libft
LIB_FLAGS = -L$(LIB_DIR) -l$(LIB)
LIB_INC = $(LIB_DIR)

INC_FLAGS = -I$(LIB_INC)

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB_FLAGS) $(INC_FLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re