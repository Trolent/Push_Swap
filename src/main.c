/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:26:23 by trolland          #+#    #+#             */
/*   Updated: 2024/04/09 17:51:32 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/errors_map.h"
#include "../includes/push_swap.h"

int	check_data(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!(ft_isdigit(argv[i][j]) || argv[i][j] == ' '
					|| argv[i][j] == '-' || argv[i][j] == '+'))
				return (-1);
			if ((argv[i][j] == '-' || argv[i][j] == '+') && argv[i][j + 1]
				&& (argv[i][j + 1] == '-' || argv[i][j + 1] == '+'))
				return (-1);
		}
	}
	return (0);
}
int	val_len(int value)
{
	int	i;

	i = 0;
	if (value < 0)
		i++;
	while (value)
	{
		value /= 10;
		i++;
	}
	return (i);
}

t_node	*assign_values(t_node **lst, char **argv)
{
	int		i;
	int		j;
	t_node	*new;

	new = NULL;
	i = 0;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) || ft_isposneg(argv[i][j]))
			{
				new = new_node(argv[i] + j);
				if (!new)
					return (free_lst(lst), ft_printf(CREATE), NULL);
				add_node_back(lst, new);
			}
			while (ft_isdigit(argv[i][j]) || ft_isposneg(argv[i][j]))
				j++;
			if (argv[i][j] == ' ')
				j++;
		}
	}
	return (*lst);
}

int is_sorted(t_node *lst)
{
	int value;
	t_node *temp;
	
	while(lst)
	{
		value = lst->nb;
		temp = lst->next;
		while (temp)
		{
			if (value > temp->nb)
				return (1);
			if (value == temp->nb)
				return(ft_printf("value entered twice\n"), 0);
			temp = temp->next;
		}
		lst =lst->next;
	}
	return (ft_printf("sorted\n"), 0);
}

int	main(int argc, char **argv)
{
	t_node	*lst;
	t_node	*temp;

	lst = NULL;
	if (argc < 2)
		return (0);
	if (check_data(argv) == -1)
		return (ft_printf("wrong input\n"), 0);
	lst = assign_values(&lst, argv);
	if (!is_sorted(lst))
		return(free_lst(&lst), 0);

	temp = lst;
	
	while (temp)
	{
		printf("%d\n", temp->nb);
		temp = temp->next;
	}
}
