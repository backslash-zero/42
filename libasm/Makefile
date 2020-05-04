NAME		=	libasm.a

NA			=	nasm

NA_flags	=	-f macho64

FLAGS		=	-Wall -Werror -Wextra

SRCS		=	ft_strlen.s			\

OBJS		=	$(SRCS:.s=.o)

TEST		=	test

%.o:		%.s
			$(NA) $(NA_FLAGS) $<

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

test:		$(NAME)
			gcc $(FLAGS) -L. -lasm -o $(TEST) main.c
			./$(TEST) < Makefile

all:		$(NAME)


clean:
			rm -rf $(OBJS) $(TEST)

fclean:		clean
			rm -rf $(NAME) $(TEST)

re:			fclean $(NAME)

.PHONY:		clean fclean re