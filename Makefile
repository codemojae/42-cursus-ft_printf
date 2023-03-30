# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hojakim <hojakim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 17:26:06 by hojakim           #+#    #+#              #
#    Updated: 2023/03/30 20:38:23 by hojakim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS 		= src/ft_printf.c src/ft_printf_util.c src/ft_printf_util2.c

BONUS		= src/ft_printf_bonus.c src/ft_printf_util_bonus.c src/ft_printf_util2_bonus.c src/ft_printf_util.c src/ft_printf_util2.c

OBJS 		= $(SRCS:c=o) 
OBJS_BONUS	= $(BONUS:c=o)

HDR			= src/ft_printf.h
HDR_BONUS	= src/ft_printf_bonus.h

ifdef BONUSFLAG
	ALLOBJ 	= $(OBJS_BONUS)
	HEADER	= $(HDR_BONUS)
else
	ALLOBJ 	= $(OBJS)
	HEADER	= $(HDR)
endif

NAME		= libftprintf.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(NAME): $(ALLOBJ)
	ar rcs $@ $^

bonus:
	make fclean
	make BONUSFLAG=1

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re