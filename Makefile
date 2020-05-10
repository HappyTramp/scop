# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/09 10:24:52 by charles           #+#    #+#              #
#    Updated: 2020/05/10 21:06:25 by charles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make
RM = rm -f

VENDOR_DIR = vendor
LIBFT_DIR = $(VENDOR_DIR)/libft

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

CC = gcc
CCFLAGS = -I$(LIBFT_DIR)/include -I$(INC_DIR) \
		  -Wall -Wextra -Werror
LDFLAGS = -L$(LIBFT_DIR) -lft

ifeq ($(shell uname),Linux)
	LDFLAGS += -lglfw -lGL -lglut -lGLEW
endif

NAME = scop
SRC = $(shell find $(SRC_DIR) -type f -name '*.c')
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
INC = $(shell find $(INC_DIR) -type f -name '*.h')

all: prebuild libft_all $(NAME)

prebuild:
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	$(CC) $(CCFLAGS) -c -o $@ $<

cleanloc:
	$(RM) $(OBJ)

fcleanloc:
	$(RM) $(NAME)

reloc: fcleanloc all

clean: libft_clean cleanloc

fclean: libft_fclean fcleanloc

re: fclean all

libft_all:
	$(MAKE) -C $(LIBFT_DIR) all

libft_clean:
	$(MAKE) -C $(LIBFT_DIR) clean

libft_fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
