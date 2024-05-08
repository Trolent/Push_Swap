/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:35:14 by trolland          #+#    #+#             */
/*   Updated: 2024/05/08 19:32:42 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/errors_map.h"
#include "../includes/push_swap.h"

t_node	*max_node(t_node *stack)
{
	t_node	*temp;
	t_node	*max;

	temp = stack;
	max = temp;
	while (temp)
	{
		if (temp->nb > max->nb)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

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

void	get_target_a(t_control *control)
{
	t_node	*temp_a;
	t_node	*temp_b;
	t_node	*closest;
	long	diff;

	temp_a = control->stack_a;
	while (temp_a)
	{
		temp_b = control->stack_b;
		closest = NULL;
		diff = 0;
		while (temp_b)
		{
			if (temp_b->nb < temp_a->nb && temp_b->nb > diff)
			{
				diff  = temp_b->nb;
				closest = temp_b;
			}
			temp_b = temp_b->next;
		}
		if (closest == NULL)
			closest = max_node(control->stack_b);
		temp_a->target = closest;
		temp_a = temp_a->next;
	}
}

void	get_target_b(t_control *control)
{
	t_node	*temp_a;
	t_node	*temp_b;
	t_node	*closest;
	long	diff;

	temp_b = control->stack_b;
	while (temp_b)
	{
		temp_a = control->stack_a;
		closest = NULL;
		diff = (unsigned int)-1;
		while (temp_a)
		{
			if (temp_b->nb < temp_a->nb && temp_a->nb - temp_b->nb < diff)
			{
				diff = temp_a->nb - temp_b->nb;
				closest = temp_a;
			}
			temp_a = temp_a->next;
		}
		if (closest == NULL)
			closest = min_node(control->stack_a);
		temp_b->target = closest;
		temp_b = temp_b->next;
	}
}
