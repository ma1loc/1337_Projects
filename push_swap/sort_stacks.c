#include "push_swap.h"

void	sort_three(t_stack *stack_a)
{
	int	first;
	int second;
	int third;

	first = stack_a->head->value;
	second = stack_a->head->next->value;
	third = stack_a->head->next->next->value;

	if (first > second && first > third && second < third)
		ra(stack_a, 1);
	else if (first < second && first > third)
		rra(stack_a, 1);
	else if (first > second && first < third)
		sa(stack_a, 1);
	else if (first < second && second > third)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (first > second && second > third)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
}
// void	sort_four(t_stack *stack_a);
void	find_smallest(t_stack *stack); //helper func
void	sort_five(t_stack *stack_a, t_stack *stack_b);
// void	sort_up_five();

// void	sort_stacks(t_stack *stack_a, t_stack *stack_b)
void	sort_stacks(t_stack *stack_a)
{
	if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 4)
		five_sort(stack_a);
	// else
	//	sort_up_five(stack_a, stack_b);
}
