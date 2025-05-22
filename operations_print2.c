/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_print2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:50:20 by davmendo          #+#    #+#             */
/*   Updated: 2025/05/22 19:50:23 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_op(char *op)
{
	write(1, op, ft_strlen(op));
	write(1, "\n", 1);
}

void	do_pa(t_node **a, t_node **b)
{
	op_pa(a, b);
	print_op("pa");
}

void	do_pb(t_node **a, t_node **b)
{
	op_pb(a, b);
	print_op("pb");
}

void	do_ra(t_node **a)
{
	op_ra(a);
	print_op("ra");
}

void	do_rb(t_node **b)
{
	op_rb(b);
	print_op("rb");
}
