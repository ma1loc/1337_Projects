#include "push_swap.h"

void	ra(t_stack *stack_a, int print_flag)
{
	t_list	*first_node;
	t_list	*last_node;

	if (!stack_a || !stack_a->head || !stack_a->head->next)
		return ;
	first_node = stack_a->head;
	last_node = stack_a->head;
	while (last_node->next)
		last_node = last_node->next;
	stack_a->head = first_node->next;
	last_node->next = first_node;
	first_node->next = NULL;
	if (print_flag)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b, int print_flag)
{
	t_list	*first_node;
	t_list	*last_node;

	if (!stack_b || !stack_b->head || !stack_b->head->next)
		return ;
	first_node = stack_b->head;
	last_node = stack_b->head;
	while (last_node->next)
		last_node = last_node->next;
	stack_b->head = first_node->next;
	last_node->next = first_node;
	first_node->next = NULL;
	if (print_flag)
		write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	write(1, "rr\n", 3);
}
