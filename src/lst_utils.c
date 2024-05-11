/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:39:19 by trolland          #+#    #+#             */
/*   Updated: 2024/05/11 17:47:39 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long	special_atoll(const char *str)
{
	int			i;
	long long	res;
	int			neg;

	i = 0;
	res = 0;
	neg = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -neg;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - '0';
		i++;
		if ((res * neg) > 2147483647 || (res * neg) < -2147483648)
			return (1);
	}
	return (res * neg);
}

t_node	*ft_lstnew_node(char *nbr)
{
	t_node		*new;
	long long	nb;
	long long	verif;

	if (verify_elements(nbr) == -1)
		return (NULL);
	verif = special_atoll(nbr);
	nb = ft_atoi(nbr);
	if (verif != nb)
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
