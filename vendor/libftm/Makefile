# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/09 20:44:53 by charles           #+#    #+#              #
#    Updated: 2020/05/09 21:20:08 by charles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

CC = gcc
OFLAG ?= -O0
CCFLAGS = $(OFLAG) -I$(INC_DIR) -Wall -Wextra -Werror

NAME = libft.a

SRC = $(shell find $(SRC_DIR) -type f -name '*.c')
INC = $(shell find $(INC_DIR) -type f -name '*.h')
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

OBJ_SUB_DIR = $(shell find $(SRC_DIR) -type d | sed 's/$(SRC_DIR)/$(OBJ_DIR)/')

all: prebuild $(NAME)

prebuild:
	mkdir -p $(OBJ_DIR) $(OBJ_SUB_DIR)

$(NAME): $(OBJ) $(INC)
	$(LIB) $@ $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
