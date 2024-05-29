/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:35:14 by trolland          #+#    #+#             */
/*   Updated: 2024/05/29 17:17:19 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
