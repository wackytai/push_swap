/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:52:48 by marvin            #+#    #+#             */
/*   Updated: 2023/03/14 16:13:23 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# ifndef PIVOT
#  define PIVOT 3
# endif

typedef struct s_list
{
	struct s_list	*prev;
	int				value;
	int				rank;
	struct s_list	*next;
}					t_list;

typedef struct s_atb
{
	int				x;
	int				y;
}					t_atb;

/* main */
int				main(int argc, char **argv);
/*parse_utils*/
t_list			*parse_arg(t_list *stack, char **argv, int argc);
void			initialize_stack(t_list **stack_a, int value);
void			free_stack(t_list **stack);
int				check_doubles(char **argv);
int				check_input(char *nptr);
/*lst_utils*/
t_list			*lstnew(int value);
t_list			*lstlast(t_list *stack);
void			lstadd_front(t_list **stack, t_list *node);
void			lstadd_back(t_list **stack, t_list *node);
int				lstsize(t_list *stack);
/*stack_utils*/
void			get_rank(t_list *stack);
int				check_sorted(t_list **stack);
void			check_to_pull(t_list **stack_a, t_list **stack_b);
int				check_to_push(t_list *stack_a, int rank, int size);
t_atb			sequence_finder(t_list *stack, int i);
/*sort_utils*/
int				put_in_place(t_list **stack, char letter, int counter);
void			arrange_stack(t_list **stack);
int				count_moves(int rank, t_list *stack);
int				store_total_moves(int moves_a, int moves_b);
t_atb			check_min(t_list *stack_a, int moves_a, t_list *stack_b,
					int moves_b);
/*ft_libft*/
int				ft_isdigit(int c);
long long		ft_atoll(const char *nptr);
int				ft_atoi(const char *nptr);
/*push_swap*/
void			push_swap(char **argv, int argc);
void			choose_sorting(int argc, t_list **stack_a, t_list **stack_b);
void			pivoting(t_list **stack_a, t_list **stack_b);
t_atb			update_seq(t_atb seq, int i, int value);
void			move_seq(t_atb seq, t_list **stack_a, t_list **stack_b,
					int size_a);
/*ps_moves*/
void			swap(t_list **stack, char letter);
void			push(t_list **src, t_list **dest, char letter);
void			rotate(t_list **stack, char letter);
void			reverse_rotate(t_list **stack, char letter);
void			push_many(t_list **stack_a, t_list **stack_b, int size_a);
/*ps_double_moves*/
void			double_swap(t_list **stack_a, t_list **stack_b);
void			double_rotate(t_list **stack_a, t_list **stack_b);
void			double_reverse_rotate(t_list **stack_a, t_list **stack_b);
void			update_stack(t_list **stack_a, t_list **stack_b, int size_a,
					int r);
/*sorting*/
void			sort_three(t_list **stack);
void			sort_five(t_list **stack_a, t_list **stack_b);
void			sort_hundreds(t_list **stack_a, t_list **stack_b);
void			sequence_leap(t_atb seq, t_list **stack_a, t_list **stack_b,
					int size_a);
int				get_tail(t_list *stack_a, t_atb seq);
/*sort_utils_extra*/
int				push_and_update(t_list **stk_a, t_list **stk_b, int size,
					int counter);
void			pivot_with_seq(t_atb seq, t_list **stack_a, t_list **stack_b,
					int size_a);
int				pivot_without_seq(t_list **stack_a, t_list **stk_b, int size_a,
					int i);
void			push_same(t_list **stk_a, int mv_a, t_list **stk_b, int mv_b);
void			push_opposites(t_list **stk_a, int mv_a, t_list **stk_b,
					int mv_b);
/* optmizing */
int				check_next(t_list *stack_a, t_atb seq, int round, int size_a);
int				get_round(int i, int size_a, int round);
int				update_counter(t_list *temp, t_list *next, int i);
int				update_next(t_list *temp, t_list **next, t_atb seq, int i);
void			check_skip_sequence(t_list **node, t_atb seq);

#endif