#include "push_swap.h"

void	to_move_five(t_stack *stack_a, t_stack *stack_b)
{
	sort_three(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	first_smallest;
	int	second_smallest;

	first_smallest = find_smallest(stack_a);
	move_to_top(stack_a, first_smallest);
	pb(stack_a, stack_b);
	second_smallest = find_smallest(stack_a);
	move_to_top(stack_a, second_smallest);
	pb(stack_a, stack_b);
	to_move_five(stack_a, stack_b);
}
