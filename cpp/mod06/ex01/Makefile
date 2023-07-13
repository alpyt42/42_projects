# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 11:44:32 by ale-cont          #+#    #+#              #
#    Updated: 2023/05/12 16:28:02 by ale-cont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
#--variables---------------------#

NAME	= deserialization
DEBUG	= no

#--color-------------------------#

GREEN	= \033[1;32m
YELLOW	= \033[1;33m
PURPLE	= \033[1;35m
CYAN	= \033[1;36m
RED		= \033[1;91m
BLUE	= \033[1;94m
MAG		= \033[1;95m
NC		= \033[0m

#--header-----------------------#

HEADER_DIR = ./
HEADER_NAMES = DataStruct.hpp
HEADERS = $(addprefix $(HEADER_DIR), $(HEADER_NAMES))

#--flag-------------------------#

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -I$(HEADER_DIR) -std=c++98
DFLAGS		= -g3 -fsanitize=address
RM			= rm
RM_FLAGS	= -rf
MAKE_FLAGS	= --no-print-directory
ifeq ($(DEBUG), yes)
CFLAGS 		+=	$(DFLAGS)
endif

#--srcs------------------------#

SRCS	= main.cpp
OBJS	= $(SRCS:.cpp=.o)

#--compilation-rules-----------#

%.o: %.cpp $(HEADERS)
	@printf "${MAG}[Compiling] ${CYAN}$<${MAG}\t\t\t\t\t${GREEN}[✓]${NC}"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "${GREEN} OK!${NC}\n"

all:
	@make $(NAME) $(MAKE_FLAGS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "\n${BLUE}'$(NAME)' executable is up to date !${NC}\n"

debug:
	$(MAKE) re DEBUG=yes

clean:
	@$(RM) $(RM_FLAGS) $(OBJS)
	@printf "${YELLOW}[Cleaning] ${CYAN}'$(NAME)' objs files\t\t\t\t${GREEN}[✓] OK!${NC}\n"

fclean :
	@$(RM) $(RM_FLAGS) $(NAME) $(OBJS)
	@printf "${RED}[Deleting] ${CYAN}'$(NAME)' executable and objs files\t\t${GREEN}[✓] OK!${NC}\n"

re: fclean all

.PHONY: all re fclean clean debug
