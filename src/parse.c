/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:46:33 by trolland          #+#    #+#             */
/*   Updated: 2024/05/29 16:54:20 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_control *control)

{
	t_node	*temp;
	t_node	*stack;

	stack = control->stack_a;
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	stack = control->stack_b;
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

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

static int	check_double(t_control *control)
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

static int	create_stack(t_control *control, int argc, char **argv, int *i)
{
	t_node	*new;

	control->stack_a = NULL;
	while (argv[*i])
	{
		new = ft_lstnew_node(argv[*i]);
		if (new == NULL)
		{
			if (argc == 2)
				ft_free_tab(argv);
			free_stack(control);
			return (-1);
		}
		ft_lstadd_node_back(&(control->stack_a), new);
		control->size_a += 1;
		(*i)++;
	}
	return (0);
}

int	parse(t_control *control, int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		return (-1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (argv == NULL)
			return (-1);
		i = 0;
	}
	if (define_thirds(control, argv, i) == -1)
		return (-1);
	if (create_stack(control, argc, argv, &i) == -1)
		return (-1);
	if (argc == 2)
		ft_free_tab(argv);
	if (check_double(control) == -1)
		return (free_stack(control), -1);
	return (0);
}
