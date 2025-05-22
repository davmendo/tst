/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:49:03 by davmendo          #+#    #+#             */
/*   Updated: 2025/05/22 19:49:11 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	error_exit_bonus(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

t_node	*create_node_bonus(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		error_exit_bonus();
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	add_back_bonus(t_node **stack, t_node *new_node)
{
	t_node	*tmp;

	if (!stack || !new_node)
		return ;
	if (!*stack)
		*stack = new_node;
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

// Function split to respect 25 lines limit (Helper for parse_arguments_bonus)
static void	process_single_arg_bonus(char *arg, t_node **stack)
{
	int		num;
	t_node	*node;

	if (!is_valid_number(arg))
	{
		if (*stack)
			free_stack(*stack);
		error_exit_bonus();
	}
	num = ft_atoi(arg);
	node = create_node_bonus(num);
	add_back_bonus(stack, node);
}

t_node	*parse_arguments_bonus(int argc, char **argv)
{
	t_node	*stack;
	int		i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		process_single_arg_bonus(argv[i], &stack);
		i++;
	}
	if (has_duplicates(stack))
	{
		free_stack(stack);
		error_exit_bonus();
	}
	return (stack);
}
