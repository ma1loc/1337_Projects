# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

int     main(int argc, char **argv);

// libft
long	ft_atoi(char *str);
size_t  ft_strlen(char *str);
char    **ft_split(char *str, char separator);
void    ft_putstr_fd(char *str, int std);
char	*ft_strnstr(const char *str, const char *to_find, size_t n);

// doubly linked list. for the nodes
typedef	struct s_list
{
	int	value;
	int	index;
	struct	s_list	*next;
	struct	s_list	*prev;
} t_list;

// the header of the nodes
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
void	rra(t_stack *stack_a, int print_flag); // reverse rotate a
void	rrb(t_stack *stack_b, int print_flag); // reverse rotate b
void	rrr(t_stack *stack_a, t_stack *stack_b); // reverse rotate a and b

// push_swap
t_list	*ft_lst_new(int value);
size_t	ft_lst_size(t_stack *stack);
t_list	*ft_last_node(t_list *header);
void	ft_lst_add_back(t_stack *stack, int value);
t_stack	*stack_init(void);
int		is_digit(char *str);
int		has_space(char *str);
int		is_valid_atoi(char *str);
void	split_input(char **argv, t_stack *stack);
void	free_split(char **split);
void	free_stack(t_stack *stack);
void	cleanup_and_exit(t_stack *stack, char **split);
int		is_duplicate(t_stack *stack, int nbr);
int		is_sorted(t_stack *stack);
// void	sort_stacks(t_stack *stack_a, t_stack *stack_b);
void	sort_stacks(t_stack *stack_a);

// sorting 2-3 numbers
// sorting 4-5 numbers
// sorting >5  numbers, yepppp

# endif
