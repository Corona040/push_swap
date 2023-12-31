/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:41:00 by ecorona-          #+#    #+#             */
/*   Updated: 2023/12/30 19:12:00 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**init_stack(t_arg *arg)
{
	t_list	**stack;
	t_list	*node;
	void	*content;
	int		i;

	stack = ft_calloc(2, sizeof(t_list *));
	i = 0;
	while (i < arg->c)
	{
		content = ft_calloc(1, sizeof(int));
		*(int *)content = ft_atoi(arg->v[i]);
		node = ft_lstnew(content);
		if (i == 0)
			stack[0] = node;
		else
			ft_lstadd_back(stack, node);
		i++;
	}
	stack[1] = ft_lstnew(NULL);
	return (stack);
}
