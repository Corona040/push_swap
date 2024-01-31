/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 10:58:28 by ecorona-          #+#    #+#             */
/*   Updated: 2024/01/31 00:12:20 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_arg	arg;
	int		**stack;

	if (argc > 1)
	{
		arg = (t_arg){.c = argc, .v = argv, .free = 0, .ptr_v = 0};
		init_args(&arg, 0, -1);
		stack = init_stack(&arg);
		if (is_sorted(stack[0]) != 1)
			median_sort(stack);
		free_argv(&arg);
		free_stack(stack);
	}
}
