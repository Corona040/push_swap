/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:14:34 by ecorona-          #+#    #+#             */
/*   Updated: 2024/01/31 00:16:05 by ecorona-         ###   ########.fr       */
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

void	print(int **stack);
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
int		shortest_path(int **stack, int target);
void	push_next(int **stack, int target);
void	naive_sort(int **stack);
/* ************************************************************************** */
// utils.c
int		*gettop(int *array);
int		*getbottom(int *array);
int		getsize(int *array);
int		is_sorted(int *array);
void	push(int **stack, int pushpush);
void	swap(int **stack, int swapswap, int print);
void	rotate(int **stack, int rotrot, int print);
void	revrot(int **stack, int revrev, int print);
/* ************************************************************************** */
// median_sort.c
float	median(int *array);
void	median_sort(int **stack);

#endif
