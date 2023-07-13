# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 15:07:12 by ale-cont          #+#    #+#              #
#    Updated: 2023/01/20 15:51:43 by ale-cont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADERS = libft.h

SOURCES = ft_isdigit.c ft_memset.c ft_strjoin.c ft_strtrim.c ft_isprint.c\
		ft_putchar_fd.c ft_strlcat.c ft_substr.c ft_atoi.c ft_itoa.c ft_putendl_fd.c\
		ft_strlcpy.c ft_tolower.c ft_bzero.c ft_putnbr_fd.c ft_strlen.c\
		ft_toupper.c ft_calloc.c ft_memchr.c ft_putstr_fd.c ft_strmapi.c ft_isalnum.c\
		ft_memcmp.c ft_split.c ft_strncmp.c ft_isalpha.c ft_memcpy.c ft_strchr.c\
		ft_strnstr.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strrchr.c ft_striteri.c\
		ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_strstr.c\
		ft_arrdup.c ft_arrlen.c ft_free_arr.c get_next_line.c ft_printf.c ft_opt_printf.c

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I .

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(AR) rcs $@ $^

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)

re : fclean
	$(MAKE) all

.PHONY: all clean fclean re