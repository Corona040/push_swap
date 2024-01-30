/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:10:37 by ecorona-          #+#    #+#             */
/*   Updated: 2024/01/30 16:57:47 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(int **stack, int size, int pushpush)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < size && stack[pushpush % 2][i] == 0)
		i++;
	while (j < size && stack[(pushpush + 1) % 2][j] == 0)
		j++;
	if (pushpush == 2)
	{
		ft_printf("pp\n");
		if (i < size && j < size)
		{
			temp = stack[pushpush % 2][i];
			stack[pushpush % 2][i] = stack[(pushpush + 1) % 2][j];
			stack[(pushpush + 1) % 2][j] = temp;
		}
	}
	else if (j < size)
	{
		stack[pushpush % 2][i - 1] = stack[(pushpush + 1) % 2][j];
		stack[(pushpush + 1) % 2][j] = 0;
		if (pushpush)
			ft_printf("pb\n");
		else
			ft_printf("pa\n");
	}
}

void	swap(int **stack, int size, int swapswap, int print)
{
	int	i;
	int	temp;

	i = 0;
	if (swapswap == 2)
	{
		ft_printf("ss\n");
		swap(stack, size, 0, 0);
		swap(stack, size, 1, 0);
	}
	else 
	{
		while (i < size - 2 && stack[swapswap][i] == 0)
			i++;
		if (stack[swapswap][i] != 0)
		{
			temp = stack[swapswap][i];
			stack[swapswap][i] = stack[swapswap][i + 1];
			stack[swapswap][i + 1] = temp;
		}
		if (print && swapswap)
			ft_printf("sb\n");
		else if (print)
			ft_printf("sa\n");
	}
}

void	rotate(int **stack, int size, int rotrot, int print)
{
	int	i;
	int	temp;
	
	i = 0;
	if (rotrot == 2)
	{
		ft_printf("rr\n");
		rotate(stack, size, 0, 0);
		rotate(stack, size, 1, 0);
	}
	else
	{
		while (i < size && stack[rotrot][i] == 0)
			i++;
		if (i != size)
		{
			temp = stack[rotrot][i];
			while (i++ < size - 1)
				stack[rotrot][i - 1] = stack[rotrot][i];
			stack[rotrot][i - 1] = temp;
		}
		if (print && rotrot)
			ft_printf("rb\n");
		else if (print)
			ft_printf("ra\n");
	}
}

void	revrot(int **stack, int size, int revrev, int print)
{
	int	i;
	int	temp;
	
	i = 0;
	if (revrev == 2)
	{
		ft_printf("rrr\n");
		revrot(stack, size, 0, 0);
		revrot(stack, size, 1, 0);
	}
	else
	{
		i = size - 1;
		if (stack[revrev][i - 1] != 0)
		{
			temp = stack[revrev][i];
			while (i >= 0 && stack[revrev][i] != 0)
			{
				stack[revrev][i] = stack[revrev][i - 1];
				i--;
			}
			stack[revrev][i + 1] = temp;
		}
		if (print && revrev)
			ft_printf("rrb\n");
		else if (print)
			ft_printf("rra\n");
	}
}

int	top(int *array, int size, int depth)
{
	int	i;

	i = 0;
	while (i + depth < size && array[i] == 0)
		i++;
	return (array[i + depth]);
}

int	count_zeros(int *array, int size)
{
	int	i;
	
	i = 0;
	while (i < size && array[i] == 0)
		i++;
	return (i);
}

int	is_sorted(int *array, int size)
{
	int	i;
	int result;

	result = 1;
	i = 1;
	while (i < size)
	{
		if (array[i] < array[i - 1])
			result = -1;
		i++;
	}
	if (result == 1)
		return (-1);
	i = 1;
	while (i < size)
	{
		if (array[i] > array[i - 1])
			return (0);
		i++;
	}
	return (1);
}
