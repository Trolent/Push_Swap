/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:38:07 by trolland          #+#    #+#             */
/*   Updated: 2024/05/29 17:26:13 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

/*node structure containing the number, the index, the cost and the target*/
typedef struct s_node
{
	int				nb;
	int				index;
	int				cost;

	struct s_node	*next;
	struct s_node	*target;
}					t_node;

/*control structure containg stacks a and b and sorting utils*/
typedef struct s_control
{
	t_node			*stack_a;
	t_node			*stack_b;
	int				size_a;
	int				size_b;
	int				mediane_a;
	int				mediane_b;
	int				stack_a_max;
	long long		third_len;
	int				first_third;
	int				seconde_third;
	int				checker;
}					t_control;

/* ************************************************************************** */
/* ******************************** PARSING ********************************* */
/* ************************************************************************** */

/*initialize the control structure and assign the values to the stacks */
int					parse(t_control *control, int argc, char **argv);
/*define the the values of the first and second third of the stack */
int					define_thirds(t_control *control, char **argv, int index);
/*verify if the string is a valid number*/
int					verify_elements(char *str);


/* ************************************************************************** */
/* ***************************** SORTING UTILS ****************************** */
/* ************************************************************************** */

/*sort the stack*/
int					sorting(t_control *control);
/*verify if the stack is sorted */
int					check_sort(t_control *control);
/*move the elements of the stack a to the stack b according to the target*/
void				move_to_a(t_control *control);
/*get the target of the elements of the stack b regarding the stack a*/
void				get_target_b(t_control *control);
/*define the cost to push each element of the stack b to the stack a*/
void				get_cost(t_control *control);
/*if a is sorted, (reverse) rotates the stack a to the smallest element*/
void				ascending(t_control *control);
/*get the smallest element of the stack*/
t_node				*min_node(t_node *stack);

/* ************************************************************************** */
/* ******************************* OPERATIONS ******************************* */
/* ************************************************************************** */

/*push the first element of the stack a to the stack b*/
void				push_b(t_control *control);
/*push the first element of the stack b to the stack a*/
void				push_a(t_control *control);
/*swap the first two elements of the stack a*/
void				swap_a(t_control *control);
/*swap the first two elements of the stack b*/
void				swap_b(t_control *control);
/*swap the first two elements of both stacks a and b*/
void				swap_ss(t_control *control);
/*rotate the stack a (the first element becomes the last)*/
void				rotate_a(t_control *control);
/*rotate the stack b (the first element becomes the last)*/
void				rotate_b(t_control *control);
/*rotate both stacks a and b (the first element becomes the last)*/
void				rotate_ab(t_control *control);
/*reverse rotate the stack a (the last element becomes the first)*/
void				reverse_a(t_control *control);
/*reverse rotate the stack b (the last element becomes the first)*/
void				reverse_b(t_control *control);
/*reverse rotate both stacks a and b (the last element becomes the first)*/
void				reverse_ab(t_control *control);

/* ************************************************************************** */
/* ******************************* LIST UTILS ******************************* */
/* ************************************************************************** */

/*create a new node and initialize it with the given number*/
t_node				*ft_lstnew_node(char *nbr);
/*return the last node of the list*/
t_node				*ft_lstlast_node(t_node *lst);
/*add a node at the end of the list*/
void				ft_lstadd_node_back(t_node **alst, t_node *new);
/*add a node at the front of the list*/
void				ft_lstadd_node_front(t_node **alst, t_node *new);
/*free both stacks a and b*/
void				free_stack(t_control *control);

#endif