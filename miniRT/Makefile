# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 17:25:36 by cmeunier          #+#    #+#              #
#    Updated: 2020/03/11 11:34:17 by cmeunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =			gcc

FLAGS =			-Wall -Wextra -Werror

LEAK_CHECK =	-fsanitize=address

GRAPHIC_LIBS =	-framework OpenGL -framework AppKit

COMPIL =		$(FLAGS) $(LEAK_CHECK)

RM =			@rm -rf

DIR_HEADERS =	./incs/

DIR_SRCS =		./srcs/

DIR_OBJS =		./obj/

SRC =			main.c								\
				maths/angles.c						\
				maths/rotations.c					\
				maths/vector_op_1.c					\
				maths/vector_op_2.c					\
				maths/vector_op_3.c					\
				mlx/RT_mlx.c						\
				mlx/save_image.c					\
				parsing/parsing_cameras.c			\
				parsing/parsing_lights.c			\
				parsing/parsing_main.c				\
				parsing/parsing_scene.c				\
				parsing/parsing_objects.c			\
				parsing/parsing_tracker.c			\
				raytracing/intersections.c			\
				raytracing/lights_1.c				\
				raytracing/lights_2.c				\
				raytracing/normals.c				\
				raytracing/object_intersection.c	\
				raytracing/viewport.c				\
				utils/colors.c						\
				utils/exit.c						\
				utils/ft_atoi.c						\
				utils/ft_atoi_double.c				\
				utils/ft_bzero.c					\
				utils/ft_strlen.c					\
				utils/ft_strjoin_free.c				\
				utils/ft_strncmp.c					\
				utils/ft_susbtr.c					\
				utils/get_line_break.c				\
				utils/get_next_line.c				\

SRCS =			$(addprefix $(DIR_SRCS), $(SRC))

OBJS =			$(SRCS:%.c=%.o)	

LIBMLX =		/usr/local/lib/libmlx.a				\

NAME =			miniRT

all:			
				$(MAKE) -j $(NAME)

$(NAME): 		$(OBJS)
				$(CC) $(COMPIL) -I $(DIR_HEADERS) $(LIBMLX) $(GRAPHIC_LIBS) $(OBJS) -o $(NAME)

%.o: %.c
				@gcc $(FLAGS) -I $(DIR_HEADERS) -c $< -o $@
				@echo "☑️  Compiled "$<" successfully!"

norme:
				norminette $(DIR_SRCS)
				norminette $(DIR_HEADERS)

clean:
				$(RM) $(OBJS)
				@echo "🗑️  Removed .o files successfully"$<"!"

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all, clean, fclean, re, bonus