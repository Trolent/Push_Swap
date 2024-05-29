/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:02:40 by trolland          #+#    #+#             */
/*   Updated: 2024/05/29 17:18:55 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*min_node(t_node *stack)
{
	t_node	*temp;
	t_node	*min;

	temp = stack;
	min = temp;
	while (temp)
	{
		if (temp->nb < min->nb)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

int	check_sort(t_control *control)
{
	t_node	*temp;

	if (control->stack_a == NULL)
		return (-1);
	temp = control->stack_a;
	while (temp->next)
	{
		if (temp->nb > temp->next->nb)
			return (-1);
		temp = temp->next;
	}
	return (0);
}

void	ascending(t_control *control)
{
	t_node	*temp;
	int		median;

	temp = min_node(control->stack_a);
	median = control->size_a / 2;
	while (control->stack_a != temp)
	{
		if (temp->index < median)
			rotate_a(control);
		else
			reverse_a(control);
	}
}
