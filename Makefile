# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 10:10:32 by jprofit           #+#    #+#              #
#    Updated: 2022/12/15 11:41:03 by jprofit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# ARGUMENTS

NAME	=	push_swap

FLAGS	=	-Wall -Wextra -Werror -g

HEADER	=	push_swap.h

SRCSFT	=	push_swap_utils.c		push_swap_struct.c		push_swap_op.c		\
			push_swap_op1.c			push_swap_op2.c			create_index.c



SRCS	=	$(addprefix functions/, ${SRCSFT})									\
			push_swap.c

OBJS	=	$(SRCS:.c=.o)

LIBDIR	=	libft/

LIB		=	push_swap

# **************************************************************************** #
# RULES

all: 			${LIB} ${NAME}

${LIB}:			${OBJS}
				$(MAKE) -C $(LIBDIR)
				$(AR) rcs $@ $^

${NAME}:		${LIB}
				$(CC) ${FLAGS} ${OBJS} -l ${LIB} -L ${LIBDIR} -o $@

%.o:			%.c ${HEADER} Makefile
				${CC} ${FLAGS} -c $< -o $@

clean:
				$(MAKE) clean -C $(LIBDIR)
				$(RM) ${OBJS}

fclean:			clean
				$(MAKE) fclean -C $(LIBDIR)
				$(RM) ${NAME}

re:				fclean
				$(MAKE) all

.PHONY:			all clean fclean re
