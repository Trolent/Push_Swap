/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:26:23 by trolland          #+#    #+#             */
/*   Updated: 2024/05/01 20:08:21 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/errors_map.h"
#include "../includes/push_swap.h"

int	verify_elements(char *str)
{
	int	i;

	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (ft_isposneg(str[i]) == 1)
		i++;
	if (str[i] == '\0')
		return (-1);
	while (ft_isdigit(str[i]))
		i++;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] != '\0')
		return (-1);
	return (1);
}

int	check_double(t_control *control)
{
	t_node	*temp;
	t_node	*comp;

	temp = control->stack_a;
	while (temp)
	{
		comp = temp->next;
		while (comp)
		{
			if (temp->nb == comp->nb)
				return (-1);
			comp = comp->next;
		}
		temp = temp->next;
	}
	return (0);
}

int	parse(t_control *control, int argc, char **argv)
{
	int		i;
	t_node	*new;

	if (argc < 3)
		return (-1);
	control->stack_a = NULL;
	i = 1;
	while (argv[i])
	{
		new = ft_lstnew_node(argv[i]);
		if (new == NULL)
		{
			// ajouter le free de la stack;
			return (-1);
		}
		ft_lstadd_node_back(&(control->stack_a), new);
		control->size_a += 1;
		i++;
	}
	if (check_double(control) == -1)
		return (-1);
	return (0);
}

int	sorting(t_control *control)
{
	push_b(control);
	push_b(control);
	push_b(control);
	rotate_b(control);
	rotate_ab(control);
	rotate_ab(control);
	// swap_a(control);
	// swap_b(control);
	// swap_ss(control);
	// reverse_a(control);
	// reverse_b(control);
	// reverse_ab(control);
	(void)control;
	return (1);
}

void init_control(t_control *control)
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
	t_node		*temp;
	t_node		*temp_b;

	init_control(&control);
	if (parse(&control, argc, argv) == -1)
		return (ft_printf("Error\n"),0);
	if (sorting(&control) == -1)
		return (ft_printf("Error\n"), 0);
	temp = control.stack_a;
	while (temp)
	{
		printf("stack a = %d\n", temp->nb);
		temp = temp->next;
	}
	temp_b = control.stack_b;
	while (temp_b)
	{
		printf("stack b = %d\n", temp_b->nb);
		temp_b = temp_b->next;
	}
	printf("siza a = %d\n", control.size_a);
	printf("siza b = %d\n", control.size_b);
}
