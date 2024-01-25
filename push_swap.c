/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:26:23 by trolland          #+#    #+#             */
/*   Updated: 2024/01/17 18:25:28 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "libft/libft.h"

t_node	*ft_find_last(t_node *lst)
{
	t_node	*last;

	last = lst;
	if (!lst)
		return (NULL);
	while (last->next)
		last = last->next;
	return (last);
}

int	ft_add_node(t_node **stack, int n)
{
	t_node	*node;
	t_node	*last;

	if (!stack)
		return (0);
	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->next = NULL;
	node->nb = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last = ft_find_last(*stack);
		last->next = node;
		node->prev = last;
	}
	return (1);
}

int	ft_create_stack(struct s_node **stack_a, char **elements, int split)
{
	long long	nb;
	int			i;

	i = 0;
	while (elements[i])
	{
		printf("%s\n", elements[i]);
		if (!ft_syntax_error(elements[i]))
			return (ft_free_error(stack_a, elements, split), 0);
		nb = ft_atoll(elements[i]);
		if (nb > 2147483647 || nb < -2147483648)
			return (ft_free_error(stack_a, elements, split), 0);
		if (!ft_check_duplicate(stack_a, nb, i))
			return (ft_free_error(stack_a, elements, split), 0);
		if (!ft_add_node(stack_a, nb))
			return (ft_free_error(stack_a, elements, split), 0);
		i++;
	}
	if (split == 0)
		ft_free_tab(elements, i);
	return (1);
}

int	ft_stack_is_sorted(t_node **stack_a)
{
	t_node	*current;
	t_node	*next;

	current = *stack_a;
	next = current->next;
	while (current && next)
	{
		if (current->nb > next->nb)
			return (0);
		current = next;
		next = current->next;
	}
	return (1);
}

int	ft_stack_len(t_node *a)
{
	int		i;
	t_node	*current;

	i = 1;
	current = a;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	ft_print_stack(t_node **a)
{
	int i = 0;
	
	while ((*a)->next)
	{
		printf("i %d elem = %d\n", i, (*a)->nb);
		(*a) = (*a)->next;
		i++;
		if (i == 2)
			break;
	}
}

char **ft_read_data(int argc, char **argv, int *i)
{
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (argv == NULL || argv[0] == NULL)
			return (free(argv), NULL);
		*i = 0;
	}
	else
		*i = 1;
	return(argv);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		stack_len;
	int		i;

	a = NULL;
	b = NULL;
	argv = ft_read_data(argc, argv, &i);
	if (!argv)
		return(0);
	if (!ft_create_stack(&a, argv + i, i))
		return (0);
	if (!ft_stack_is_sorted(&a))
	{
		stack_len = ft_stack_len(a) - 1;
		printf("%d\n", stack_len);
		if (stack_len == 2)
			ft_sa(&a);
		// else if (stack_len(a) == 3)
		//         sort_three(&a);
		//     else
		//         sort_stack(&a, &b);
	}
	ft_print_stack(&a);
	// initialize from there
	ft_free_stack(a);
	return (0);
}
