# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 20:33:05 by rorollin          #+#    #+#              #
#    Updated: 2025/02/12 17:55:05 by rorollin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

#SOURCES######################

SOURCES_DIR = src

SOURCES_NAME = main.c

SOURCES = $(addprefix $(SOURCES_DIR)/, $(SOURCES_NAME))

SOURCES_BONUS = 

#OBJECTS#######################

OBJ_DIR = obj

OBJECTS = $(SOURCES:%.c=$(OBJ_DIR)/%.o)

#DEPS##########################

DEPS = $(SOURCES:%.c=$(OBJ_DIR)/%.d)

#INCLUDES#######################

HEADERS_DIR = include/ libft/include/ 

HEADERS_NAME = push_swap.h libft.h

INCLUDES = $(addprefix -I , $(HEADERS_DIR))

#LIBFT########################

LIBFT = libft

LIBFT_PATH = $(LIBFT)/$(LIBFT).a

#COMPILER#####################

COMPILER = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP -ggdb3

all: git make_libft $(NAME)

$(NAME):  $(OBJECTS) $(LIBFT_PATH)
	$(COMPILER) $(CFLAGS) $(INCLUDES) $^ -o $@
	@echo "$(NAME) built succesfully."


$(OBJ_DIR)/%.o: %.c 
	mkdir -p $(dir $@)
	$(COMPILER) $(CFLAGS) $(INCLUDES) -c $< -o $@

-include $(DEPS)

git: 
	@git submodule update --init --remote --recursive

make_libft:
	@$(MAKE) -s -C $(LIBFT)

clean:
	@$(MAKE) -s -C $(LIBFT) clean
	@rm -rf $(OBJ_DIR)
	@rm -f .bonus
	@echo "Cleaned !"

fclean:
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) clean
	@rm -f $(NAME)
	@echo "Fcleaned !"

re:	
	$(MAKE) fclean 
	$(MAKE) all


.PHONY: all clean fclean re make_libft git
