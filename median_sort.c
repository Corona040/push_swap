/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:03:17 by ecorona-          #+#    #+#             */
/*   Updated: 2024/01/31 01:05:16 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_average(int *array, int size)
{
	int	*top;
	int	sum;
	int	n;

	top = gettop(array);
	if (*top == 0)
		return (0);
	sum = 0;
	n = 0;
	while (top[n] > 0 && n < size)
	{
		sum += top[n];
		n++;
	}
	return (sum /  n);
}

void	print(int **stack)
{
	for (int j = 0; j < 2; j++)
	{
		if (j == 0)
			ft_printf("a: ");
		else
			ft_printf("b: ");
		for (int k = 0; stack[j][k] >= 0; k++)
			ft_printf("%i:%i, ", k, stack[j][k]);
		ft_printf("\n\n");
	}
}

void	push_half(int **stack, int pushpush, int size)
{
	int	*top;
	int	med;

	top = gettop(stack[pushpush]);
	med = ft_average(stack[pushpush], size);
	if (*top != 0)
	{
		while (size > 0)
		{
			if (!pushpush)
			{
				if (*top <= med)
				{
					push(stack, 1);
					top++;
					size -= 2;
				}
				else
					rotate(stack, pushpush, 1);
			}
			if (pushpush)
			{
				if (*top >= med)
				{
					push(stack, 0);
					top++;
					size -= 2;
				}
				else
					rotate(stack, pushpush, 0);
			}
		}
	}
}

void	median_sort(int **stack)
{
	int	size;
	int	s;

	size = getsize(stack[0]);
	push_half(stack, 0, size);
	s = size;
	while (s > 2)
	{
		s /= 2;
		for (int i = 0; i < 2; i++)
		{
			print(stack);
			push_half(stack, i, s);
			for (int j = 0; j < s; j++)
				push(stack, i);
			for (int j = 0; j < s; j++)
				rotate(stack, i, 1);
		}
	}
	print(stack);
}
