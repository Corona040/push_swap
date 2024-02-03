/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 10:58:28 by ecorona-          #+#    #+#             */
/*   Updated: 2024/02/03 13:19:34 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_arg	arg;
	int		**stack;

	if (argc > 1)
	{
		arg = (t_arg){.c = argc, .v = argv, .free = 0, .ptr_v = 0};
		init_args(&arg, 0, -1);
		stack = init_stack(&arg);
		if (is_sorted(stack[0]) != 1)
		{
			if (arg.c <= 3)
				sort_three(stack, 0);
			else if (arg.c <= 6)
				sort_six(stack);
			else if (is_sorted(stack[0]) != 1)
			{
				push(stack, 1);
				push(stack, 1);
				turk_sort(stack);
				retrieve(stack);
			}
		}
		free_argv(&arg);
		free_stack(stack);
	}
}

void	turk_sort(int **stack)
{
	int	*target;
	int	*top;
	int	i;

	while (count_zeros(stack[1]) > 0)
	{
		target = gettarget(stack);
		i = 0;
		while (target && i < 2)
		{
			top = gettop(stack[i]);
			while (*top > 0 && *top != target[i])
			{
				top = gettop(stack[i]);
				if (shortest_path(top, target[i]) >= 0)
					rotate(stack, i, 1);
				else
					revrot(stack, i, 1);
			}
			i++;
		}
		push(stack, 1);
		swap_sort(stack, 1);
		free(target);
	}
}

void	retrieve(int **stack)
{
	int	*topb;
	int	max;
	int	path;

	topb = gettop(stack[1]);
	max = getminmax(topb, 1);
	path = shortest_path(topb, max);
	while (*topb != max)
	{
		topb = gettop(stack[1]);
		if (path >= 0)
			rotate(stack, 1, 1);
		else
			revrot(stack, 1, 1);
	}
	while (count_zeros(stack[0]) > 0)
		push(stack, 0);
}
