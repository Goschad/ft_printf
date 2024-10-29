# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marwen <marwen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 10:09:58 by mbouaza           #+#    #+#              #
#    Updated: 2024/10/29 22:05:43 by marwen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Name --- #

NAME 	= libftprintf.a

# --- Directory --- #

LIB_DIR = lib_dir/

OBJ_DIR = objs_dir/

# --- Compiler --- #

CC 		= @gcc

# --- Flags --- #

CFLAGS 	= -Wall -Werror -Wextra

# --- Colors --- #

RED      =      "\033[1;31m"
GREEN    =      "\033[1;32m"
BLUE     =      "\033[0;34m"
PURPLE   =      "\033[1;35m"
END      =      "\033[0;0m"

# --- Srcs --- #

SRCS 	=	ft_printf.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_strlen.c \
			ft_putnbr_unsigned.c \
			ft_putnbr_hex_maj.c \
			ft_putnbr_hex_min.c \
			ft_put_ptr.c

# --- Objs --- #

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# - All --- #

all: $(LIB_DIR)$(NAME)

# --- Objs dir --- #

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# --- Compilation --- #

$(LIB_DIR)$(NAME) : $(OBJS)
	$(Compilation_lib)
	@mkdir -p $(LIB_DIR)
	@ar -rcs $(LIB_DIR)$(NAME) $(OBJS)

# --- Clear --- #

clean: Deleting_objs
	@rm -rf $(OBJ_DIR)

fclean: clean Deleting_lib
	@rm -rf $(LIB_DIR)$

re : fclean all

# --- Message --- #

Deleting_objs:
	@echo $(RED)"[-] Delete > ./$(OBJ_DIR)"$(END)

Deleting_lib:
	@echo $(RED)"[-] Delete > ./$(LIB_DIR)"$(END)

Compilation_lib = @for file in $(SRCS); do \
        printf $(BLUE)"[+] Compilation > "; \
        printf $(GREEN)"$$file"; \
        sleep 0.04; \
        printf "\r\033[K"; \
	done; \
    printf $(BLUE)"[+] Compilation > "; \
    echo $(GREEN)"Success"$(END);