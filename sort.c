/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:06:00 by ecorona-          #+#    #+#             */
/*   Updated: 2024/01/29 20:55:22 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_zeros(int *array, int size)
{
	int	result;
	int i;

	result = 0;
	i = 0;
	while (i < size)
	{
		if (array[i++] == 0)
			result++;
	}
	return (result);
}

void	append(int **stack, int **ops, int op)
{
	int	*temp;

	if (!*ops)
	{
		*ops = ft_calloc(2, sizeof(int));
		if (!ops)
			leave(NULL, stack, 1, EXIT_FAILURE);
		(*ops)[0] = 1;
		(*ops)[1] = op;
	}
	else
	{
		temp = *ops;
		*ops = ft_calloc((*ops)[0] + 2, sizeof(int));
		if (!ops)
		{
			free(temp);
			leave(NULL, stack, 1, EXIT_SUCCESS);
		}
		ft_memcpy(*ops, temp, (temp[0] + 1) * sizeof(int));
		free(temp);
		(*ops)[(*ops)[0]] = op;
		(*ops)[0] += 1;
	}
}

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

int	*push_next(int **stack, int size, int *cursor, int target)
{
	static int	*ops;

	if (shortest_path(stack, size, *cursor, target))
	{
		while (stack[0][*cursor] != target)
		{
			*cursor = (*cursor + 1) % size;
			while(!stack[0][*cursor])
				*cursor = (*cursor + 1) % size;
		}
		append(stack, &ops, 2);
	}
	else
	{
		while (stack[0][*cursor] != target)
		{
			*cursor = around(*cursor, size);
			while(!stack[0][*cursor])
				*cursor = around(*cursor, size);
		}
		append(stack, &ops, 3);
	}
	stack[0][*cursor] = 0;
	while (!stack[0][*cursor] && count_zeros(stack[0], size) != size)
		*cursor = (*cursor + 1) % size;
	append(stack, &ops, 1);
	return (ops);
}

void	sort_stack(int **stack, int size)
{
	int		i;
	int		cursor;
	int		target;
	int		*op_list;
	char	**op_set;

	op_set = (char *[]){"pa", "pb", "ra", "rra", "sa"};
	cursor = 0;
	target = 1;
	while (count_zeros(stack[0], size) < size)
	{
		op_list = push_next(stack, size, &cursor, target);
		target++;
	}
	i = 1;
	while (i < op_list[0])
		ft_printf("%s\n", op_set[op_list[i++]]);
	free(op_list);
	i = 0;
	while (i < size)
	{
		ft_printf("pa\n");
		i++;
	}
}
