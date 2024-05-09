/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:28:38 by trolland          #+#    #+#             */
/*   Updated: 2024/05/09 19:34:32 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_b(t_control *control)
{
	t_node	*temp;

	if (control->stack_a == NULL)
		return ;
	temp = control->stack_a;
	control->stack_a = control->stack_a->next;
	temp->next = control->stack_b;
	control->stack_b = temp;
	control->size_a -= 1;
	control->size_b += 1;
	if (control->checker == 0)
		ft_printf("pb\n");
}

void	push_a(t_control *control)
{
	t_node	*temp;

	if (control->stack_b == NULL)
		return ;
	temp = control->stack_b;
	control->stack_b = control->stack_b->next;
	temp->next = control->stack_a;
	control->stack_a = temp;
	control->size_a += 1;
	control->size_b -= 1;
	if (control->checker == 0)
		ft_printf("pa\n");
}
