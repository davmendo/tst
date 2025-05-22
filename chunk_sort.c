/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:52:28 by davmendo          #+#    #+#             */
/*   Updated: 2025/05/22 19:52:30 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_count(int total)
{
	if (total <= 100)
		return (5);
	else if (total <= 500)
		return (11);
	return (22);
}

static void	push_chunks(t_node **a, t_node **b, int chunk_size, int max_val)
{
	int	current_max;
	int	pushed;

	current_max = chunk_size;
	pushed = 0;
	while (*a && pushed < max_val)
	{
		if ((*a)->index <= current_max)
		{
			do_pb(a, b);
			pushed++;
			if ((*b)->index < current_max - chunk_size / 2)
				do_rb(b);
			if (pushed == current_max)
				current_max += chunk_size;
		}
		else
			do_ra(a);
	}
}

static int	find_max_position(t_node *stack)
{
	t_node	*current;
	int		max_index;
	int		position;
	int		stack_size;

	current = stack;
	max_index = current->index;
	position = 0;
	stack_size = 0;
	while (current)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			position = stack_size;
		}
		current = current->next;
		stack_size++;
	}
	return (position);
}

static void	push_back_to_a(t_node **a, t_node **b)
{
	int	position;
	int	stack_size;

	while (*b)
	{
		position = find_max_position(*b);
		stack_size = list_length(*b);
		if (position <= stack_size / 2)
			while (position--)
				do_rb(b);
		else
			while (position++ < stack_size)
				do_rrb(b);
		do_pa(a, b);
	}
}

void	sort_chunks(t_node **stack_a, t_node **stack_b)
{
	int	total;
	int	chunk_count;
	int	chunk_size;

	total = list_length(*stack_a);
	chunk_count = get_chunk_count(total);
	chunk_size = total / chunk_count + (total % chunk_count != 0);
	push_chunks(stack_a, stack_b, chunk_size, total);
	push_back_to_a(stack_a, stack_b);
}
