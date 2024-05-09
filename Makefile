# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trolland <trolland@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 16:23:19 by trolland          #+#    #+#              #
#    Updated: 2024/05/09 21:32:57 by trolland         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

LIBFT	= 	libft/libft.a

SRC := lst_utils.c push.c reverse.c swap.c rotate.c target.c cost.c parse.c \
		move_to_a_b.c sort.c median.c sort_utils.c

SRCS := $(addprefix src/, $(SRC))
OBJS := $(patsubst src/%.c, object/%.o, $(SRCS))
DEPS := $(OBJS:.o=.d)

SRC_MAIN := main/main.c
SRC_BONUS := main_bonus/main_bonus.c

CC := cc

CFLAGS := -Wall -Werror -Wextra -MMD -MP -Iincludes -Ilibft -g

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS) object/main.o $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) object/main.o $(LIBFT) -o $(NAME)

$(BONUS_NAME): $(OBJS) object/bonus_main.o $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) object/bonus_main.o $(LIBFT) -o $(BONUS_NAME)

object/%.o: src/%.c
	@if [ ! -d "object" ]; then mkdir object; fi
	@printf "\033[0;32m\tCompiling: $<\033[0m\n";
	@$(CC) $(CFLAGS) -c $< -o $@

object/main.o: $(SRC_MAIN)
	@if [ ! -d "object" ]; then mkdir object; fi
	@printf "\033[0;32m\tCompiling: $<\033[0m\n";
	@$(CC) $(CFLAGS) -c $< -o $@

object/bonus_main.o: $(SRC_BONUS)
	@if [ ! -d "object" ]; then mkdir object; fi
	@printf "\033[0;32m\tCompiling: $<\033[0m\n";
	@$(CC) $(CFLAGS) -c $< -o $@ -DBONUS

$(LIBFT):
	@$(MAKE) -C libft

clean:
	@$(MAKE) --no-print-directory clean -C libft
	@echo "Cleaning push_swap's object files..."
	@rm -rf object
	@rm -rf object_bonus

fclean: clean
	@echo "Cleaning libft..."
	@echo "Cleaning push_swap..."
	@rm -f $(NAME) $(BONUS_NAME)
	@rm -f libft/libft.a

re: fclean all

norm:
	$(MAKE) -C libft norm
	@echo 'Checking header files...'
	@output_header=$$(norminette -R CheckDefine includes/*.h); \
	echo "$$output_header" | awk '/Error/ {print "\033[0;31m" $$0 "\033[0m"}'; \
	echo 'Checking main file...'; \
	output_main=$$(norminette -R CheckForbiddenSourceHeader main/*.c); \
	echo "$$output_main" | awk '/Error/ {print "\033[0;31m" $$0 "\033[0m"}'; \
	echo 'Checking main_bonus file...'; \
	output_main_bonus=$$(norminette -R CheckForbiddenSourceHeader main_bonus/*.c); \
	echo "$$output_main_bonus" | awk '/Error/ {print "\033[0;31m" $$0 "\033[0m"}'; \
	echo 'Checking source files...'; \
	output_source=$$(norminette -R CheckForbiddenSourceHeader src/*.c); \
	echo "$$output_source" | awk '/Error/ {print "\033[0;31m" $$0 "\033[0m"}'; \
	total_errors=$$(echo "$$output_header $$output_source $$output_main \
	$$output_main_bonus" | grep -c 'Error:'); \
	if [ $$total_errors -gt 0 ]; then \
	    echo "\033[0;31m$$total_errors errors found\033[0m"; \
	else \
	    echo "\033[0;32mNo norminette error in Pipex\033[0m"; \
	fi

-include $(DEPS) $(DEPS_BONUS) 

.PHONY: all clean fclean re norm bonus
