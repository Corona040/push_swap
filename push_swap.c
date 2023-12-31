/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 10:58:28 by ecorona-          #+#    #+#             */
/*   Updated: 2023/12/30 19:58:56 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_arg	arg;
	t_list	**stack;
	t_list	*node;

	arg = (t_arg){.c = argc, .v = argv, .free = 0, .ptr_v = argv};
	init_args(&arg, 0, -1);
	free_argv(&arg);
	stack = init_stack(&arg);
	node = stack[0];
	(void) node;
}

/*
int	main(int argc, char **argv)
{
	t_arg	arg;
	t_list	**stack;
	t_list	*node;

	arg = (t_arg){.c = argc, .v = argv, .free = 0, .ptr_v = argv};
	init_args(&arg, 0, -1);
	//for (int i = 0; i < arg.c; i++)
	//	ft_printf("%i\n", ft_atoi(arg.v[i]));
	free_argv(&arg);
	stack = init_stack(&arg);
	node = stack[0];
	for (int i = 0; i < arg.c; i++)
	{
		ft_printf("%i\n",*(int *)(node->content));
		node = node->next;
	}
}
*/
