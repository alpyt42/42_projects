# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 19:17:58 by ale-cont          #+#    #+#              #
#    Updated: 2023/04/13 17:46:43 by amontalb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

#--variables-------------------------------------------------------------------#

NAME		=	cub3d
DEBUG		=	no
OS			=	$(shell uname)
USER 		=	$(shell id -u -n)

#--includes & libraries--------------------------------------------------------#

INC_DIR		=	includes/
HEADERS		= 	includes/cub3d.h
LIB_DIR		=	libs
LIBFT_DIR	=	$(LIB_DIR)/libft

#--sources & objects-----------------------------------------------------------#

SRC_DIR		=	srcs/
OBJ_DIR		=	.objects

#--mlx-------------------------------------------------------------------------#

ifeq ($(OS), Darwin)
MLX_DIR 	=	$(LIB_DIR)/mlx_mac
else ifeq ($(OS), Linux)
MLX_DIR 	=	$(LIB_DIR)/mlx_linux
endif

#--flags-----------------------------------------------------------------------#

CFLAGS		=	-Wall -Wextra -Werror -pipe -I $(LIBFT_DIR) -I $(MLX_DIR) -I $(INC_DIR)
DFLAGS		=	-g3 -fsanitize=address
MLX_FLAGS 	= 	-L $(MLX_DIR)

#--mlx flags-------------------------------------------------------------------#

ifeq ($(OS), Darwin)
MLX_FLAGS 	+= -framework OpenGL -framework AppKit
else ifeq ($(OS), Linux)
MLX_FLAGS 	+= -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm
endif

#--Sources-----------------------------------------------------------------------#

MAIN = main
PARSING = parse dico get_keys get_map init check_keys
RAYCASTING = raycasting floor_ceiling mlx_init move map_dis draw_wall raycasting_bis
UTILS = utils free utils_bis

SOURCES =	$(addsuffix .c, $(addprefix srcs/main/, $(MAIN)))			\
			$(addsuffix .c, $(addprefix srcs/parsing/, $(PARSING)))		\
			$(addsuffix .c, $(addprefix srcs/raycasting/, $(RAYCASTING)))		\
			$(addsuffix .c, $(addprefix srcs/utils/, $(UTILS)))		\

#--debug & define flags--------------------------------------------------------#

ifeq ($(DEBUG), yes)
CFLAGS 		+=	$(DFLAGS)
endif

ifeq ($(OS), Darwin)
CFLAGS 		+=	-DMACOS
endif

#--libs------------------------------------------------------------------------#

LIBFT	=	$(LIBFT_DIR)/libft.a
MLX		=	$(MLX_DIR)/libmlx.a

#--objects---------------------------------------------------------------------#

OBJECTS	=	$(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

#--global rules----------------------------------------------------------------#

.DEFAULT_GOAL = all

#--compilation rules-----------------------------------------------------------#

all:
	$(MAKE) libs 
	$(MAKE) $(NAME)

$(NAME): $(OBJECTS)
	@echo "\n\033[0;34mCompiling cub3d...\n\033[0m"
	@$(CC) $^ $(CFLAGS) $(LIBFT) $(MLX_FLAGS) $(MLX) -o $@ 
	@echo "\033[0;32m\033[1mcub3d is up to date !\033[0m"

$(OBJ_DIR)/%.o: %.c $(HEADERS) $(LIBFT) $(MLX)
	@ mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	printf "%-95b%b" "[\033[0;95m\033[3mcompiling\033[0m]\t\033[36m$<\033[0m" "\033[32m[✓]\033[0m\n"

#--libs, debugs & bonus--------------------------------------------------------#

libs:
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)

debug:
	$(MAKE) re DEBUG=yes

#--re, clean & fclean----------------------------------------------------------#

re:
	$(MAKE) fclean
	$(MAKE) all

clean:
	@echo "\033[0;33mCleaning libft...\033[0m"
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo "\033[0;33mCleaning mlx...\033[0m"
	$(MAKE) -C $(MLX_DIR) clean
	@echo "\033[0;31mDeleting cub3d objects...\033[0m"
	@$(RM) -rf $(OBJECTS)

fclean:
	$(MAKE) clean
	@echo "\033[0;33mCleaning libft...\033[0m"
	$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "\033[0;31mDeleting cub3d executable...\033[0m"
	@$(RM) $(NAME)

#--PHONY-----------------------------------------------------------------------#

.PHONY: all libs debug re clean fclean
 