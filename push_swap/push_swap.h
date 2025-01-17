# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h> // delete_me
#include <unistd.h>
#include <stdlib.h>

// how know
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
void	pa(t_stack *stack_a, t_stack *stack_b, int print_flag); // push 

void	pb();
void	ra();
void	rb();
void	rr();
void	rra();
void	rrb();
void	rrr();

// push_swap noting to do with this know
void    is_valid_num(char **argv);



# endif
