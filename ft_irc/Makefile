#--variables---------------------#

NAME	=	ircserv
DEBUG	=	no

#--color-------------------------#

BBLACK	=	\033[1;30m
BRED	=	\033[1;31m
BGREEN	=	\033[1;32m
BYELLOW	=	\033[1;33m
BBLUE	=	\033[1;34m
BPURPLE	=	\033[1;35m
BCYAN	=	\033[1;36m
BWHITE	=	\033[1;37m
NC		=	\033[0m

#--header-----------------------#

HEADER_DIR		=	inc/
HEADER_NAMES	=	Channel.hpp \
					irc.hpp \
					numerics.h \
					Server.hpp \
					User.hpp \
					utils.hpp

HEADERS			=	$(addprefix $(HEADER_DIR), $(HEADER_NAMES))

#--flag-------------------------#

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -I$(HEADER_DIR) -std=c++98 -g3 #-fsanitize=address
DFLAGS		=	-g3 -D DEBUG=1 -fsanitize=address -fstandalone-debug
RM			=	rm
RM_FLAGS	=	-rf
MAKE_FLAGS	=	--no-print-directory
ifeq ($(DEBUG), yes)
CFLAGS 		+=	$(DFLAGS)
endif

#--srcs------------------------#
SRCS_DIR	=	srcs/
CMD_DIR		=	commands/
SRCS_FILES	=	Channel.cpp \
				main.cpp \
				Server.cpp \
				User.cpp \
				utils.cpp

CMD_FILES	=	invite.cpp \
				join.cpp \
				kick.cpp \
				mode.cpp \
				nick.cpp \
				part.cpp \
				pass.cpp \
				privmsg.cpp \
				quit.cpp \
				topic.cpp \
				user.cpp \
				who.cpp
CMDS		=	$(addprefix $(CMD_DIR), $(CMD_FILES))
SRCS_FILES	+=	$(CMDS)
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))

#--objs------------------------#
OBJS_FOLDER	=	.objs/
OBJS_FILES	=	$(SRCS_FILES:.cpp=.o)
OBJS		=	$(addprefix $(OBJS_FOLDER), $(OBJS_FILES))

#--compilation-rules-----------#

$(OBJS_FOLDER)%.o: $(SRCS_DIR)%.cpp $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "${BPURPLE}[Compiling] ${BCYAN}$<${BPURPLE}\t\t\t\t${BGREEN}[✓]${NC}\n"

all: $(NAME)

$(NAME): $(OBJS_FOLDER) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "\n${BGREEN}Flags ${BWHITE}: $(CFLAGS)${NC}\n"
	@printf "${BBLUE}'$(NAME)' is up to date !${NC} (./ircserv <port> <password>)\n"

$(OBJS_FOLDER):
	@mkdir -p $(OBJS_FOLDER)
	@mkdir -p $(OBJS_FOLDER)/$(CMD_DIR)

debug:
	$(MAKE) re DEBUG=yes

clean:
	@$(RM) $(RM_FLAGS) $(OBJS_FOLDER)
	@printf "${BYELLOW}[Cleaning] ${BCYAN}'$(NAME)' objs files\t\t\t\t${BGREEN}[✓]${NC}\n"

fclean: clean
	@$(RM) $(RM_FLAGS) $(NAME)
	@printf "${BRED}[Deleting] ${BCYAN}'$(NAME)' executable and objs files\t\t${BGREEN}[✓]${NC}\n"

re: fclean all

.PHONY: all re fclean clean debug
