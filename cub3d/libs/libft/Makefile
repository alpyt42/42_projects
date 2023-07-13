# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 15:07:12 by ale-cont          #+#    #+#              #
#    Updated: 2023/04/03 19:08:02 by ale-cont         ###   ########.fr        #
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
		ft_arrdup.c ft_arrlen.c ft_free_arr.c get_next_line.c ft_printf.c ft_opt_printf.c\
		ft_strchars_i.c ft_split_set.c pos_in_arr.c display_arr.c sort_arr.c ft_replace_in_arr.c\
		ft_append_tab.c

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I .

all : $(NAME)

$(NAME) : $(OBJECTS)
	@echo "\033[0;34mCompiling libft...\n\033[0m"
	$(AR) rcs $@ $^
	@echo "\033[0;32m\033[1mlibft is up to date !\n\033[0m"

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@echo "\033[0;31mDeleting libft binaries...\033[0m"
	@$(RM) $(OBJECTS)
	@$(RM) $(HEADERS).gch

fclean : clean
	@echo "\033[0;31mDeleting libft executable...\033[0m"
	@$(RM) $(NAME)

re : fclean
	$(MAKE) all

.PHONY: all clean fclean re