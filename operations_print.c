/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:50:06 by davmendo          #+#    #+#             */
/*   Updated: 2025/05/22 19:50:08 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_op(char *op)
{
	write(1, op, ft_strlen(op));
	write(1, "\n", 1);
}

void	do_sa(t_node **a)
{
	op_sa(a);
	print_op("sa");
}

void	do_sb(t_node **b)
{
	op_sb(b);
	print_op("sb");
}

void	do_ss(t_node **a, t_node **b)
{
	op_ss(a, b);
	print_op("ss");
}

void	do_rr(t_node **a, t_node **b)
{
	op_rr(a, b);
	print_op("rr");
}
