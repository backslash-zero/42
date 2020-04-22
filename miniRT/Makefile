# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 17:25:36 by cmeunier          #+#    #+#              #
#    Updated: 2020/04/22 17:23:47 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =			gcc

FLAGS =			-Wall -Wextra -Werror

LEAK_CHECK =	-fsanitize=address

#GRAPHIC_LIBS =	-framework OpenGL -framework AppKit
GRAPHIC_LIBS =	-lm -lbsd -lX11 -lXext

COMPIL =		$(FLAGS) $(LEAK_CHECK)

RM =			@rm -rf

DIR_HEADERS =	./incs/

DIR_SRCS =		./srcs/

DIR_LIBMLX =	./minilibx/

DIR_OBJS =		./obj/

SRC =			main.c								\
				maths/angles.c						\
				maths/rotations.c					\
				maths/vector_op_1.c					\
				maths/vector_op_2.c					\
				maths/vector_op_3.c					\
				mlx/key_bindings_1.c				\
				mlx/key_bindings_2.c				\
				mlx/rt_mlx_1.c						\
				mlx/rt_mlx_2.c						\
				mlx/save_image.c					\
				parsing/parsing_cameras.c			\
				parsing/parsing_lights.c			\
				parsing/parsing_main.c				\
				parsing/parsing_scene.c				\
				parsing/parsing_skip.c				\
				parsing/parsing_objects.c			\
				parsing/parsing_test_objects.c 		\
				parsing/parsing_test_others.c 		\
				parsing/parsing_objects_utils.c		\
				parsing/parsing_tracker.c			\
				raytracing/intersections.c			\
				raytracing/lights_1.c				\
				raytracing/lights_2.c				\
				raytracing/lights_3.c				\
				raytracing/normals.c				\
				raytracing/object_intersection_1.c	\
				raytracing/object_intersection_2.c	\
				raytracing/viewport.c				\
				utils/colors.c						\
				utils/exit_1.c						\
				utils/exit_2.c						\
				utils/ft_atoi.c						\
				utils/ft_atoi_double.c				\
				utils/ft_bzero.c					\
				utils/ft_itoa.c						\
				utils/ft_strlen.c					\
				utils/ft_strjoin_free.c				\
				utils/ft_strncmp.c					\
				utils/ft_susbtr.c					\
				utils/get_line_break.c				\
				utils/get_next_line.c				\

SRCS =			$(addprefix $(DIR_SRCS), $(SRC))

OBJS =			$(SRCS:%.c=%.o)	

LIBMLX =		$(addprefix $(DIR_LIBMLX), *.o)		 \
				$(addprefix $(DIR_LIBMLX), libmlx.a) \


NAME =			miniRT

all:			
				$(MAKE) $(NAME)
				#$(MAKE) -j $(NAME)

$(NAME): 		$(OBJS)
				@echo "☑️  Compiled ALL OBJECTS successfully!"
				$(CC) $(COMPIL) -I $(DIR_HEADERS) $(LIBMLX) $(OBJS) -o $(NAME) $(GRAPHIC_LIBS)

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