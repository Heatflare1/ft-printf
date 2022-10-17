NAME	:= libftprintf.a
HEADER	:= ft_printf.h
CC		:= gcc
CFLAGS	:=	-Wall -Wextra -Werror
#LDFLAGS ?= 
RM		:=	rm -f

LIBFT	=:	libft

SRC 	:=	ft_printf.c \
			functions.c

BON_SRC :=


OBJ		:=	$(SRC:.c=.o)
BON_OBJ :=  $(BON_SRC:_bonus.c=_bonus.o)

all:  $(NAME)

bonus: $(OBJ) $(BON_OBJ)
	ar -rcs $(NAME) $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I libft -c $< -o $@ 

$(NAME): $(OBJ)
	make -C libft bonus
	cp libft/libft.a .
	mv libft.a $(NAME)
	ar -rcs $(NAME) $^

clean:
	make -C libft clean
	$(RM) $(OBJ) $(BON_OBJ)

fclean:
	make -C libft fclean
	$(RM) $(NAME) $(OBJ) $(BON_OBJ)

re: fclean all

.PHONY: clean all fclean re Bonus,