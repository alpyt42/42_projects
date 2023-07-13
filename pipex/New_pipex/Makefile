NAME		=	pipex

HEADER		=	./includes/

LIBFT		=	libft/libft.a

CC			=	gcc

CFLAGS		=	-Werror -Wall -Wextra -g -I $(HEADER) #-fsanitize=address

SRCS		=	srcs/pipex.c \
				srcs/get_h_doc.c \
				srcs/path_search.c \
				srcs/execution.c

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(LIBFT) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

$(LIBFT)	:
				make -C ./libft

clean		:
				rm -rf $(OBJS)
				make clean -C ./libft

fclean		:	clean 
				$(MAKE) -C libft fclean
				$(RM) $(NAME)

re			:	fclean all