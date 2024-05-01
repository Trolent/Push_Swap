/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:03:28 by trolland          #+#    #+#             */
/*   Updated: 2024/05/01 19:33:10 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/errors_map.h"
#include "../includes/push_swap.h"

void	swap_a(t_control *control)
{
	t_node	*temp;

	if (control->stack_a == NULL || control->stack_a->next == NULL)
		return ;
	temp = control->stack_a;
	control->stack_a = control->stack_a->next;
	temp->next = control->stack_a->next;
	control->stack_a->next = temp;
	ft_printf("sa\n");
}

void	swap_b(t_control *control)
{
	t_node	*temp;

	if (control->stack_b == NULL || control->stack_b->next == NULL)
		return ;
	temp = control->stack_b;
	control->stack_b = control->stack_b->next;
	temp->next = control->stack_b->next;
	control->stack_b->next = temp;
	ft_printf("sb\n");
}

void	swap_ss(t_control *control)
{
	t_node	*temp;

    temp = NULL;
	if (!(control->stack_a == NULL || control->stack_a->next == NULL))
	{
		temp = control->stack_a;
		control->stack_a = control->stack_a->next;
		temp->next = control->stack_a->next;
		control->stack_a->next = temp;
	}
	if (!(control->stack_b == NULL || control->stack_b->next == NULL))
	{
		temp = control->stack_b;
		control->stack_b = control->stack_b->next;
		temp->next = control->stack_b->next;
		control->stack_b->next = temp;
	}
    if (temp)
        ft_printf("ss\n");
}
