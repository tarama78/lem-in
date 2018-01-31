# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynacache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 10:53:49 by ynacache          #+#    #+#              #
#    Updated: 2018/02/01 00:14:19 by tnicolas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

NAME_BONUS = visu_hex/visu-hex

FILES_BONUS = main.c \
			  ft_error2.c \
			  ft_close.c \
			  ft_key_event.c \
			  ft_print_result.c \
			  ft_next_step.c \
			  ft_init_win.c \
			  lib/ft_set_coord.c \
			  lib/ft_put_px.c \
			  lib/ft_put_line.c \
			  lib/ft_reset_win.c \
			  lib/ft_print_win.c

FILES = ft_dispatch_2.c \
		ft_dispatch.c \
		algo.c \
		init_algo.c \
		path_algo.c \
		ft_sz_lst.c \
		main.c

COMMUN = lem_in_3.c \
		 lem_in_2.c \
		 lem_in.c \
		 use.c \
		 ft_fruit_a.c \
		 ft_fruit_lst.c

HFILES = includes/lem_in.h \
		 libft/includes/libft.h \
		 visu_hex/includes/visu_hex.h \
		 visu_hex/includes/visu_hex_struct.h

BONUS_DIR = visu_hex/
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = libft/
LIBFT_LIB = -L $(LIBFT_DIR) -lft
LIBX_DIR = visu_hex/minilibx_macos/
LIBX_LIB = -L $(LIBX_DIR) -lmlx -framework OpenGL -framework AppKit

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = objs/
SRCS_DIR = srcs/

INC_DIR =	includes/ \
			libft/includes/ \
			visu_hex/includes/ \
			$(LIBX_DIR)

INC := $(addprefix -I , $(INC_DIR))
SRCS := $(addprefix $(SRCS_DIR), $(FILES))
OBJS := $(addprefix $(OBJS_DIR), $(FILES:.c=.o))
SRCS_BONUS := $(addprefix visu_hex/srcs/, $(FILES_BONUS))
OBJS_BONUS := $(addprefix visu_hex/objs/, $(FILES_BONUS:.c=.o))
SRCS_COM := $(addprefix $(SRCS_DIR), $(COMMUN))
OBJS_COM := $(addprefix $(OBJS_DIR), $(COMMUN:.c=.o))

NORMAL = "\x1B[0m"
RED = "\x1B[31m"
GREEN = "\x1B[32m"
YELLOW = "\x1B[33m"
BLUE = "\x1B[34m"
MAGENTA = "\x1B[35m"
CYAN = "\x1B[36m"
WHITE = "\x1B[37m"
BOLD = "\e[1m"
LIGHT = "\e[2m"
ITALIC = "\e[3m"
ULINE = "\e[4m"

ARG = "map.txt"

START = @printf $(GREEN)$(BOLD)"LEM-IN\n--------------------\n"$(NORMAL)
END = @printf $(GREEN)$(BOLD)"--------------------\n"$(NORMAL)

all:
	@make -C $(LIBFT_DIR)
	@printf $(GREEN)$(BOLD)"MINILIBX\n--------------------\n"$(NORMAL)$(YELLOW)
	@make -C $(LIBX_DIR)
	@printf $(GREEN)$(BOLD)"--------------------\n"$(NORMAL)
	$(START)
	@make $(NAME)
	$(END)
	@printf $(GREEN)$(BOLD)"VISU-HEX\n--------------------\n"$(NORMAL)
	@make $(NAME_BONUS)
	@printf $(GREEN)$(BOLD)"--------------------\n"$(NORMAL)

$(NAME): $(OBJS_DIR) $(OBJS) $(OBJS_COM) $(LIBFT)
	@printf $(CYAN)"-> create program : $(NAME)\n"$(NORMAL)
	@$(CC) -o $(NAME) $(OBJS) $(OBJS_COM) $(INC) $(CFLAGS) $(LIBFT_LIB)

$(NAME_BONUS): $(OBJS_DIR) $(OBJS_BONUS) $(OBJS_COM) $(LIBFT)
	@printf $(CYAN)"-> create program : $(NAME_BONUS)\n"$(NORMAL)
	@$(CC) -o $(NAME_BONUS) $(OBJS_BONUS) $(OBJS_COM) $(INC) $(CFLAGS) $(LIBFT_LIB) $(LIBX_LIB)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HFILES)
	@printf $(YELLOW)"-> $<\n"$(NORMAL)
	@$(CC) -c $(INC) $< -o $@ $(CFLAGS)

visu_hex/objs/%.o: visu_hex/srcs/%.c $(HFILES)
	@printf $(YELLOW)"-> $<\n"$(NORMAL)
	@$(CC) -c $(INC) $< -o $@ $(CFLAGS)

$(OBJS_DIR):
	@mkdir -p $(dir $(OBJS))
	@mkdir -p $(dir $(OBJS_BONUS))
	@mkdir -p $(dir $(OBJS_COM))

clean:
	@make -C $(LIBFT_DIR) clean
	@printf $(GREEN)$(BOLD)"MINILIBX\n--------------------\n"$(NORMAL)$(YELLOW)
	@make -C $(LIBX_DIR) clean
	@printf $(GREEN)$(BOLD)"--------------------\n"$(NORMAL)
	$(START)
	@printf $(RED)"-x remove .o files\n"$(NORMAL)
	@rm -rf $(OBJS_DIR)
	@rm -rf visu_hex/objs
	$(END)

fclean: clean
	@make -C $(LIBFT_DIR) cleanlib
	$(START)
	@printf $(RED)"-x remove $(NAME)\n"$(NORMAL)
	@rm -f $(NAME)
	@printf $(RED)"-x remove $(NAME_BONUS)\n"$(NORMAL)
	@rm -f $(NAME_BONUS)
	$(END)

re: fclean
	@make

exec:
	@clear
	@make
	@printf $(MAGENTA)$(BOLD)"EXEC LEM-IN\n--------------------\n"$(NORMAL)
	@printf "map:\n"$(YELLOW)
	@cat $(ARG)
	@printf $(NORMAL)"\nresult:\n"
	@./$(NAME) < $(ARG)
	@./$(NAME) < $(ARG) 2> /dev/null | ./$(NAME_BONUS)
	@printf $(MAGENTA)$(BOLD)"--------------------\n"$(NORMAL)

open:
	@vim +Line `git config --get remote.origin.url | sed "s/..*/+SergeGit/"` $(SRCS) $(SRCS_BONUS) $(SRCS_COM) $(HFILES) Makefile

.PHONY: all clean fclean re
