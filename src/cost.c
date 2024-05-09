/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:38:57 by trolland          #+#    #+#             */
/*   Updated: 2024/05/09 19:55:31 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_cost(t_control *control)
{
	t_node	*temp;

	temp = control->stack_b;
	while (temp)
	{
		temp->cost = temp->index;
		if (temp->index > control->mediane_b)
			temp->cost = control->size_b - temp->index;
		if (temp->target->index < control->mediane_a)
			temp->cost += temp->target->index;
		else
			temp->cost += control->size_a - temp->target->index;
		temp = temp->next;
	}
}
