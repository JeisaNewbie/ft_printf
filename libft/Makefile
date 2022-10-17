# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhwang2 <jhwang2@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 14:45:57 by jhwang2           #+#    #+#              #
#    Updated: 2022/07/20 18:51:21 by jhwang2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
SRC			=	ft_memset.c ft_bzero.c ft_memcpy.c\
				ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c\
				ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
				ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c\
				ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
				ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c\
				\
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
				ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c\
				ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c
OBJ			=	$(SRC:.c=.o)

INCLUDE		=	./libft.h

BONUS_SRC	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
				ft_lstmap.c
BONUS_OBJ	=	$(BONUS_SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror
CC			=	CC

ifdef WITH_BONUS
	OBJECTS = $(OBJ) $(BONUS_OBJ)
else
	OBJECTS = $(OBJ)
endif

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(NAME) : $(OBJECTS)
	ar -rc $@ $^

bonus :
	@make WITH_BONUS=1 all

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean : clean
	@rm -f $(NAME)

re:
	make fclean
	make all

.PHONY	:	all bonus clean fclean re
