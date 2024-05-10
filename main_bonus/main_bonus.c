/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:36:20 by trolland          #+#    #+#             */
/*   Updated: 2024/05/10 10:21:00 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	quit(t_control *control, char *line)
{
	free_stack(control);
	free(line);
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

char	*do_ops(t_control *control, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		swap_a(control);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		swap_b(control);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		swap_ss(control);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		push_a(control);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		push_b(control);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		rotate_a(control);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rotate_b(control);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rotate_ab(control);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		reverse_a(control);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		reverse_b(control);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		reverse_ab(control);
	else
		quit(control, line);
	return (get_next_line(0));
}

void	checker(t_control *control, char *line)
{
	char	*tmp;

	while (line && (line[0] != '\n' || line[0] != '\0'))
	{
		tmp = line;
		line = do_ops(control, line);
		free(tmp);
	}
	if (control->stack_b)
		ft_printf("KO\n");
	else if (check_sort(control) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(line);
}

void	init_control(t_control *control)
{
	control->stack_a = NULL;
	control->stack_b = NULL;
	control->size_a = 0;
	control->size_b = 0;
	control->mediane_a = 0;
	control->mediane_b = 0;
	control->stack_a_max = 0;
	control->third_len = 0;
	control->first_third = 0;
	control->seconde_third = 0;
	control->checker = 1;
}

int	main(int argc, char **argv)
{
	t_control	control;
	char		*line;

	if (argc == 1)
		return (0);
	init_control(&control);
	if (parse(&control, argc, argv) == -1)
		return (ft_putstr_fd("Error\n", 2), 0);
	line = get_next_line(0);
	if (!line && check_sort(&control) == -1)
		return (ft_printf("KO\n"), 0);
	else if (!line && check_sort(&control) == 0)
		return (ft_printf("OK\n"), 0);
	else
		checker(&control, line);
	free_stack(&control);
}
