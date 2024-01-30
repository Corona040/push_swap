/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:14:34 by ecorona-          #+#    #+#             */
/*   Updated: 2024/01/30 16:59:23 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_arg
{
	int		c;
	char	**v;
	int		free;
	char	**ptr_v;
}	t_arg;

typedef struct s_intlist
{
	int	*list;
	int	size;
}	t_intlist;

/* ************************************************************************** */
//	init_args.c
void	leave(t_arg *arg, int **stack, int error, int error_status);
void	free_argv(t_arg *arg);
void	split_argv(t_arg *arg);
void	check_args(t_arg *arg, int zeros, int i, int j);
void	init_args(t_arg *arg, int is_neg, int idx);
/* ************************************************************************** */
//	init_stack.c
void	free_stack(int **stack);
void	ft_bubble_sort(int *dest, int *src, int size);
void	ft_index_algo(int **stack, int *sorted_a, int *result,  int size);
void	ft_index(t_arg *arg, int **stack, int size);
int		**init_stack(t_arg *arg);
/* ************************************************************************** */
// naive_sort.c
int		shortest_path(int **stack, int size, int cursor, int target);
void	push_next(int **stack, int size, int *cursor, int target);
void	naive_sort(int **stack, int size);
/* ************************************************************************** */
// utils.c
void	push(int **stack, int size, int pushpush);
void	swap(int **stack, int size, int swapswap, int print);
void	rotate(int **stack, int size, int rotrot, int print);
void	revrot(int **stack, int size, int revrev, int print);
int		top(int *array, int size, int depth);
int		count_zeros(int *array, int size);
int		is_sorted(int *array, int size);
/* ************************************************************************** */
// median_sort.c
float	median(int *array, int size);
void	median_sort(int **stack, int size);

#endif
