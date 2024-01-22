/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:37:42 by trolland          #+#    #+#             */
/*   Updated: 2024/01/17 13:59:23 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void ft_error()
{
	ft_putstr_fd("Error\n", 2);
}

void	ft_free_stack(t_node *a)
{
	t_node	*current;
	t_node	*next;

	current = a;
	while (current != NULL && current->next != a)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(current);
}

void	ft_free_error(t_node **stack_a, char **elements, int split)
{
	int	i;
	

	ft_free_stack(*stack_a);
	if (split == 0)
	{
		i = 0;
		while (elements[i])
			i++;
		ft_free_tab(elements, i);
	}
	ft_error();
}
