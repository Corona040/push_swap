/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:10:37 by ecorona-          #+#    #+#             */
/*   Updated: 2024/01/31 19:34:49 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*gettop(int *array)
{
	int	i;

	i = 0;
	while (array[i] == 0)
		i++;
	if (array[i] < 0)
		i--;
	return (array + i);
}

int	*getbottom(int *array)
{
	int	i;

	i = 0;
	while (array[i] >= 0)
		i++;
	return (array + i);
}

int	getsize(int *array)
{
	int	*top;
	int	i;

	top = gettop(array);
	i = 0;
	while (top[i] > 0)
		i++;
	return (i);
}

int	getminmax(int *array, int minmax)
{
	int	*top;
	int	result;

	top = gettop(array);
	result = *top;
	while (*top++ && *top > 0)
	{
		if (minmax && *top > result)
			result = *top;
		if (!minmax && *top < result)
			result = *top;
	}
	return (result);
}

int	is_sorted(int *array)
{
	int	*top;
	int	asc;
	int	desc;
	int	i;

	asc = 1;
	desc = -1;
	top = gettop(array);
	if (top[0] < 0)
		return (0);
	if (top[1] < 0)
		return (1);
	i = 0;
	while (top[++i] > 0)
	{
		if (top[i] > top[i - 1])
			desc = 0;
		else
			asc = 0;
	}
	return (asc + desc);
}
