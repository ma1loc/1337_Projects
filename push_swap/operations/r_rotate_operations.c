#include "../src_push_swap/push_swap.h"

void	rra(t_stack *stack_a, int print_flag)
{
	t_list	*first_node;
	t_list	*last_node;
	t_list	*second_last_node;

	if (!stack_a || !stack_a->head || !stack_a->head->next)
		return ;
	first_node = stack_a->head;
	last_node = ft_last_node(stack_a->head);
	second_last_node = stack_a->head;
	while (second_last_node->next != last_node)
		second_last_node = second_last_node->next;
	second_last_node->next = NULL;
	last_node->next = first_node;
	stack_a->head = last_node;
	if (print_flag)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b, int print_flag)
{
	t_list	*first_node;
	t_list	*last_node;
	t_list	*second_last_node;

	if (!stack_b || !stack_b->head || !stack_b->head->next)
		return ;
	first_node = stack_b->head;
	last_node = ft_last_node(stack_b->head);
	second_last_node = stack_b->head;
	while (second_last_node->next != last_node)
		second_last_node = second_last_node->next;
	second_last_node->next = NULL;
	last_node->next = first_node;
	stack_b->head = last_node;
	if (print_flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	write(1, "rrr\n", 4);
}
