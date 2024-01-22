/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:18:08 by trolland          #+#    #+#             */
/*   Updated: 2024/01/17 17:42:00 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	ft_swap_node(t_node **top)
{
	t_node	*node1;
	t_node	*node2;
	t_node	*temp_next;
	t_node	*temp_prev;

    printf("1 = %d \n", (*top)->nb);
    printf("2 = %d \n", (*top)->next->nb);
    
	if (*top == NULL || (*top)->next == NULL)
		return ;
    node1 = *top;
    node2 = (*top)->next;
    temp_next = node1->next;
    temp_prev = node1->prev;

    node1->next = node2->next;
    node2->next = temp_next;

    node1->prev = node2->prev;
    node2->prev = temp_prev;

    // if (node1->prev != NULL)
    //     node1->prev->next = node1;
    // if (node1->next != NULL)
    //     node1->next->prev = node1;
    // if (node2->prev != NULL)
    //     node2->prev->next = node2;
    // if (node2->next != NULL)
    //     node2->next->prev = node2;

    // if (temp_prev == NULL)
    //     *top = node2;
        
    printf("after 1 = %d \n", (*top)->nb);
    printf("after 2 = %d \n", (*top)->next->nb);
}

void	ft_sa(t_node **top)
{
	ft_swap_node(top);
	ft_putstr_fd("sa\n", 1);
}