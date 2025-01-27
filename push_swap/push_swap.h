# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // remove it
#include <unistd.h>
#include <stdlib.h>

int     main(int argc, char **argv);


long	ft_atoi(char *str);
size_t  ft_strlen(char *str);
char    **ft_split(char *str, char separator);
void    ft_putstr_fd(char *str, int std);
char	*ft_strnstr(const char *str, const char *to_find, size_t n);

typedef	struct s_list
{
	int		value;
	int		index;
	struct	s_list	*next;
} t_list;

typedef	struct s_stack
{
	t_list *head;
	int size;
} t_stack;

void	sa(t_stack *stack_a, int print_flag);
void	sb(t_stack *stack_b, int print_flag);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a, int print_flag);
void	rb(t_stack *stack_b, int print_flag);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a, int print_flag);
void	rrb(t_stack *stack_b, int print_flag);
void	rrr(t_stack *stack_a, t_stack *stack_b);

int		find_largest(t_stack *stack);

t_list	*ft_lst_new(int value);
int		ft_lst_size(t_stack *stack);
t_list	*ft_last_node(t_list *header);
void	ft_lst_add_back(t_stack *stack, int value);
t_stack	*stack_init(void);
int		is_digit(char *str);
int		has_space(char *str);
int		is_valid_atoi(char *str);
void	split_input(char **argv, t_stack *stack_a, t_stack *stack_b);
void	free_split(char **split);
void	free_stack(t_stack *stack);
void	cleanup_and_exit(t_stack *stack_a, t_stack *stack_b, char **split);
int		is_duplicate(t_stack *stack, int nbr);
int		is_sorted(t_stack *stack);
void	sort_stacks(t_stack *stack_a, t_stack *stack_b);
int		*sorted_array(t_stack *stack_a);
void	sort_num(t_stack *stack_a, t_stack *stack_b);
int		count_chunk(int stack_size);
int     count_chunk(int stack_size);
void    put_index(t_stack *stack);
int     find_max_pos(t_stack *stack);
int     get_min_index(t_stack *stack);

# endif