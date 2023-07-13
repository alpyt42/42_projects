# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 19:17:58 by wangthea          #+#    #+#              #
#    Updated: 2023/03/27 15:52:06 by amontalb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--variables-------------------------------------------------------------------#

NAME		=	minishell
DEBUG		=	no

#--includes & libraries--------------------------------------------------------#

INC_DIR		=	includes/
HEADERS		= 	includes/minishell.h
LIBFT_DIR	=	libft/

#--sources & objects-----------------------------------------------------------#

SRC_DIR		=	srcs/
OBJ_DIR		=	.objects

#--flags-----------------------------------------------------------------------#

CFLAGS		=	-Wall -Wextra -Werror -I $(LIBFT_DIR) -I $(INC_DIR)
DFLAGS		=	-g3 #-fsanitize=address
READFLAGS 	= 	-L /usr/local/opt/readline/lib -I /usr/local/opt/readline/include -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include

#--Sources-----------------------------------------------------------------------#

BUILTINS = builtin builtin_bis
ENV = env init get_here_doc
EXEC = exec_cmd mini exec fork_function
MAIN = main prompt signals
PARSING = expand expand_bis lexing parse_all cmdsplit strim_quotes fill_nodes redirection
UTILS = matrix other_function error other_function_bis

SOURCES =	$(addsuffix .c, $(addprefix srcs/main/, $(MAIN)))			\
			$(addsuffix .c, $(addprefix srcs/builtins/, $(BUILTINS))) 	\
			$(addsuffix .c, $(addprefix srcs/env/, $(ENV))) 			\
			$(addsuffix .c, $(addprefix srcs/exec/, $(EXEC))) 			\
			$(addsuffix .c, $(addprefix srcs/parsing/, $(PARSING))) 	\
			$(addsuffix .c, $(addprefix srcs/utils/, $(UTILS)))

#--debug & define flags--------------------------------------------------------#

ifeq ($(DEBUG), yes)
CFLAGS 		+=	$(DFLAGS)
endif

#--libs------------------------------------------------------------------------#

LIBFT	=	$(LIBFT_DIR)/libft.a

#--objects---------------------------------------------------------------------#

OBJECTS	=	$(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

#--global rules----------------------------------------------------------------#

.DEFAULT_GOAL = all

#--compilation rules-----------------------------------------------------------#

all:
	$(MAKE) lib 
	$(MAKE) $(NAME)

$(NAME): $(OBJECTS)
	@echo "\n\033[0;32mCompiling minishell...\033[0m"
	$(CC) $^ $(CFLAGS) $(READFLAGS) $(LIBFT) -lreadline -o $@
	@echo "\n\033[0;32mMinishell is up to date !\033[0m"

$(OBJ_DIR)/%.o: %.c $(HEADERS) $(LIBFT)
	@ mkdir -p $(dir $@)
	$(CC) $(READFLAGS) $(CFLAGS) -c $< -o $@

#--libs, debugs & bonus--------------------------------------------------------#

lib:
	$(MAKE) -C $(LIBFT_DIR)

debug:
	$(MAKE) re DEBUG=yes

#--re, clean & fclean----------------------------------------------------------#

re:
	$(MAKE) fclean
	$(MAKE) all

clean:
	@echo "\033[0;31mCleaning libft..."
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo "\nRemoving binaries..."
	@$(RM) -rf $(OBJECTS)
	@echo "\033[0m"

fclean:
	@echo "\nDeleting objects..."
	@$(MAKE) clean
	@echo "\033[0;31mCleaning libft..."
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "\nDeleting executable..."
	@$(RM) $(NAME)
	@echo "\033[0m"

#--PHONY-----------------------------------------------------------------------#

.PHONY: all libs debug re clean fclean
 