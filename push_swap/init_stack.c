/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:43:08 by ecorona-          #+#    #+#             */
/*   Updated: 2024/03/29 16:30:44 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(int **stack)
{
	if (stack)
	{
		if (stack[0])
			free(stack[0]);
		if (stack[1])
			free(stack[1]);
		free(stack);
	}
}

void	ft_bubble_sort(int *dest, int *src, int size)
{
	int	i;
	int	j;
	int	temp;

	ft_memcpy(dest, src, size * sizeof(int));
	i = 0;
	while (i < size)
	{
		j = 1;
		while (j < size - i)
		{
			if (dest[j - 1] > dest[j])
			{
				temp = dest[j];
				dest[j] = dest[j - 1];
				dest[j - 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_index_algo(int **stack, int *sorted_a, int *result, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (sorted_a[i] == stack[0][j] && !result[j])
			{
				stack[0][j] = i + 1;
				result[j] = 1;
			}
			j++;
		}
		i++;
	}
}

void	ft_index(t_arg *arg, int **stack, int size)
{
	int	*sorted_a;
	int	*result;

	stack[0][size] = -1;
	stack[1][size] = -1;
	sorted_a = ft_calloc(size, sizeof(int));
	if (!sorted_a)
		leave(arg, stack, 1, EXIT_FAILURE);
	result = ft_calloc(size, sizeof(int));
	if (!result)
	{
		free(sorted_a);
		leave(arg, stack, 1, EXIT_FAILURE);
	}
	ft_bubble_sort(sorted_a, stack[0], size);
	ft_index_algo(stack, sorted_a, result, size);
	free(sorted_a);
	free(result);
}

int	**init_stack(t_arg *arg)
{
	int	**stack;
	int	*a;
	int	*b;
	int	i;

	stack = ft_calloc(2, sizeof(int *));
	if (!stack)
		leave(arg, stack, 1, EXIT_FAILURE);
	a = ft_calloc(arg->c + 1, sizeof(int));
	if (!a)
		leave(arg, stack, 1, EXIT_FAILURE);
	stack[0] = a;
	b = ft_calloc(arg->c + 1, sizeof(int));
	if (!b)
		leave(arg, stack, 1, EXIT_FAILURE);
	stack[1] = b;
	i = 0;
	while (i < arg->c)
	{
		a[i] = ft_atoi(arg->v[i]);
		b[i] = 0;
		i++;
	}
	ft_index(arg, stack, i);
	return (stack);
}
