/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:55:13 by trolland          #+#    #+#             */
/*   Updated: 2024/05/07 16:48:13 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	indexing(t_control *control)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = control->stack_a;
	while (temp)
	{
		temp->index = i;
		i++;
		temp = temp->next;
	}
	i = 0;
	temp = control->stack_b;
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
	t_node *chepest;

	temp = control->stack_a;
	chepest = temp;
	while(temp)
	{
		if (temp->cost == 0)
			return(temp);
		if (temp->cost < chepest->cost)
			chepest = temp;
		temp = temp->next;
	}
	return(chepest);
}

void do_ops_ab(t_control *control)
{
	t_node *temp;

	temp = get_chepest_cost(control);
	// printf("temp is %d\n", temp->nb);
	// printf("temp target is %d\n", temp->target->nb);
	// printf("temp cost is %d\n", temp->cost);
	if(temp->cost == 0)
	{
		push_b(control);
		return;
	}
	while(temp->index != 0 || temp->target->index != 0)
	{
	// printf("temp index is %d and target index is %d\n", temp->index, temp->target->index);
		if((temp->index <= (control->size_a - 1) / 2) && (temp->target->index <= (control->size_b - 1) / 2) && temp->cost > 0 && temp->index != 0 && temp->target->index != 0)
		{
			// printf("reached 1\n");
			rotate_ab(control);
			temp->cost--;
		}
		else if ((temp->index >= (control->size_a - 1) / 2) && (temp->target->index >= (control->size_b - 1) / 2) && temp->cost > 0 && temp->index != 0 && temp->target->index != 0)
		{
			// printf("reached 2\n");
			reverse_ab(control);
			temp->cost--;
		}
		else if (temp->index <= (control->size_a - 1) / 2 && temp->cost > 0 && temp->index != 0)
		{
			// printf("reached 3\n");
			rotate_a(control);
			temp->cost--;
		}
		else if (temp->index >= (control->size_a - 1) / 2 && temp->cost > 0 && temp->index != 0)
		{
			// printf("reached 4\n");
			reverse_a(control);
			temp->cost--;
		}
		else if(temp->target->index <= (control->size_b - 1) / 2 && temp->cost > 0 && temp->target->index != 0)
		{
			// printf("reached 5\n");
			rotate_b(control);
			temp->cost--;
		}
		else if(temp->target->index >= (control->size_b - 1) / 2 && temp->cost > 0 && temp->target->index != 0)
		{
			// printf("reached 6\n");
			reverse_b(control);
			temp->cost--;
		}
		indexing(control);
	}
	push_b(control);
}

void	move_to_b(t_control *control)
{
	push_b(control);
	if (control->size_a > 3)
		push_b(control);
	while(control->size_a > 3)
	{
		get_target_a(control);
		indexing(control);
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
        if(temp->target->index < control->size_a / 2)
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
        get_target_b(control);
        indexing(control);
        do_ops_ba(control);
	}
}
