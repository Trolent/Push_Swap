# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trolland <trolland@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 16:23:19 by trolland          #+#    #+#              #
#    Updated: 2024/05/07 15:55:44 by trolland         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT	= 	libft/libft.a

SRC := 		main.c lst_utils.c push.c reverse.c swap.c rotate.c target.c cost.c \
			parse.c move_to_a_b.c
			
SRCS := 	$(addprefix src/, $(SRC))
OBJS := 	$(patsubst src/%.c, object/%.o, $(SRCS))
DEPS := 	$(OBJS:.o=.d)

SRCS_BONUS := 	$(addprefix src_bonus/, $(SRC))
OBJS_BONUS := 	$(patsubst src_bonus/%.c, object_bonus/%.o, $(SRCS_BONUS))
DEPS_BONUS := 	$(OBJS_BONUS:.o=.d)

CC := cc

CFLAGS := -Wall -Werror -Wextra -MMD -MP -Iincludes -Ilibft -g

all:	$(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	
bonus: $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME)

object_bonus/%.o: src_bonus/%.c
	@if [ ! -d "object_bonus" ]; then mkdir object_bonus; fi
	@printf "\033[0;32m\tCompiling: $<\033[0m\n";
	@$(CC) $(CFLAGS) -c $< -o $@


object/%.o: src/%.c
	@if [ ! -d "object" ]; then mkdir object; fi
	@printf "\033[0;32m\tCompiling: $<\033[0m\n";
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C libft

clean:
	@rm -rf object
	@rm -rf object_bonus
	@$(MAKE) --no-print-directory clean -C libft

fclean: clean
	@rm -f $(NAME) mlx

re: fclean all

norm:
	$(MAKE) -C libft norm
	@echo 'Checking header files...'
	@output_header=$$(norminette -R CheckDefine includes/*.h); \
	echo "$$output_header" | awk '/Error/ {print "\033[0;31m" $$0 "\033[0m"}'; \
	echo 'Checking source files...'; \
	output_source=$$(norminette -R CheckForbiddenSourceHeader src/*.c); \
	echo "$$output_source" | awk '/Error/ {print "\033[0;31m" $$0 "\033[0m"}'; \
	total_errors=$$(echo "$$output_header $$output_source" | grep -c 'Error:'); \
	if [ $$total_errors -gt 0 ]; then \
	    echo "\033[0;31m$$total_errors errors found\033[0m"; \
	else \
	    echo "\033[0;32mNo norminette error in Pipex\033[0m"; \
	fi

-include $(DEPS) $(DEPS_BONUS) 

.PHONY: all clean fclean re norm bonus
