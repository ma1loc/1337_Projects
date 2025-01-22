#include "push_swap.h"

// example 2 1 3 6 5 8 = 12 instructions, check this out.
// 132-done
// 231-not
// 213-not
// 321-not
// 312-done

void	sort_three(t_stack *stack_a)
{
	int	first;
	int second;
	int third;

	first = stack_a->head->value;
	second = stack_a->head->next->value;
	third = stack_a->head->next->next->value;

	if (first < second && second > third)
	{
		rra(stack_a, 1);
		sa(stack_a, 1);
	}
	else if (first > second && second < third)
		ra(stack_a, 1);
	else if (first > second && first > third)
		ra(stack_a, 1);
	else if (first < second && first > third)
		rra(stack_a, 1);
	else if (first > second && second > third)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
}

void	sort_five();
void	sort_up_five();

// void	sort_stacks(t_stack *stack_a, t_stack *stack_b)
void	sort_stacks(t_stack *stack_a)
{
	if (stack_a->size == 3)
		sort_three(stack_a);
	//else if (stack_size <= 5)
	//	five_sort(stack_a, stack_b);
	//else
	//	sort_up_five(stack_a, stack_b);

}
