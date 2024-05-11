/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:02:40 by trolland          #+#    #+#             */
/*   Updated: 2024/05/11 17:37:20 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	get_max(t_control *control)
{
	t_node	*temp;
	int		*max;

	temp = control->stack_a;
	max = &(control->stack_a_max);
	*max = -2147483648;
	while (temp)
	{
		if (temp->nb > *max)
			*max = temp->nb;
		temp = temp->next;
	}
}
