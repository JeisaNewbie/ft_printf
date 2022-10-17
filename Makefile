SRCS	= ft_printf.c

SRCS_B	=

OBJS	= ${SRCS:.c=.o}

OBJS_B	= ${SRCS_B:.c=.o}

NAME	= libftprintf.a

RM 		= rm -f

AR		= ar rc

define libft_call
		cd libft && $(MAKE) $(1) && cd ..
endef

.c.o:
		gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
		$(call libft_call, all)
		${AR} ${NAME} ${OBJS}

bonus: 		${OBJS_B}
		$(call libft_call, all)
		${AR} ${NAME} ${OBJS_B}

clean:
		$(call libft_call, clean)
		${RM} ${OBJS} ${OBJS_B}

fclean:		clean
		$(call libft_call, fclean)
		${RM}	${NAME}

re: 		fclean all

.PHONY: 	all bonus clean fclean re
