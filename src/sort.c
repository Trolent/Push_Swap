/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:53:21 by trolland          #+#    #+#             */
/*   Updated: 2024/05/10 11:06:49 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_a(t_control *control)
{
	get_max(control);
	if (control->stack_a->nb == control->stack_a_max)
	{
		rotate_a(control);
		if (control->stack_a->nb > control->stack_a->next->nb)
			swap_a(control);
	}
	else if (control->stack_a->next->nb == control->stack_a_max)
	{
		reverse_a(control);
		if (control->stack_a->nb > control->stack_a->next->nb)
			swap_a(control);
	}
	else if (control->stack_a->nb > control->stack_a->next->nb)
		swap_a(control);
}

void	third_sort(t_control *control)
{
	while (control->size_a > 3)
	{
		while (control->size_a > 3 && control->size_a > control->third_len)
		{
			if (control->stack_a->nb < control->first_third)
			{
				push_b(control);
				if (control->stack_a->nb > control->seconde_third)
					rotate_ab(control);
				else
					rotate_b(control);
			}
			else if (control->stack_a->nb > control->seconde_third)
				rotate_a(control);
			else
				push_b(control);
		}
		if (control->size_a > 3)
			push_b(control);
	}
}

void	sort_small(t_control *control)
{
	push_b(control);
	if (control->size_a > 3)
		push_b(control);
	if (control->stack_b->next)
		if (control->stack_b->nb < control->stack_b->next->nb)
			swap_b(control);
}

int	sorting(t_control *control)
{
	if (check_sort(control) == 0)
		return (0);
	if (control->size_a > 5)
		third_sort(control);
	else if (control->size_a > 3)
		sort_small(control);
	sort_three_a(control);
	if (control->size_b > 0)
		move_to_a(control);
	if (check_sort(control) == -1)
		ascending(control);
	return (1);
}
