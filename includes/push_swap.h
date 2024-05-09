/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:38:07 by trolland          #+#    #+#             */
/*   Updated: 2024/05/09 20:03:14 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				nb;
	int				index;
	int				cost;

	struct s_node	*next;
	struct s_node	*target;
}					t_node;

typedef struct s_control
{
	t_node			*stack_a;
	t_node			*stack_b;
	int				size_a;
	int				size_b;
	int				mediane_a;
	int				mediane_b;
	int				stack_a_max;
	int				median_value;
	int				checker;
}					t_control;

t_node				*ft_lstnew_node(char *nbr);
t_node				*ft_lstlast_node(t_node *lst);
void				ft_lstadd_node_back(t_node **alst, t_node *new);
void				ft_lstadd_node_front(t_node **alst, t_node *new);

int					verify_elements(char *str);

void				swap_a(t_control *control);
void				swap_b(t_control *control);
void				swap_ss(t_control *control);

void				push_b(t_control *control);
void				push_a(t_control *control);

void				rotate_a(t_control *control);
void				rotate_b(t_control *control);
void				rotate_ab(t_control *control);

void				reverse_a(t_control *control);
void				reverse_b(t_control *control);
void				reverse_ab(t_control *control);

void				get_target_a(t_control *control);
void				get_target_b(t_control *control);
t_node				*max_node(t_node *stack);

void				get_cost(t_control *control);

int					parse(t_control *control, int argc, char **argv);

void				move_to_a(t_control *control);
void				move_to_b(t_control *control);

void				indexing(t_control *control);

t_node				*min_node(t_node *stack);

void				free_stack(t_control *control);

int					sorting(t_control *control);

int					check_sort(t_control *control);

void				sort_tab(int **tab, int size);
int					define_median(t_control *control, char **argv, int index);

int					check_sort(t_control *control);
void				ascending(t_control *control);
void				get_max(t_control *control);

#endif