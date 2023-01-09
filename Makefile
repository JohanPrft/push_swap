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

HEADERS	=	push_swap.h

INCLUDES=	$(addprefix includes/, ${HEADERS})

SRCFILE=	push_swap_utils.c		push_swap_struct.c		push_swap_op.c		\
			push_swap_op1.c			push_swap_op2.c			create_index.c		\
			sort_algo.c				push_swap.c

SRCS	=	$(addprefix src/, ${SRCFILE})

OBJS	=	$(SRCS:.c=.o)

LIBDIR	=	libft/

LIB		= 	libft.a

LIBFULL	=	$(addprefix $(LIBDIR), $(LIB))

LIBSHORT=	$(LIB:lib%.a=%)

# **************************************************************************** #
# RULES

all: 			makelib ${NAME}

makelib:
				@$(MAKE) -C $(LIBDIR)

${NAME}:		${OBJS}
				$(CC) ${FLAGS} -L ${LIBDIR} -l${LIBSHORT} ${OBJS} -o $@

%.o:			%.c ${INCLUDES} Makefile
				${CC} ${FLAGS} -c $< -o $@

clean:
				$(MAKE) clean -C $(LIBDIR)
				$(RM) ${OBJS}

fclean:			clean
				$(MAKE) fclean -C $(LIBDIR)
				$(RM) ${NAME}

re:				fclean
				$(MAKE) all

.PHONY:			all makelib clean fclean re
