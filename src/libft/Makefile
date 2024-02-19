# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 09:14:35 by xamayuel          #+#    #+#              #
#    Updated: 2024/02/19 13:57:17 by xamayuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***************************** STRUCTURE ************************************ #
# - ../../.objs/parser-> Folder with object files  
# - *.c -> code files                                                          #
# - lexer.a -> library file                                                    #
# **************************************************************************** #

NAME = libft.a
SRC_DIR = 
OBJ_DIR = ../../.objs/libft
DESTINATION = ../../libraries/
# ------------- COLORS
RESET			= 	\033[0m
GREEN 			= 	\033[38;5;46m
WHITE 			= 	\033[38;5;15m
GREY 			= 	\033[38;5;8m
ORANGE 			= 	\033[38;5;202m
RED 			= 	\033[38;5;160m
PINK			=   \033[38;5;162m
LIGHT_PINK      =   \033[38;5;200m
BLUE			= 	\033[38;5;39m
DARK_BLUE		=   \033[38;5;57m
# -----------------SRC


SRC = /ft_isalpha.c /ft_toupper.c \
		/ft_isdigit.c /ft_tolower.c \
		/ft_isalnum.c /ft_strchr.c \
		/ft_isascii.c /ft_strrchr.c \
		/ft_isprint.c /ft_strncmp.c \
		/ft_strlen.c  /ft_memchr.c \
		/ft_memset.c  /ft_memcmp.c \
		/ft_bzero.c   /ft_strnstr.c \
		/ft_memcpy.c  /ft_atoi.c \
		/ft_memmove.c /ft_strchrc.c \
		/ft_strlcpy.c  \
		/ft_strlcat.c /ft_strcat.c 

SRC += /ft_calloc.c /ft_strdup.c
SRC += /ft_substr.c /ft_strjoin.c
SRC += /ft_strtrim.c /ft_split.c /ft_itoa.c
SRC += /ft_strmapi.c /ft_striteri.c /ft_putchar_fd.c
SRC += /ft_putstr_fd.c /ft_putendl_fd.c /ft_putnbr_fd.c
SRC += /ft_lstnew.c /ft_lstadd_front.c /ft_lstsize.c
SRC += /ft_lstlast.c /ft_lstadd_back.c /ft_lstdelone.c
SRC += /ft_lstclear.c /ft_lstiter.c /ft_lstmap.c
SRC += /ft_2d_array_count.c /ft_2d_array_free.c 
SRC += /ft_strncmp_nocase.c /ft_charlcat.c /ft_isspace.c
OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))
CC = gcc
HEAD = -I ../../includes 
CFLAGS = -Wall -Werror -Wextra

RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) 
		@ar rcs ${DESTINATION}${NAME} ${OBJ} 

$(OBJ_DIR)/%.o: %.c
		@mkdir -p $(OBJ_DIR)
		@echo "$(GREY)Compiling.............................$(LIGHT_PINK)$(<F)"
		@$(CC) $(CFLAGS) $(HEAD)  -c $< -o $@
		@echo "$(GREEN)DONE!$(GREY)"
		@sleep .2

$(LIBFT):
		@make -s $(LIBFT_DIR)
		
clean:
		@$(RM) $(OBJ_DIR)
		sleep .1
		clear

fclean: clean
		@$(RM) ${DESTINATION}$(NAME)
		sleep .1
		clear
		@echo "$(BLUE)╔════════════════════════════════════╗"
		@echo "$(BLUE)║        ${DARK_BLUE} 🗑️  LIBFT REMOVED 🗑️ ${BLUE}        ║"
		@echo "$(BLUE)╚════════════════════════════════════╝ $(RESET)"

re: fclean all

.PONY: all clean fclean re
