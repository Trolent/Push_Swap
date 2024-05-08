/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:55:13 by trolland          #+#    #+#             */
/*   Updated: 2024/05/08 20:53:01 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	indexing(t_control *control)
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

t_node *get_chepest_cost(t_control *control)
{
	t_node *temp;
	t_node *cheapest;

	temp = control->stack_a;
	cheapest = temp;
	while(temp)
	{
		if (temp->cost == 0)
			cheapest = temp;
		if (temp->cost < cheapest->cost)
			cheapest = temp;
		temp = temp->next;
	}
	return(cheapest);
}

void do_ops_ab(t_control *control)
{
	t_node *temp;

	temp = get_chepest_cost(control);
	if(temp->index == 0 && temp->target->index == 0)
	{
		push_b(control);
		return;
	}
	while((temp->index != 0 || temp->target->index != 0))
	{
		indexing(control);
		if(temp->index < control->mediane_a && temp->target->index < control->mediane_b && temp->index != 0 && temp->target->index != 0)
			rotate_ab(control);
		else if(temp->index >= control->mediane_a && temp->target->index >= control->mediane_b && temp->index != 0 && temp->target->index != 0)
			reverse_ab(control);
		else if(temp->index < control->mediane_a && temp->index != 0)
			rotate_a(control);
		else if(temp->index >= control->mediane_a)
			reverse_a(control);
		else if(temp->target->index < control->mediane_b && temp->target->index != 0)
			rotate_b(control);
		else if(temp->target->index >= control->mediane_b)
			reverse_b(control);
	}
	if (temp->index == 0 && temp->target->index == 0)
		push_b(control);
}

void	move_to_b(t_control *control)
{
	push_b(control);
	if (control->size_a > 3)
		push_b(control);
	while(control->size_a > 3)
	{
		indexing(control);
		get_target_a(control);
		get_cost(control);
		do_ops_ab(control);
	}
}

void do_ops_ba(t_control *control)
{
    t_node *temp;

    temp = control->stack_b;
    while(control->stack_a != temp->target)
    {
        if(temp->target->index <= (control->size_a - 1) / 2)
            rotate_a(control);
        else
            reverse_a(control);
        indexing(control);
    }
    push_a(control);
}

void move_to_a(t_control *control)
{
	while(control->size_b > 0)
	{
        indexing(control);
        get_target_b(control);
        do_ops_ba(control);
	}
}
