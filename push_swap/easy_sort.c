/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:05:47 by ecorona-          #+#    #+#             */
/*   Updated: 2024/03/29 16:31:01 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(int	**stack, int sortsort)
{
	int	*top;

	top = gettop(stack[sortsort]);
	if (*top == getminmax(stack[sortsort], 1))
		rotate(stack, sortsort, 1);
	top = gettop(stack[sortsort]);
	if (is_sorted(stack[sortsort]) != 1 \
		&& *top != getminmax(stack[sortsort], 1) \
		&& *top != getminmax(stack[sortsort], 0))
	{
		if (top[1] == getminmax(stack[sortsort], 0))
			swap(stack, sortsort, 1);
		else
			revrot(stack, sortsort, 1);
	}
	top = gettop(stack[sortsort]);
	if (is_sorted(stack[sortsort]) != 1 \
		&& *top == getminmax(stack[sortsort], 0))
	{
		swap(stack, sortsort, 1);
		rotate(stack, sortsort, 1);
	}
}

void	descsort_three(int	**stack, int sortsort)
{
	int	*top;

	top = gettop(stack[sortsort]);
	if (*top == getminmax(stack[sortsort], 0))
		rotate(stack, sortsort, 1);
	top = gettop(stack[sortsort]);
	if (is_sorted(stack[sortsort]) != -1 \
		&& *top != getminmax(stack[sortsort], 1) \
		&& *top != getminmax(stack[sortsort], 0))
	{
		if (top[1] == getminmax(stack[sortsort], 1))
			swap(stack, sortsort, 1);
		else
			revrot(stack, sortsort, 1);
	}
	top = gettop(stack[sortsort]);
	if (is_sorted(stack[sortsort]) != -1 \
		&& *top == getminmax(stack[sortsort], 1))
	{
		swap(stack, sortsort, 1);
		rotate(stack, sortsort, 1);
	}
}

void	sort_six(int **stack)
{
	int	*top;

	while (getsize(stack[1]) < 3)
	{
		top = gettop(stack[0]);
		if (*top <= 3)
			push(stack, 1);
		else
			rotate(stack, 0, 1);
	}
	sort_three(stack, 0);
	descsort_three(stack, 1);
	while (count_zeros(stack[0]) > 0)
		push(stack, 0);
}
