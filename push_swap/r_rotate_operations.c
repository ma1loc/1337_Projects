#include "push_swap.h"

// the last element become the first
void	rra(t_stack *stack_a, int print_flag)
{
	t_list *first_node;
	t_list *last_node;

	if (!stack_a || !stack_a->head || !stack_a->head->next)
		return ;

	first_node = stack_a->head;
	last_node = stack_a->tail; // save before removing it

	stack_a->tail = last_node->prev; // move to old_tail prev to be a tail
	stack_a->tail->next = NULL;	 // set the next of the new tail to NULL as it last
	first_node->prev = last_node;	 // set the prev of the first node to tail as a first
	last_node->next = first_node;	 // update the next of the new_node to point the first one
	last_node->prev = NULL;		 // as the first one there's no prev
	stack_a->head = last_node;	 // here we update the head to point to new node.
	if (print_flag)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b, int print_flag)
{
	t_list *first_node;
	t_list *last_node;

	if (!stack_b || !stack_b->head || !stack_b->head->next || !stack_b->tail)
		return ;

	first_node = stack_b->head;
	last_node = stack_b->tail;

	stack_b->tail = last_node->prev;
	stack_b->tail->next = NULL;
	first_node->prev = last_node;
	last_node->next = first_node;
	last_node->prev = NULL;
	stack_b->head = last_node;
	if (print_flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
}
