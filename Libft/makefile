# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 16:52:31 by cmeunier          #+#    #+#              #
#    Updated: 2019/10/22 12:37:11 by cmeunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

CFLAGS	+=	-Wall -Wextra -Werror

SRC		=	ft_atoi.c						\
			ft_bzero.c						\
			ft_isalnum.c					\
			ft_isalpha.c					\
			ft_isascii.c					\
			ft_isdigit.c					\
			ft_isprint.c					\
			ft_memccpy.c					\
			ft_memchr.c						\
			ft_memset.c						\
			ft_memcmp.c						\
			ft_memcpy.c						\
			ft_memmove.c					\
			ft_strchr.c						\
			ft_strlen.c						\
			ft_strncmp.c					\
			ft_strrchr.c					\
			ft_strnstr.c					\
			ft_tolower.c					\
			ft_toupper.c					\
			ft_strlcpy.c					\
			ft_strlcat.c					\
			ft_calloc.c						\
			ft_strdup.c						\
			ft_strjoin.c					\
			ft_strtrim.c					\
			ft_split.c						\
			ft_strmapi.c					\
			ft_itoa.c						\
			ft_putchar_fd.c					\
			ft_putnbr_fd.c					\
			ft_putendl_fd.c					\
			ft_putstr_fd.c					\
			ft_substr.c						\

SRC_B	=	ft_lstnew.c						\
			ft_lstadd_front.c				\
			ft_lstsize.c					\
			ft_lstlast.c					\
			ft_lstadd_back.c				\
			ft_lstdelone.c					\
			ft_lstclear.c					\
			ft_lstiter.c					\
			ft_lstmap.c						\
			
OBJ		=	$(SRC:%.c=%.o) 

OBJ_B	=	$(SRC_B:%.c=%.o)

NAME	=	libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	@echo "libft.a ready"

%.o:	%.c
		@$(CC) $(FLAGS) -o $@ -c $<

bonus: $(OBJ) $(OBJ_B)
	ar rcs $(NAME) $(OBJ) $(OBJ_B)
	@echo "libft.a with bonus ready"

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_B)

fclean:
	$(MAKE) clean
	rm -f $(NAME)
	rm -f *~

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus