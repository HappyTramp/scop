# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/09 20:44:53 by charles           #+#    #+#              #
#    Updated: 2020/05/12 16:03:51 by charles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f
MAKE = make --no-print-directory
JOBS = 4

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

CC = gcc
OFLAG ?= -O0
CCFLAGS = $(OFLAG) -I$(INC_DIR) -Wall -Wextra -Werror

NAME = libftm.a

SRC = $(shell find $(SRC_DIR) -type f -name '*.c')
INC = $(shell find $(INC_DIR) -type f -name '*.h')
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

OBJ_SUB_DIR = $(shell find $(SRC_DIR) -type d | sed 's/$(SRC_DIR)/$(OBJ_DIR)/')

all: prebuild
	@$(MAKE) -j$(JOBS) $(NAME)

prebuild:
	@mkdir -p $(OBJ_DIR) $(OBJ_SUB_DIR)

$(NAME): $(OBJ) $(INC)
	@echo "Linking: $@"
	@$(LIB) $@ $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling: $@"
	@$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	@echo "Removing objects"
	@$(RM) $(OBJ)

fclean: clean
	@echo "Removing $(NAME)"
	@$(RM) $(NAME)

re: fclean all
