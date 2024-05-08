/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:38:57 by trolland          #+#    #+#             */
/*   Updated: 2024/05/08 21:00:45 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/errors_map.h"
#include "../includes/push_swap.h"

void	get_cost(t_control *control)
{
	t_node *temp;

	temp = control->stack_a;
	while (temp)
	{
		temp->cost = temp->index;
		if (temp->index > control->mediane_a)
			temp->cost = control->size_a - temp->index;
		if(temp->target->index < control->mediane_b)
			temp->cost += temp->target->index;
		else
			temp->cost += control->size_b - temp->target->index;
		temp = temp->next;
	}
}
