/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 10:58:28 by ecorona-          #+#    #+#             */
/*   Updated: 2024/01/30 17:04:22 by ecorona-         ###   ########.fr       */
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
		free_argv(&arg);
		if (is_sorted(stack[0], arg.c) != 1)
		{
			// naive_sort(stack, arg.c);
			median_sort(stack, arg.c);
		}
		for (int j = 0; j < 2; j++)
		{
			if (j == 0)
				ft_printf("a\n");
			else
				ft_printf("b\n");
			for (int k = 0; k < arg.c; k++)
				ft_printf("%i:%i, ", k, stack[j][k]);
			ft_printf("\n\n");
		}
		free_stack(stack);
	}
}
