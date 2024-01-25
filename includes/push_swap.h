/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:38:07 by trolland          #+#    #+#             */
/*   Updated: 2024/01/24 14:14:06 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
	int				nb;
	int				index;
	int				push_cost;

	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
}					t_node;

int					ft_syntax_error(char *str);
int					ft_check_duplicate(t_node **a, int n, int size);

void				ft_free_stack(t_node *a);
void				ft_free_error(t_node **stack_a, char **elements, int split);

void ft_swap_node(t_node **top);
void ft_sa(t_node **top);

#endif