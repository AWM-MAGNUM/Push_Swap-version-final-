/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 00:55:38 by bel-kase          #+#    #+#             */
/*   Updated: 2023/04/06 00:33:33 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int			i;
	long long	res;
	int			signe;

	res = 0;
	signe = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res = res + str[i] - 48;
		i++;
	}
	return (signe * res);
}

long long int	ft_atoll(const char *str)
{
	t_node	atoll;

	atoll.sign = 1;
	atoll.i = -1;
	atoll.result = 0;
	while (str[atoll.i] == ' ' || str[atoll.i] == '+')
		atoll.i++;
	if (str[atoll.i++] == '-')
		atoll.sign = -1;
	while (str[++atoll.i] != '\0')
	{
		if (str[atoll.i] < '0' || str[atoll.i] > '9')
			return (0);
		atoll.digit = str[atoll.i] - '0';
		atoll.result = atoll.result * 10 + atoll.digit;
		if (atoll.result > LLONG_MAX)
		{
			if (atoll.sign == 1)
				return (LLONG_MAX);
			else
				return (LLONG_MIN);
		}
	}
	return (atoll.result * atoll.sign);
}

int	ft_lstsize(t_node *head)
{
	int		size;
	t_node	*current;

	size = 0;
	current = head;
	while (current != NULL && size < INT_MAX)
	{
		size++;
		current = current->next;
	}
	return (size);
}
