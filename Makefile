# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slangero <slangero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/05 11:00:32 by slangero          #+#    #+#              #
#    Updated: 2024/10/07 20:18:06 by slangero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PIPEX_SRCS =	main.c \
				process.c \
				fork_pipe.c \
				execute_command.c \
				extract_env.c \
				create_exec_path.c \
				error_free.c \

PRINTF_SRCS =	ft_printf/ft_printf.c \
				ft_printf/print_charstr.c \
				ft_printf/print_nbr.c \
				ft_printf/print_pointer.c \

UTILS_SRCS =	utils/ft_strlen.c \
				utils/ft_split.c \
				utils/ft_strjoin.c \
				utils/ft_strncmp.c \
				utils/ft_substr.c \
				utils/ft_strdup.c \
				utils/ft_putstr_fd.c \

SRCS = $(PIPEX_SRCS) $(PRINTF_SRCS) $(UTILS_SRCS) 

OBJS = $(SRCS:.c=.o)

NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

INC = -I. -Ift_printf -Iutils

RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re