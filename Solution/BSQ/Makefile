# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyeghiaz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/06 12:55:30 by lyeghiaz          #+#    #+#              #
#    Updated: 2020/10/06 12:55:45 by lyeghiaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ${wildcard ./srcs/*.c}
OBJS	= ${SRCS:.c=.o}
INCL	= include
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= BSQ

.c.o :	
			${CC} -I ${INCL} ${CFLAGS} -c $< -o ${<:.c=.o}

all :		${OBJS}
			${CC} -o ${NAME} ${OBJS}

${NAME} :	all

clean :
			rm -f ${OBJS}

fclean :	clean
			rm -f ${NAME}

re :		fclean all
	
.PHONY :	all ${NAME} clean fclean re
