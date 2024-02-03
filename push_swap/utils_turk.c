/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_turk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:43:43 by ecorona-          #+#    #+#             */
/*   Updated: 2024/02/03 15:55:23 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	shortest_path(int *array, int target)
{
	int	*top;
	int	*bottom;
	int	up;
	int	down;

	top = gettop(array);
	bottom = getbottom(array) - 1;
	down = 0;
	while (top[down] > 0 && top[down] != target)
		down++;
	up = 1;
	while (*bottom > 0 && *bottom != target)
	{
		up++;
		bottom--;
	}
	if (up < down)
		return (-up);
	return (down);
}

int	closest(int	*array, int n)
{
	int	result;
	int	closest;
	int	temp;

	result = *array;
	closest = *array - n;
	if (closest < 0)
		closest = -closest;
	while (*array++ > 0)
	{
		temp = *array - n;
		if (temp < 0)
			temp = -temp;
		if (temp < closest)
		{
			closest = temp;
			result = *array;
		}
	}
	return (result);
}

int	*gettarget(int **stack)
{
	int	*topa;
	int	*topb;
	int	*target;

	topa = gettop(stack[0]);
	topb = gettop(stack[1]);
	target = NULL;
	if (*topa > 0 && *topb > 0)
	{
		target = ft_calloc(2, sizeof(int));
		if (!target)
			leave(NULL, stack, 1, EXIT_FAILURE);
		findtarget(target, topa, topb);
	}
	return (target);
}

void	findtarget(int *target, int *topa, int *topb)
{
	int	short_path;
	int	temp;
	int	i;

	target[0] = *topa;
	target[1] = closest(topb, *topa);
	short_path = shortest_path(topb, target[1]);
	if (short_path < 0)
		short_path = -short_path;
	i = 0;
	while (topa[i++] > 0)
	{
		temp = shortest_path(topb, closest(topb, topa[i]));
		if (temp < 0)
			temp = -temp;
		temp += i;
		if (temp < short_path)
		{
			short_path = temp;
			target[0] = topa[i];
			target[1] = closest(topb, topa[i]);
		}
	}
}

void	swap_sort(int **stack, int swapswap)
{
	int	*top;

	top = gettop(stack[swapswap]);
	if (top[0] > 0 && top[1] > 0)
	{
		if (top[0] < top[1])
			swap(stack, swapswap, 1);
	}
}
