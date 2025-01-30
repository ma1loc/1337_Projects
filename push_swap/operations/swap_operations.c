#include "../src_push_swap/push_swap.h"

void	swap(t_stack *stack)
{
	t_list	*first_node;
	t_list	*second_node;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	first_node = stack->head;
	second_node = first_node->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	stack->head = second_node;
}

void	sa(t_stack *stack_a, int print_flag)
{
	swap(stack_a);
	if (print_flag)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b, int print_flag)
{
	swap(stack_b);
	if (print_flag)
		write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	write(1, "ss\n", 3);
}
