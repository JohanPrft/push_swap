# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 10:10:32 by jprofit           #+#    #+#              #
#    Updated: 2022/12/12 14:34:23 by jprofit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# ARGUMENTS

NAME	=	libpush_swap.a

FLAGS	=	-Wall -Wextra -Werror

HEADER	=	push_swap.h

SRCS	=	push_swap.c

OBJS	=	$(SRCS:.c=.o)

LIBDIR	=	libft/

# **************************************************************************** #
# RULES

all: 			${NAME}

${NAME}:		${OBJS}
				$(MAKE) -C $(LIBDIR)
				$(AR) rcs $@ $^

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
