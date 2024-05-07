/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:38:57 by trolland          #+#    #+#             */
/*   Updated: 2024/05/07 19:01:25 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/errors_map.h"
#include "../includes/push_swap.h"

void	cost_rev_rot(t_control *control, t_node *temp, long *i, long *cost)
{
	while ((temp->index + *i <= (control->size_a - 1) / 2)
		&& (temp->target->index + *i <= (control->size_b - 1) / 2) && *cost > 0)
	{
		(*cost)--;
		(*i)++;
	}
	while ((temp->index - *i > (control->size_a - 1) / 2)
		&& (temp->target->index - *i > (control->size_b - 1) / 2) && *cost > 0)
	{
		(*cost)--;
		(*i)++;
	}
}

void	get_cost(t_control *control)
{
	t_node	*temp;
	int		index1;
	int		index2;
	long	cost;
	long	i;

	temp = control->stack_a;
	while (temp)
	{
		if (temp->index > control->size_a / 2)
			index1 = control->size_a - temp->index;
		else
			index1 = temp->index;
		if (temp->target->index > control->size_b / 2)
			index2 = control->size_b - temp->target->index;
		else
			index2 = temp->target->index;
		cost = index1 + index2;
		// printf("temp is %d\n---temp index is %d, target index is %d\n---size a is %d, size b is %d\n", temp->nb, temp->index,
			// temp->target->index, control->size_a, control->size_b);
		i = 0;
		cost_rev_rot(control, temp, &i, &cost);
		temp->cost = cost;
		// printf("---------------------------temp cost is %d\n", temp->cost);
		temp = temp->next;
	}
}
