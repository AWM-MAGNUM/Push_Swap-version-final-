/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_stack_generator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 00:56:40 by bel-kase          #+#    #+#             */
/*   Updated: 2023/04/04 00:56:42 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_num(t_node **pile)
{
	t_node	sort_3;

	sort_3.a = (*pile)->value;
	sort_3.b = (*pile)->next->value;
	sort_3.c = (*pile)->next->next->value;
	if (sort_3.a > sort_3.b && sort_3.c < sort_3.a && sort_3.c < sort_3.b)
	{
		ft_swap(pile, 1);
		ft_r_rotate(pile, 1);
	}
	else if (sort_3.a < sort_3.b && sort_3.b > sort_3.c && sort_3.c > sort_3.a)
	{
		ft_swap(pile, 1);
		ft_rotate(pile, 1);
	}
	else if (sort_3.a > sort_3.b && sort_3.b < sort_3.c && sort_3.c > sort_3.a)
		ft_swap(pile, 1);
	else if (sort_3.a < sort_3.b && sort_3.b > sort_3.c)
		ft_r_rotate(pile, 1);
	else if (sort_3.c > sort_3.b && sort_3.b < sort_3.a && sort_3.a > sort_3.c)
		ft_rotate(pile, 1);
}

void	sort_four_num(t_node **stack_a, t_node **stack_b)
{
	int		min_val;
	t_node	*min_node;
	t_node	*tmp;

	min_val = (*stack_a)->value;
	min_node = *stack_a;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->value < min_val)
		{
			min_val = tmp->value;
			min_node = tmp;
		}
		tmp = tmp->next;
	}
	while (*stack_a != min_node)
	{
		ft_rotate(stack_a, 1);
	}
	ft_push(stack_a, stack_b, 0);
	sort_three_num(stack_a);
	ft_push(stack_b, stack_a, 1);
}

void	sort_five_elm(t_node **stack_a, t_node **stack_b)
{
	int		min_val;
	t_node	*min_node;
	t_node	*tmp;

	min_val = (*stack_a)->value;
	min_node = *stack_a;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->value < min_val)
		{
			min_val = tmp->value;
			min_node = tmp;
		}
		tmp = tmp->next;
	}
	while (*stack_a != min_node)
	{
		ft_rotate(stack_a, 1);
	}
	ft_push(stack_a, stack_b, 0);
	sort_four_num(stack_a, stack_b);
	ft_push(stack_b, stack_a, 1);
}
