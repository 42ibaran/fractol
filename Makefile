# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibaran <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/06 09:08:51 by ibaran            #+#    #+#              #
#    Updated: 2019/03/19 15:37:02 by ibaran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: $(NAME)
.PHONY: clean
.PHONY: fclean
.PHONY: re

VPATH:= ./sources/ ./objects/ ./includes/

NAME := fractol

CC := gcc
FRAMEWORK := -framework OpenGL -framework AppKit
LIB := libft/libft.a minilibx/libmlx.a
INCLUDES := -I minilibx/ -I includes/ -I libft/includes/
FLAGS := -Wall -Wextra -Werror -O2

SRCS_PATH := ./sources/
OBJS_PATH := ./objects/
INCL_PATH := ./includes/

SRCS_NAME := \
main.c \
helpers.c \
interactions.c \
allocation.c \
drawing.c \
calculation.c \
change_params.c
OBJS_NAME := $(SRCS_NAME:.c=.o)
INCL_NAME := \
fractol.h

SRCS := $(patsubst %,$(SRCS_PATH)%,$(SRCS_NAME))
OBJS := $(patsubst %,$(OBJS_PATH)%,$(OBJS_NAME))
INCL := $(patsubst %,$(INCL_PATH)%,$(INCL_NAME))

all: $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo [CC] $<
	@$(CC) $(FLAGS) -o $@ -c $< $(INCLUDES)

$(NAME): $(OBJS)
	@echo "[Compiling Libft]"
	@make -C libft/
	@echo "[Compiling MiniLibX]"
	@make -C minilibx/
	@echo "[Compiling Fractol]"
	@$(CC) $(FLAGS) -o $@ $^ $(LIB) $(FRAMEWORK)

clean:
	@echo "[Cleaning All]"
	@make -C libft/ clean
	@make -s -C minilibx/ clean
	@/bin/rm -f $(OBJS)

fclean: clean
	@make -s -C libft/ fclean
	@echo "[Fcleaning All]"
	@/bin/rm -f $(NAME)

norme:
	@norminette $(SRCS) $(INCL)

re: fclean all
