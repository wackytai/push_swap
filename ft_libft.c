/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:59:50 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/02/03 14:28:00 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

long long	ft_atoll(const char *nptr)
{
	int			i;
	long long	s;
	long long	res;

	i = 0;
	s = 1;
	res = 0;
	if (nptr[i] == '-')
	{
		s *= -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = ((res * 10) + (nptr[i] - '0'));
		i++;
	}
	return (res * s);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	s;
	int	res;

	i = 0;
	s = 1;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
	{
		i++;
	}
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (res * s);
}
