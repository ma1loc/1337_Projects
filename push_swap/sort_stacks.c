#include "push_swap.h"

// example 2 1 3 6 5 8 = 12 instructions, check this out.

void	sort_three(t_stack *stack_a)
{
	t_list	*head;
	
	int first;
	int second;
	int therd;

	head = stack_a->head;
	first = head->value;
	second = head->next->value;
	therd = head->next->next->value;

	if (stack_a->size == 2)
		sa(stack_a, 1);
	else
	{
		if (first < second && second > therd) // 132
		{
			rra(stack_a, 1); // 213
			sa(stack_a, 1); // 123 done
		}
		else if (first > second && second < therd) // 213;
			sa(stack_a, 1); // 123 done
		else if (first < second && first > therd)  // 231
			rra(stack_a, 1); // 123 done
		else if (first > second && second > therd) // 321
		{
			sa(stack_a, 1); // 231
			rra(stack_a, 1); // 123 done
		}
		else if (first > second && first > therd) // 312
			ra(stack_a, 1); // 123 done
	}
}

void	sort_five();
void	sort_up_five();

// void	sort_stacks(t_stack *stack_a, t_stack *stack_b)
void	sort_stacks(t_stack *stack_a)
{
	int stack_size;
	
	stack_size = stack_a->size;

	if (stack_size <= 3)
		sort_three(stack_a);
	//else if (stack_size <= 5)
	//	five_sort(stack_a, stack_b);
	//else
	//	sort_up_five(stack_a, stack_b);

}
 