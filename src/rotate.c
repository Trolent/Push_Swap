/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:39:26 by trolland          #+#    #+#             */
/*   Updated: 2024/05/09 19:34:40 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_control *control)
{
	t_node	*temp;

	if (control->stack_a == NULL || control->stack_a->next == NULL)
		return ;
	temp = control->stack_a;
	control->stack_a = control->stack_a->next;
	temp->next = NULL;
	ft_lstadd_node_back(&control->stack_a, temp);
	if (control->checker == 0)
		ft_printf("ra\n");
}

void	rotate_b(t_control *control)
{
	t_node	*temp;

	if (control->stack_b == NULL || control->stack_b->next == NULL)
		return ;
	temp = control->stack_b;
	control->stack_b = control->stack_b->next;
	temp->next = NULL;
	ft_lstadd_node_back(&control->stack_b, temp);
	if (control->checker == 0)
		ft_printf("rb\n");
}

void	rotate_ab(t_control *control)
{
	t_node	*temp;

	temp = NULL;
	if (!(control->stack_a == NULL || control->stack_a->next == NULL))
	{
		temp = control->stack_a;
		control->stack_a = control->stack_a->next;
		temp->next = NULL;
		ft_lstadd_node_back(&control->stack_a, temp);
	}
	if (!(control->stack_b == NULL || control->stack_b->next == NULL))
	{
		temp = control->stack_b;
		control->stack_b = control->stack_b->next;
		temp->next = NULL;
		ft_lstadd_node_back(&control->stack_b, temp);
	}
	if (temp && control->checker == 0)
		ft_printf("rr\n");
}
