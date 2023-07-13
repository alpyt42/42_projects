NAME = pipex

HEADERS = pipex.h

SOURCES = ft_split.c libft_utils.c libft_utils_2.c pipex.c utils.c

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