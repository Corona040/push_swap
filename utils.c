/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:10:37 by ecorona-          #+#    #+#             */
/*   Updated: 2024/01/31 00:51:51 by ecorona-         ###   ########.fr       */
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

int	is_sorted(int *array)
{
	int	*top;
	int	asc;
	int	desc;

	asc = 1;
	desc = -1;
	top = gettop(array);
	if (*top < 0)
		return (0);
	while (*top++ > 0)
	{
		if (*top > *(top - 1))
			desc = 0;
		else
			asc = 0;
	}
	return (asc + desc);
}

void	push(int **stack, int pushpush)
{
	int	*topa;
	int	*topb;

	topa = gettop(stack[pushpush]);
	if (*topa > 0)
		topa--;
	topb = gettop(stack[(pushpush + 1) % 2]);
	if (*topb > 0)
	{
		*topa = *topb;
		*topb = 0;
		if (pushpush)
			ft_printf("pb\n");
		else
			ft_printf("pa\n");
	}
}

void	swap(int **stack, int swapswap, int print)
{
	int	*top;
	int	temp;

	if (swapswap == 2)
	{
		ft_printf("ss\n");
		swap(stack, 0, 0);
		swap(stack, 1, 0);
	}
	else 
	{
		top = gettop(stack[swapswap]);
		if (top[0] > 0 && top[1] > 0)
		{
			temp = top[0];
			top[0] = top[1];
			top[1] = temp;
			if (print && swapswap)
				ft_printf("sb\n");
			else if (print)
				ft_printf("sa\n");
		}
	}
}

void	rotate(int **stack, int rotrot, int print)
{
	int	*top;
	int	temp;
	
	if (rotrot == 2)
	{
		ft_printf("rr\n");
		rotate(stack, 0, 0);
		rotate(stack, 1, 0);
	}
	else
	{
		top = gettop(stack[rotrot]);
		if (top[0] > 0 && top[1] > 0)
		{
			temp = top[0];
			while (*(++top) > 0)
				*(top - 1) = *top;
			*(top - 1) = temp;
			if (print && rotrot)
				ft_printf("rb\n");
			else if (print)
				ft_printf("ra\n");
		}
	}
}

void	revrot(int **stack, int revrev, int print)
{
	int	*top;
	int	*bottom;
	int	temp;
	
	if (revrev == 2)
	{
		ft_printf("rrr\n");
		revrot(stack, 0, 0);
		revrot(stack, 1, 0);
	}
	else
	{
		top = gettop(stack[revrev]);
		bottom = getbottom(stack[revrev]) - 1;
		if (*bottom > 0 && *(bottom - 1) > 0)
		{
			temp = *bottom;
			while (bottom-- != top)
				bottom[1] = bottom[0];
			top[0] = temp;
			if (print && revrev)
				ft_printf("rrb\n");
			else if (print)
				ft_printf("rra\n");
		}
	}
}
