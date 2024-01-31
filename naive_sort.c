/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naive_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:06:00 by ecorona-          #+#    #+#             */
/*   Updated: 2024/01/30 20:29:32 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	shortest_path(int **stack, int size, int target)
{
	int cursor;
	int right;
	int left;

	cursor = count_zeros(stack[1], size);
	right = 1;
	left = 1;
	while (stack[1][cursor] != target)
	{
		cursor++;
		right++;
	}
	cursor = size - 1;
	while (stack[1][cursor] != target)
	{
		cursor--;
		left++;
	}
	if (left < right)
		return (0);
	return (1);
}

void	push_next(int **stack, int size, int target)
{
	if (shortest_path(stack, size, target))
		while (top(stack[1], size, 0) != target)
			rotate(stack, size, 1, 1);
	else
		while (top(stack[1], size, 0) != target)
			revrot(stack, size, 1, 1);
	push(stack, size, 0);
}

void	naive_sort(int **stack, int size)
{
	int		target;

	target = size;
	while (count_zeros(stack[1], size) < size)
	{
		push_next(stack, size, target);
		target--;
	}
}
