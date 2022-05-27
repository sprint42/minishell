# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 14:57:06 by mcha              #+#    #+#              #
#    Updated: 2022/05/27 21:55:26 by yejikim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
RM		= rm -rf
CFLAGS	= -I $(HEAD_ROOT) -Wall -Werror -Wextra -g3 -fsanitize=address
RLLINK	= -l readline -L$(HOME)/.brew/opt/readline/lib
RLINC	=  -I$(HOME)/.brew/opt/readline/include

NAME	= minishell

HEAD_ROOT	= includes
OBJS_ROOT	= obj
SRCS_ROOT	= src

# Src subdirectory
SRCS_UTIL 	= src/util
SRCS_TEST 	= src/test
SRCS_IS		= $(SRCS_TEST)/is
SRCS_PROC	= $(SRCS_TEST)/proc
SRCS_STRUCT	= $(SRCS_TEST)/struct
SRCS_NODE	= $(SRCS_TEST)/node
SRCS_FREE	= $(SRCS_TEST)/free
SRCS_LINK	= $(SRCS_TEST)/link
SRCS_ERROR	= $(SRCS_TEST)/error
SRCS_LIBF	= libft
SRCS_GNL	= gnl
SRCS_BUILT	= src/builtin

# Add subdirectory
SRCS_ROOT += $(SRCS_UTIL) $(SRCS_TEST) $(SRCS_IS) $(SRCS_PROC) $(SRCS_STRUCT) $(SRCS_LIBF) $(SRCS_NODE) $(SRCS_FREE) $(SRCS_LINK) $(SRCS_ERROR) $(SRCS_BUILT) $(SRCS_GNL)

# Src files
FILE_TEST 	= $(notdir $(wildcard $(SRCS_TEST)/*.c))
FILE_UTIL 	= $(notdir $(wildcard $(SRCS_UTIL)/*.c))
FILE_IS		= $(notdir $(wildcard $(SRCS_IS)/*.c))
FILE_PROC	= $(notdir $(wildcard $(SRCS_PROC)/*.c))
FILE_STRUCT	= $(notdir $(wildcard $(SRCS_STRUCT)/*.c))
FILE_NODE	= $(notdir $(wildcard $(SRCS_NODE)/*.c))
FILE_FREE	= $(notdir $(wildcard $(SRCS_FREE)/*.c))
FILE_LIBF 	= $(notdir $(wildcard $(SRCS_LIBF)/*.c))
FILE_LINK 	= $(notdir $(wildcard $(SRCS_LINK)/*.c))
FILE_ERROR	= $(notdir $(wildcard $(SRCS_ERROR)/*.c))
FILE_BUILT	= $(notdir $(wildcard $(SRCS_BUILT)/*.c))
FILE_ROOT	= $(notdir $(wildcard src/*.c))
FILE_GNL	= $(notdir $(wildcard $(SRCS_GNL)/*.c))

vpath %.c $(SRCS_ROOT)

# Common file objects
TEST_OBJ	= $(FILE_TEST:.c=.o)
IS_OBJ		= $(FILE_IS:.c=.o)
PROC_OBJ	= $(FILE_PROC:.c=.o)
STRUCT_OBJ	= $(FILE_STRUCT:.c=.o)
NODE_OBJ	= $(FILE_NODE:.c=.o)
FREE_OBJ	= $(FILE_FREE:.c=.o)
LIBF_OBJ	= $(FILE_LIBF:.c=.o)
LINK_OBJ	= $(FILE_LINK:.c=.o)
ERROR_OBJ	= $(FILE_ERROR:.c=.o)
BUILT_OBJ	= $(FILE_BUILT:.c=.o)
ROOT_OBJ	= $(FILE_ROOT:.c=.o)
GNL_OBJ		= $(FILE_GNL:.c=.o)

OBJS := $(TEST_OBJ) $(IS_OBJ) $(PROC_OBJ) $(STRUCT_OBJ) $(LIBF_OBJ) $(NODE_OBJ) $(FREE_OBJ) $(LINK_OBJ) $(ERROR_OBJ) $(BUILT_OBJ) $(ROOT_OBJ) $(GNL_OBJ)
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