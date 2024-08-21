# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slangero <slangero@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 15:21:14 by slangero          #+#    #+#              #
#    Updated: 2024/07/16 21:09:46 by slangero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###########################DIRECTORIES
SRCS = ft_printf.c \
		print_charstr.c \
		print_nbr.c \
		print_pointer.c \

###########################VARIABLES

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

DFLAGS = -g -fsanitize=address

GCC = gcc

RM = rm -f

NAME = libftprintf.a

APPNAME = monapplication

#############################TARGETS

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}
	@echo "libft has compiled successfully"

%.o: %.c
	${GCC} ${CFLAGS} -c $^ -o $@ 

exec: ${NAME}
	${GCC} ${CFLAGS} main.o ${NAME}

##############################

clean:
	${RM} ${OBJS}
	@echo ".o files have been CLEAN"

fclean: clean
	${RM} ${NAME}
	@echo "libft has been FULL CLEAN"

re: fclean all

##############################

.PHONY: all clean fclean re
