/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 00:56:27 by bel-kase          #+#    #+#             */
/*   Updated: 2023/04/04 01:39:09 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_node **pile_a, t_node **pile_b)
{
	t_node	sort;

	sort.i = 0;
	sort.len = ft_lstsize(*pile_a);
	sort.max_index = max_index_position(pile_a);
	sort.max_bits = max_bit_position(sort.len);
	*pile_b = NULL;
	while (sort.i <= sort.max_bits)
	{
		sort.k = 0;
		while (sort.k < sort.len)
		{
			sort.current_bit = ((*pile_a)->index >> sort.i);
			if (!(sort.current_bit & 1))
				ft_push(pile_a, pile_b, 0);
			else
				ft_rotate(pile_a, 1);
			sort.k++;
		}
		sort.i++;
		while (*pile_b)
			ft_push(pile_b, pile_a, 1);
	}
}

void	ft_push(t_node **pile_a, t_node **pile_b, int op)
{
	t_node	*tmp;
	t_node	*new_elem;

	if (*pile_a == NULL)
		return ;
	tmp = *pile_a;
	new_elem = (t_node *)malloc(sizeof(t_node));
	if (!new_elem)
		return ;
	new_elem->value = (*pile_a)->value;
	new_elem->index = (*pile_a)->index;
	new_elem->next = NULL;
	if (*pile_b == NULL)
		*pile_b = new_elem;
	else
	{
		new_elem->next = *pile_b;
		*pile_b = new_elem;
	}
	*pile_a = (*pile_a)->next;
	free(tmp);
	if (op == 1)
		write(1, "pa\n", 3);
	else if (op == 0)
		write(1, "pb\n", 3);
}
