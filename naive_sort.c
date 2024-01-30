/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naive_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:06:00 by ecorona-          #+#    #+#             */
/*   Updated: 2024/01/30 16:59:34 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	around(int cursor, int size)
{
	int result;

	result = (cursor - 1);
	if (result < 0)
		result = size + result;
	return (result);
}

int	shortest_path(int **stack, int size, int cursor, int target)
{
	int	temp;
	int right;
	int left;

	temp = cursor;
	right = 0;
	left = 0;
	while (stack[0][cursor] != target)
	{
		cursor = (cursor + 1) % size;
		while (!stack[0][cursor])
			cursor = (cursor + 1) % size;
		right++;
	}
	cursor = temp;
	while (stack[0][cursor] != target)
	{
		cursor = around(cursor, size);
		while (!stack[0][cursor])
			cursor = around(cursor, size);
		left++;
	}
	if (left < right)
		return (0);
	return (1);
}

void	push_next(int **stack, int size, int *cursor, int target)
{
	while (!stack[0][*cursor])
		*cursor = (*cursor + 1) % size;
	if (shortest_path(stack, size, *cursor, target))
	{
		while (stack[0][*cursor] != target)
		{
			*cursor = (*cursor + 1) % size;
			while(!stack[0][*cursor])
				*cursor = (*cursor + 1) % size;
			ft_printf("ra\n");
		}
	}
	else
	{
		while (stack[0][*cursor] != target)
		{
			*cursor = around(*cursor, size);
			while(!stack[0][*cursor])
				*cursor = around(*cursor, size);
			ft_printf("rra\n");
		}
	}
	stack[0][*cursor] = 0;
	ft_printf("pb\n");
}

void	naive_sort(int **stack, int size)
{
	int		i;
	int		cursor;
	int		target;

	cursor = 0;
	target = 1;
	while (count_zeros(stack[0], size) < size)
	{
		push_next(stack, size, &cursor, target);
		target++;
	}
	i = 0;
	while (i < size)
	{
		ft_printf("pa\n");
		i++;
	}
}
