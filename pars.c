/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 00:56:08 by bel-kase          #+#    #+#             */
/*   Updated: 2023/04/04 01:43:56 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	ft_range_value_int(char **argv, int argc)
{
	int			i;
	int			j;
	long long	value;

	i = 1;
	while (i < argc)
	{
		if (!ft_is_int(argv[i]))
			exit(1);
		value = ft_atoll(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
			exit(1);
		j = i + 1;
		while (j < argc)
		{
			if (atoi(argv[i]) == atoi(argv[j]))
				exit(1);
			j++;
		}
		i++;
	}
}
