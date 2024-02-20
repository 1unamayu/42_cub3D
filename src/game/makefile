# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 15:38:08 by javigarc          #+#    #+#              #
#    Updated: 2024/02/20 21:06:18 by javi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = game.a
SRC_DIR = 
OBJ_DIR = ../../.objs/game
LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a
DESTINATION = ../../libraries/

# Colors
RESET = \033[0m
GREEN = \033[38;5;46m
WHITE = \033[38;5;15m
GREY = \033[38;5;8m
ORANGE = \033[38;5;202m
RED = \033[38;5;160m
PINK = \033[38;5;162m
LIGHT_PINK = \033[38;5;200m
BLUE = \033[38;5;39m
DARK_BLUE = \033[38;5;57m

# Source files
SRC = $(SRC_DIR)/game.c\
	  $(SRC_DIR)/game_calculus.c\
	  $(SRC_DIR)/game_color.c\
	  $(SRC_DIR)/game_draw.c\
	  $(SRC_DIR)/game_draw_light.c\
	  $(SRC_DIR)/game_draw_rotations.c\
	  $(SRC_DIR)/game_hooks.c\
	  $(SRC_DIR)/game_hooks_ctl.c\
	  $(SRC_DIR)/game_map.c\

OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))
CC = gcc
HEAD = -I ../../includes \
	   -I $(LIBFT_DIR) 
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -L ./$(LIBFT_DIR) 
RM = /bin/rm -rf

# Linker flags for final binary linking, not for object files
LFLAGS = -L$(LIBFT_DIR) -L$(GNL_DIR) -L$(MINILIBX_DIR) -lmlx
LLFLAGS = -framework OpenGL -framework AppKit

# Remove command
RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) 
		@${MAKE} -C ../libft 
		@ar rcs ${DESTINATION}${NAME} ${OBJ}  ../../.objs/libft/*.o 

$(OBJ_DIR)/%.o: %.c
		@mkdir -p $(OBJ_DIR)
		@echo "$(GREY)Compiling.............................$(DARK_BLUE)$(<F)"
		@$(CC) $(CFLAGS) $(HEAD)  -c $< -o $@
		@echo "$(GREEN)DONE!$(GREY)"
		@sleep .2

$(LIBFT):
		@make -C $(LIBFT_DIR) 

		
clean:
		@$(RM) $(OBJ_DIR)
		sleep .1
		clear

fclean: clean
		@$(RM) ${DESTINATION}$(NAME)
		sleep .1
		clear
		@echo "$(ORANGE)╔════════════════════════════════════╗"
		@echo "$(ORANGE)║       ${DARK_BLUE} 🗑️  GAME REMOVED 🗑️ ${ORANGE}         ║"
		@echo "$(ORANGE)╚════════════════════════════════════╝ $(RESET)"

re: fclean all

.PONY: all clean fclean re
