#include "push_swap.h"
    
// ra = "rotate a" -> the first element become the last one in [stack a]
void	ra(t_stack *stack_a, int print_flag)
{
	t_list *first_node;
	t_list *last_node;

	// check if the stack_a is valid and have least two elements.
	if (!stack_a || !stack_a->head || !stack_a->head->next)
		return ;

	first_node = stack_a->head; // the first node
	last_node = stack_a->tail; // the last node from tail

	stack_a->head = first_node->next;
	stack_a->head->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	last_node->prev = NULL;
	// here i have to update the tail of the header?
	stack_a->tail = first_node;
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
	last_node = stack_b->tail;
	
	stack_b->head = first_node->next;
	stack_b->head->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	last_node->prev = NULL;
	stack_b->tail = first_node;
	if (print_flag)
		write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	write(1, "rr\n", 3);
}
