/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:53:21 by trolland          #+#    #+#             */
/*   Updated: 2024/05/08 20:41:14 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_sort(t_control *control)
{
	t_node	*temp;

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
	while (temp)
	{
		if (temp->nb > *max)
			*max = temp->nb;
		temp = temp->next;
	}
}


void	sort_three_a(t_control *control)
{
	get_max(control);
	if (control->stack_a->nb == control->stack_a_max)
	{
		rotate_a(control);
		if (control->stack_a->nb > control->stack_a->next->nb)
			swap_a(control);
	}
	if (control->stack_a->next->nb == control->stack_a_max)
	{
		reverse_a(control);
		if (control->stack_a->nb > control->stack_a->next->nb)
			swap_a(control);
	}
	if (control->stack_a->nb > control->stack_a->next->nb)
		swap_a(control);
}

// void median_sort(t_control *control)
// {
//     t_node *temp;
    
// }

int	sorting(t_control *control)
{
	if (check_sort(control) == 0)
		return (0);
	if (control->size_a > 3)
    {
        // median_sort(control);
		move_to_b(control);
    }
	sort_three_a(control);
	if (control->size_b > 0)
		move_to_a(control);
	if (check_sort(control) == -1)
		ascending(control);
	return (1);
}
