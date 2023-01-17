/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:53:24 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/01/11 16:35:20 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**stack;
	if (argc > 1)
	{
		if (argc > 2)
		{
			if (check_doubles(argv) == 0)
				exit(0);
		}
		*stack = parse_arg(argv);
		while ((*stack)->next != NULL)
		{
			printf("Value: %lld\n", (*stack)->value);
			*stack = (*stack)->next;
		}
	}
	return (0);
}
