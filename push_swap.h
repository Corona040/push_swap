/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:14:34 by ecorona-          #+#    #+#             */
/*   Updated: 2023/12/30 19:05:27 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef struct s_arg
{
	int		c;
	char	**v;
	int		free;
	char	**ptr_v;
}	t_arg;

void	init_args(t_arg *arg, int is_neg, int idx);
void	leave(t_arg *arg, int error);
void	check_args(t_arg *arg, int zeros, int i, int j);
void	free_argv(t_arg *arg);
t_list	**init_stack(t_arg *arg);

#endif
