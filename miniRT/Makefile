# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 17:25:36 by cmeunier          #+#    #+#              #
#    Updated: 2020/05/01 01:46:42 by cmeunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =			clang

FLAGS =			-Wall -Wextra -Werror

DEBUG_INFO =	-g

LEAK_CHECK =	-fsanitize=address

GRAPHIC_LIBS =	-lm -lbsd -lX11 -lXext
# Libs for Mac OS : GRAPHIC_LIBS =	-framework OpenGL -framework AppKit

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

DFLT =			default/key_bindings_1.c			\
				default/key_bindings_2.c			\

BONUS =			bonus/key_bindings_1_bonus.c		\
				bonus/key_bindings_2_bonus.c		\

SRCS_MAIN =		$(addprefix $(DIR_SRCS), $(SRC))

SRCS_DFLT =		$(addprefix $(DIR_SRCS), $(DFLT))

SRCS_BONUS =	$(addprefix $(DIR_SRCS), $(BONUS))

OBJS_MAIN =		$(SRCS_MAIN:%.c=%.o)

OBJS_DFLT =		$(SRCS_DFLT:%.c=%.o)

OBJS_BONUS =	$(SRCS_BONUS:%.c=%.o)

LIBMLX =		$(addprefix $(DIR_LIBMLX), *.o)		 \
				$(addprefix $(DIR_LIBMLX), libmlx.a) \


NAME =			miniRT

NAME_BONUS =	miniRT_Bonus

all:
				$(MAKE) $(NAME)

$(NAME): 		$(OBJS_MAIN) $(OBJS_DFLT)
				@echo "☑️  Compiled ALL OBJECTS and defaults successfully!"
				@echo "Compiling with libmlx library and graphic libs"
				@$(CC) $(COMPIL) -I $(DIR_HEADERS) $(LIBMLX) $(OBJS_MAIN) $(OBJS_DFLT) -o $(NAME) $(GRAPHIC_LIBS)
				@echo "MiniRT in default mode is ready"


$(NAME_BONUS): 	$(OBJS_MAIN) $(OBJS_BONUS)
				@echo "☑️  Compiled ALL OBJECTS and bonuses successfully!"
				@echo "Compiling with libmlx library and graphic libs"
				@$(CC) $(COMPIL) -I $(DIR_HEADERS) $(LIBMLX) $(OBJS_MAIN) $(OBJS_BONUS) -o $(NAME) $(GRAPHIC_LIBS)
				@echo "MiniRT with bonuses is ready"

%.o: %.c
				@gcc $(FLAGS) -I $(DIR_HEADERS) -c $< -o $@
				@echo "☑️  Compiled "$<" successfully!"

bonus:			
				$(MAKE) $(NAME_BONUS)

norme:
				norminette $(DIR_SRCS)
				norminette $(DIR_HEADERS)

clean:
				$(RM) $(OBJS_MAIN)
				$(RM) $(OBJS_DFLT)
				$(RM) $(OBJS_BONUS)
				@echo "🗑️  Removed .o files successfully"$<"!"

fclean:			clean
				$(RM) $(NAME)
				@echo "Deleted executable"
				$(RM) save.bmp
				@echo "Deleted saved images"

re:				fclean all

.PHONY:			all, clean, fclean, re, bonus