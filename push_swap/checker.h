#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE   42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, char c);
char	*ft_strdup(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list		*head;
	int			size;
}	t_stack;

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

t_stack	*stack_init(void);
void	split_input(char **argv, t_stack *stack_a, t_stack *stack_b);
void	free_stack(t_stack *stack);
void	free_stacks(t_stack *stack_a, t_stack *stack_b);
int		is_sorted(t_stack *stack);
t_list	*ft_last_node(t_list *header);
int		find_largest(t_stack *stack);
t_list	*ft_lst_new(int value);
int		ft_lst_size(t_stack *stack);
void	ft_lst_add_back(t_stack *stack, t_stack *stack_b, int value);
int		is_digit(char *str);
int		has_space(char *str);
void	free_split(char **split);
void	cleanup_and_exit(t_stack *stack_a, t_stack *stack_b, char **split);
int		is_duplicate(t_stack *stack, int nbr);
void	sort_stacks(t_stack *stack_a, t_stack *stack_b);
int		*sorted_array(t_stack *stack_a);
void	sort_num(t_stack *stack_a, t_stack *stack_b);
int		count_chunk(int stack_size);
void	put_index(t_stack *stack);
int		get_min_index(t_stack *stack);
int		find_max_pos(t_stack *stack);
void	sort_three(t_stack *stack_a);
void	sort_four(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
int		find_smallest(t_stack *stack);
void	move_to_top(t_stack *stack, int smallest);
int		all_space(char *str);
int		ft_atoi(char *str, t_stack *stack_a, t_stack *stack_b, char **split);

#endif