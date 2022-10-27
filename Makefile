NAME	=	libftprintf.a
CC	=	cc
INCLUDE	=	./ft_printf.h
SRCS_DIR	=	./
SRCS_NAME	=	ft_printf.c ft_hexa.c ft_printf_utils.c ft_putchar.c ft_putstr.c ft_strjoin.c
SRCS	=	$(addprefix $(SRCS_DIR),$(SRCS_NAME))
OBJS	=	$(SRCS:.c=.o)
CFLAGS := -Wall -Wextra -Werror
RM := rm -f
AR := ar
ARFLAG := crs
LIBFT_DIR := ./libft/

FLAGS	=	-Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)libft.a ./$(NAME)
	$(AR) $(ARFLAG) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@
clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
