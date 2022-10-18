### VAR
NAME		:=	libftprintf.a
HEADER		:=	ft_printf.h
OBJ_DIR		:=	./obj
SRC_DIR 	:=	./src
INCLUDE		:=  -I ./include \

### UTILS
CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror
COMPILE	:=	$(CC) $(CFLAGS)
RM		:=	rm -f

SRC 	:=	ft_printf.c \
			functions.c \
			printf_utils.c \
			basetoa.c \
			hexfunctions.c \

OBJ		:=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
SRC		:=	$(addprefix $(SRC_DIR)/,$(SRC))

BON_SRC :=

BON_OBJ :=  $(BON_SRC:_bonus.c=_bonus.o)

### EXEC
all:  $(NAME)

##bonus: $(OBJ) $(BON_OBJ)
##ar -rsc $(NAME) $^

$(NAME): $(OBJ)
	ar -rsc $(NAME) $^ 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) | $(OBJ_DIR)
	$(COMPILE) -c $< -o $@ $(INCLUDE)

$(OBJ_DIR):
	mkdir $@

clean:
	$(RM) $(OBJ) $(BON_OBJ)

fclean:
	$(RM) $(NAME) $(OBJ) $(BON_OBJ)

re: fclean all

.DEFAULT_GOAL: all

.PHONY: clean all fclean re Bonus,