# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 12:59:41 by rteoh             #+#    #+#              #
#    Updated: 2024/06/25 12:59:41 by rteoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
INCLUDE = ./includes/
CC = cc
CFLAGS = -fsanitize=address -g3
RM = rm -rf

SRC = child.c error.c free.c pipex.c
OBJ = $(SRC:.c=.o)
SRC_DIR = src/
OBJ_DIR = obj/
SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

NAME_BNS = pipex_bns
SRC_BNS = error_bnx.c here_doc.c pipex_bnx.c files_bnx.c input_check.c
OBJ_BNS = $(SRC_BNS:.c=.o)
SRC_BNS_DIR = bonus/
OBJ_BNS_DIR = obj_bns/

SRCS_BNS = $(addprefix $(SRC_BNS_DIR), $(SRC_BNS))
OBJS_BNS = $(addprefix $(OBJ_BNS_DIR), $(OBJ_BNS))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

bonus: $(OBJ_BNS_DIR) $(NAME_BNS)

$(OBJ_BNS_DIR)%.o: $(SRC_BNS_DIR)%.c | $(OBJ_BNS_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(OBJ_BNS_DIR):
	mkdir -p $(OBJ_BNS_DIR)

$(NAME_BNS): $(OBJS_BNS)
	$(CC) $(CFLAGS) $(OBJS_BNS) ./libft/libft.a -o $(NAME_BNS)

clean:
		@$(MAKE) -C ./libft fclean
		@$(RM) $(OBJ_DIR)
		@$(RM) $(OBJ_BNS_DIR)

fclean: clean
		@rm -f $(NAME)
		@rm -f $(NAME_BNS)

re: fclean all bonus

.PHONY: all clean fclean re