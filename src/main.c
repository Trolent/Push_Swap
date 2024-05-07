/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:26:23 by trolland          #+#    #+#             */
/*   Updated: 2024/05/07 18:56:26 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/errors_map.h"
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

void	get_max(t_control *control, char c)
{
	t_node	*temp;
	int		*max;

	if (c == 'a')
	{
		temp = control->stack_a;
		max = &(control->stack_a_max);
	}
	if (c == 'b')
	{
		temp = control->stack_b;
		max = &(control->stack_b_max);
	}
	*max = temp->nb;
	while (temp)
	{
		if (temp->nb > *max)
			*max = temp->nb;
		temp = temp->next;
	}
}

void	sort_three_a(t_control *control)
{
	get_max(control, 'a');
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

void	ascending(t_control *control)
{
	t_node	*temp;
	int		median;

	temp = min_node(control->stack_a);
	median = control->size_a / 2;
	while (control->stack_a != temp)
	{
		if (temp->index <= median)
			rotate_a(control);
		else
			reverse_a(control);
	}
}

int	sorting(t_control *control)
{
	if (check_sort(control) == 0)
		return (0);
	if (control->size_a > 3)
		move_to_b(control);
	sort_three_a(control);
	if (control->size_b > 0)
		move_to_a(control);
	if (check_sort(control) == -1)
		ascending(control);
	return (1);
}

void	init_control(t_control *control)
{
	control->stack_a = NULL;
	control->stack_b = NULL;
	control->size_a = 0;
	control->size_b = 0;
	control->mediane_a = 0;
	control->mediane_b = 0;
}

int	main(int argc, char **argv)
{
	t_control	control;

	init_control(&control);
	if (parse(&control, argc, argv) == -1)
		return (ft_printf("Error\n"), 0);
	if (sorting(&control) == -1)
		return (ft_printf("Error\n"), 0);
	free_stack(control.stack_a);
}
