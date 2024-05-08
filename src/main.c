/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:26:23 by trolland          #+#    #+#             */
/*   Updated: 2024/05/07 19:59:48 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/errors_map.h"
#include "../includes/push_swap.h"

void	init_control(t_control *control)
{
	control->stack_a = NULL;
	control->stack_b = NULL;
	control->size_a = 0;
	control->size_b = 0;
	control->mediane_a = 0;
	control->mediane_b = 0;
	control->stack_a_max = 0;
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
