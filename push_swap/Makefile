NAME = push_swap

HEADERS = push_swap.h

SOURCES = ft_clear_list.c ft_strjoin.c algo.c ft_lstadd_back.c  main.c algo_radx.c ft_lstadd_front.c \
		parsing.c ft_lstlast.c push_function.c ft_lstnew.c push_swap.c ft_atoi.c ft_lstsize.c \
		ft_bzero.c ft_putstr.c ft_calloc.c ft_split.c

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I .

all :    $(NAME)

$(NAME) : $(OBJECTS)
	${CC} ${CFLAG} -o $@ $^

%.o : %.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)

re : fclean
	$(MAKE) all

.PHONY: all clean fclean re