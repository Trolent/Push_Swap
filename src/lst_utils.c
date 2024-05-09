/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:39:19 by trolland          #+#    #+#             */
/*   Updated: 2024/05/09 19:34:26 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_lstnew_node(char *nbr)
{
	t_node		*new;
	long long	nb;

	if (verify_elements(nbr) == -1)
		return (NULL);
	nb = ft_atoll(nbr);
	if (nb > 2147483647 || nb < -2147483648)
		return (NULL);
	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

t_node	*ft_lstlast_node(t_node *lst)
{
	t_node	*last;

	last = lst;
	if (!lst)
		return (NULL);
	while (last->next)
		last = last->next;
	return (last);
}

void	ft_lstadd_node_back(t_node **alst, t_node *new)
{
	t_node	*lst;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	lst = ft_lstlast_node(*alst);
	lst->next = new;
}

void	ft_lstadd_node_front(t_node **alst, t_node *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}
