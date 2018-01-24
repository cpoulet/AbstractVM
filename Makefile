# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/07 12:10:08 by kcosta            #+#    #+#              #
#*   Updated: 2017/04/28 07:55:15 by kcosta           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

# =========== Colors =========== #
CLEAR			:= "\033[2K"
UP				:= "\033[A"
EOC				:= "\033[0;0m"
BLACK			:= "\033[0;30m"
RED				:= "\033[0;31m"
GREEN			:= "\033[0;32m"
YELLOW			:= "\033[0;33m"
BLUE			:= "\033[0;34m"
PURPLE			:= "\033[0;35m"
CYAN			:= "\033[0;36m"
WHITE			:= "\033[0;37m"
# ============================== #

# ========== Editable ========== #
AVM					:= avm
# ============================== #

# ========== Standard ========== #
CC					:= clang++
FLAGS				:= -Wall -Wextra -Werror
# ============================== #

# =========== Files ============ #
AVM_SRCS_FILES		:=	avm.cpp \
						toto.cpp
AVM_HEADERS_FILES	:=	avm.h		\
						toto.h
# ============================== #

# ========== Sources =========== #
AVM_PATH			:= srcs/
AVM_SRCS			:= $(addprefix $(AVM_PATH), $(AVM_SRCS_FILES))
# ============================== #

# ========== Objects =========== #
OBJS_PATH			:= objs/
AVM_OBJS_PATH		:= objs/
AVM_OBJS 			:= $(addprefix $(AVM_OBJS_PATH), $(AVM_SRCS_FILES:.c=.o))
# ============================== #

# ========== Includes ========== #
INCLUDES_PATH		:= includes/
INCLUDES			:= -I $(INCLUDES_PATH)
AVM_HEADERS			:= $(addprefix $(INCLUDES_PATH), $(AVM_HEADERS_FILES))
# ============================== #

.PHONY: all libft clean fclean re

all: $(AVM)

$(AVM_OBJS_PATH)%.o: $(AVM_PATH)%.c $(AVM_HEADERS)
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@mkdir $(AVM_OBJS_PATH) 2> /dev/null || true
	$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(AVMWAR): $(AVM_OBJS)
	$(CC) $(FLAGS) $(AVM_OBJS) -o $@

clean:
	@rm -fv $(AVM_OBJS)
	@rmdir $(OBJS_PATH) 2> /dev/null || true

fclean: clean
	@rm -fv $(AVMWAR)

re: fclean all
