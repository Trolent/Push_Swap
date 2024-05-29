/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:55:13 by trolland          #+#    #+#             */
/*   Updated: 2024/05/29 17:10:27 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	indexing(t_control *control)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = control->stack_a;
	control->mediane_a = control->size_a / 2;
	control->mediane_b = control->size_b / 2;
	while (temp)
	{
		temp->index = i;
		i++;
		temp = temp->next;
	}
	temp = control->stack_b;
	i = 0;
	while (temp)
	{
		temp->index = i;
		i++;
		temp = temp->next;
	}
}

static t_node	*get_chepest_cost(t_control *control)
{
	t_node	*temp;
	t_node	*cheapest;

	temp = control->stack_b;
	cheapest = temp;
	while (temp)
	{
		if (temp->cost == 0)
			cheapest = temp;
		if (temp->cost < cheapest->cost)
			cheapest = temp;
		temp = temp->next;
	}
	return (cheapest);
}

static void	ops_details(t_control *control, t_node*temp)
{
	while ((temp->index != 0 || temp->target->index != 0))
	{
		indexing(control);
		if (temp->index < control->mediane_b
			&& temp->target->index < control->mediane_a && temp->index != 0
			&& temp->target->index != 0)
			rotate_ab(control);
		else if (temp->index >= control->mediane_b
			&& temp->target->index >= control->mediane_a && temp->index != 0
			&& temp->target->index != 0)
			reverse_ab(control);
		else if (temp->index < control->mediane_b && temp->index != 0)
			rotate_b(control);
		else if (temp->index >= control->mediane_b && temp->index != 0)
			reverse_b(control);
		else if (temp->target->index < control->mediane_a
			&& temp->target->index != 0)
			rotate_a(control);
		else if (temp->target->index >= control->mediane_a
			&& temp->target->index != 0)
			reverse_a(control);
	}
}

static void	do_ops_ba(t_control *control)
{
	t_node	*temp;

	temp = get_chepest_cost(control);
	if (temp->index == 0 && temp->target->index == 0)
	{
		push_a(control);
		return ;
	}
	ops_details(control, temp);
	if (temp->index == 0 && temp->target->index == 0)
		push_a(control);
}

void	move_to_a(t_control *control)
{
	while (control->size_b > 0)
	{
		indexing(control);
		get_target_b(control);
		get_cost(control);
		do_ops_ba(control);
	}
}
