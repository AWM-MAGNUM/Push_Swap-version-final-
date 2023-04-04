/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_insruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 00:55:58 by bel-kase          #+#    #+#             */
/*   Updated: 2023/04/04 00:56:01 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_node **stack, int op)
{
	t_node	*first;
	t_node	*second;
	int		tmp;

	if (*stack == NULL || (*stack)->next == *stack)
		return ;
	first = *stack;
	second = (*stack)->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
	if (op == 0)
		write(1, "sb\n", 3);
	else if (op == 1)
		write(1, "sa\n", 3);
	else
		return ;
}

void	ft_rotate(t_node **stack, int op)
{
	t_node	*last;
	t_node	*first;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	if (op == 0)
		write(1, "rb\n", 3);
	else if (op == 1)
		write(1, "ra\n", 3);
	else
		return ;
}

void	ft_r_rotate(t_node **stack, int is_a)
{
	t_node	*last;
	t_node	*prev;

	if (*stack && (*stack)->next)
	{
		last = *stack;
		prev = NULL;
		while (last->next != NULL)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *stack;
		*stack = last;
	}
	if (!is_a)
		write(1, "rrb\n", 4);
	else if (is_a == 1)
		write(1, "rra\n", 4);
	return ;
}
