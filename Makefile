# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 20:33:05 by rorollin          #+#    #+#              #
#    Updated: 2025/03/28 12:36:30 by rorollin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

#SOURCES######################

SOURCES_DIR = src

SOURCES_NAME = main.c error_handling.c parsing.c  

SOURCES_UTILS = context_utils.c node_utils.c stack_utils.c array_utils.c \
				movelist_utils.c target_utils.c stack_stat.c stack_manip.c \
				movelist_print.c

SOURCES_CONTEXT =  context_move_push.c context_move_rotate.c context_move_rrotate.c \
				   context_move_swap.c 

SOURCES_ALGO = find_target.c stack_state.c node_search.c move_optimize.c algo_loop.c \
			   special_case.c

SOURCES_DEBUG = debug.c test.c

SOURCES = $(addprefix $(SOURCES_DIR)/,\
		  $(SOURCES_NAME)\
		  $(addprefix utils/, $(SOURCES_UTILS))\
		  $(addprefix context/, $(SOURCES_CONTEXT))\
		  $(addprefix algo/, $(SOURCES_ALGO))\
		  )
# $(addprefix .hidden/, $(SOURCES_DEBUG))\
		  


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

CFLAGS_DEBUG = -Wall -Wextra -Werror -MMD -MP -ggdb3 -Wshadow -Wconversion -Wsign-conversion -Wstrict-prototypes -Wmissing-prototypes \
-Wformat=2 -Wformat-security -Wnull-dereference -Wstack-protector -Wfloat-equal -Wpointer-arith \
-Wcast-align -Wundef -Wbad-function-cast -Wstrict-overflow=4 -Wdouble-promotion -Walloca -Wvla \
-Wwrite-strings -Wuninitialized -fno-delete-null-pointer-checks -fno-omit-frame-pointer -std=c11

CFLAGS_PROD = -Wall -Wextra -Werror -MMD -MP -ggdb3 -O3

CFLAGS = $(CFLAGS_PROD)

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
