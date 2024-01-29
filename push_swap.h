/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:14:34 by ecorona-          #+#    #+#             */
/*   Updated: 2024/01/29 20:00:33 by ecorona-         ###   ########.fr       */
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
// sort.c
int		count_zeros(int *array, int size);
void	append(int **stack, int **ops, int op);
int		shortest_path(int **stack, int size, int cursor, int target);
int		*push_next(int **stack, int size, int *cursor, int target);
void	sort_stack(int **stack, int size);

#endif
