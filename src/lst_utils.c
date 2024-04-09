/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:27:17 by trolland          #+#    #+#             */
/*   Updated: 2024/04/09 17:35:36 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*new_node(char *str)
{
	int		i;
	int		value;
	t_node	*new;

	i = 0;
	value = ft_atoll(str);
	if (value != ft_atoi(str))
		return (NULL);
	new = ft_calloc(1, sizeof(t_node));
	if (!new)
		return (NULL);
	new->nb = value;
	return (new);
}

t_node	*lstlast_node(t_node *lst)
{
	t_node	*last;

	last = lst;
	if (!lst)
		return (NULL);
	while (last->next)
		last = last->next;
	return (last);
}

void	add_node_back(t_node **alst, t_node *new)
{
	t_node	*lst;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	lst = lstlast_node(*alst);
	lst->next = new;
}

void	free_lst(t_node **lst)
{
	t_node *temp;
	t_node *to_free;

	temp = *lst;
	while (temp)
	{
		to_free = temp;
		temp = temp->next;
		free(to_free);
	}
}