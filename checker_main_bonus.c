#include "checker_bonus.h"

static void	handle_rotate_ops(char *instr, t_node **stack_a, t_node **stack_b)
{
	if (ft_strcmp(instr, "ra") == 0)
		op_ra(stack_a);
	else if (ft_strcmp(instr, "rb") == 0)
		op_rb(stack_b);
	else if (ft_strcmp(instr, "rr") == 0)
		op_rr(stack_a, stack_b);
	else if (ft_strcmp(instr, "rra") == 0)
		op_rra(stack_a);
	else if (ft_strcmp(instr, "rrb") == 0)
		op_rrb(stack_b);
	else if (ft_strcmp(instr, "rrr") == 0)
		op_rrr(stack_a, stack_b);
	else
	{
		free_stack(*stack_a);
		free_stack(*stack_b);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

static void	handle_instruction(char *instr, t_node **stack_a, t_node **stack_b)
{
	if (!instr)
		return ;
	if (ft_strcmp(instr, "sa") == 0)
		op_sa(stack_a);
	else if (ft_strcmp(instr, "sb") == 0)
		op_sb(stack_b);
	else if (ft_strcmp(instr, "ss") == 0)
		op_ss(stack_a, stack_b);
	else if (ft_strcmp(instr, "pa") == 0)
		op_pa(stack_a, stack_b);
	else if (ft_strcmp(instr, "pb") == 0)
		op_pb(stack_a, stack_b);
	else
		handle_rotate_ops(instr, stack_a, stack_b);
}

static void	process_input(t_node **stack_a, t_node **stack_b)
{
	char	*line;
	int		len;

	line = get_next_line(0);
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		handle_instruction(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = parse_arguments_bonus(argc, argv);
	process_input(&stack_a, &stack_b);
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
