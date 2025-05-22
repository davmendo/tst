/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_print3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:50:28 by davmendo          #+#    #+#             */
/*   Updated: 2025/05/22 19:50:31 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Static helper function to print operation names
static void	print_op(char *op)
{
	write(1, op, ft_strlen(op));
	write(1, "\n", 1);
}

void	do_rra(t_node **a)
{
	op_rra(a);
	print_op("rra");
}

void	do_rrb(t_node **b)
{
	op_rrb(b);
	print_op("rrb");
}

void	do_rrr(t_node **a, t_node **b)
{
	op_rrr(a, b);
	print_op("rrr");
}
