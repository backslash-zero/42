# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 17:25:36 by cmeunier          #+#    #+#              #
#    Updated: 2020/01/29 17:51:22 by cmeunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =			gcc

FLAGS =			-Wall -Wextra -Werror

LEAK_CHECK =	-fsanitize=address

GRAPHIC_LIBS =	-framework OpenGL -framework AppKit

COMPIL =		$(FLAGS) $(LEAK_CHECK)

RM =			rm -rf

DIR_HEADERS =	./incs/

DIR_SRCS =		./srcs/

DIR_OBJS =		./obj/

SRC =			main.c							\
				parsing/scene.c					\
				utils/ft_bzero.c				\
				utils/ft_strjoin_free.c			\
				utils/ft_susbtr.c				\
				utils/get_line_break.c			\
				utils/get_next_line.c			\
				utils/ft_rad.c						\
				maths/vector_op_1.c				\
				maths/vector_op_2.c				\
				maths/vector_op_3.c				\

SRCS =			$(addprefix $(DIR_SRCS), $(SRC))

OBJS =			$(SRCS:.c=.o)

LIBMLX =		/usr/local/lib/libmlx.a \

NAME =			miniRT

all:			$(NAME)

$(NAME): 		$(OBJS)
				$(CC) $(COMPIL) -I $(DIR_HEADERS) $(LIBMLX) $(GRAPHIC_LIBS) $(OBJS) -o $(NAME)

%.o: %.c
				@gcc $(FLAGS) -I $(DIR_HEADERS) -c $< -o $@
				@echo "Compiled "$<" successfully!"

norme:
				norminette $(DIR_SRCS)
				norminette $(DIR_HEADERS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all, clean, fclean, re, bonus