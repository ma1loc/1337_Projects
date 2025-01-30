#include "../src_push_swap/push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp;

	if (!stack_b || !stack_b->head)
		return ;
	tmp = stack_b->head;
	stack_b->head = stack_b->head->next;
	tmp->next = stack_a->head;
	stack_a->head = tmp;
	stack_a->size++;
	stack_b->size--;
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp;

	if (!stack_a || !stack_a->head)
		return ;
	tmp = stack_a->head;
	stack_a->head = stack_a->head->next;
	tmp->next = stack_b->head;
	stack_b->head = tmp;
	stack_a->size--;
	stack_b->size++;
	write(1, "pb\n", 3);
}
