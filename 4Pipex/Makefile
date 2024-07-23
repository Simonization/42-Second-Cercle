# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slangero <slangero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/05 11:00:32 by slangero          #+#    #+#              #
#    Updated: 2024/07/16 21:09:33 by slangero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



##################################DIRECTORIES
SRCS = main.c \
		utils.c \

###################################VARIABLES

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

DLAGS = -g -fsanitize=adress

GCC = gcc 

RM = rm -f

NAME = pipex.a

//APPNAME = monapplication ? 

###################################TARGETS

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}
	@echo "pipex has compiled successfully"

.o: .c 
	${GCC} ${CFLAGS} -c $< -o ${OBJS}
// DFLAGS 
// %.o: %.c
	//${GCC} ${CFLAGS} -c $^ -o $@
//exec: ${NAME}
	// ${GCC} ${CFLAGS} main.o ${NAME}

###################################

clean:
	${RM} ${OBJS}
	@echo ".o files have been cleaned"

fclean: clean
	${RM} ${NAME}
	@echo "pipex has been cleaned thoroughly"

re: fclean all

###################################

.PHONY: all clean fclean re


/***

# OBJETS= SRC(.o=.c)

# $(NAME)

# target: prerequisites
# 	command
# 	command
# 	command

# target: dependency
# 	cc -Wall $(NAME) 

# lib: objets
# 	ar rcs $(OBJETS) $(NAMEofLIB)

# objets: fichiers.c


# all
# clean
# fclean
# re
***/
