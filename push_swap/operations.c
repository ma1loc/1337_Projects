#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	// if the stack have just < 2 ? or nothing????
	if (!stack_a || stack_a->size < 2)
		return ;
	t_list *first_node;
	t_list *second_node;

	first_node = stack_a->head;  // hold the first node;
	second_node = first_node->next; // hold the next node after the first;
	
	// update the first node to the node after the second.
	first_node->next = second_node->next;
	if (second_node->next) // if there's a third node
		second_node->next->prev = first_node;
	// if it's the second become the first there's no prev (prev == NULL)
	second_node->prev = NULL;
	// here we have to add the next of the second node == first node 
	// (from now on it will be the second node, yes).
	second_node->next = first_node;
	// as i say, yes i talking to my self just to remember :),
	// the second go's first the prev will be NULL;
	// the first_node(second) have to set them to the prev will be the secont_node(first)
	first_node->prev = second_node;
	// here i have to update the stack head to pointing the new header (second_node of course)
	stack_a->head = second_node;
	// this option is just for the tail of the stack_a if it equal == 2
	// the tail have to change.
	if (stack_a->size == 2)
		stack_a->tail = first_node;
}
