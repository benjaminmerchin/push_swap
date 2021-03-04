NAME_C	=	checker
NAPE_P	=	push_swap
CC		=	clang
HEADER	=	header.h
OBJDIR	=	object
SRC		=	libft.c operation.c
SRC_C	=	checker.c $(SRC)
SRC_P	=	push_swap.c $(SRC)
OBJ_C 	=	$(addprefix $(OBJDIR)/, $(SRC_C:.c=.o))
OBJ_P 	=	$(addprefix $(OBJDIR)/, $(SRC_P:.c=.o))
CFLAGS	=	-Wall -Wextra -Werror#-g#-fsanitize=address

all: $(NAME_C) $(NAME_P)

$(NAME_C): $(OBJ_C)
	@$(CC) $(CFLAGS) -o $(NAME_C) $(OBJ_C)

$(NAME_P): $(OBJ_P)
	@$(CC) $(CFLAGS) -o $(NAME_P) $(OBJ_P)

$(OBJDIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_C) $(OBJ_P)

fclean: clean
	@rm -f $(NAME_C) $(NAME_P)

re: fclean all

.PHONY: clean fclean all re bonus