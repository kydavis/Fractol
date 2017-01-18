# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdavis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 18:48:35 by kdavis            #+#    #+#              #
#    Updated: 2017/01/17 15:10:40 by kdavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

MAKE		= make

FILENAMES	= fractol_index.c fractol_error.c fractol_pixel.c fractol_zoom.c
FILENAMES	+=fractol_color_palette.c fractol_hooks.c fractol_julia.c
FILENAMES	+= #test_colors.c
FILENAMES	+= main.c test_fract.c

L1			= ft
L2			= mlx

SRCDIR		= src/
IDIR		= includes/
LIBDIR		= lib/

SRC			=$(addprefix $(SRCDIR), $(FILENAMES))
LIB1		=$(addprefix lib, $(L1))
LIB2		=$(addprefix lib, $(L2))

IFLAGS		=-I $(IDIR) -I $(LIBDIR)$(L1)/$(IDIR) -I $(LIBDIR)$(L2)/
CFLAGS		:= -Wall -Werror -Wextra #-fsanitize=address
LFLAGS		+= -L $(LIBDIR) -l$(L1) -l$(L2) -framework OpenGL -framework AppKit
CC			= gcc

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): | $(LIBDIR)$(LIB1).a $(LIBDIR)$(LIB2).a
	$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(SRC) -o $@

$(LIBDIR)$(LIB1).a:
	$(MAKE) -C $(LIBDIR)$(L1)
	cp -rf $(LIBDIR)$(L1)/$(LIB1).a $(LIBDIR)$(LIB1).a

$(LIBDIR)$(LIB2).a:
	$(MAKE) -C $(LIBDIR)$(L2)
	cp -rf $(LIBDIR)$(L2)/$(LIB2).a $(LIBDIR)$(LIB2).a

clean:
	$(MAKE) -C $(LIBDIR)$(L1) clean
	$(MAKE) -C $(LIBDIR)$(L2) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBDIR)lib$(L1).a
	rm -rf $(LIBDIR)lib$(L2).a
	$(MAKE) -C $(LIBDIR)$(L1) fclean

.PHONY: eclean
eclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: ere
ere: eclean all
