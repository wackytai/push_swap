/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:28:38 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/03/14 16:03:09 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_and_update(t_list **stk_a, t_list **stk_b, int size, int counter);

void	pivot_with_seq(t_atb seq, t_list **stack_a, t_list **stack_b,
				int size_a)
{
	int	tail;

	tail = get_tail(*stack_a, seq);
	while (lstsize(*stack_a) > seq.x)
	{
		move_seq(seq, stack_a, stack_b, size_a);
		if ((*stack_a)->next->rank == tail || (*stack_a)->rank == tail
			|| (*stack_a)->prev->rank == tail)
			break ;
	}
	return ;
}

int	pivot_without_seq(t_list **stack_a, t_list **stk_b, int size_a, int i)
{
	t_list	*head_a;
	int		counter;

	counter = ((size_a * i) / PIVOT) - ((size_a * (i - 1)) / PIVOT);
	head_a = *stack_a;
	while (counter > 0)
	{
		while ((*stack_a)->rank <= (size_a * i) / PIVOT && counter > 0)
			counter = push_and_update(stack_a, stk_b, size_a, counter);
		head_a = *stack_a;
		while ((*stack_a)->rank > (size_a * i) / PIVOT && counter > 0)
		{
			rotate(stack_a, 'a');
			if (*stack_a == head_a)
				break ;
		}
		if (*stack_a == head_a || lstsize(*stack_a) == 3)
			break ;
	}
	i++;
	return (i);
}

int	push_and_update(t_list **stk_a, t_list **stk_b, int size, int counter)
{
	if ((*stk_a)->rank < (size - 2))
		push(stk_a, stk_b, 'b');
	else
		rotate(stk_a, 'a');
	counter--;
	return (counter);
}

void	push_same(t_list **stk_a, int mv_a, t_list **stk_b, int mv_b)
{
	if (mv_a <= 0)
	{
		while (mv_a++ < 0 && mv_b++ < 0)
			double_reverse_rotate(stk_a, stk_b);
		while (mv_a++ <= 0)
			reverse_rotate(stk_a, 'a');
		while (mv_b++ <= 0)
			reverse_rotate(stk_b, 'b');
	}
	else
	{
		while (mv_a-- > 0 && mv_b-- > 0)
			double_rotate(stk_a, stk_b);
		while (mv_a-- > 0)
			rotate(stk_a, 'a');
		while (mv_b-- > 0)
			rotate(stk_b, 'b');
	}
	return ;
}

void	push_opposites(t_list **stk_a, int mv_a, t_list **stk_b, int mv_b)
{
	if (mv_a < 0)
	{
		while (mv_a++ < 0)
			reverse_rotate(stk_a, 'a');
	}
	else if (mv_a > 0)
	{
		while (mv_a-- > 0)
			rotate(stk_a, 'a');
	}
	if (mv_b < 0)
	{
		while (mv_b++ < 0)
			reverse_rotate(stk_b, 'b');
	}
	else if (mv_b > 0)
	{
		while (mv_b-- > 0)
			rotate(stk_b, 'b');
	}
	return ;
}
