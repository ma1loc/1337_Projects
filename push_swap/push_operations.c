#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	// push first element in stack_b on top of stack_a
	t_list	*tmp;
	
	// first thing first here have to check stack_b is empty
	if (!stack_b || !stack_b->head) // check out this head->next //
		return ;

	// store the node being removed
	tmp = stack_b->head;
	stack_b->head = stack_b->head->next;
	if (stack_b->head) // -> check out this <- //
		stack_b->head->prev = NULL; // 
	// [tmp->next = stack_a->head] tmp as it will be the first node i give here
	// what the header points to becouse we don't want to loss the data
	tmp->next = stack_a->head; 
	if (stack_a->head)
		stack_a->head->prev = tmp;
	stack_a->head = tmp; // here we update the head point
	tmp->prev = NULL; 
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
	if (stack_a->head)
		stack_a->head->prev = NULL;
	tmp->next = stack_b->head;
	if (stack_b->head)
		stack_b->head->prev = tmp;
	stack_b->head = tmp;
	tmp->prev = NULL;
	stack_a->size--;
	stack_b->size++;
	write(1, "pb\n", 3);
}
