# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 14:57:06 by mcha              #+#    #+#              #
#    Updated: 2022/05/21 17:56:37 by yejikim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
RM		= rm -rf
CFLAGS	= -I $(HEAD_ROOT) -Wall -Werror -Wextra -g
RLLINK	= -l readline -L$(HOME)/.brew/opt/readline/lib
RLINC	=  -I$(HOME)/.brew/opt/readline/include

NAME	= minishell

HEAD_ROOT	= includes
OBJS_ROOT	= obj
SRCS_ROOT	= src

# Src subdirectory
SRCS_UTIL = src/util
SRCS_TEST = src/test

# Add subdirectory
# SRCS_ROOT += $(SRCS_UTIL) $(SRCS_TEST)

# Src files
FILE_TEST = $(notdir $(wildcard $(SRCS_TEST)/*.c))

vpath %.c $(SRCS_ROOT)

# Common file objects
COMM_OBJ	= main.o
TEST_OBJ	= $(FILE_TEST:.c=.o)

OBJS := $(COMM_OBJ) $(UTIL_OBJ)
OBJS := $(addprefix $(OBJS_ROOT)/, $(OBJS))

all : $(NAME)

$(OBJS_ROOT)/%.o : %.c
		@echo "[~] Linking $<"
		@$(CC) $(CFLAGS) $(RLINC) -c -o $@ $<

$(NAME) : $(OBJS)
		@echo "[+] Create minishell"
		@$(CC) $(CFLAGS) $(RLINC) $(RLLINK) -o $@ $(OBJS)

clean :
		@$(RM) $(OBJS)
		@echo "[-] Delete object files"

fclean : clean
		@$(RM) $(NAME)
		@echo "[-] Delete run files"

re : fclean all

.PHONY : all clean fclean re