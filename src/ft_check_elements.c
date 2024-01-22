/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:53:53 by trolland          #+#    #+#             */
/*   Updated: 2024/01/17 08:55:53 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	ft_syntax_error(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == 0)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_duplicate(t_node **a, int n, int size)
{
	int		i;
	t_node	*current;

	current = *a;
	i = 0;
	if (size == 0 || !current)
		return (1);
	while (i < size)
	{
		if (current->nb == n)
			return (0);
		else
			current = current->next;
		i++;
	}
	return (1);
}
