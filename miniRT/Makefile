# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 17:25:36 by cmeunier          #+#    #+#              #
#    Updated: 2020/01/21 17:36:24 by cmeunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_DIR = libs
INC_DIR = incs
SRC_DIR = srcs
OBJ_DIR = objs

CC =		gcc
CFLAGS =	-Wall -Werror -Wextra
OFLAGS =	$(LIB_DIR)/$(LIBFT_DIR)/$(LIBFT) $(MLX) 
NAME =		miniRT

SRCS = 		main.c \

OBJS =		$(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))
MLX_DIR = mlx
LIBFT_DIR = libft
MLX = libmlx.dylib
LIBFT = libft.a

$(NAME):	$(OBJS)
			$(MAKE) -C $(LIB_DIR)/$(MLX_DIR)
			$(MAKE) -C $(LIB_DIR)/$(LIBFT_DIR)
			cp $(LIB_DIR)/$(MLX_DIR)/$(MLX)  .
			$(CC) $(OFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INC_DIR)/* Makefile
			mkdir -p $(OBJ_DIR)/
			$(CC) $(CFLAGS) -c $< -o $@


all :	${NAME}

clean :
			rm -rf $(OBJS) $(LIB_DIR)/$(LIBFT_DIR)/*/*.o $(LIB_DIR)/$(MLX_DIR)/*.o

fclean :clean
			rm -rf $(NAME) $(LIB_DIR)/$(MLX_DIR)/$(MLX) $(LIB_DIR)/$(LIBFT_DIR)/$(LIBFT) $(LIB_DIR)/$(LIBFT_DIR)/libc/libc.a $(MLX)

re :	fclean all

clean2 : 
	rm -rf $(NAME)

c : clean2 all
	./$(NAME) file.rt