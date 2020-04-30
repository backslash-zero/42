# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 17:25:36 by cmeunier          #+#    #+#              #
#    Updated: 2020/04/28 21:56:09 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =			clang

FLAGS =			-Wall -Wextra -Werror

DEBUG_INFO =	-g

LEAK_CHECK =	-fsanitize=address

# mac : GRAPHIC_LIBS =	-framework OpenGL -framework AppKit
GRAPHIC_LIBS =	-lm -lbsd -lX11 -lXext

COMPIL =		$(FLAGS) $(LEAK_CHECK) $(DEBUG_INFO)

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
				utils/colors_1.c					\
				utils/colors_2.c					\
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

$(NAME): 		$(OBJS)
				@echo "☑️  Compiled ALL OBJECTS successfully!"
				@echo "Compiling with libmlx library and graphic libs"
				@$(CC) $(COMPIL) -I $(DIR_HEADERS) $(LIBMLX) $(OBJS) -o $(NAME) $(GRAPHIC_LIBS)
				@echo "MiniRT is ready"

%.o: %.c
				@gcc $(FLAGS) -I $(DIR_HEADERS) -c $< -o $@
				@echo "☑️  Compiled "$<" successfully!"

bonus:			
				$(MAKE) $(NAME)

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