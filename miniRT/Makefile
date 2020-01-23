# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 17:25:36 by cmeunier          #+#    #+#              #
#    Updated: 2020/01/23 16:28:50 by cmeunier         ###   ########.fr        #
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

SRC =			main.c \
				parsing/scene.c \
				

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