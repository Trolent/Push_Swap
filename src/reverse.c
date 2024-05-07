/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:28:38 by trolland          #+#    #+#             */
/*   Updated: 2024/05/07 19:00:39 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/errors_map.h"
#include "../includes/push_swap.h"

void	reverse_a(t_control *control)
{
	t_node	*temp;

	if (control->stack_a == NULL || control->stack_a->next == NULL)
		return ;
	temp = control->stack_a;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next->next = control->stack_a;
	control->stack_a = temp->next;
	temp->next = NULL;
	ft_printf("rra\n");
}

void	reverse_b(t_control *control)
{
	t_node	*temp;

	if (control->stack_b == NULL || control->stack_b->next == NULL)
		return ;
	temp = control->stack_b;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next->next = control->stack_b;
	control->stack_b = temp->next;
	temp->next = NULL;
	ft_printf("rrb\n");
}

void	reverse_ab(t_control *control)
{
	t_node	*temp;

	if (!(control->stack_a == NULL || control->stack_a->next == NULL))
	{
		temp = control->stack_a;
		while (temp->next->next != NULL)
			temp = temp->next;
		temp->next->next = control->stack_a;
		control->stack_a = temp->next;
		temp->next = NULL;
	}
	if (!(control->stack_b == NULL || control->stack_b->next == NULL))
	{
		temp = control->stack_b;
		while (temp->next->next != NULL)
			temp = temp->next;
		temp->next->next = control->stack_b;
		control->stack_b = temp->next;
		temp->next = NULL;
	}
	if (temp != NULL)
		ft_printf("rrr\n");
}
