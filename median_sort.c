/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:03:17 by ecorona-          #+#    #+#             */
/*   Updated: 2024/01/30 17:06:36 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	average(int *array, int size)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < size)
		sum += array[i++];
	return ((float) sum / (size - count_zeros(array, size)));
}

void	median_sort(int **stack, int size)
{
	int	i;
	int	j;
	float med;

	i = 0;
	while (!is_sorted(stack[0], size))
	{
		while (count_zeros(stack[i % 2], size) < size - 2)
		{
			j = 0;
			med = average(stack[i % 2], size);
			while (j < size)
			{
				if ((float) top(stack[i % 2], size, 0) < med)
					push(stack, size, (i + 1) % 2);
				else
					rotate(stack, size, i % 2, 1);
				j++;
			}
		}
		j = 0;
		while (count_zeros(stack[(i + 1) % 2], size) < 50)
		{
			if (top(stack[i % 2], size, 0) > top(stack[i % 2], size, 1) \
				&& top(stack[(i + 1) % 2], size, 0) < top(stack[(i + 1) % 2], size, 1))
				swap(stack, size, 2, 1);
			else if (top(stack[i % 2], size, 0) > top(stack[i % 2], size, 1))
				swap(stack, size, i % 2, 1);
			else if (top(stack[(i + 1) % 2], size, 0) < top(stack[(i + 1) % 2], size, 1))
				swap(stack, size, (i + 1) % 2, 1);
			push(stack, size, i % 2);
			j++;
		}
		i++;
	}
	while (count_zeros(stack[1], size) < size)
	{
		revrot(stack, size, 1, 1);
		push(stack, size, 0);
	}
}
