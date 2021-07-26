NAME	=	libftprintf.a

SRC 	=	ft_printf.c \
			parser/ft_parse_type.c parser/ft_parser.c \
			types/ft_printf_d_i.c types/ft_printf_char.c types/ft_printf_u.c types/ft_printf_xX.c \
			types/ft_printf_string.c types/ft_printf_p.c types/ft_printf_percent.c types/ft_printf_d_i_zero.c \
			utils/ft_utils_num.c utils/ft_putnbr_hex.c utils/ft_putnbr_u_.c \
			libft/ft_atoi.c libft/ft_putstr_fd.c libft/ft_strlen.c libft/ft_isdigit.c libft/ft_putchar_fd.c libft/ft_putnbr_fd.c

OBJ		= ${SRC:.c=.o}
FLAGS	= -Wall -Werror -Wextra 
HEADER	= ./includes

.c.o:
		gcc $(FLAGS) -I${HEADER} -c $< -o ${<:.c=.o}

all:  $(NAME)


$(NAME): $(OBJ) ./includes/ft_printf.h 
		ar rcs $(NAME) $(OBJ)


clean:
		rm -rf ${OBJ}

fclean: clean
		rm -rf ${NAME} 

re: 	fclean all

bonus:	re

.PHONY: all clean fclean re