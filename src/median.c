/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:00:54 by trolland          #+#    #+#             */
/*   Updated: 2024/05/09 20:01:37 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_tab(int **tab, int size)
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
}

int	define_median(t_control *control, char **argv, int index)
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
	sort_tab(&tab, i);
	control->median_value = tab[(i - 1) / 2];
	return (free(tab), 0);
}
