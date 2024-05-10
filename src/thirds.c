/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thirds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:00:54 by trolland          #+#    #+#             */
/*   Updated: 2024/05/10 10:23:53 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_tab(int **tab, int size, t_control *control)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[0][i] > tab[0][j])
				ft_int_xor_swap(&tab[0][i], &tab[0][j]);
			j++;
		}
		i++;
	}
	if (size % 3 == 0)
		i = size / 3;
	else
		i = size / 3 + 1;
	control->first_third = tab[0][i - 1];
	control->seconde_third = tab[0][i * 2 - 1];
	control->third_len = size - i * 2 + 2;
}

int	define_thirds(t_control *control, char **argv, int index)
{
	int	i;
	int	*tab;

	i = 0;
	while (argv[index])
	{
		index++;
		i++;
	}
	if (i < 1)
		return (-1);
	tab = malloc(sizeof(int) * i);
	if (tab == NULL)
		return (-1);
	index -= i;
	i = 0;
	while (argv[index])
	{
		tab[i] = ft_atoi(argv[index]);
		i++;
		index++;
	}
	sort_tab(&tab, i, control);
	return (free(tab), 0);
}
