NAME		=	libasm.a

TESTER		=	tester.c

EXEC		=	test

NA			=	nasm

NA_FLAGS	=	-f elf64

CC			=	clang

CC_FLAGS	=	-Wall -Werror -Wextra

LEAK_FLAGS	= 	-fsanitize=address

SRC_NAME	=	ft_strlen.s			\
				ft_strcpy.s			\
				ft_strcmp.s			\
				ft_strdup.s			\
				ft_read.s			\
				ft_write.s			\

OBJ_NAME	=	$(SRC_NAME:.s=.o)

SRC_PATH	=	src/

OBJ_PATH	=	obj/

SRC			=	$(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ			=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))

.PHONY:			all re clean fclean

all:			$(NAME)

$(NAME):		$(OBJ)
				ar rcs $(NAME) $(OBJ)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.s
				mkdir $(OBJ_PATH) 2> /dev/null || true
				$(NA) $(NA_FLAGS) $< -o $@

clean:
				rm -rf $(OBJ_PATH)

fclean:			clean
				rm -rf $(NAME)

re:				fclean all

run: 			all
				$(CC) $(CC_FLAGS) $(LEAK_FLAGS) $(TESTER) $(NAME) -o $(EXEC)
				./$(EXEC)

