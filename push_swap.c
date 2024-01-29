/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 10:58:28 by ecorona-          #+#    #+#             */
/*   Updated: 2024/01/29 19:16:24 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_arg	arg;
	int		**stack;

	arg = (t_arg){.c = argc, .v = argv, .free = 0, .ptr_v = 0};
	init_args(&arg, 0, -1);
	stack = init_stack(&arg);
	free_argv(&arg);
	sort_stack(stack, arg.c);
	free_stack(stack);
}
