CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ./ft_nputchar.c ./ft_printf.c ./ft_putnbr_base.c ./ft_putnbr.c ./ft_putstr.c ./ft_strlen.c ./ft_u_putnbr.c ./print_address.c

NAME = libftprintf.a

AR = ar -rcs

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

all: $(NAME)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean: 
	rm -rf $(OBJ) 

fclean: clean
	rm -rf $(NAME)

re: fclean all