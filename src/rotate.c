/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:39:26 by trolland          #+#    #+#             */
/*   Updated: 2024/05/08 20:11:46 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/errors_map.h"
#include "../includes/push_swap.h"

void	rotate_a(t_control *control)
{
	t_node	*temp;

	if (control == NULL || control->stack_a->next == NULL)
		return ;
	temp = control->stack_a;
	control->stack_a = control->stack_a->next;
	temp->next = NULL;
	ft_lstadd_node_back(&control->stack_a, temp);
	ft_printf("ra\n");
}

void	rotate_b(t_control *control)
{
	t_node	*temp;

	if (control == NULL || control->stack_b->next == NULL)
		return ;
	temp = control->stack_b;
	control->stack_b = control->stack_b->next;
	temp->next = NULL;
	ft_lstadd_node_back(&control->stack_b, temp);
	ft_printf("rb\n");
}

void	rotate_ab(t_control *control)
{
	t_node	*temp;

	if (!(control == NULL || control->stack_a->next == NULL))
	{
		temp = control->stack_a;
		control->stack_a = control->stack_a->next;
		temp->next = NULL;
		ft_lstadd_node_back(&control->stack_a, temp);
	}
	if (!(control == NULL || control->stack_b->next == NULL))
	{
		temp = control->stack_b;
		control->stack_b = control->stack_b->next;
		temp->next = NULL;
		ft_lstadd_node_back(&control->stack_b, temp);
	}
	if (temp)
		ft_printf("rr\n");
}
