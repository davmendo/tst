/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:53:49 by davmendo          #+#    #+#             */
/*   Updated: 2025/05/22 19:53:51 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"

/* Parsing functions for bonus (checker) */
t_node	*parse_arguments_bonus(int argc, char **argv);
t_node	*create_node_bonus(int value);
void	add_back_bonus(t_node **stack, t_node *new_node);

#endif
