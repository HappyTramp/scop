# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/09 10:24:52 by charles           #+#    #+#              #
#    Updated: 2020/05/14 15:30:27 by charles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM = rm -f
MAKE = make --no-print-directory

VENDOR_DIR = vendor
LIBFT_DIR = $(VENDOR_DIR)/libft
LIBFTM_DIR = $(VENDOR_DIR)/libftm

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

CC = gcc
OFLAG ?= -O0
CCFLAGS = -I$(LIBFT_DIR)/include -I$(INC_DIR) -I$(LIBFTM_DIR)/inc \
		  $(shell pkg-config --cflags sdl2) \
		  $(OFLAG) -Wall -Wextra #-Werror
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(LIBFTM_DIR) -lftm -lm

ifeq ($(shell uname),Linux)
	LDFLAGS += $(shell pkg-config --libs glew sdl2)
endif

NAME = scop
SRC = $(shell find $(SRC_DIR) -type f -name '*.c')
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
INC = $(shell find $(INC_DIR) -type f -name '*.h')

all: prebuild $(NAME)

prebuild:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/graphic

$(NAME): $(OBJ) libft_all libftm_all
	@echo "Linking $@"
	@$(CC) -o $@ $(OBJ) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	@echo "Compiling $@"
	@$(CC) $(CCFLAGS) -c -o $@ $<

cleanloc:
	@echo "Compiling objects"
	@$(RM) $(OBJ)

fcleanloc: cleanloc
	@echo "Removing $(NAME)"
	@$(RM) $(NAME)

reloc: fcleanloc all

clean: libft_clean libftm_fclean cleanloc

fclean: libft_fclean libftm_fclean fcleanloc

re: fclean all

libft_all:
	$(MAKE) -C $(LIBFT_DIR) all

libft_clean:
	$(MAKE) -C $(LIBFT_DIR) clean

libft_fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean

libftm_all:
	$(MAKE) -C $(LIBFTM_DIR) all

libftm_clean:
	$(MAKE) -C $(LIBFTM_DIR) clean

libftm_fclean:
	$(MAKE) -C $(LIBFTM_DIR) fclean
