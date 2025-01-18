# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h> // delete_me
#include <unistd.h>
#include <stdlib.h>

int     main(int argc, char **argv);

// libft
long	ft_atoi(char *str);
size_t  ft_strlen(char *str);
char    **ft_split(char *str, char separator);
void    ft_putstr_fd(char *str);

// doubly linked list. for the nodes
typedef	struct s_list
{
	int	value;
	int	index;
	struct	s_list	*next;
	struct	s_list	*prev;
} t_list;

// the stack of the nodes
typedef	struct s_stack
{
	t_list *head;
	t_list *tail;
	int size;
} t_stack;

// Operations
void	sa(t_stack *stack_a, int print_flag); // swap stack a;
void	sb(t_stack *stack_b, int print_flag); //swap stack b;
void	ss(t_stack *stack_a, t_stack *stack_b); // swap the stack both of them.
void	pa(t_stack *stack_a, t_stack *stack_b); // push b to a
void	pb(t_stack *stack_a, t_stack *stack_b); // push a to b
void	ra(t_stack *stack_a, int print_flag); // rotate a
void	rb(t_stack *stack_b, int print_flag); // rotate b
void	rr(t_stack *stack_a, t_stack *stack_b); // rotate a and b
void	rra(); // reverse rotate a
void	rrb(); // reverse rotate b
void	rrr(); // reverse rotate a and b

// func for parsing (duplicat, char, --, ++, skip taps/speces/new_line...)

/// push_swap noting to do with this know
// func push the new nodes to the stack
// func check if the numbers is sorted before
// sorting 2-3 numbers
// sorting 4-5 numbers
// sorting >5  numbers, yepppp

# endif
